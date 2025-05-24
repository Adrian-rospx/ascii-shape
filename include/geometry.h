// geometric shapes and drawing
#pragma once

#include <vector>

#include "screen.h"

struct Vertex {
    float x;
    float y;
};

class Shape {
public:
    std::vector<Vertex> Vertices;
    
    Shape(const std::vector<Vertex>& Vertices) : Vertices(Vertices) {}

    void draw_shape(Screen& scr, const char character = '#');
    void draw_outline(Screen& scr, const char character = '#');
};