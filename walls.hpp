#ifndef WALLS_HPP_INCLUDED
#define WALLS_HPP_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <time.h>
#include "bird.hpp"

#define H 640
#define W 480

class walls{
private:
    int top;
    int bot;
    int x = W;
    int _w = 20;
    int width = x - _w;
    int speed = 2;
    unsigned int color = 0xFFFFFFFF;
public:
    void draw(SDL_Renderer** render);
    void update();
    bool notvisible();
    int getX();
    int checkBird(bird b,SDL_Renderer** render);
    walls();
};





#endif // WALLS_HPP_INCLUDED
