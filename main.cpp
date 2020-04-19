#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "gach.h"
#include "function.h"
using namespace std;

bool play_again = false;
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
void playGame()
{
    SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    while(true)
    {
        play_again = false;
        gach box;
        int time_delay;
        point A,B,C,D;
        int a,b;//toa do tam
        bool quit = false,end = false;
        a=2;
        b=dai/2-1;
        box.get_toa_do_Tam(a,b);
        score = 0;
        srand(time(0));
        int hinh_truoc = rand() % 7 + 1, hinh_sau;

        init();
        gach box1;
        SDL_Event e;
        while(!end)
        {
            quit = false;
            k=0;//dung de quay truong hop 7,3,4
            hinh_sau = hinh_truoc;
            box.getType(hinh_sau);
            box.get_toa_do_Tam(a,b);
            getABCD(box,A,B,C,D);
            lui_dong(renderer,box);
            SDL_Delay(150);
            srand(time(0));
            hinh_truoc = rand() % 7 + 1;
            while(!quit)
            {
                SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                SDL_RenderClear(renderer);
                ve_le(renderer);
                box.render(renderer,A,B,C,D,box.type);

                goDown(box,A,B,C,D,a,renderer);
                ve_gach_da_co_dinh(renderer,box);
                printScore(renderer,score);
                time_delay = 150;
                ve_le2(renderer);

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
                            SDL_Delay(time_delay/7);
                            turnLeft(box,A,B,C,D,b);
                            break;
                        case SDLK_d:
                            SDL_Delay(time_delay/7);
                            turnRight(box,A,B,C,D,b);
                            break;
                        case SDLK_s:
                            while(IsMove(box,A,B,C,D,0))
                            {
                                goDown(box,A,B,C,D,a,renderer);
                            }
                            SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                            SDL_RenderClear(renderer);
                            co_dinh_gach(A,B,C,D,box);
                            ve_gach_da_co_dinh(renderer,box);
                            ve_le(renderer);
                            ve_le2(renderer);
                            printScore(renderer,score);
                            khoi_gach_tiep_theo(box1,renderer,hinh_truoc);
                            box.render(renderer,A,B,C,D,box.type);
                            SDL_RenderPresent(renderer);
                            break;
                        case SDLK_w:
                            SDL_Delay(time_delay/7);
                            if(IsMove(box,A,B,C,D,0) && inside(renderer,box,A,B,C,D))
                            {
                                k++;
                                xoay(renderer,box,k,A,B,C,D);
                                SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                                SDL_RenderClear(renderer);
                                ve_le(renderer);
                                ve_gach_da_co_dinh(renderer,box);
                                printScore(renderer,score);
                                box.render(renderer,A,B,C,D,box.type);
                                ve_le2(renderer);
                                khoi_gach_tiep_theo(box1,renderer,hinh_truoc);
                                SDL_RenderPresent(renderer);
                                SDL_Delay(time_delay*1/5);
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
                        ve_le(renderer);
                        ve_gach_da_co_dinh(renderer,box);
                        khoi_gach_tiep_theo(box,renderer,hinh_truoc);
                        ve_le2(renderer);
                        printScore(renderer,score);
                        printEndgame(renderer,score);
                        SDL_RenderPresent(renderer);

                        fstream f1;
                        f1.open("high_score.txt",ios::in);
                        string data1;
                        getline(f1, data1);
                        f1.close();
                        int b1 = score;
                        int c1 = stoi(data1);

                        if(c1 < b1)
                        {
                            f1.open("high_score.txt",ios::out);
                            string s1 = to_string(b1);
                            f1 << s1;
                            f1.close();
                        }
                        else
                        {
                            f1.open("high_score.txt",ios::out);
                            f1 << data1;
                            f1.close();
                        }

                        SDL_Event e1;
                        end = true;
                        while (!play_again)
                        {
                            SDL_Delay(10);
                            if ( SDL_PollEvent(&e1) == 0)
                                continue;
                            if (e1.type == SDL_QUIT)
                                break;
                            if (e1.type == SDL_KEYDOWN && e1.key.keysym.sym == SDLK_ESCAPE)
                            {
                                play_again = false;
                                break;
                            }
                            if (e1.type == SDL_MOUSEBUTTONDOWN)
                            {
                                bool checkk = (e1.button.x >= (le_trai+2)*20+22 && e1.button.x <= (le_trai+2)*20+22+116 &&
                                               e1.button.y >= 150*2-2 && e1.button.y <= 150*2-2 + 23);
                                if(checkk)
                                {
                                    play_again = true;
                                    break;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    else
                    {
                        a=2;
                        b=dai/2-1;
                        break;
                    }
                }
            }
        }
        if(play_again == true)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    quitSDL(window, renderer);
}
void drawStart(SDL_Renderer *renderer1)
{
    ve_le(renderer1);
    ve_le2(renderer1);
    SDL_Rect filled_rect;
    filled_rect.x = 20*(le_trai+1)+20;
    filled_rect.y = SCREEN_HEIGHT/2 - 180;
    filled_rect.w = 160;
    filled_rect.h = 200;
    SDL_SetRenderDrawColor(renderer1,0, 170, 170, 0);
    SDL_RenderFillRect(renderer1,&filled_rect);

    filled_rect.x = 20*(le_trai+1)+36;
    filled_rect.y = SCREEN_HEIGHT/2 - 165;
    filled_rect.w = 124;
    filled_rect.h = 80;
    SDL_SetRenderDrawColor(renderer1, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer1,&filled_rect);

}
int main(int argc, char* argv[])
{
    cout<<"click Play to start."<<endl;
    SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
    SDL_Window* window1;
    SDL_Renderer* renderer1;
    initSDL(window1, renderer1);
    drawStart(renderer1);

    TTF_Init();
    TTF_Font * font = TTF_OpenFont("vgafix.fon", 20);
    SDL_Color color = { 255, 0, 0 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,
                            "HIGH SCORE", color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer1, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 20*(le_trai+1)+55, SCREEN_HEIGHT/2 - 165, 90, 18 };
    SDL_RenderCopy(renderer1, texture, NULL, &dstrect);
    //hien thi high score
    fstream f;
    f.open("high_score.txt",ios::in);
    string data;
    getline(f, data);
    int num = stoi(data);
    const char *highScore = data.c_str();
    color ={255,255,255};
    surface = TTF_RenderText_Solid(font,highScore, color);
    texture = SDL_CreateTextureFromSurface(renderer1, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    if(num < 10 )
    {
        dstrect = { 20*(le_trai+1)+97-6,  SCREEN_HEIGHT/2 - 145, 10, 19 };
    }
    else if(num < 100)
    {
        dstrect = { 20*(le_trai+1)+97-13,  SCREEN_HEIGHT/2 - 145, 20, 19 };
    }
    else
    {
        dstrect = { 20*(le_trai+1)+97-18,  SCREEN_HEIGHT/2 - 145, 30, 19 };
    }
    SDL_RenderCopy(renderer1, texture, NULL, &dstrect);

    //ghi lai score vao file
    f << data;
    f.close();
    //ve nut PLAY
    SDL_Rect filled_rect;
    filled_rect.x = 20*(le_trai+1)+60;
    filled_rect.y = SCREEN_HEIGHT/2 - 40;
    filled_rect.w = 80;
    filled_rect.h = 40;
    SDL_SetRenderDrawColor(renderer1, 0,0,0,0);
    SDL_RenderFillRect(renderer1,&filled_rect);
    //vien nut
    filled_rect.x = 20*(le_trai+1)+60;
    filled_rect.y = SCREEN_HEIGHT/2 - 40;
    filled_rect.w = 80;
    filled_rect.h = 40;
    SDL_SetRenderDrawColor(renderer1, 254,245, 6, 0);
    SDL_RenderDrawRect(renderer1,&filled_rect);

    font = TTF_OpenFont("vgafix.fon", 500);
    color = { 66, 103, 178 };
    surface = TTF_RenderText_Solid(font, "PLAY", color);
    texture = SDL_CreateTextureFromSurface(renderer1, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = { 20*(le_trai+1)+64, SCREEN_HEIGHT/2 - 38, 72, 32 };
    SDL_RenderCopy(renderer1, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer1);
    bool play = false;
    SDL_Event e1;
    while (true)
    {
        SDL_Delay(10);
        if ( SDL_PollEvent(&e1) == 0)
            continue;
        if (e1.type == SDL_QUIT)
            break;
        if (e1.type == SDL_KEYDOWN && e1.key.keysym.sym == SDLK_ESCAPE)
            break;
        if (e1.type == SDL_MOUSEBUTTONDOWN)
        {
            bool checkk = (e1.button.x >= 20*(le_trai+1)+60 && e1.button.x <= 20*(le_trai+1)+60+80 &&
                           e1.button.y >= SCREEN_HEIGHT/2 - 40 && e1.button.y <= SCREEN_HEIGHT/2);
            if(checkk)
            {
                play = true;
                SDL_RenderClear(renderer1);
                break;
            }
            else continue;
        }
    }
    if(play == true)
    {
        SDL_Delay(50);
        quitSDL(window1, renderer1);
        playGame();
    }
    return 0;
}
