#include "../include/Quadtree.h"


Node::Node(float x, float y, float width){
    this->x = x;
    this->y = y;
    this->width = width;
    this->divided = false;
    this->ne = nullptr;
    this->nd = nullptr;
    this->sd = nullptr;
    this->se = nullptr;
}

void Node::divide(std::vector<Node *> &children){
    int new_width = this->width >> 1;
    this->ne = new Node(this->x, this->y, new_width);
    this->nd = new Node(this->x+new_width, this->y, new_width);
    this->sd = new Node(this->x+new_width, this->y+new_width, new_width);
    this->se = new Node(this->x, this->y+new_width, new_width);
    children.push_back(this->ne);
    children.push_back(this->nd);
    children.push_back(this->sd);
    children.push_back(this->se);
    this->divided = true;
}
// void Node::updateBalls(std::vector<Particle> &v)
// {
// }
bool Node::contains(Node *other){

}

void Node::draw(SDL_Renderer *target){
    SDL_Rect rect{(int)this->x, (int)this->y, this->width, this->width};
    SDL_RenderDrawRect(target, &rect);
    
}


//
Quadtree::Quadtree(int width, int depth)
{
    this->root = new Node(0,0,width);
    this->maxDepth = depth;
    this->divide();
}

void Quadtree::divide(){
    std::vector<Node*> parent;
    std::vector<Node*> children;
    parent.push_back(this->root);
    this->nodes.push_back(this->root);
    for (int i=0;i<this->maxDepth;i++){
        for (auto &it : parent){
            it->divide(children);
        }

        for (auto &it2 : children){
            this->nodes.push_back(it2);
        }

        parent.clear();
        parent.swap(children);
    }
}


void Quadtree::drawNodes(SDL_Renderer* target){
    SDL_SetRenderDrawColor(target, 255,255,255,255);
    for(auto &it : this->nodes){
        it->draw(target);
    }


}

// void Quadtree::updateNodes()
// {
// }
