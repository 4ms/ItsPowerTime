//is_just_pressed() false after ctor
//is_just_released() false after ctor
//is_pressed() false after ctor
//touching inside -> is_just_pressed = true, is_pressed=true
//touching inside -> is_just_pressed read twice = false, is_pressed read twice =true
//touching outside -> is_* = false
//touching inside, then touching outside -> is_* = false
//touching inside, then no touching -> is_just_released = true, is_just_pressed = true? false?, is_pressed = false
//
//Need: mock/fake for ts_touch_within_rect()
//-->returns TOUCHED_INSIDE, TOUCHED_OUTSIDE, NO_TOUCH depending on what we're testing
//
//Need: stubs for draw commands:
//set_fg_color()
//fill_rounded_rect()
//set_bg_color()
//set_font_size()
//get_font_line_height()
//display_string()
//
