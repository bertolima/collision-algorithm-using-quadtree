cmake_minimum_required(VERSION 3.0.0)
project(sdl2_demo VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(sdl2_demo ${SOURCES})


target_link_libraries(sdl2_demo SDL2main SDL2 GL) 
 