#include "bird.hpp"

void bird::jump()
{
    if(this->accel == 0)
    {
        this->accel = 1;
    }
    this->velocity = -12;
}

void bird::draw(SDL_Renderer** render)
{
    //printf("%d\n",this->y);
    if(this->y >  (H - (this->radius))){
        this->y = (H - (this->radius));
        this->velocity = 0;
        this->accel = 0;
    }
    else
    {
        this->y += this->velocity;
        this->velocity += this->accel;
    }
    filledCircleColor(*render,this->x,this->y,this->radius,0xFF0000FF);

}

bird::bird(int x, int y, int rad)
{
    this->x = x;
    this->y = y;
    this->radius = rad;
}

int bird::getX()
{
    return this->x;
}

int bird::getY()
{
    return this->y;
}
