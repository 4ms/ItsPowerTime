#include "page_manual.h"
#include "display_wrapper.h"

ManualMeasuringPage::ManualMeasuringPage(psProfile &psRef)
: MeasuringPage(psRef)
{
	const uint32_t wid = 25;
	const uint32_t ht = 20;

	const uint32_t top = 250;
	const uint32_t left = 120;
	const uint32_t ysp = 25;
	const uint32_t xsp = 40;

	p12_up.rect = {left + xsp, top, wid, ht, 0};
	p12_up.text = "+";
	p12_up.fontsize = FONT_SIZE_VERY_SMALL;
	p12_up.text_color = LCD_COLOR_BLACK;
	p12_up.bg_color = LCD_COLOR_RED;

	p12_down.rect = {left, top, wid, ht, 0};
	p12_down.text = "-";
	p12_down.fontsize = FONT_SIZE_VERY_SMALL;
	p12_down.text_color = LCD_COLOR_BLACK;
	p12_down.bg_color = LCD_COLOR_GREEN;

	p5_up.rect = {left + xsp, top + ysp, wid, ht, 0};
	p5_up.text = "+";
	p5_up.fontsize = FONT_SIZE_VERY_SMALL;
	p5_up.text_color = LCD_COLOR_BLACK;
	p5_up.bg_color = LCD_COLOR_RED;

	p5_down.rect = {left, top + ysp, wid, ht, 0};
	p5_down.text = "-";
	p5_down.fontsize = FONT_SIZE_VERY_SMALL;
	p5_down.text_color = LCD_COLOR_BLACK;
	p5_down.bg_color = LCD_COLOR_GREEN;

	n12_up.rect = {left + xsp, top + ysp*2, wid, ht, 0};
	n12_up.text = "+";
	n12_up.fontsize = FONT_SIZE_VERY_SMALL;
	n12_up.text_color = LCD_COLOR_BLACK;
	n12_up.bg_color = LCD_COLOR_RED;

	n12_down.rect = {left, top + ysp*2, wid, ht, 0};
	n12_down.text = "-";
	n12_down.fontsize = FONT_SIZE_VERY_SMALL;
	n12_down.text_color = LCD_COLOR_BLACK;
	n12_down.bg_color = LCD_COLOR_GREEN;
}

void ManualMeasuringPage::display() {
	MeasuringPage::display();
	p12_up.draw();
	p12_down.draw();
	p5_up.draw();
	p5_down.draw();
	n12_up.draw();
	n12_down.draw();
}

uint16_t ManualMeasuringPage::inc_mA(uint16_t mA) {
	mA += 100;
	if (mA > 3000)
		mA = 3000;
	return mA;
}

uint16_t ManualMeasuringPage::dec_mA(uint16_t mA) {
	if (mA <= 100)
		mA = 0;
	else
		mA -= 100;
	return mA;
}

void ManualMeasuringPage::update() {
	MeasuringPage::update();
	p12_up.update();
	p12_down.update();
	p5_up.update();
	p5_down.update();
	n12_up.update();
	n12_down.update();

	if (p12_up.is_just_released()) {
		ps.mA_12V = inc_mA(ps.mA_12V);
		display_ps_profile();
	}
	if (p12_down.is_just_released()) {
		ps.mA_12V = dec_mA(ps.mA_12V);
		display_ps_profile();
	}
	if (p5_up.is_just_released()) {
		ps.mA_5V = inc_mA(ps.mA_5V);
		display_ps_profile();
	}
	if (p5_down.is_just_released()) {
		ps.mA_5V = dec_mA(ps.mA_5V);
		display_ps_profile();
	}
	if (n12_up.is_just_released()) {
		ps.mA_N12V = inc_mA(ps.mA_N12V);
		display_ps_profile();
	}
	if (n12_down.is_just_released()) {
		ps.mA_N12V = dec_mA(ps.mA_N12V);
		display_ps_profile();
	}
}

