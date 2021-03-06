#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Rect {
    uint32_t x;
    uint32_t y;
    uint32_t width; 
    uint32_t height;
};

struct RoundedRect {
    uint32_t x;
    uint32_t y;
    uint32_t width;
    uint32_t height;
    uint32_t radius;
};

#endif 
