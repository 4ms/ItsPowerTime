#include "display.h"
#include "display_wrapper.h"

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

    config_but.rect.x = 60;
    config_but.rect.y = 270;
    config_but.rect.width = 100;
    config_but.rect.height = 50;
    config_but.rect.radius = 7;
    config_but.text = "Config";
    config_but.fontsize = FONT_SIZE_SMALL;
    config_but.text_color = LCD_COLOR_BLACK;
    config_but.bg_color = LCD_COLOR_ORANGE;
}

void MainPage::display() {
    fill_screen(LCD_COLOR_WHITE);
	start_but.draw();
	config_but.draw();
}

void MainPage::update() {
	start_but.update();
	config_but.update();
}

MeasuringPage::MeasuringPage() {
    stop_but.rect.x = 60;
    stop_but.rect.y = 200;
    stop_but.rect.width = 120;
    stop_but.rect.height = 60;
    stop_but.rect.radius = 15;
    stop_but.text = "STOP";
    stop_but.fontsize = FONT_SIZE_MED;
    stop_but.text_color = LCD_COLOR_WHITE;
    stop_but.bg_color = LCD_COLOR_RED;
}

void MeasuringPage::display(psProfile& ps) {
    fill_screen(LCD_COLOR_YELLOW);
    set_bg_color(LCD_COLOR_YELLOW);
    set_fg_color(LCD_COLOR_BLACK);
    set_font_size(FONT_SIZE_SMALL);
    display_string_centered(0, "Measuring");
    display_string(0, LINE(1), "Time Elapsed:", LEFT_MODE);
	char ma_string[6];
    display_string(0, LINE(17), "Set +12 mA: ", LEFT_MODE);
	if (snprintf(ma_string, sizeof ma_string, "%d", ps.mA_12V) >=0 )
		display_string(1, LINE(17), ma_string, RIGHT_MODE);

    display_string(0, LINE(18), "Set +5 mA: ", LEFT_MODE);
	if (snprintf(ma_string, sizeof ma_string, "%d", ps.mA_5V) >=0 )
		display_string(1, LINE(18), ma_string, RIGHT_MODE);

    display_string(0, LINE(19), "Set -12 mA: ", LEFT_MODE);
	if (snprintf(ma_string, sizeof ma_string, "%d", ps.mA_N12V) >=0 )
		display_string(1, LINE(19), ma_string, RIGHT_MODE);

	stop_but.draw();
}

void MeasuringPage::update(MeasurementTimer& timer) {
	stop_but.update();
	if (timer.read_ms() > timer.last_time_read) {
		timer.last_time_read = timer.read_ms();
		display_time((float)timer.last_time_read/1000.0f);
	}
}

void MeasuringPage::display_time(float tm) {
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

void display_debug_info(const char *debug_text) {
    set_font_size(FONT_SIZE_SMALL);
    set_fg_color(LCD_COLOR_BLACK);
    display_string(0, LINE(12), debug_text, LEFT_MODE);
}
