#include <cmath>

#include "screen.h"
#include "line_drawing.h"

void draw_line_alg_low(const float x1, const float y1, const float x2, const float y2) {
    const float dx = x2 - x1;
    const float dy = y2 - y1;
    const float m = dy / dx;  // m = slope

    // drawing:
    for(int x = std::round(x1); x <= std::round(x2); x++) {
        const int y = static_cast<int>(m * (x-x1) + y1);
        screen.at(y).at(x) = 'y';
    }
}
void draw_line_alg_steep(const float x1, const float y1, const float x2, const float y2) {
    const float dx = x2 - x1;
    const float dy = y2 - y1;
    const float m = dy / dx;  // m = slope

    // drawing:
    for(int y = std::round(y1); y <= std::round(y2); y++) {
        const int x = static_cast<int>((y-y1) / m + x1);
        screen.at(y).at(x) = 'x';
    }
}

void draw_line(float x1, float y1, float x2, float y2) {
    if(std::abs(x2-x1) > std::abs(y2-y1)) {
        // switch points if the x values aren't in order
        if(x1 > x2) {
            float temp = x1;
            x1 = x2;
            x2 = temp;

            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        draw_line_alg_low(x1, y1, x2, y2);
    } else {
        if(y1 > y2) {
            float temp = x1;
            x1 = x2;
            x2 = temp;

            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        draw_line_alg_steep(x1, y1, x2, y2);
    }
}