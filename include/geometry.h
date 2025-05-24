// geometric shapes and drawing
#pragma once

#include <vector>

#include "screen.h"

struct Point {
    float x;
    float y;
};

class Shape {
    std::vector<Point> Vertices;
public:
    Shape(const std::vector<Point>& Vertices) : Vertices(Vertices) {}

    void draw_outline(Screen& scr, const char character = '#');
};