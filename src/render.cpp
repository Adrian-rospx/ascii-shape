// screen rendering functions
#include "render.h"

#include <iostream>
#include <string>

/*
    colors handled:
    'w' - white;  
    'r' - red;   'g' - green;    'y' - yellow;
    'b' - blue;  'm' - magenta;  'c' - cyan;
    'k' - black;
*/
const std::string get_color_code(const char color) {
    switch (color) {
        case 'w':
            return "\033[0m";
        case 'r':
            return "\033[31m";
        case 'g':
            return "\033[32m";
        case 'y':
            return "\033[33m";
        case 'b':
            return "\033[34m";
        case 'm':
            return "\033[35m";
        case 'c':
            return "\033[36m";
        case 'k':
            return "\033[37m";
        default:
            return "\033[0m";
    }
}

void Screen::render() {
    for(auto row_iter = this->buffer.rbegin(); row_iter != this->buffer.rend(); ++row_iter) {
        // create a string, add to it and flush it all at once
        std::string line(this->WIDTH, char());

        for(const Pixel& pixel : *row_iter) {
            // draws uncolored character
            line += (get_color_code(pixel.color) + pixel.character);
        }
        std::cout << line << "\033[0m\n";
    }
}