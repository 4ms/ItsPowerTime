#include "page_config.h"
#include "display_wrapper.h"

ConfigPage::ConfigPage() {
	TestPS_but.rect.x = 60;
	TestPS_but.rect.y = 20;
	TestPS_but.rect.width = 120;
	TestPS_but.rect.height = 60;
	TestPS_but.rect.radius = 5;
	TestPS_but.text = "TestPS";
	TestPS_but.fontsize = FONT_SIZE_MED;
	TestPS_but.text_color = LCD_COLOR_WHITE;
	TestPS_but.bg_color = LCD_COLOR_BLUE;

	RP25_but.rect.x = 60;
	RP25_but.rect.y = 100;
	RP25_but.rect.width = 120;
	RP25_but.rect.height = 60;
	RP25_but.rect.radius = 5;
	RP25_but.text = "RP 25";
	RP25_but.fontsize = FONT_SIZE_MED;
	RP25_but.text_color = LCD_COLOR_WHITE;
	RP25_but.bg_color = LCD_COLOR_BLUE;

	RP35_but.rect.x = 60;
	RP35_but.rect.y = 180;
	RP35_but.rect.width = 120;
	RP35_but.rect.height = 60;
	RP35_but.rect.radius = 5;
	RP35_but.text = "RP 35";
	RP35_but.fontsize = FONT_SIZE_MED;
	RP35_but.text_color = LCD_COLOR_WHITE;
	RP35_but.bg_color = LCD_COLOR_BLUE;

	RP45_but.rect.x = 60;
	RP45_but.rect.y = 260;
	RP45_but.rect.width = 120;
	RP45_but.rect.height = 60;
	RP45_but.rect.radius = 5;
	RP45_but.text = "RP 45";
	RP45_but.fontsize = FONT_SIZE_MED;
	RP45_but.text_color = LCD_COLOR_WHITE;
	RP45_but.bg_color = LCD_COLOR_BLUE;
}

void ConfigPage::display() {
	fill_screen(LCD_COLOR_ORANGE);
	set_bg_color(LCD_COLOR_ORANGE);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_BIG);
	display_string_centered(0, "Select PS:");
	ConfigPage::TestPS_but.draw();
	RP25_but.draw();
	RP35_but.draw();
	RP45_but.draw();
}

void ConfigPage::update() {
	TestPS_but.update();
	RP25_but.update();
	RP35_but.update();
	RP45_but.update();
}

