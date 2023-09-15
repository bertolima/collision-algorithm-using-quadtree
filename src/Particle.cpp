#include "Particle.h"

int randomInt(int start, int range)
{
    return (start + rand() % range);

}



Particle::Particle(SDL_Point center, int radius)
{
    this->center = center;
    this->radius = radius;
    this->velocity = SDL_Point{randomInt(50,150), randomInt(50,150)};

}

Particle::~Particle()
{
}

bool Particle::colides(Particle other)
{
    if((this->center.x - other.getCenter().x) * (this->center.x  - other.getCenter().x)
     + (this->center.y - other.getCenter().y) * (this->center.y  - other.getCenter().y)
      <= (this->radius+other.getRadius())*(this->radius+other.getRadius())){
        return true;
    }
    return false;
}

void Particle::updatePositionsPosCollision(Particle other)
{
}

void Particle::boundaries(int x, int y)
{
    if (this->center.x + (this->radius/2) >= x || this->center.x <= 0) this->velocity.x = this->velocity.x * -1;   
    if (this->center.y + (this->radius/2) >= y || this->center.y <= 0) this->velocity.y = this->velocity.y * -1;

}

void Particle::updatePosition(float dt)
{
}

SDL_Point Particle::getCenter()
{
    return this->center;
}

int Particle::getRadius()
{
    return this->radius;
}

void Particle::update(int x, int y, float dt)
{
    this->updatePosition(dt);
    this->boundaries(x,y);
}
