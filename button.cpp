#include "button.h"

void create_start_button(Button &start_but) {
    start_but.rect.x = 60;
    start_but.rect.y = 60;
    start_but.rect.width = 120;
    start_but.rect.height = 80;
    
    start_but.text = "START";
    start_but.fontsize = FONT_SIZE_BIG;
    start_but.text_color = LCD_COLOR_WHITE;
    start_but.bg_color = LCD_COLOR_BLUE;
}

void create_config_button(Button &config_but) {
    config_but.rect.x = 140;
    config_but.rect.y = 270;
    config_but.rect.width = 100;
    config_but.rect.height = 50;
    
    config_but.text = "Config";
    config_but.fontsize = FONT_SIZE_SMALL;
    config_but.text_color = LCD_COLOR_GREEN;
    config_but.bg_color = LCD_COLOR_YELLOW;
}

void create_stop_button(Button &but) {
    but.rect.x = 60;
    but.rect.y = 200;
    but.rect.width = 120;
    but.rect.height = 60;
    
    but.text = "STOP";
    but.fontsize = FONT_SIZE_MED;
    but.text_color = LCD_COLOR_WHITE;
    but.bg_color = LCD_COLOR_RED;
}

void Button::_draw(uint32_t bg, uint32_t textcolor) {
    set_fg_color(bg);
    fill_rect(rect.x, rect.y, rect.width, rect.height);
    
    set_bg_color(bg);
    set_fg_color(textcolor);
    set_font_size(fontsize);
    
    uint16_t center_x = rect.x + (rect.width/2);
    const uint16_t screen_center = 120;
    
    uint16_t center_y = rect.y + (rect.height/2);
    uint16_t line_height = get_font_line_height(fontsize);
    
    display_string(screen_center + center_x, center_y - (line_height/2), text.c_str(), CENTER_MODE);
}

void Button::draw() {
    _draw(bg_color, text_color);
}

void Button::draw_depressed() {
    uint32_t dep_bg = ((~bg_color)>>4) & 0xFFFFFF00;
    uint32_t dep_fg = (text_color<<8) & 0xFFFFFF00;
    
    _draw(dep_bg, dep_fg);
}

void Button::update() {
    TouchShapeStates tss = ts_touch_within_rect(rect);
    
    if (tss == TOUCHED_INSIDE) {
        if (_pressed == false) {
            _just_pressed = true;
            draw_depressed();
            _drawn_normal = false;
        }
        _pressed = true;   
    }
    else if (tss == TOUCHED_OUTSIDE) {
        _pressed = false;
        if (!_drawn_normal) {
            draw();
            _drawn_normal = true;
        }
    }
    else {
        if (_pressed == true) {
            _just_released = true;
            draw();
            _drawn_normal = true;
        }
        _pressed = false;
    }        
}

bool Button::is_pressed() {
    return _pressed;
}

bool Button::is_just_pressed() {
    if (_just_pressed) {
        _just_pressed = false;
        return true;
    }
    else 
        return false;
}

bool Button::is_just_released() {
    if (_just_released) {
        _just_released = false;
        return true;
    }
    else 
        return false;
}
