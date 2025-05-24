#include <vector>

#include "geometry.h"
#include "screen.h"

// constants:
const int HEIGHT = 20;
const int WIDTH = 20;

// initial Screen, defined in "screen.h"
Screen scr(HEIGHT, WIDTH);

int main() {
    // draw two points in corners
    scr.buffer.at(0).at(0) = Pixel('@', 'w');
    scr.buffer.at(scr.HEIGHT - 1).at(scr.WIDTH - 1) = Pixel('@', 'w');

    // create a Shape, defined in "geometry.h"
    Shape quad({
        {0,   12},
        {7,   12},
        {11,  19},
        {12,  12},
        {19,  12},
        {13,  9},
        {15,  0},
        {10,  6},
        {4,   0},
        {7,   9},
    });

    quad.draw_shape(scr, '.');
    quad.draw_outline(scr, '#');

    // render the shape
    scr.render();
    
    return 0;
}