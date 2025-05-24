#include <iostream>
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
        {5,    11.8},
        {14.4, 15.6},
        {18,   2.6},
        {2.3,  5}
    });
    quad.draw_outline(scr, '#');

    // render the shape
    scr.render();

    // edge table creation
    EdgeTable edgt(quad.Vertices);
    // print to check
    for(const Edge& edge : edgt.Edges) {
        std::cout << edge.y_min << ' ' << edge.x_at_y_min << '\n';
    }

    return 0;
}