#include "page_measurement.h"
#include "display_wrapper.h"

MeasuringPage::MeasuringPage(psProfile &psRef)
: ps{psRef}
{
	stop_but.rect.x = 60;
	stop_but.rect.y = 200;
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
	display_string(0, LINE(17), "Set +12 mA: ", LEFT_MODE);
	display_string(0, LINE(18), "Set +5 mA: ", LEFT_MODE);
	display_string(0, LINE(19), "Set -12 mA: ", LEFT_MODE);
	display_ps_profile();

	stop_but.draw();
}

void MeasuringPage::display_ps_profile() {
	char ma_string[6];
	set_bg_color(LCD_COLOR_YELLOW);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_SMALL);
	if (snprintf(ma_string, sizeof ma_string, "%4d", ps.mA_12V) >=0 )
		display_string(1, LINE(17), ma_string, RIGHT_MODE);
	if (snprintf(ma_string, sizeof ma_string, "%4d", ps.mA_5V) >=0 )
		display_string(1, LINE(18), ma_string, RIGHT_MODE);
	if (snprintf(ma_string, sizeof ma_string, "%4d", ps.mA_N12V) >=0 )
		display_string(1, LINE(19), ma_string, RIGHT_MODE);
}

void MeasuringPage::update() {
	stop_but.update();
	if (timer.read_ms() > timer.last_time_read) {
		timer.last_time_read = timer.read_ms();
		display_time((float)timer.last_time_read/1000.0f);
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

