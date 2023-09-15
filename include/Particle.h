#pragma once
#include <SDL2/SDL.h>

int randomInt(int start, int range);


class Particle{
    public:
        Particle(SDL_Point center, int radius);
        ~Particle();
        bool colides(Particle other);
        void updatePositionsPosCollision(Particle other);
        SDL_Point getCenter();
        int getRadius();
        void update(int x, int y, float dt);


    private:
        void boundaries(int x,int y);
        void updatePosition(float dt);
        int radius;
        SDL_Point center;
        SDL_Point velocity;
        
};

