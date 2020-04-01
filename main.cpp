#include <iostream>
#include <SDL.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "block.h"
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}
const string WINDOW_TITLE = "An Implementation of Code.org Painter";

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
        logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void waitUntilKeyPressed();

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true)
    {
        if ( SDL_WaitEvent(&e) != 0 &&
                (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
void getBrick(struct brick &box, SDL_Renderer *renderer,int type)
{

    if(type == 1)
        box.render1(renderer);
    else if (type == 2)
    {
        box.render2(renderer);
    }
    else if (type == 3)
    {
        box.render3(renderer);
    }
    else if (type == 4)
    {
        box.render4(renderer);
    }
    else if (type == 5)
    {
        box.render5(renderer);
    }

}
int main(int argc, char* argv[])
{

    SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool quit = false;
    initSDL(window, renderer);
    int signal = 0;
    brick box;
    box.getXY( SCREEN_WIDTH/(2*(box.size)),1);
    SDL_Event e;
    int le_trai = (SCREEN_WIDTH-10*box.size)/2;
    int le_phai = SCREEN_WIDTH-(SCREEN_WIDTH-10*box.size)/2;
    while(true)
    {
        srand(time(0));
        int random = rand() % 5 + 1;
        //getBrick(box,renderer,random);
        while(!quit)
        {


            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderClear(renderer);
            if(!box.inside(le_trai, le_phai, SCREEN_HEIGHT))
            {
                box.y=1;
                break;
            }
            box.goDown();

            SDL_Rect rect;
            rect.x = 0;
            rect.y = 0;
            rect.w = (SCREEN_WIDTH-10*box.size)/2 ;
            rect.h = SCREEN_HEIGHT;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);

            SDL_Rect rect2;
            rect2.x = SCREEN_WIDTH-(SCREEN_WIDTH-10*box.size)/2;
            rect2.y = 0;
            rect2.w = (SCREEN_WIDTH-10*box.size)/2;
            rect2.h = SCREEN_HEIGHT;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect2);

//        if(signal == 0) getBrick(box,renderer);
            //box.render1(renderer);
            getBrick(box,renderer,random);

            int time_delay = 100;
            SDL_RenderPresent(renderer);
            SDL_Delay(time_delay);
            while( SDL_PollEvent( &e ) != 0 )
            {

                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }

                if (e.type == SDL_KEYDOWN)
                {
                    SDL_Delay(time_delay/6);
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        break;
                    case SDLK_a:
                        box.turnLeft();
                        break;
                    case SDLK_d:
                        box.turnRight();
                        break;
                    //case SDLK_s: box.turnDown(); break;
                    case SDLK_w:
                        box.xoay_nguoc();
                        break;
                    }
                }
            }
        }
    }
    //waitUntilKeyPressed();

    quitSDL(window, renderer);
    return 0;
}
