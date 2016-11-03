#include "bird.hpp"
#include "walls.hpp"
#include <vector>
#include <SDL2/SDL_ttf.h>
#define H 640
#define W 480

SDL_Window* window = nullptr;
SDL_Renderer* render = nullptr;

bool running = true;

int main(int argc, char* argv[])
{
    unsigned int currenTime = 0;
    unsigned int previousTime = 0;
    float frameTime = 0;
    float deltaTime = 0;
    bird myBird(60,30,15);
    std::vector<walls*> wallies;
    wallies.push_back(new walls());

    SDL_Init(SDL_INIT_VIDEO);
     TTF_Init();


    window = SDL_CreateWindow("Flappy",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              W,
                              H,
                              SDL_WINDOW_SHOWN);

    render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    TTF_Font* font = TTF_OpenFont("arial.ttf",20);
    SDL_Color col = {144 , 75 , 255 ,255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(font,"Score",col);
    SDL_Texture* text = SDL_CreateTextureFromSurface(render,textSurface);
    SDL_Rect rect;
    rect.x = rect.y = 0;
    SDL_QueryTexture(text,NULL,NULL,&rect.w,&rect.h);

    SDL_FreeSurface(textSurface);
    textSurface = nullptr;

    SDL_Event event;

    while(running)
    {
        previousTime = currenTime;
        currenTime = SDL_GetTicks();
        deltaTime = (currenTime - previousTime)/1000.0f;
        while(SDL_PollEvent(&event) != 0)
        {
            // Handle Events
            if(event.type == SDL_QUIT){
                running = false;
            }
            else if(event.type == SDL_KEYDOWN){
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_SPACE:
                            myBird.jump();
                            break;
                        }
                }
        }

        frameTime += deltaTime;

        if(frameTime >= 2.0f)
        {
            frameTime = 0;
            wallies.push_back(new walls());
        }



        SDL_SetRenderDrawColor(render,0,0,0,0xFF);
        SDL_RenderClear(render);



        for(int i = 0 ; i < wallies.size() ; i++)
        {
           wallies.at(i)->draw(&render);
           wallies.at(i)->update();
           wallies.at(i)->checkBird(myBird,&render);

            if(wallies.at(i)->getX() <= 0)
            {
                wallies.erase(wallies.begin() + i);
            }
        }

        //printf("%d\n",wallies.size());



        myBird.draw(&render);

        SDL_RenderCopy(render,text,NULL,&rect);




        //SDL_Delay(14);

        SDL_RenderPresent(render);

    }


    SDL_DestroyTexture(text);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    window = nullptr;
    text = nullptr;
    render = nullptr;
    SDL_Quit();
    return 0;
}
