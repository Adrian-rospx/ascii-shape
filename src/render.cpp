// screen rendering functions
#include "render.h"

#include <iostream>
#include <string>

void Screen::render() {
    for(auto row_iter = this->buffer.rbegin(); row_iter != this->buffer.rend(); ++row_iter) {
        // create a string, add to it and flush it all at once
        std::string line(this->WIDTH, char());

        for(auto pixel : *row_iter) {
            // draws uncolored character
            line += pixel.character;
        }
        std::cout << line << '\n';
    }
}