#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Screen{
    public:
        Screen(const std::string &title, int width, int height);
        ~Screen();

        void pollEvents();
        inline bool isClosed() const {return closed;}

        void update(float dt);
        void render();
    private:
        bool init();
        std::string title;
        int width = 800;
        int height = 800;
        bool closed = false;

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_Event event;
        int x = 0;
        Uint64 NOW = SDL_GetPerformanceCounter();
        Uint64 LAST = 0;
        double delta = 0;
        int a = SDL_GetTicks();
        int b = SDL_GetTicks();
        
};