#pragma once

#include <vector>
#include <cassert>
#include <SDL2/SDL.h>

class Node{
    public:
        bool divided;
        float x;
        float y;
        int width;
        Node *ne;
        Node *nd;
        Node *sd;
        Node *se;
        Node(float x, float y, float width);
        ~Node();
        void divide(std::vector<Node*> &children);
        // void updateNodes(std::vector<Particle> &v, std::vector<Node*> nodes)
        // void updateBalls(std::vector<Particle> &v);
        bool contains(Node* other);
        void draw(SDL_Renderer* target);


};

class Quadtree{
    private:
        Node* root;
        int maxDepth;
        std::vector<Node*> nodes;
        std::vector<Node*> drawnableNodes;
        void divide();
    public:
        Quadtree(int width, int depth);
        ~Quadtree();
        void drawNodes(SDL_Renderer* target);
        // void updateNodes(std::vector<Particle> &v, std::vector<Node*> nodes);
};