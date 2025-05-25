// geometry classes implementations
#include "shape.h"

#include <cmath>
#include <cstddef>
#include <vector>

#include "rasterize.h"

// calculate screen vertices (local vertices + center vertex location)
void Shape::update_screen_vertices() {
    Vertices_screen = Vertices_local;
    for(Vertex& v : Vertices_screen) {
        v.add(Center);
    }
}

void Shape::draw_outline(const char character, const char color) {
    size_t size = Vertices_screen.size();
    for(size_t i = 0; i < size; i++) {
        // use each vertex and the next one to create an edge
        const Vertex v1 = Vertices_screen[i];
        const Vertex v2 = Vertices_screen[(i+1 != size) ? i+1 : 0];

        using std::lround;
        draw_line(scr, 
            lround(v1.x), 
            lround(v1.y), 
            lround(v2.x), 
            lround(v2.y), 
            character,
            color
        );
    }
}

void Shape::draw_fill(const char character, const char color) {
    EdgeTable edge_table(scr, Vertices_screen);
    edge_table.fill_shape(scr, character, color);
}