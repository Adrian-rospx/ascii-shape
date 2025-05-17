#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// constants
const int WIDTH = 20;
const int HEIGHT = 20;

// initial screen
std::vector<std::string> screen(
    HEIGHT, 
    std::string(WIDTH, ' ')
);

struct Point {
    float x;
    float y;
};

void draw_line_alg(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy / dx;      // m = slope

    for(int x = std::round(x1); x <= std::round(x2); x++) {
        const int y = static_cast<int>(m * (x-x1) + y1);
        screen.at(y).at(x) = 'y';
    }
}

// rendering function (flips screen for convenience)
void render() {
    for(auto it = screen.rbegin(); it != screen.rend(); ++it) {
        std::cout << *it << '\n';
    }
}

int main() {
    screen.at(0).at(0) = '@';
    screen.at(HEIGHT - 1).at(WIDTH - 1) = '@';

    draw_line_alg(0, 16, 15, 5);

    render();

    return 0;
}