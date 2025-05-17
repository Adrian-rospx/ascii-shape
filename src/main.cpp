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

// rendering function (flips screen for convenience)
void render() {
    for(auto it = screen.rbegin(); it != screen.rend(); ++it) {
        std::cout << *it << '\n';
    }
}

int main() {
    screen.at(0).at(0) = '@';
    screen.at(HEIGHT - 1).at(WIDTH - 1) = '@';

    render();

    return 0;
}