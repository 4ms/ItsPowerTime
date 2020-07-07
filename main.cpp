#include "mbed.h"
#include "ts.h"
#include "display_wrapper.h"
#include "pages.h"
#include "button.h"
#include "adc.h"
#include "measurementTimer.h"
#include "current_setter.h"

void show_debug_xytouch();

enum AppStates {
	INITIALIZING,
	MAIN_SCREEN,
	CONFIG,
	MEASURING,
	SHOW_RESULTS,
};

AppStates app_state;
MeasurementTimer timer;
CurrentSetter currentSetter;

Button MainPage::start_but;
Button MainPage::config_but;
Button MeasuringPage::stop_but;
Button ConfigPage::TestPS_but;
Button ConfigPage::RP25_but;
Button ConfigPage::RP35_but;
Button ConfigPage::RP45_but;

MainPage mainPage;
ConfigPage configPage;
MeasuringPage measureingPage;

static void app_transition_to(AppStates new_state)
{
	switch (new_state) {
	case (INITIALIZING): {
		SplashPage::display();
		wait(2);

		uint32_t display_size_x = get_display_size_x();
		uint32_t display_size_y = get_display_size_y();

		bool success = ts_init(display_size_x, display_size_y);

		if (!success) {
			TSErrorPage::display();
			while(true) {;}
		}
		//Default Power Supply
		currentSetter.set_profile(psProfiles::TestPS);
		break;
	}

	case (MAIN_SCREEN):
		currentSetter.stop();
		MainPage::display();
		break;

	case (CONFIG):
		ConfigPage::display();
		break;

	case (MEASURING): {
		timer.reset();
		timer.start();
		currentSetter.start();
		auto ps = currentSetter.get_profile();
		MeasuringPage::display(ps);
		break;
	}

	case (SHOW_RESULTS):
		break;
	default:
		break;
	}
	app_state = new_state;
}

int main()
{
	app_transition_to(INITIALIZING);

	while (1) {
		switch (app_state) {
		case (INITIALIZING):
			app_transition_to(MAIN_SCREEN);
			break;

		case (MAIN_SCREEN): {
			MainPage::update();
			if (MainPage::start_but.is_just_released()) {
				app_transition_to(MEASURING);
			}
			if (MainPage::config_but.is_just_released()) {
				app_transition_to(CONFIG);
			}
			break;
		}

		case (CONFIG): {
			ConfigPage::update();
			if (ConfigPage::TestPS_but.is_just_released()) {
				currentSetter.set_profile(psProfiles::TestPS);
				app_transition_to(MAIN_SCREEN);
			}
			if (ConfigPage::RP25_but.is_just_released()) {
				currentSetter.set_profile(psProfiles::RowPower25);
				app_transition_to(MAIN_SCREEN);
			}
			if (ConfigPage::RP35_but.is_just_released()) {
				currentSetter.set_profile(psProfiles::RowPower35);
				app_transition_to(MAIN_SCREEN);
			}
			if (ConfigPage::RP45_but.is_just_released()) {
				currentSetter.set_profile(psProfiles::RowPower45);
				app_transition_to(MAIN_SCREEN);
			}
			break;
		}

		case (MEASURING): {
			MeasuringPage::update(timer);
			if (MeasuringPage::stop_but.is_just_released()) {
				app_transition_to(MAIN_SCREEN);
			}
			break;
		}

		case (SHOW_RESULTS):
			break;
		}
	}
}


void show_debug_xytouch() {
	uint16_t x, y;
	static char debugtxt[30];
	bool touched = ts_is_touch_detected(x, y);
	sprintf((char*)debugtxt, "%c x=%d y=%d	", touched ? 'X' : ' ', x, y);
	display_debug_info(debugtxt);
}

