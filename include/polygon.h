// geometric shapes and drawing
#pragma once

#include <vector>

#include "render.h"

struct Vertex {
    float x;
    float y;
    void add(const Vertex& item) {
        x += item.x; y += item.y;
    }
};

class Polygon {
    Screen& scr;
    const Vertex Center;

    const std::vector<Vertex> Vertices_local;
    std::vector<Vertex> Vertices_screen;
public:

    Polygon(Screen* scr, const std::vector<Vertex>& Vertices) : 
        scr(*scr), 
        Vertices_local(Vertices),
        Center{static_cast<float>(scr->WIDTH)/2, static_cast<float>(scr->HEIGHT)/2} {
            update_screen_vertices();
        }

    void update_screen_vertices();

    void draw_fill(const char character, const char color);
    void draw_outline(const char character, const char color);
};