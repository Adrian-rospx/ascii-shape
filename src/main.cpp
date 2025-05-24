#include <vector>

#include "drawing.h"
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
        {5,   13},
        {14,  18},
        {18,  2},
        {2,   5}
    });


    // edge table creation
    EdgeTable edgeTable(scr, quad.Vertices);

    edgeTable.draw_shape(scr, '.');
    quad.draw_outline(scr, '#');

    // render the shape
    scr.render();
    
    return 0;
}