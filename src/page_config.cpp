#include "page_config.h"
#include "display_wrapper.h"

ConfigPage::ConfigPage() {
	const uint16_t rows = 5;
	const uint16_t cols = 2;
	const uint16_t x_spacing = 10;
	const uint16_t y_spacing = 20;
	const uint16_t top_margin = 20;
	uint16_t width = (get_display_size_x() - (x_spacing * (cols - 1))) / cols;
	uint16_t height = (get_display_size_y() - (y_spacing * (rows - 1)) - top_margin) / rows;
	uint16_t cur_row = 0;
	uint16_t cur_col = 0;
	
	for (auto &ps : psProfileArray.data) {
		auto &but = ps_buts[ps.key];
		but.ps_index = ps.key;
		but.rect.x = cur_col * (width + x_spacing);
		but.rect.y = cur_row * (height + y_spacing) + top_margin;
		but.rect.width = width;
		but.rect.height = height;
		but.rect.radius = 3;
		but.text = psProfileArray[ps.key].name;
		if (but.text.length() > 9)
			but.fontsize = FONT_SIZE_VERY_SMALL;
		else
			but.fontsize = FONT_SIZE_SMALL;
		but.text_color = LCD_COLOR_WHITE;
		but.bg_color = LCD_COLOR_BLUE;

		if (++cur_row >= rows) {
			cur_row = 0;
			if (++cur_col >= cols)
				break;
		}
	}

}

void ConfigPage::display() {
	fill_screen(LCD_COLOR_ORANGE);
	set_bg_color(LCD_COLOR_ORANGE);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_MED);
	display_string_centered(0, "Select PS:");
	for (auto &but : ps_buts) {
		but.draw();
	}
}

void ConfigPage::update() {
	for (auto &but : ps_buts) {
		but.update();
	}
}

