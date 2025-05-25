cmake_minimum_required(VERSION 4.0.0)

project(ascii_shape LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ascii_shape 
    "src/main.cpp"
    "src/render.cpp"
    "src/shape.cpp"
    "src/rasterize.cpp"
)

target_include_directories(ascii_shape PUBLIC 
    include
)