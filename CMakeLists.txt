cmake_minimum_required(VERSION 3.0.0)
project(sdl2_demo VERSION 0.1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(my_includes "./include/Screen.h" "./include/Quadtree.h" "./include/Particle.h")
set(my_cpps "./src/main.cpp" "./src/Screen.cpp" "./src/Quadtree.cpp" "./src/Particle.cpp")

add_executable(sdl2_demo ${my_includes} ${my_cpps})
include_directories(./include)

target_link_libraries(sdl2_demo SDL2main SDL2 GL) 
