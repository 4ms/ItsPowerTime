#include "mbed.h"
#include "ts.h"
#include "display_wrapper.h"
#include "pages.h"
#include "button.h"
#include "current_setter.h"
#include "ps_profiles.h"

void show_debug_xytouch();

class ItsPowerTimeApp {
public:
	enum AppStates {
		INITIALIZING,
		MAIN_SCREEN,
		CONFIG,
		MEASURING,
		MANUAL_MEASURING,
		SHOW_RESULTS,
	};
	AppStates app_state;

	psProfile active_ps;
	CurrentSetter currentSetter {active_ps};

	MainPage mainPage;
	ConfigPage configPage;
	MeasuringPage measuringPage {active_ps};
	ManualMeasuringPage manualPage {active_ps};
	TSErrorPage tsErrorPage;
	SplashPage splashPage;

	ItsPowerTimeApp() {
		currentSetter.stop();
		//Default Power Supply
		active_ps = psProfileArray[0];
		transition_to(INITIALIZING);
	}

	void transition_to(AppStates new_state)
	{
		switch (new_state) {
		case (INITIALIZING): {

			uint32_t display_size_x = get_display_size_x();
			uint32_t display_size_y = get_display_size_y();

			bool success = ts_init(display_size_x, display_size_y);

			if (!success) {
				tsErrorPage.display();
				wait_ms(200);
				//while(true) {;}
			}

			splashPage.display();
			wait_ms(200);
			break;
		}

		case (MAIN_SCREEN):
			currentSetter.stop();
			mainPage.display();
			break;

		case (CONFIG):
			configPage.display();
			break;

		case (MEASURING): {
			measuringPage.timer.reset();
			measuringPage.timer.start();
			currentSetter.start();
			measuringPage.display();
			break;
		}

		case (MANUAL_MEASURING): {
			active_ps = psProfiles::ManualMode;
			manualPage.timer.reset();
			manualPage.timer.start();
			currentSetter.start();
			manualPage.display();
			break;
		}

		case (SHOW_RESULTS):
			break;
		default:
			break;
		}
		app_state = new_state;
	}

	void loop() {
		switch (app_state) {
		case (INITIALIZING):
			transition_to(MAIN_SCREEN);
			break;

		case (MAIN_SCREEN): {
			mainPage.update();
			if (mainPage.start_but.is_just_released()) {
				transition_to(MEASURING);
			}
			if (mainPage.config_but.is_just_released()) {
				transition_to(CONFIG);
			}
			if (mainPage.manual_but.is_just_released()) {
				transition_to(MANUAL_MEASURING);
			}
			break;
		}

		case (CONFIG): {
			configPage.update();
			for (auto &but : configPage.ps_buts) {
				if (but.is_just_released()) {
					active_ps = psProfileArray[but.ps_index];
					transition_to(MAIN_SCREEN);
				}
			}
			break;
		}

		case (MEASURING): {
			measuringPage.update();
			if (measuringPage.stop_but.is_just_released()) {
				transition_to(MAIN_SCREEN);
			}
			break;
		}

		case (MANUAL_MEASURING): {
			manualPage.update();
			currentSetter.start();
			if (manualPage.stop_but.is_just_released()) {
				transition_to(MAIN_SCREEN);
			}
			break;
		}

		case (SHOW_RESULTS):
			break;
		}
	}
};

int main()
{
	ItsPowerTimeApp app;

	while (1) {
		app.loop();
	}
}


void display_debug_info(const char *debug_text) {
	set_font_size(FONT_SIZE_SMALL);
	set_fg_color(LCD_COLOR_BLACK);
	display_string(0, LINE(12), debug_text, LEFT_MODE);
}

void show_debug_xytouch() {
	uint16_t x, y;
	static char debugtxt[30];
	bool touched = ts_is_touch_detected(x, y);
	sprintf((char*)debugtxt, "%c x=%d y=%d	", touched ? 'X' : ' ', x, y);
	display_debug_info(debugtxt);
}

