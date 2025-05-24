// geometry classes implementations
#include "geometry.h"

#include <cmath>
#include <cstddef>

#include "drawing.h"

void Shape::draw_outline(Screen& scr, const char character) {
    size_t size = Vertices.size();
    for(size_t i = 0; i < size; i++) {
        // use each vertex and the next one to create an edge
        const Point v1 = Vertices[i];
        const Point v2 = Vertices[(i+1 != size) ? i+1 : 0];

        using std::lround;
        draw_line(scr, 
            static_cast<int>(lround(v1.x)), 
            static_cast<int>(lround(v1.y)), 
            static_cast<int>(lround(v2.x)), 
            static_cast<int>(lround(v2.y)), 
            character
        );
    }
}