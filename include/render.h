// screen pixels container for drawing with rendering methods
#pragma once

#include <cstdint>
#include <vector>

// each pixel carries rgb values between 0-255
struct Pixel {
    char character = ' ';
    char color = ' ';

    Pixel(const char character, const char color) : character(character), color(color) {}
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

    // rendering function (flips screen for convenience)
    void render();
};
