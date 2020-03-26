#include "display.h"
#include "display_wrapper.h"

void display_failed_ts_init() {
    fill_screen(LCD_COLOR_RED);
    
    set_bg_color(LCD_COLOR_RED);
    set_fg_color(LCD_COLOR_WHITE);
    set_font_size(FONT_SIZE_MED);
    display_string_centered(5, "TOUCHSCREEN");
    display_string_centered(6, "INIT FAIL");
}

void display_splash_screen() {
    fill_screen(LCD_COLOR_WHITE);
    
    set_bg_color(LCD_COLOR_WHITE);
    set_fg_color(LCD_COLOR_BLACK);
    set_font_size(FONT_SIZE_MED);
    display_string_centered(4, "IT'S");
    display_string_centered(5, "POWER");
    display_string_centered(6, "TIME");
}

void display_debug_info(const char *debug_text) {
    set_font_size(FONT_SIZE_SMALL);
    set_fg_color(LCD_COLOR_BLACK);
    display_string(0, LINE(12), debug_text, LEFT_MODE);
}

void display_main_screen() {
    fill_screen(LCD_COLOR_WHITE);
}

void display_measuring_screen() {
    fill_screen(LCD_COLOR_YELLOW);
    set_bg_color(LCD_COLOR_YELLOW);
    set_fg_color(LCD_COLOR_BLACK);
    set_font_size(FONT_SIZE_BIG);
    display_string_centered(0, "Measuring");
    display_string(0, LINE(1), "Time Elapsed:", LEFT_MODE);
}

void display_time(float tm) {
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
