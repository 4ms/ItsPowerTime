#include "page_splash.h"
#include "display_wrapper.h"

// Splash Page
void SplashPage::display() {
	fill_screen(LCD_COLOR_WHITE);

	set_bg_color(LCD_COLOR_WHITE);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_MED);
	display_string_centered(4, "IT'S");
	display_string_centered(5, "POWER");
	display_string_centered(6, "TIME");
}
SplashPage::SplashPage() {}
void SplashPage::update() {}

// Todo: combine these pages into one, and only show error if it occurs
// TouchScreen Error Page
void TSErrorPage::display() {
	fill_screen(LCD_COLOR_RED);

	set_bg_color(LCD_COLOR_RED);
	set_fg_color(LCD_COLOR_WHITE);
	set_font_size(FONT_SIZE_MED);
	display_string_centered(5, "TOUCHSCREEN");
	display_string_centered(6, "INIT FAIL");
}
TSErrorPage::TSErrorPage() {}
void TSErrorPage::update() {}

