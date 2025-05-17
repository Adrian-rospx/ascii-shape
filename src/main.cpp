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

void render() {
    for(const std::string& row : screen) {
        std::cout << row << '\n';
    }
}

int main() {
    screen.at(0).at(0) = '@';
    screen.at(HEIGHT - 1).at(WIDTH - 1) = '@';

    render();

    return 0;
}