// line drawing module
#pragma once

#include <algorithm>
#include <vector>

#include "shape.h"
#include "render.h"

// line drawing utility
void draw_line(Screen& scr, 
    int x1, int y1, int x2, int y2, 
    const char character
);

// edge structure for polygon drawing
struct Edge {
    int y_min, y_max;
    float x;        // float for accuracy when drawing
    float dx_dy;    // inverse slope
};

// edge table (polygon drawing)
class EdgeTable {
    std::vector<Edge> make_edge_vector(const std::vector<Vertex>& Vertices);
public:
    int y_min, y_max;
    std::vector<std::vector<Edge>> edge_buckets;
    std::vector<Edge> AET;  // active edge table

    EdgeTable(const Screen& scr,
        const std::vector<Vertex>& Vertices
    ) {
        edge_buckets.resize(scr.HEIGHT);

        // array of all edges:
        const std::vector<Edge> edges = make_edge_vector(Vertices);

        // min and max elements
        y_min = std::min_element(edges.cbegin(), edges.cend(), 
            [](const Edge& a, const Edge& b) { 
                return a.y_min < b.y_min;
            }
        )->y_min;
        y_max = std::max_element(edges.cbegin(), edges.cend(), 
            [](const Edge& a, const Edge& b) { 
                return a.y_max < b.y_max;
            }
        )->y_max;

        // add to edge buckets by y_min value
        for(const Edge& e : edges) {
            edge_buckets[e.y_min].push_back(e);
        }
    }

    void fill_shape(Screen& scr, const char character='@', const char color = 'w');
};