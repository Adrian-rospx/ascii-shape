// line drawing module
#pragma once

#include <algorithm>
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

    void draw(Screen& scr) {
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
        }
    }
};