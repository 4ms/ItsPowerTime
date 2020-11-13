#include "page_main.h"
#include "display_wrapper.h"

MainPage::MainPage() {
	start_but.rect.x = 60;
	start_but.rect.y = 60;
	start_but.rect.width = 120;
	start_but.rect.height = 80;
	start_but.rect.radius = 5;
	start_but.text = "START";
	start_but.fontsize = FONT_SIZE_BIG;
	start_but.text_color = LCD_COLOR_WHITE;
	start_but.bg_color = LCD_COLOR_RED;

	config_but.rect.x = 20;
	config_but.rect.y = 270;
	config_but.rect.width = 100;
	config_but.rect.height = 50;
	config_but.rect.radius = 7;
	config_but.text = "Config";
	config_but.fontsize = FONT_SIZE_SMALL;
	config_but.text_color = LCD_COLOR_BLACK;
	config_but.bg_color = LCD_COLOR_ORANGE;

	//manual_but.rect = {160, 270, 60, 50, 7};
	manual_but.rect.x = 160;
	manual_but.rect.y = 270;
	manual_but.rect.width = 60;
	manual_but.rect.height = 50;
	manual_but.rect.radius = 7;
	manual_but.text = "Man.";
	manual_but.fontsize = FONT_SIZE_SMALL;
	manual_but.text_color = LCD_COLOR_BLUE;
	manual_but.bg_color = LCD_COLOR_WHITE;
}

void MainPage::display() {
	fill_screen(LCD_COLOR_WHITE);

	set_font_size(FONT_SIZE_MED);
	set_fg_color(LCD_COLOR_BLACK);
	set_bg_color(LCD_COLOR_WHITE);
	display_string(0, 150 , psname, CENTER_MODE);

	start_but.draw();
	config_but.draw();
	manual_but.draw();
}

void MainPage::display_one_rail(float val, float expected_val, int pos_x, int pos_y) {
	const float kTolerance = 1.0f;
	if (fabsf(val - expected_val) < kTolerance) {
		set_bg_color(LCD_COLOR_GREEN);
		set_fg_color(LCD_COLOR_BLACK);
	} else {
		set_bg_color(LCD_COLOR_RED);
		set_fg_color(LCD_COLOR_WHITE);
	}

	set_font_size(FONT_SIZE_MED);

	char reading_string[8];
	if ( sprintf(reading_string, " %04.1fV", val) >= 0 )
		display_string(pos_x, pos_y, reading_string, LEFT_MODE);

}

void MainPage::display_measurements() {
	display_one_rail(measurer.get_average(AdcChannels::voltage12V), 12.0f, 80, 190);
	display_one_rail(measurer.get_average(AdcChannels::voltage5V), 5.0f, 80, 210);
	display_one_rail(measurer.get_average(AdcChannels::voltageN12V), 12.0f, 80, 230);
	display_string(70, 230, "-", LEFT_MODE);
}

void MainPage::update() {
	start_but.update();
	config_but.update();
	manual_but.update();

	if (timer.read_ms() > timer.last_time_read) {
		timer.last_time_read = timer.read_ms();

		if ((timer.last_time_read % 50) == 0) {
			display_measurements();
			measurer.reset_all_averages();
		} else {
			measurer.update_all_averages();
		}
	}
}


void MainPage::start() {
	timer.reset();
	timer.start();
	display_measurements();
}
