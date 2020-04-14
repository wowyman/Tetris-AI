#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "gach.h"
#include "function.h"
using namespace std;

int game_play = -1;
void logSDLError(std::ostream& os,const std::string &msg, bool fatal = false);

void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
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

int main(int argc, char* argv[])
{
    SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    while(true)
    {
        game_play = -1;
        gach box;
        point A,B,C,D;
        int a,b;//toa do tam
        bool quit = false,end = false;
        a=2;
        b=20;
        box.get_toa_do_Tam(a,b);
        score = 0;
        srand(time(0));
        int hinh_truoc = rand() % 7 + 1, hinh_sau;
        int le_trai = ((SCREEN_WIDTH -10*box.size)/2)/box.size-1;
        int le_phai = le_trai + 11;
        init( le_trai, le_phai);
        gach box1;
        SDL_Event e;
        while(!end)
        {
            k=0;//dung de quay truong hop 7,3,4
            hinh_sau = hinh_truoc;
            box.getType(hinh_sau);
            box.get_toa_do_Tam(a,b);
            getABCD(box,A,B,C,D);
            lui_dong(renderer,box);
            SDL_Delay(250);
            srand(time(0));
            hinh_truoc = rand() % 7 + 1;
            while(!quit)
            {
                SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                SDL_RenderClear(renderer);
                ve_le(renderer,box);
                box.render(renderer,A,B,C,D,box.type);

                goDown(box,A,B,C,D,a);
                ve_gach_da_co_dinh(renderer,box);
                printScore(renderer,score);
                int time_delay = 200;
                ve_le2(renderer,box);

                khoi_gach_tiep_theo(box1,renderer,hinh_truoc);

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

                        switch (e.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            break;
                        case SDLK_a:
                            SDL_Delay(time_delay/6);
                            turnLeft(box,A,B,C,D,b);
                            break;
                        case SDLK_d:
                            SDL_Delay(time_delay/6);
                            turnRight(box,A,B,C,D,b);
                            break;
                        case SDLK_s:
                            while(IsMove(box,A,B,C,D,0))
                            {
                                goDown(box,A,B,C,D,a);
                            }
                            SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                            SDL_RenderClear(renderer);
                            ve_gach_da_co_dinh(renderer,box);
                            ve_le(renderer,box);
                            ve_le2(renderer,box);
                            printScore(renderer,score);
                            khoi_gach_tiep_theo(box1,renderer,hinh_truoc);
                            box.render(renderer,A,B,C,D,box.type);
                            SDL_RenderPresent(renderer);
                            break;
                        case SDLK_w:
                            SDL_Delay(time_delay/6);
                            if(IsMove(box,A,B,C,D,0) && inside(renderer,box,A,B,C,D))
                            {
                                k++;
                                xoay(renderer,box,k,A,B,C,D);
                                SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                                SDL_RenderClear(renderer);
                                ve_le(renderer,box);
                                ve_gach_da_co_dinh(renderer,box);
                                printScore(renderer,score);
                                box.render(renderer,A,B,C,D,box.type);
                                ve_le2(renderer,box);
                                khoi_gach_tiep_theo(box1,renderer,hinh_truoc);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(time_delay*2/5);
                            }
                            break;

                        }
                    }
                }

                if(!IsMove(box,A,B,C,D,0))
                {
                    co_dinh_gach(A,B,C,D,box);

                    if(end_game(box))
                    {
                        SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                        SDL_RenderClear(renderer);
                        ve_le(renderer,box);
                        ve_gach_da_co_dinh(renderer,box);
                        ve_le2(renderer,box);
                        printScore(renderer,score);
                        printEndgame(renderer,score);
                        SDL_RenderPresent(renderer);
                        end = true;
                        while(game_play == -1)
                        {
                            while( SDL_PollEvent( &e ) != 0 )
                            {
                                if( e.type == SDL_QUIT )
                                {
                                    quit = true;
                                }
                                if (e.type == SDL_KEYDOWN)
                                {
                                    switch (e.key.keysym.sym)
                                    {
                                    case SDLK_n:
                                        game_play = 0;
                                        break;
                                    case SDLK_y:
                                        game_play = 1;
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                    else
                    {
                        a=2;
                        b=20;
                        break;
                    }
                }
            }
        }
        if(game_play == 0)
            break;
        if(game_play == 1)
            SDL_Delay(500);
            continue;
    }
    quitSDL(window, renderer);
}
