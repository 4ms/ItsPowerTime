#include <string>
#include "display_wrapper.h"
#include "ts.h"

class Button {

public:
    Rect rect;
    std::string text;
    uint32_t text_color;
    uint32_t bg_color;
    FontSizes fontsize;
        
    void draw();
    void draw_depressed();
    bool is_pressed();
    bool is_just_pressed();
    bool is_just_released();
    void update();
    
private:
    bool _pressed;
    bool _just_pressed;
    bool _just_released;
    void _draw(uint32_t bg, uint32_t textcolor);
    bool _drawn_normal;
};

void create_start_button(Button &start);
void create_config_button(Button &config);
void create_stop_button(Button &but);
