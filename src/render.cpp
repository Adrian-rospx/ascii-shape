// screen rendering functions
#include "render.h"

#include <iostream>
#include <string>

std::string get_color(const char color) {
    switch (color) {
        case 'w':
            return "\033[0m";
        case 'r':
            return "\033[31m";
        case 'g':
            return "\033[32m";
        case 'b':
            return "\033[34m";
        default:
            return "\033[0m";
    }
}

void Screen::render() {
    for(auto row_iter = this->buffer.rbegin(); row_iter != this->buffer.rend(); ++row_iter) {
        // create a string, add to it and flush it all at once
        std::string line(this->WIDTH, char());

        for(auto pixel : *row_iter) {
            // draws uncolored character
            line += (get_color(pixel.color) + pixel.character);
        }
        std::cout << line << "\033[0m\n";
    }
}