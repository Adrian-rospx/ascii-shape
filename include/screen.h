// screen buffer made from a matrix of pixels
#pragma once

#include <cstdint>
#include <vector>

// each pixel carries rgb values between 0-255
struct Pixel {
    uint8_t r=0;
    uint8_t g=0;
    uint8_t b=0;

    Pixel(const uint8_t r, const uint8_t g, const uint8_t b) : r(r), g(g), b(b) {}
    Pixel() {}
};

// screen buffer with height and width container
struct Screen {
    const uint32_t HEIGHT;
    const uint32_t WIDTH;

    std::vector<std::vector<Pixel>> buffer;

    Screen(const int height = 10, const int width = 10) : 
        HEIGHT(height), 
        WIDTH(width), 
        buffer(
            height, 
            std::vector<Pixel>(width, Pixel())
        ) {}
};