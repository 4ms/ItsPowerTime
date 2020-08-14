#include "page_config.h"
#include "display_wrapper.h"

ConfigPage::ConfigPage() {
	const uint16_t rows = 3;
	const uint16_t cols = 3;
	const uint16_t x_spacing = 10;
	const uint16_t y_spacing = 10;
	const uint16_t top_margin = 12;
	uint16_t width = (get_display_size_x() - (x_spacing * (cols - 1))) / rows;
	uint16_t height = (get_display_size_y() - (y_spacing * (rows - 1))) / cols;
	uint16_t cur_row = 0;
	uint16_t cur_col = 0;
	uint8_t ps_i = 0;

	for (auto &but : ps_buts) {
		but.ps_index = ps_i;
		but.rect.x = cur_row * (width + x_spacing);
		but.rect.y = cur_col * (height + y_spacing) + top_margin;
		but.rect.width = width;
		but.rect.height = height;
		but.rect.radius = 3;
		but.text = psProfileArray[ps_i].name;
		but.fontsize = FONT_SIZE_MED;
		but.text_color = LCD_COLOR_WHITE;
		but.bg_color = LCD_COLOR_BLUE;

		if (++cur_row >= rows) {
			cur_row = 0;
			if (++cur_col >= cols)
				break;
		}

		ps_i++;
	}

}

void ConfigPage::display() {
	fill_screen(LCD_COLOR_ORANGE);
	set_bg_color(LCD_COLOR_ORANGE);
	set_fg_color(LCD_COLOR_BLACK);
	set_font_size(FONT_SIZE_BIG);
	display_string_centered(0, "Select PS:");
	for (auto &but : ps_buts)
		but.draw();
}

void ConfigPage::update() {
	for (auto &but : ps_buts) {
		but.update();
	}
}

