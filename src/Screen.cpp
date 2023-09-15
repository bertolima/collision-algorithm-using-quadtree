#include "../include/Screen.h"


Screen::Screen(const std::string &title){
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
    this->window = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    this->initSquares();
    if(this->window == nullptr){
        std::cerr << "Failed to create window\n";
        return 0;
    }
    return true;
}

void Screen::updateSquares(float dt)
{
    for (int i=0;i<10;i++){
        float a = (20*dt);
        this->rects[i].x = (rects[i].x + a);
        this->rects[i].y = (rects[i].y + a);
    }
}

void Screen::initSquares()
{
    this->quadtree = new Quadtree(SCREEN_WIDTH, 8);
    
    
}

void Screen::renderSquares()
{
    this->quadtree->drawNodes(this->renderer);
}

void Screen::pollEvents()
{
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

void Screen::update(float dt)
{
    // this->updateSquares(dt);

}


void Screen::render()
{

    SDL_SetRenderDrawColor(this->renderer,0,0,0,255);
    SDL_RenderClear(this->renderer);
    this->renderSquares();
    SDL_RenderPresent(this->renderer);
    
} 

