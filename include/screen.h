// screen buffer made from a vector of strings
#pragma once

#include <cstdint>
#include <vector>

// each pixel carries rgb values between 0-255
struct Pixel {
    uint8_t r, g, b;

    Pixel(const uint8_t r, const uint8_t g, const uint8_t b) : r(r), g(g), b(b) {}
    Pixel() : r(0), g(0), b(0) {}
};

// screen buffer with height and width container
struct Screen {
    const int HEIGHT;
    const int WIDTH;

    std::vector<std::vector<Pixel>> buffer;

    Screen(const int height = 10, const int width = 10) : 
        HEIGHT(height), 
        WIDTH(width), 
        buffer(
            height, 
            std::vector<Pixel>(width, Pixel())
        ) {}
};