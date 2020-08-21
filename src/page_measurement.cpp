#include "page_measurement.h"
#include "display_wrapper.h"

MeasuringPage::MeasuringPage(PSProfile &psRef)
: ps{psRef}
{
	stop_but.rect.x = 60;
	stop_but.rect.y = 140;
	stop_but.rect.width = 120;
	stop_but.rect.height = 60;
	stop_but.rect.radius = 15;
	stop_but.text = "STOP";
	stop_but.fontsize = FONT_SIZE_MED;
	stop_but.text_color = LCD_COLOR_WHITE;
	stop_but.bg_color = LCD_COLOR_RED;

	did_pass = false;
	did_fail = false;
}

void MeasuringPage::display() {
	fill_screen(LCD_COLOR_YELLOW);
	set_bg_color(LCD_COLOR_YELLOW);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_SMALL);
	display_string_centered(0, "Measuring");
	display_string(0, LINE(1), "Time Elapsed:", LEFT_MODE);

	set_font_size(FONT_SIZE_MED);
	int minutes = MeasurementTimer::get_minutes(ps.test_time_s);
	float seconds = MeasurementTimer::get_seconds(ps.test_time_s);
	char tm_string[10];
	if (snprintf(tm_string, sizeof tm_string, "of %2d:%02.0f", minutes, seconds) >= 0)
		display_string(0, 50, tm_string, RIGHT_MODE);

	set_font_size(FONT_SIZE_SMALL);
	display_string(0, 254, "Set +12 mA: ", LEFT_MODE);
	display_string(0, 279, "Set +5 mA: ", LEFT_MODE);
	display_string(0, 304 , "Set -12 mA: ", LEFT_MODE);
	display_ps_profile();

	set_font_size(FONT_SIZE_MED);
	display_string(0, 229, ps.name, CENTER_MODE);

	set_font_size(FONT_SIZE_SMALL);
	set_fg_color(LCD_COLOR_GRAY);
	display_string(0, LINE(5), "+12V:     V", LEFT_MODE);
	display_string(0, LINE(6), " +5V:     V", LEFT_MODE);
	display_string(0, LINE(7), "-12V:     V", LEFT_MODE);
	display_string(0, LINE(5), "mA", RIGHT_MODE);
	display_string(0, LINE(6), "mA", RIGHT_MODE);
	display_string(0, LINE(7), "mA", RIGHT_MODE);
	display_measurements();

	stop_but.draw();
}

void MeasuringPage::display_ps_profile() {
	char ma_string[6];
	set_bg_color(LCD_COLOR_YELLOW);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_SMALL);
	if (snprintf(ma_string, sizeof ma_string, "%4d", ps.mA_12V) >=0 )
		display_string(1, 254, ma_string, RIGHT_MODE);
	if (snprintf(ma_string, sizeof ma_string, "%4d", ps.mA_5V) >=0 )
		display_string(1, 279, ma_string, RIGHT_MODE);
	if (snprintf(ma_string, sizeof ma_string, "%4d", ps.mA_N12V) >=0 )
		display_string(1, 304, ma_string, RIGHT_MODE);
}

void MeasuringPage::display_measurements() {
	char reading_string[8];
	set_bg_color(LCD_COLOR_YELLOW);
	set_fg_color(LCD_COLOR_BLUE);
	set_font_size(FONT_SIZE_SMALL);

	if ( sprintf(reading_string, "%2.2f", measurer.get_average(AdcChannels::voltage12V)) >= 0 )
		display_string(55, LINE(5), reading_string, LEFT_MODE);
	if ( sprintf(reading_string, "%2.2f", measurer.get_average(AdcChannels::voltage5V)) >= 0 )
		display_string(65, LINE(6), reading_string, LEFT_MODE);
	if ( sprintf(reading_string, "%2.2f", measurer.get_average(AdcChannels::voltageN12V)) >= 0 )
		display_string(55, LINE(7), reading_string, LEFT_MODE);

	if ( sprintf(reading_string, "%4d", (uint16_t)measurer.get_average(AdcChannels::current12V)) >= 0 )
		display_string(215, LINE(5), reading_string, RIGHT_MODE);
	if ( sprintf(reading_string, "%4d", (uint16_t)measurer.get_average(AdcChannels::current5V)) >= 0 )
		display_string(215, LINE(6), reading_string, RIGHT_MODE);
	if ( sprintf(reading_string, "%4d", (uint16_t)measurer.get_average(AdcChannels::currentN12V)) >= 0 )
		display_string(215, LINE(7), reading_string, RIGHT_MODE);
}


