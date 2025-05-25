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
    Shape quad(&scr, {
        {20.2,  19},
        {24,  12},
        {38,  12},
        {26,  9},
        {30,  0},
        {20,  6},
        {8,   0},
        {14,  9},
        {0,   12},
        {15,  12},
    });

    // rasterize
    quad.draw_fill('.');
    quad.draw_outline('$');

    // render the shape
    scr.render();
    
    return 0;
}