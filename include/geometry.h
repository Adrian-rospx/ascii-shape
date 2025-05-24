// geometric shapes and drawing
#pragma once

#include <vector>

#include "screen.h"

struct Vertex {
    float x;
    float y;
};

class Shape {
    std::vector<Vertex> Vertices;
public:
    Shape(const std::vector<Vertex>& Vertices) : Vertices(Vertices) {}

    void draw_outline(Screen& scr, const char character = '#');
};