#include <stdint.h>
#include "button.h"
#include "ps_profiles.h"
#include "measurementTimer.h"

class ConfigPage {
public:
	ConfigPage();
    static void display();
	static void update();

	static Button TestPS_but;
	static Button RP25_but;
	static Button RP35_but;
	static Button RP45_but;
};

class MainPage {
public:
	MainPage();
    static void display();
	static void update();

	static Button start_but;
	static Button config_but;
};

class SplashPage {
public:
	SplashPage();
    static void display();
	static void update();

};

class TSErrorPage {
public:
	TSErrorPage();
    static void display();
	static void update();

};

class MeasuringPage {
public:
	MeasuringPage();
    static void display(psProfile& ps);
	static void update(MeasurementTimer& timer);
	static void display_time(float tm);

	static Button stop_but;
};

void display_failed_ts_init();
void display_splash_screen();
void display_main_screen();

void display_debug_info(const char *debug_text);
