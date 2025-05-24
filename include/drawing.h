// line drawing module
#pragma once

#include "screen.h"

// line drawing utility
void draw_line(Screen& scr, int x1, int y1, int x2, int y2, const char character);

struct Edge {
    int y_min;
    int y_max;
    int x_at_y_min;
    float dx_dy;    // inverse slope
};