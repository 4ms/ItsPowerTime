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
	start_but.draw();
	config_but.draw();
	manual_but.draw();
}

void MainPage::update() {
	start_but.update();
	config_but.update();
	manual_but.update();
}

