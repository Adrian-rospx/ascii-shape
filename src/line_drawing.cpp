#include <cmath>

#include "screen.h"
#include "line_drawing.h"

void draw_line_alg_low(Screen& scr, const int x1, const int y1, const int x2, const int y2) {
    const int dx = x2 - x1;
    const int dy = y2 - y1;
    const float m = static_cast<float>(dy) / dx;    // m = slope

    // drawing:
    for(int x = x1; x <= x2; x++) {
        const int y = static_cast<int>(static_cast<float>(x-x1) * m + y1);
        scr.buffer.at(y).at(x).r = 255;
    }
}
void draw_line_alg_steep(Screen& scr, const int x1, const int y1, const int x2, const int y2) {
    const int dx = x2 - x1;
    const int dy = y2 - y1;
    const float m = static_cast<float>(dy) / dx;

    for(int y = y1; y <= y2; y++) {
        const int x = static_cast<int>(static_cast<float>(y-y1) / m + x1);
        scr.buffer.at(y).at(x).r = 255;
    }
}

void draw_line(Screen& scr, int x1, int y1, int x2, int y2) {

    if(std::abs(x2-x1) > std::abs(y2-y1)) {
        // switch points if the x values aren't in order
        if(x1 > x2) {
            int temp = x1;
            x1 = x2;
            x2 = temp;

            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        draw_line_alg_low(scr, x1, y1, x2, y2);
    } else {
        if(y1 > y2) {
            int temp = x1;
            x1 = x2;
            x2 = temp;

            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        draw_line_alg_steep(scr, x1, y1, x2, y2);
    }
}