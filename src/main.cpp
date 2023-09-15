#include <iostream>
#include <stdio.h>
#include "../include/Screen.h"

struct Timer
{
    Uint64 previous_ticks{};
    float elapsed_seconds{};

    void tick()
    {
        const Uint64 current_ticks{ SDL_GetPerformanceCounter() };
        const Uint64 delta{ current_ticks - previous_ticks };
        previous_ticks = current_ticks;
        static const Uint64 TICKS_PER_SECOND{ SDL_GetPerformanceFrequency() };
        elapsed_seconds = delta / static_cast<float>(TICKS_PER_SECOND);
        if(elapsed_seconds > 0.5) elapsed_seconds = 0.5f;
    }
};

int main()
{

    
    const int UPDATE_FREQUENCY{ 60 };
    const float CYCLE_TIME{ 1.0f / UPDATE_FREQUENCY };
    static Timer system_timer;
    float accumulated_seconds{ 0.0f };
    Screen screen("Teste", 800, 800);

    while(!screen.isClosed()){
        system_timer.tick();
        accumulated_seconds += system_timer.elapsed_seconds;
        screen.pollEvents();
        while (std::isgreater(accumulated_seconds, CYCLE_TIME))
        {
            accumulated_seconds = -CYCLE_TIME;
            static Timer physics_timer;
            physics_timer.tick();
            std::cout << physics_timer.elapsed_seconds << "\n";
            screen.update(physics_timer.elapsed_seconds);
            screen.render();
        
        }
        
    }
    return 0;
}
