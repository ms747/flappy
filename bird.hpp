#ifndef BIRD_HPP_INCLUDED
#define BIRD_HPP_INCLUDED

    #include <SDL2/SDL2_gfxPrimitives.h>

#define H 640
#define W 480

class bird
{
private:
    int x;
    int y;
    int radius;
    int velocity = 7;
    int accel = 1;
public:
    bird(int x , int y , int rad);
    void draw(SDL_Renderer** render);
    void jump();
    int getX();
    int getY();
};




#endif // BIRD_HPP_INCLUDED
