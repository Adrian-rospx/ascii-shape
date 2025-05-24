// line drawing module
#pragma once

#include <algorithm>
#include <vector>

#include "geometry.h"
#include "screen.h"

// line drawing utility
void draw_line(Screen& scr, int x1, int y1, int x2, int y2, const char character);

// edge structure for polygon drawing
struct Edge {
    int y_min;
    int y_max;
    int x_at_y_min;
    float dx_dy;    // inverse slope
};

// edge table (polygon drawing)
class EdgeTable {
    Edge vertices_to_edge(const Vertex& v1_y_min, const Vertex& v2);
public:
    std::vector<Edge> Edges;

    EdgeTable(const std::vector<Vertex>& Vertices) {

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
        // sort edges by y_min
        std::sort(Edges.begin(), Edges.end(), 
            [](const Edge& A, const Edge& B) {
                return A.y_min < B.y_min;
        });

    }
};