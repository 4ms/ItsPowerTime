#pragma once

#include "LCD_DISCO_F429ZI.h"

enum FontSizes {
	FONT_SIZE_VERY_SMALL,
    FONT_SIZE_SMALL,
    FONT_SIZE_MED,
    FONT_SIZE_BIG,
};

void set_bg_color(uint32_t color);
void set_fg_color(uint32_t color);
void set_font_size(FontSizes size);
void fill_screen(uint32_t color);
void fill_rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
void fill_rounded_rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t radius);
void display_string(uint16_t X, uint16_t Y, const char *pText, Text_AlignModeTypdef mode);
void display_string_centered(uint16_t line, const char *pText);
void display_int(uint16_t X, uint16_t Y, int number, const char *format, Text_AlignModeTypdef mode);
void display_float(uint16_t X, uint16_t Y, float number, const char *format, Text_AlignModeTypdef mode);
uint32_t get_display_size_x();
uint32_t get_display_size_y();
uint16_t get_font_line_height(FontSizes size);
