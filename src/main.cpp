#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "screen.h"
#include "line_drawing.h"

// constants
const int WIDTH = 20;
const int HEIGHT = 20;

// initial screen, externed in screen.h
std::vector<std::string> screen(
    HEIGHT, 
    std::string(WIDTH, ' ')
);

struct Point {
    float x;
    float y;
};

// rendering function (flips screen for convenience)
void render() {
    for(auto it = screen.rbegin(); it != screen.rend(); ++it) {
        std::cout << *it << '\n';
    }
}

int main() {
    screen.at(0).at(0) = '@';
    screen.at(HEIGHT - 1).at(WIDTH - 1) = '@';

    draw_line(5, 16, 16, 2);

    render();

    return 0;
}