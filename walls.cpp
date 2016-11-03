#include "walls.hpp"

walls::walls()
{
    srand(SDL_GetTicks());
    this->top = rand() % (H/2);
    for(int i = 0; i < 10000 ; i++);
    srand(time(NULL));
    this->bot = rand() % (H/2);
}

void walls::update()
{
    this->x -= this->speed;

}

void walls::draw(SDL_Renderer** render)
{
    // (w,h,w,h) (x1,y1,x2,y2)
    // (480,640,480,640)
    boxColor(*render,this->x,0,this->x - 20,this->top,this->color);
    boxColor(*render,this->x,(H - this->bot) , this->x -20 ,H , this->color );
    //srand(SDL_GetTicks());
    //boxColor(*render,this->x,this->y,this->x+this->w,rand() % (H/2),0xFFFFFFFF);
    //srand(SDL_GetTicks());
    //boxColor(*render,this->x,H- (rand()%(H/2)),this->x+this->w,H,0xFFFFFFFF);

}


bool walls::notvisible()
{
    if(this->x <= 0)
    {
        return true;
    }
    return false;
}

int walls::getX()
{
    return this->x;
}

int walls::checkBird(bird b,SDL_Renderer** render)
{
    if (b.getY() >= this->top && b.getY() <= (H - this->bot))
    {
        if(b.getX() >= (this->x - 20) && b.getX() <= (this->x))
        {
                this->color = 0xFFFF0000;
        }
         //printf("true\n");

         //walls::draw(render);
    }
    else{
        this->color = 0xFF0000FF;
        //printf("fasle\n");
    }
    //printf("%d %d %d\n",this->x,b.getX(),this->x - 20);
}


