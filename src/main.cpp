#include <iostream>
#include <stdio.h>
#include <ctime>
#include "../include/Screen.h"


int main(int argc, char** argv)
{
    srand(static_cast<unsigned>(time(NULL)));
    Screen screen("Teste");

    Uint32 lastUpdate = SDL_GetPerformanceCounter();
    while(!screen.isClosed()){
        
        screen.pollEvents();
        Uint32 current = SDL_GetPerformanceCounter();
        float dt = (current - lastUpdate) / (float)SDL_GetPerformanceFrequency();
        lastUpdate = current;
        screen.update(dt);
        
        screen.render();
	}
    return 0;
}
