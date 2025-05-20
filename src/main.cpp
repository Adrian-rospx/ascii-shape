#include <iostream>
#include <conio.h>

#include "screen.h"
#include "line_drawing.h"

// constants:
const int HEIGHT = 20;
const int WIDTH = 20;

// initial screen, defined in "screen.h"
Screen scr(HEIGHT, WIDTH);

// rendering function (flips screen for convenience)
void render(const Screen& scr) {
    for(auto row_iter = scr.buffer.rbegin(); row_iter != scr.buffer.rend(); ++row_iter) {
        // create a string, add to it and flush it all at once
        std::string line(scr.WIDTH, char());

        for(auto col_item : *row_iter) {
            // draws x for colored red pixels
            if(col_item.r != 0)
                line += 'x';
            else
                line += ' ';
        }
        std::cout << line << '\n';
    }
}

int main() {
    // draw screen red
    scr.buffer.at(0).at(0).r = 255;
    scr.buffer.at(HEIGHT - 1).at(WIDTH - 1).r = 255;

    draw_line(scr, 5, 16, 16, 2);

    render(scr);

    return 0;
}