void MeasuringPage::update() {
	stop_but.update();
	if (timer.read_ms() > timer.last_time_read) {
		timer.last_time_read = timer.read_ms();
		display_time((float)timer.last_time_read/1000.0f);

		if ((timer.last_time_read % 50) == 0) {
			display_measurements();
			check_for_failures();
			measurer.reset_all_averages();
		} else {
			measurer.update_all_averages();
		}
	}

	if ((timer.read_ms() > (ps.test_time_s * 1000)) && !did_fail) {
		did_pass = true;
		for (auto &r : results) {
			if (!r.passed)
				did_pass = false;
		}
	}

	handle_startup_sound();
}

void MeasuringPage::check_for_failures() {
	const uint16_t kStabilizationTime = 3000;
	const float kVoltageTolerance = 1.0F;
	const float kCurrentTolerance = 200.0F;

	if (timer.read_ms() >= kStabilizationTime) {
		//Todo:
		//for (auto &chan : AdcChannelList)
		//    check_for_failure(chan);
		//    void check_for_failure(AdcChannel chan) {
		//        expected_val = ps.val[chan]; 
		//        tolerance = ps.tolerance[chan];
		//    // PSProfile { 
		// 		PSPRofileID psPRofileID;
		//    	float val[NumAdcChannels];
		//    	float tolerance[NumAdcChannels];
		//    	uint16_t test_time_s;
		//    	}
		//
		//    	const PSProfile psPRofileArray[] = {
		// 	      {Pod20, {12.0F, 5.0F, 12.0F, 700, 1000, 280}, {1.0, 1.0, 1.0, 100, 100, 50}, 10*60},
		//    	}
		//    	
		check_for_failure(AdcChannels::voltage12V, 12.0F, kVoltageTolerance);
		check_for_failure(AdcChannels::voltage5V, 5.0F, kVoltageTolerance);
		check_for_failure(AdcChannels::voltageN12V, 12.0F, kVoltageTolerance);
		check_for_failure(AdcChannels::current12V, (float)ps.mA_12V, kCurrentTolerance);
		check_for_failure(AdcChannels::current5V, (float)ps.mA_5V, kCurrentTolerance);
		check_for_failure(AdcChannels::currentN12V, (float)ps.mA_N12V, kCurrentTolerance);
	} else {
		measurer.reset_all_minmax();
	}
}

//Todo: Checker class
void MeasuringPage::register_fail(AdcChannels chan, float bad_value, ResultType::FailCode code) {
	did_fail = true;
	results[chan].passed = false;
	results[chan].fail_time = timer.read_ms();
	results[chan].set_fail_code(code);
	results[chan].failed_value = bad_value;
}

void MeasuringPage::check_for_failure(AdcChannels chan, float expected_val, float tolerance) {
	if (results[chan].passed) {
		float actual_val = measurer.get_average(chan);
		if ((actual_val - expected_val) > tolerance) {
			register_fail(chan, actual_val, ResultType::FailCode::AVERAGE_TOO_HIGH);
		}
		if ((expected_val - actual_val) > tolerance) {
			register_fail(chan, actual_val, ResultType::FailCode::AVERAGE_TOO_LOW);
		}
		actual_val = measurer.get_max(chan);
		if ((actual_val - expected_val) > tolerance) {
			register_fail(chan, actual_val, ResultType::FailCode::SPIKE);
		}
		actual_val = measurer.get_min(chan);
		if ((expected_val - actual_val) > tolerance) {
			register_fail(chan, actual_val, ResultType::FailCode::DIP);
		}
	}
}

void MeasuringPage::handle_startup_sound() {
	if (audioout.is_playing) {
		if (timer.read_ms() >= 100)
			audioout.stop();
	}
}

void MeasuringPage::start() {
	for (auto &r : results)
		r.passed = true;

	did_pass = false;
	did_fail = false;

	timer.reset();
	timer.start();
	audioout.start_buzzer(200);
	display();
}

void MeasuringPage::cleanup() {
	audioout.stop();
}

void MeasuringPage::display_time(float tm) {
	set_bg_color(LCD_COLOR_YELLOW);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_BIG);

	int minutes = MeasurementTimer::get_minutes(tm);
	float seconds = MeasurementTimer::get_seconds(tm);

	char tm_string[10];
	if (snprintf(tm_string, sizeof tm_string, "%2d:%04.01f", minutes, seconds) >= 0)
		display_string(0, LINE(2), tm_string, LEFT_MODE);
}

