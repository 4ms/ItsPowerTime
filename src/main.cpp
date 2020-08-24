#include "mbed.h"
#include "ts.h"
#include "display_wrapper.h"
#include "pages.h"
#include "button.h"
#include "current_setter.h"
#include "ps_profiles.h"
#include "test_results.h"

using namespace PSProfiles;

void show_debug_xytouch();

class ItsPowerTimeApp {
public:
	enum AppStates {
		INITIALIZING,
		MAIN_SCREEN,
		CONFIG,
		MEASURING,
		MANUAL_MEASURING,
		SHOW_FAIL_RESULTS,
		SHOW_PASS_RESULTS,
	};
	AppStates app_state;

	PSProfile active_ps;
	PSProfileID active_ps_id;

	struct CurrentSetter {
		CurrentSetter(PSProfile &ps) : active_ps{ps} {}
		CurrentSetCtl<CurrentSetPins::pin[Set12V], CurrentSetPins::pin[Set5V], CurrentSetPins::pin[SetN12V]> currentSetDriver;
		void start() {	
			currentSetDriver.set_val(Set5V, active_ps.mA_5V);
			currentSetDriver.set_val(Set12V, active_ps.mA_12V);
			currentSetDriver.set_val(SetN12V, active_ps.mA_N12V);
		}
		void stop() { currentSetDriver.stop(); }
		void update() { start(); }
	private:
		PSProfile &active_ps;
	} currentSetter{active_ps};

	MainPage mainPage;
	ConfigPage configPage;
	MeasuringPage measuringPage {active_ps};
	ManualMeasuringPage manualPage {active_ps};
	TSErrorPage tsErrorPage;
	SplashPage splashPage;
	PassResultsPage passResultPage;
	FailResultsPage failResultPage;

	ItsPowerTimeApp() {
		currentSetter.stop();
		//Default Power Supply
		active_ps = psProfileArray[PSProfileID::Manual];
		transition_to(INITIALIZING);
	}

	void transition_to(AppStates new_state) {
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
				mainPage.psname = active_ps.name;
				currentSetter.stop();
				mainPage.display();
				break;

			case (CONFIG):
				configPage.display();
				break;

			case (MEASURING): {
				if (active_ps == psProfileArray[PSProfileID::Manual]) {
					new_state = MANUAL_MEASURING;
					transition_to(new_state);
				} else {
					active_ps = psProfileArray[active_ps_id]; //reload
					currentSetter.start();
					measuringPage.start();
				}
				break;
			}

			case (MANUAL_MEASURING): {
				currentSetter.start();
				manualPage.start();
				break;
			}

			case (SHOW_PASS_RESULTS):
				currentSetter.stop();
				passResultPage.start();
				break;

			case (SHOW_FAIL_RESULTS):
				currentSetter.stop();
				failResultPage.start();
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
						active_ps_id = but.ps_index;
						transition_to(MAIN_SCREEN);
					}
				}
				break;
			}

			case (MEASURING): {
				measuringPage.update();
				if (measuringPage.stop_but.is_just_released()) {
					measuringPage.cleanup();
					transition_to(MAIN_SCREEN);
				}
				if (measuringPage.failed()) {
					measuringPage.cleanup();
					failResultPage.set_results(measuringPage.results);
					//Or does it make more sense to say: failResultsPage.results = measuringPage.get_results();
					transition_to(SHOW_FAIL_RESULTS);
				}
				if (measuringPage.passed()) {
					measuringPage.cleanup();
					passResultPage.set_results(measuringPage.results);
					transition_to(SHOW_PASS_RESULTS);
				}
				break;
			}

			case (MANUAL_MEASURING): {
				manualPage.update();
				currentSetter.update();
				if (manualPage.stop_but.is_just_released()) {
					manualPage.cleanup();
					transition_to(MAIN_SCREEN);
				}
				break;
			}

			case (SHOW_PASS_RESULTS): {
				passResultPage.update();
				if (passResultPage.continue_but.is_just_released()) {
					passResultPage.cleanup();
					transition_to(MAIN_SCREEN);
				}
				break;
			}

			case (SHOW_FAIL_RESULTS): {
				failResultPage.update();
				if (failResultPage.continue_but.is_just_released()) {
					failResultPage.cleanup();
					transition_to(MAIN_SCREEN);
				}
				break;
			}
		}
	}

private:
};

int main() {
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

