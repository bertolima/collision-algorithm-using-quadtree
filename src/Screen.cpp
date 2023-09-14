#include "../include/Screen.h"
#include "Screen.h"

Screen::Screen(const std::string &title, int width, int height){
    this->width = width;
    this->height = height;
    this->title = title;

    if (!init()){
        this->closed = true;
    }
}

Screen::~Screen(){
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

bool Screen::init(){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cerr << "Failed to initialize SDL\n";
        return 0;
    }
    this->window = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, 0);
    this->renderer = SDL_CreateRenderer(this->window, -1, 0);

    if(this->window == nullptr){
        std::cerr << "Failed to create window\n";
        return 0;
    }
    return true;
}

void Screen::pollEvents(){
    if(SDL_PollEvent(&this->event)){
        switch (event.type){
            case SDL_QUIT:
                this->closed = true;
                break;
            default:
                break;
        }
    }
}

void Screen::update()
{
    this->pollEvents();
    

}

void Screen::render()
{

    this->a = SDL_GetTicks();
    this->delta =  this->a -  this->b;
    if (this->delta > 1000/60.0)
    {
        SDL_SetRenderDrawColor(this->renderer,0,0,0,255);
        SDL_RenderClear(this->renderer);
        SDL_SetRenderDrawColor(this->renderer, 255,255,255,255);
        SDL_RenderDrawLine(this->renderer,0,30, this->x, 30);
        SDL_RenderPresent(this->renderer);
        this->b = this->a;
        this->x = this->x + (80 * this->delta/1000);
    
    }
} 

