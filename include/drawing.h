// line drawing module
#pragma once

#include <iostream>
#include <vector>

#include "geometry.h"
#include "screen.h"

// line drawing utility
void draw_line(Screen& scr, 
    int x1, int y1, int x2, int y2, 
    const char character
);

// edge structure for polygon drawing
struct Edge {
    int y_min;
    int y_max;
    int x_at_y_min;
    float dx_dy;    // inverse slope
};

// edge table (polygon drawing)
class EdgeTable {
    std::vector<Edge> make_edge_vector(const std::vector<Vertex>& Vertices);
public:
    std::vector<std::vector<Edge>> edge_buckets;

    EdgeTable(const Screen& scr,
        const std::vector<Vertex>& Vertices
    ) {
        edge_buckets.resize(scr.HEIGHT);

        // array of all edges:
        const std::vector<Edge> edges = make_edge_vector(Vertices);
        
        // add to egde buckets by y_min value
        for(const Edge& e : edges) {
            edge_buckets[e.y_min].push_back(e);
        }

    }
};