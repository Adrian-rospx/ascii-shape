#include <conio.h>
#include <vector>

#include "geometry.h"
#include "screen.h"

// constants:
const int HEIGHT = 20;
const int WIDTH = 20;

// initial screen, defined in "screen.h"
Screen scr(HEIGHT, WIDTH);


int main() {
    // draw two points in corners
    scr.buffer.at(0).at(0) = Pixel('@', 'w');
    scr.buffer.at(scr.HEIGHT - 1).at(scr.WIDTH - 1) = Pixel('@', 'w');

    // create a square shape
    Shape quad({
        {5, 12},
        {15, 15},
        {18, 2.5f},
        {2, 5}
    });
    quad.draw_outline(scr);

    // render the shape
    scr.render();

    return 0;
}