// geometry classes implementations
#include "geometry.h"

#include <cmath>
#include <cstddef>

#include "rasterize.h"

void Shape::draw_outline(const char character) {
    size_t size = Vertices.size();
    for(size_t i = 0; i < size; i++) {
        // use each vertex and the next one to create an edge
        const Vertex v1 = Vertices[i];
        const Vertex v2 = Vertices[(i+1 != size) ? i+1 : 0];

        using std::lround;
        draw_line(scr, 
            lround(v1.x), 
            lround(v1.y), 
            lround(v2.x), 
            lround(v2.y), 
            character
        );
    }
}

void Shape::draw_fill(const char character) {
    EdgeTable edge_table(scr, Vertices);
    edge_table.fill_shape(scr, character);
}