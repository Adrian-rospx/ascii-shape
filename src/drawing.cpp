// line drawing algorithm implementation
#include "drawing.h"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <vector>

#include "screen.h"
#include "geometry.h"

// general drawing function
void draw(Screen& scr, const int x, const int y, const char character, const char color = 'w') {
    scr.buffer[y][x] = Pixel(character, color);
}
// draw horizontal line
void draw_h(Screen& scr, const int y, const int x1, const int x2, const char character, const char color = 'w') {
    for(int x = x1; x < x2; x++) {
        scr.buffer[y][x] = Pixel(character, color);
    }
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
    const float x_at_y_min = std::lround(v_y_min.x);

    const float dx = std::round(v_y_max.x) - std::round(v_y_min.x);
    const int dy = y_max - y_min;

    return Edge{y_min, y_max, x_at_y_min, dx/dy};
}
// turns vertices into a vector of edges
std::vector<Edge> EdgeTable::make_edge_vector(const std::vector<Vertex>& Vertices) {
    // create an array with all edges
    std::vector<Edge> Edges;

    for(size_t i=0; i < Vertices.size(); i++) {
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

// main drawing function
void EdgeTable::draw_shape(Screen& scr, const char character, const char color) {

    for(int y = y_min; y < y_max; y++) {
        // add edges from current edge bucket
        if(!edge_buckets[y].empty()) {
            for(const Edge& edge : edge_buckets[y])
                AET.push_back(edge);
        }
        // remove y = y_max
        AET.erase(std::remove_if(AET.begin(), AET.end(),
            [y](const Edge& A) {
                return y == A.y_max;
            }
            ), AET.end()
        );
        // sort by current x value
        std::sort(AET.begin(), AET.end(), 
            [](const Edge& A, const Edge& B) {
                return A.x < B.x;
            }
        );

        // pair edges two and two for drawing
        for(size_t i = 0; i+1 < AET.size(); i+=2) {
            const int x_start = std::ceil(AET[i].x);
            const int x_end   = std::floor(AET[i+1].x);

            draw_h(scr, y, x_start, x_end, character, color);
        }
        // increase x accordingly
        for(auto& edge : AET) {
            edge.x += edge.dx_dy; 
        }
    }
}