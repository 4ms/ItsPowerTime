#include "page_measurement.h"
#include "display_wrapper.h"

MeasuringPage::MeasuringPage(psProfile &psRef)
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
}

void MeasuringPage::display() {
	fill_screen(LCD_COLOR_YELLOW);
	set_bg_color(LCD_COLOR_YELLOW);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_SMALL);
	display_string_centered(0, "Measuring");
	display_string(0, LINE(1), "Time Elapsed:", LEFT_MODE);
	display_string(0, 254, "Set +12 mA: ", LEFT_MODE);
	display_string(0, 279, "Set +5 mA: ", LEFT_MODE);
	display_string(0, 304 , "Set -12 mA: ", LEFT_MODE);
	display_ps_profile();

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

	// uint8_t t[] = {
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// 	250, 200, 150, 100, 50, 10, 60, 110, 210, 250,
	// };
	// audioout.play_wav(t, 100, 10000);
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
	char reading_string[6];
	set_bg_color(LCD_COLOR_YELLOW);
	set_fg_color(LCD_COLOR_BLUE);
	set_font_size(FONT_SIZE_SMALL);

	if ( sprintf(reading_string, "%2.2f", measurer.read_12V_mV()) >= 0 )
		display_string(55, LINE(5), reading_string, LEFT_MODE);
	if ( sprintf(reading_string, "%2.2f", measurer.read_5V_mV()) >= 0 )
		display_string(65, LINE(6), reading_string, LEFT_MODE);
	if ( sprintf(reading_string, "%2.2f", measurer.read_N12V_mV()) >= 0 )
		display_string(55, LINE(7), reading_string, LEFT_MODE);

	if ( sprintf(reading_string, "%4d", measurer.read_12V_mA()) >= 0 )
		display_string(215, LINE(5), reading_string, RIGHT_MODE);
	if ( sprintf(reading_string, "%4d", measurer.read_5V_mA()) >= 0 )
		display_string(215, LINE(6), reading_string, RIGHT_MODE);
	if ( sprintf(reading_string, "%4d", measurer.read_N12V_mA()) >= 0 )
		display_string(215, LINE(7), reading_string, RIGHT_MODE);
}


void MeasuringPage::update() {
	stop_but.update();
	if (timer.read_ms() > timer.last_time_read) {
		timer.last_time_read = timer.read_ms();
		display_time((float)timer.last_time_read/1000.0f);
		if ((timer.last_time_read % 100) == 0)
			display_measurements();
	}

	play_startup_sound();
}

void MeasuringPage::play_startup_sound() {
	if (!audioout.is_playing) {
		if (timer.read_ms() < 1000)
			audioout.start_buzzer(100);
	} else {
		if (timer.read_ms() >= 1000)
			audioout.stop();
	}
}

void MeasuringPage::display_time(float tm) {
	set_bg_color(LCD_COLOR_YELLOW);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_BIG);
	char tm_string[20];
	int minutes;
	float seconds;
	minutes = tm / 60;
	seconds = tm - (minutes*60);
	int ret = snprintf(tm_string, sizeof tm_string, "%d:%04.01f", minutes, seconds);
	if (ret>=0)
		display_string(0, LINE(2), tm_string, LEFT_MODE);
}

