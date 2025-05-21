// geometry classes implementations
#include "geometry.h"

#include <cmath>

#include "line_drawing.h"

void Shape::draw_outline(Screen& scr) {
    for(int i=0; i<Vertices.size(); i++) {
        const Point v1 = Vertices.at(i);
        const Point v2 = Vertices.at((i+1) % Vertices.size());

        draw_line(scr, 
            static_cast<int>(std::round(v1.x)), 
            static_cast<int>(std::round(v1.y)), 
            static_cast<int>(std::round(v2.x)), 
            static_cast<int>(std::round(v2.y))
        );
    }
}