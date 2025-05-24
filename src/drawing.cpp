// line drawing algorithm implementation
#include "drawing.h"

#include <algorithm>
#include <cmath>
#include <vector>

#include "screen.h"
#include "geometry.h"

// general drawing function
void draw(Screen& scr, const int x, const int y, const char character, const char color = 'w') {
    scr.buffer.at(y).at(x) = Pixel(character, color);
}

/*
    Line drawing algorithm functions
*/
void draw_line_alg_low(Screen& scr, 
    const int x1, const int y1, const int x2, const int y2, 
    const char character
) {
    const int dx = x2 - x1;
    const int dy = y2 - y1;
    const float m = static_cast<float>(dy) / dx;    // m = slope

    // drawing:
    for(int x = x1; x <= x2; x++) {
        const int y = static_cast<int>(std::lround(static_cast<float>(x-x1) * m + y1));
        draw(scr, x, y, character);
    }
}
void draw_line_alg_steep(Screen& scr, 
    const int x1, const int y1, const int x2, const int y2,
    const char character
) {
    const int dx = x2 - x1;
    const int dy = y2 - y1;
    const float inv_m = static_cast<float>(dx) / dy;// inverse slope to avoid zero division

    for(int y = y1; y <= y2; y++) {
        const int x = static_cast<int>(std::lround(static_cast<float>(y-y1) * inv_m + x1));
        draw(scr, x, y, character);
    }
}

void draw_line(Screen& scr, int x1, int y1, int x2, int y2, const char character) {

    if(std::abs(x2-x1) > std::abs(y2-y1)) {
        // switch points if the x values aren't in order
        if(x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        draw_line_alg_low(scr, x1, y1, x2, y2, character);
    } else {
        if(y1 > y2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        draw_line_alg_steep(scr, x1, y1, x2, y2, character);
    }
}

/*
    Edge table functions
*/
Edge vertices_to_edge(const Vertex& v_y_min, const Vertex& v_y_max) {
    const int y_min = std::lround(v_y_min.y);
    const int y_max = std::lround(v_y_max.y);
    const int x_at_y_min = std::lround(v_y_min.x);

    const float dx = std::abs(v_y_min.x - v_y_max.x);
    const int dy = y_max - y_min;

    return Edge{y_min, y_max, x_at_y_min, dx/dy};
}
std::vector<Edge> EdgeTable::make_edge_vector(const std::vector<Vertex>& Vertices) {
    // create an array with all edges
    std::vector<Edge> Edges;

    for(int i=0; i < Vertices.size(); i++) {
        // select neighboring vertices to create edges
        const Vertex v1 = Vertices[i];
        const Vertex v2 = Vertices[(i+1 != Vertices.size()) ? i+1 : 0];

        if(v1.y < v2.y) {
            Edges.push_back(vertices_to_edge(v1, v2));
        }
        else {
            Edges.push_back(vertices_to_edge(v2, v1));
        }
    }
    
    return Edges;
}


void scanline_fill(Screen& scr,
    std::vector<Vertex> Vertices
) {

}