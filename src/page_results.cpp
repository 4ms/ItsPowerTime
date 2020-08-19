#include "page_results.h"
#include "display_wrapper.h"
#include "channel_defs.h"

ResultsPage::ResultsPage() {
	continue_but.rect.x = 60;
	continue_but.rect.y = 200;
	continue_but.rect.width = 120;
	continue_but.rect.height = 80;
	continue_but.rect.radius = 5;
	continue_but.text = "Continue";
	continue_but.fontsize = FONT_SIZE_MED;
	continue_but.text_color = LCD_COLOR_BLACK;
	continue_but.bg_color = LCD_COLOR_YELLOW;
}

FailResultsPage::FailResultsPage() {
	flash_color_1 = LCD_COLOR_RED;
	flash_color_2 = LCD_COLOR_WHITE;
	bg_color = flash_color_1;
	fg_color = flash_color_2;
	strcpy(result_string, "FAIL");
}

PassResultsPage::PassResultsPage() {
	flash_color_1 = LCD_COLOR_GREEN;
	flash_color_2 = LCD_COLOR_WHITE;
	bg_color = flash_color_1;
	fg_color = flash_color_2;
	strcpy(result_string, "PASS");
}

void ResultsPage::set_results(ResultType *results) {
	test_results = results;
}

void ResultsPage::display() {
	fill_screen(bg_color);
	set_bg_color(bg_color);
	set_fg_color(fg_color);
	set_font_size(FONT_SIZE_BIG);
	display_string_centered(1, result_string);
	continue_but.draw();
}

void FailResultsPage::display() {
	ResultsPage::display();
	set_bg_color(bg_color);
	set_fg_color(fg_color);
	set_font_size(FONT_SIZE_SMALL);

	set_fg_color(LCD_COLOR_BLACK);
	display_string(0, 60, "12V: ", LEFT_MODE);
	if (test_results[AdcChannels::voltage12V].passed) {
		set_fg_color(LCD_COLOR_GREEN);
		display_string(50, 60, "pass", LEFT_MODE);
	} else {
		set_fg_color(fg_color);
		display_string(50, 60, "FAIL", LEFT_MODE);
		set_fg_color(LCD_COLOR_BLACK);
		display_number(130, 60, (test_results[AdcChannels::voltage12V].fail_time/1000), "@%ds", LEFT_MODE);
		//test_results.result_string(res);
	}
	

		// , voltage5V, voltageN12V,
	// current12V, current5V, currentN12V,
}

void PassResultsPage::display() {
	ResultsPage::display();
}

void ResultsPage::start() {
	timer.reset();
	timer.start();
	display();
}

void FailResultsPage::start() {
	ResultsPage::start();
	audio.start_buzzer(1000);
}

void PassResultsPage::start() {
	ResultsPage::start();
	audio.start_buzzer(200);
}

void ResultsPage::cleanup() {
	audio.stop();
}

void ResultsPage::update() {
	continue_but.update();
}

void FailResultsPage::update() {
	if ((timer.read_ms() - timer.last_time_read) > 500) {
		bool invert_screen = (bg_color == LCD_COLOR_RED);
		bg_color = invert_screen ? LCD_COLOR_WHITE : LCD_COLOR_RED;
		fg_color = invert_screen ? LCD_COLOR_RED : LCD_COLOR_WHITE;
		uint16_t freq = invert_screen ? 800 : 1000;
		audio.start_buzzer(freq);
		display();

		timer.last_time_read = timer.read_ms();
	}
	ResultsPage::update();
}

void PassResultsPage::update() {
	if ((timer.read_ms() - timer.last_time_read) > 500) {
		bool invert_screen = (bg_color == LCD_COLOR_GREEN);
		bg_color = invert_screen ? LCD_COLOR_WHITE : LCD_COLOR_GREEN;
		fg_color = invert_screen ? LCD_COLOR_GREEN : LCD_COLOR_WHITE;
		display();

		timer.last_time_read = timer.read_ms();
	}
	ResultsPage::update();
}

