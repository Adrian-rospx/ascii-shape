#include <vector>

#include "shape.h"
#include "render.h"

// constants:
const int HEIGHT = 20;
const int WIDTH = 40;

// initial Screen, defined in "render.h"
Screen scr(HEIGHT, WIDTH);

int main() {
    // draw two points in corners
    scr.buffer.at(0).at(0) = Pixel('-', 'w');
    scr.buffer.at(scr.HEIGHT - 1).at(scr.WIDTH - 1) = Pixel('-', 'w');

    // create a Shape, defined in "shape.h"
    Shape myLetter(&scr, {
        {5, 8},     // right side
        {16, -8},
        {10, -8},   // middle gap right
        {4, -1},
        {-6, -1},
        {-6, 2},
        {3, 2},     // inside loop
        {1, 5},
        {-8, 5},    // loop end
        {-9, -8},
        {-15, -8}, // left side
        {-13,  8},
    });

    // rasterize, colors defined in "render.h"
    myLetter.draw_fill('.', 'r');
    myLetter.draw_outline('$', 'r');

    // render the shape
    scr.render();
    
    return 0;
}