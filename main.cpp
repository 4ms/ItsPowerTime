#include "mbed.h"
#include "ts.h"
#include "display_wrapper.h"
#include "display.h"
#include "button.h"
#include "adc.h"

//Todo: make UIElements.cpp/h
//rename disaply.cpp/h to backgrounds.c/h
//UIElements contains the buttons and backgrounds
//if (ui.stop_but.is_just_pressed())

void show_debug_xytouch();

enum AppStates {
    INITIALIZING,
    MAIN_SCREEN,
    CONFIG,
    MEASURING,
    SHOW_RESULTS,
};

AppStates app_state;
Button start_but;
Button config_but;
Button stop_but;
Button continue_but;
Button restart_but;
Timer timer;


static void app_transition_to(AppStates new_state)
{
    switch (new_state) {
    case (INITIALIZING): {
        display_splash_screen();
        wait(2);
        
        uint32_t display_size_x = get_display_size_x();
        uint32_t display_size_y = get_display_size_y();
        
        bool success = ts_init(display_size_x, display_size_y);
        
        if (!success) {
            display_failed_ts_init();   
            while(true) {;}
        }
    
        create_start_button(start_but);
        create_config_button(config_but);
        create_stop_button(stop_but);
        break;
    }
        
    case (MAIN_SCREEN):
        display_main_screen(); 
        start_but.draw();
        config_but.draw();
        break;
    
    case (CONFIG):
        break;
        
    case (MEASURING):
        timer.reset();
        timer.start();
        display_measuring_screen();
        stop_but.draw();
        break;
    
    case (SHOW_RESULTS):
        break;
    default:
        break;
    }
    app_state = new_state;
}

int main()
{
    int last_time_read = 0;

    app_transition_to(INITIALIZING);
    
    while (1) {
        switch (app_state) {
        case (INITIALIZING):
            app_transition_to(MAIN_SCREEN);
            break;
            
        case (MAIN_SCREEN):
            start_but.update();
            config_but.update();      
            if (start_but.is_just_released()) {
                app_transition_to(MEASURING);
            }
            break;
        
        case (CONFIG):
            break;
            
        case (MEASURING): {
            stop_but.update();
            if (timer.read_ms() > last_time_read) {
                last_time_read = timer.read_ms();
                display_time(last_time_read/1000);
            }
            if (stop_but.is_just_released()) {
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
    sprintf((char*)debugtxt, "%c x=%d y=%d    ", touched ? 'X' : ' ', x, y);
    display_debug_info(debugtxt);   
}
