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
    scr.buffer.at(0).at(0) = Pixel('@', 'w');
    scr.buffer.at(scr.HEIGHT - 1).at(scr.WIDTH - 1) = Pixel('@', 'w');

    // create a Shape, defined in "shape.h"
    Shape square(&scr, {
        {16, 8},
        {16, -8},
        {-16, -8},
        {-16,  8},
    });

    // rasterize, colors defined in "render.h"
    square.draw_fill('.', 'g');
    square.draw_outline('$', 'g');

    // render the shape
    scr.render();
    
    return 0;
}