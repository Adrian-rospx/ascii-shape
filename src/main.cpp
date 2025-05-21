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

        for(auto pixel : *row_iter) {
            // draws uncolored character
            line += pixel.character;
        }
        std::cout << line << '\n';
    }
}

int main() {
    // draw two 
    scr.buffer.at(0).at(0) = Pixel('@', 'w');
    scr.buffer.at(scr.HEIGHT - 1).at(scr.WIDTH - 1) = Pixel('@', 'w');

    draw_line(scr, 5, 16, 16, 2);

    render(scr);

    return 0;
}