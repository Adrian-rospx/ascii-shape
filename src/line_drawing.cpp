#include <cmath>

#include "screen.h"
#include "line_drawing.h"

void draw_line_alg_low(const int x1, const int y1, const int x2, const int y2) {
    const int dx = x2 - x1;
    const int dy = y2 - y1;
    const float m = static_cast<float>(dy) / dx;    // m = slope

    // drawing:
    for(int x = x1; x <= x2; x++) {
        const int y = static_cast<int>(static_cast<float>(x-x1) * m + y1);
        screen.at(y).at(x) = 'y';
    }
}
void draw_line_alg_steep(const int x1, const int y1, const int x2, const int y2) {
    const int dx = x2 - x1;
    const int dy = y2 - y1;
    const float m = static_cast<float>(dy) / dx;

    for(int y = y1; y <= y2; y++) {
        const int x = static_cast<int>(static_cast<float>(y-y1) / m + x1);
        screen.at(y).at(x) = 'x';
    }
}

void draw_line(const float x1_f, const float y1_f, const float x2_f, const float y2_f) {
    // cast parameters to intagers
    int x1 = std::round(x1_f);
    int y1 = std::round(y1_f);
    int x2 = std::round(x2_f);
    int y2 = std::round(y2_f);

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
        draw_line_alg_low(x1, y1, x2, y2);
    } else {
        if(y1 > y2) {
            int temp = x1;
            x1 = x2;
            x2 = temp;

            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        draw_line_alg_steep(x1, y1, x2, y2);
    }
}