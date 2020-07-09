#include "display_wrapper.h"

static LCD_DISCO_F429ZI lcd;

void set_bg_color(uint32_t color) {
	lcd.SetBackColor(color);
}
void set_fg_color(uint32_t color) {
	lcd.SetTextColor(color);
}

void set_font_size(FontSizes size) {
	if (size==FONT_SIZE_SMALL)
		BSP_LCD_SetFont(&Font16);
	else if (size==FONT_SIZE_MED)
		BSP_LCD_SetFont(&Font20);
	else if (size==FONT_SIZE_BIG)
		BSP_LCD_SetFont(&Font24);
	else if (size==FONT_SIZE_VERY_SMALL)
		BSP_LCD_SetFont(&Font12);
}

uint16_t get_font_line_height(FontSizes size) {
	if (size==FONT_SIZE_SMALL)
		return Font16.Height;
	else if (size==FONT_SIZE_MED)
		return Font20.Height;
	else if (size==FONT_SIZE_BIG)
		return Font24.Height;
	else if (size==FONT_SIZE_VERY_SMALL)
		return Font12.Height;
	else
		return Font16.Height; //default
}

void fill_screen(uint32_t color) {
	lcd.Clear(color);
}

void fill_rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
	lcd.FillRect(x, y, width, height);
}

void fill_rounded_rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t radius) {
	if (radius == 0)
		fill_rect(x, y, width, height);
	else {
		lcd.FillRect(x + radius, y, width - 2 * radius, height);
		lcd.FillRect(x, y + radius, width, height - 2 * radius);
		lcd.FillCircle(x + radius, y + radius, radius);
		lcd.FillCircle(x + width - radius - 1, y + radius, radius);
		lcd.FillCircle(x + radius, y + height - radius - 1, radius);
		lcd.FillCircle(x + width - radius - 1, y + height - radius -1, radius);
	}
}

void display_string(uint16_t X, uint16_t Y, const char *pText, Text_AlignModeTypdef mode) {
	lcd.DisplayStringAt(X, Y, const_cast<uint8_t *>(reinterpret_cast<const uint8_t *>(pText)), mode);
}

void display_string_centered(uint16_t line, const char *pText) {
	lcd.DisplayStringAt(0, LINE(line), const_cast<uint8_t *>(reinterpret_cast<const uint8_t *>(pText)), CENTER_MODE);
}

uint32_t get_display_size_x() {
	return lcd.GetXSize();
}

uint32_t get_display_size_y() {
	return lcd.GetYSize();
}
