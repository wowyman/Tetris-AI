#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include "brick.h"
#include "ai.h"

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
        SDL_Delay(50);
    }
}
void playGame()
{
    SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    int next_block,cur_block,start=2;
    dark = false;
    count_dark = -1;
    int count_AI = 0;
    while(true)//vong lap de choi lai
    {
        play_again = false;
        bool quit = false,end = false;

        int time_delay = 200;
        point A,B,C,D;
        a = start;
        b = width/2 - 1;
        box.Get_Center_Brick(a,b);
        score = 0;

        next_block = rand() % 7 + 1;

        init();
        brick box1;
        SDL_Event e;
        bool check1[20]= {}; //luu xem diem thuoc doan nao
        while(!end)//vong lap de lap lai su di chuyen cua cac khoi gach
        {

            quit = false;
            cur_block = next_block;
            box.getType(cur_block);
            box.Get_Center_Brick(a,b);
            shape_of_you(box,A,B,C,D);
            delete_row(renderer,box);

            for(int i=1; i<=20; i++) //dung de tang toc do,giam delay
            {
                if(!check1[i] && score>=(i*10) && time_delay >=0)
                {
                    check1[i] = true;
                    time_delay -= 10;
                }
            }

//====================================================================================================================
//====================================================================================================================
//====================================================================================================================
//====================================================================================================================
//  AI
            if(run_AI == true)
            {
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<10; j++)
                    {
                        score_AI[i][j] = MAXXX;
                    }
                }
                for(int x=0; x<10; x++)
                {
                    for(int y=0; y<4; y++)
                    {
                        init_clone();
                        brick box2 = box;
                        box2.getType(cur_block);
                        point a_,b_,c_,d_;
                        box2.Get_Center_Brick(2,x+left_margin+1);
                        shape_of_you(box2,a_,b_,c_,d_);

                        for(int rotation = 0; rotation <=y; rotation ++)
                        {
                            rotate(box2,a_,b_,c_,d_);
                        }

                        if(!inside_AI(box2,a_,b_,c_,d_))
                        {
                            score_AI[y][x] = -8888;
                            continue;
                        }
                        else
                        {
                            while(IsMove_AI(box2,a_,b_,c_,d_))
                            {
                                goDown(box2,a_,b_,c_,d_,a2);
                            }
                            board_clone[a_.x][a_.y] = box2.type;
                            board_clone[b_.x][b_.y] = box2.type;
                            board_clone[c_.x][c_.y] = box2.type;
                            board_clone[d_.x][d_.y] = box2.type;
//cac dieu kien tham khao tai trang https://codemyroad.wordpress.com/2013/04/14/tetris-ai-the-near-perfect-player/
        //XET CAC DIEU KIEN :   1/ Chieu cao tong hop(CCTH) = tong chieu cao cac cot
                            //  2/ So dong full(SDF) = so dong da du 10 o gach
                            //  3/ So luong ho(Holes) = so luong o trong ma tren no la o gach
                            //  4/ Do gap genh(Bumpiness) = tong cua cac hieu giua chieu cao 2 cot lien ke(lay tri tuyet doi)
                            int CCTH = 0;
                            int high_cols[10];
                            for(int i = left_margin +1; i <= right_margin-1; i++ )
                            {
                                int _height = (height-5) - High_Col(i);
                                CCTH += _height;
                                high_cols[i - left_margin - 1] = _height;
                            }
                            int Bumpiness = 0;
                            for(int i = 0; i < 9; i ++)
                            {
                                Bumpiness = Bumpiness + abs(high_cols[i] - high_cols[i+1]);
                            }
                            int Holes=0;

                            for(int i = 5; i < height-1; i++)
                            {
                                for(int j=left_margin+1; j<=right_margin-1; j++)
                                {
                                    if(board_clone[i][j] ==0 && board_clone[i-1][j] != 0) Holes+=1;
                                }
                            }
                            int SDF = 0;
                            for(int i=4; i<height-1; i++)
                            {
                                if(IsFullRow(i) == true)
                                {
                                    SDF ++;
                                }
                            }
                            double tong_Diem = hs1*CCTH + hs2*SDF + hs3*Holes + hs4*Bumpiness;
                            score_AI[y][x] = tong_Diem;
                        }
                    }
                }
                int x_= 1,y_= width/2 - 3;
                double max_score_AI = MAXXX + 1.0;
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 10; j++)
                    {
                        if(score_AI[i][j] == -8888) continue;
                        if(score_AI[i][j] > max_score_AI)
                        {
                            max_score_AI = score_AI[i][j];
                            x_ = i;
                            y_ = j + left_margin + 1;
                        }
                    }
                }
                a = start;
                b = y_;
                box.Get_Center_Brick(a,b);
                shape_of_you(box,A,B,C,D);
                for(int rotation=0; rotation<=x_; rotation++)
                {
                    rotate(box,A,B,C,D);
                }

            }
//====================================================================================================================
//====================================================================================================================
//====================================================================================================================
//====================================================================================================================
// END AI
            next_block = rand() % 7 + 1; //lay hinh tiep theo

            while(!quit)//vong lap de di chuyen khoi gach
            {
                if(dark)
                    SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                else
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

                SDL_RenderClear(renderer);

                box.render(renderer,A,B,C,D,box.type);

                goDown(box,A,B,C,D,a);
                Print_Fixed_Block(renderer,box);
                Print_Background(renderer);
                Print_Next_Block(box1,renderer,next_block);
                printScore(renderer,score);
                SDL_RenderPresent(renderer);


                if(!run_AI)
                {
                    SDL_Delay(time_delay);
                }
                else SDL_Delay(0);

                while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    if(run_AI == false)
                    {
                        if (e.type == SDL_KEYDOWN)
                        {

                            switch (e.key.keysym.sym)
                            {
                            case SDLK_ESCAPE:
                                quit = true;
                                end = true;
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
                                    goDown(box,A,B,C,D,a);
                                }
                                if(dark)
                                    SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                                else
                                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

                                SDL_RenderClear(renderer);
                                Fixed_Block(A,B,C,D,box);
                                Print_Fixed_Block(renderer,box);

                                box.render(renderer,A,B,C,D,box.type);
                                Print_Background(renderer);
                                Print_Next_Block(box1,renderer,next_block);
                                printScore(renderer,score);
                                SDL_RenderPresent(renderer);
                                break;
                            case SDLK_w:
                                SDL_Delay(time_delay/7);
                                if(IsMove(box,A,B,C,D,0) && inside(renderer,box,A,B,C,D))
                                {
                                    rotate(box,A,B,C,D);
                                    if(dark)
                                        SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                                    else
                                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
                                    SDL_RenderClear(renderer);

                                    Print_Fixed_Block(renderer,box);
                                    box.render(renderer,A,B,C,D,box.type);

                                    Print_Background(renderer);
                                    Print_Next_Block(box1,renderer,next_block);
                                    printScore(renderer,score);
                                    SDL_RenderPresent(renderer);
                                    SDL_Delay(time_delay*1/5);
                                }
                                break;
                            }
                        }
                    }
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                    {

                        bool checkk = (e.button.x >= (right_margin+1)*20 && e.button.x <= (right_margin+1)*20+5*20 &&
                                       e.button.y >= 17*20 && e.button.y <= 17*20+20*2);
                        if(checkk)//reset
                        {
                            SDL_Rect rect;
                            rect.x = (right_margin+1)*20;
                            rect.y = 17*20;
                            rect.w = 5*20;
                            rect.h = 2*20;
                            SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                            SDL_RenderDrawRect(renderer,&rect);
                            SDL_RenderPresent(renderer);
                            quit = true;
                            end = true;
                            play_again = true;
                            break;
                        }
                        checkk = (e.button.x >= (right_margin+1)*20 && e.button.x <= (right_margin+1)*20+5*20 &&
                                  e.button.y >= 14*20 && e.button.y <= 14*20+20*2);
                        if(checkk)
                        {
                            count_dark++;
                            SDL_Rect rect;
                            rect.x = (right_margin+1)*20;
                            rect.y = 14*20;
                            rect.w = 5*20;
                            rect.h = 2*20;
                            SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                            SDL_RenderDrawRect(renderer,&rect);
                            SDL_RenderPresent(renderer);
                            if(count_dark %2 == 0)
                                dark = true;
                            else
                                dark = false;

                        }
                        checkk = (e.button.x >= (right_margin+1)*20 && e.button.x <= (right_margin+1)*20+5*20 &&
                                  e.button.y >= 20*20 && e.button.y <= 20*20+20*2);
                        if(checkk)
                        {
                            count_AI++;
                            SDL_Rect rect;
                            rect.x = (right_margin+1)*20;
                            rect.y = 20*20;
                            rect.w = 5*20;
                            rect.h = 2*20;
                            SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                            SDL_RenderDrawRect(renderer,&rect);
                            SDL_RenderPresent(renderer);
                            if(count_AI % 2 == 1)
                                run_AI = true;
                            else
                                run_AI = false;

                        }

                    }
                }


                if(!IsMove(box,A,B,C,D,0))
                {
                    Fixed_Block(A,B,C,D,box);

                    if(End_Game(box))
                    {
                        if(dark)
                            SDL_SetRenderDrawColor(renderer, 0, 28, 101, 0);
                        else
                            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
                        SDL_RenderClear(renderer);

                        Print_Fixed_Block(renderer,box);


                        Print_Background(renderer);
                        printScore(renderer,score);
                        printEndgame(renderer,score);
                        Print_Next_Block(box,renderer,next_block);
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
                                bool checkk = (e1.button.x >= (left_margin+2)*20+22 && e1.button.x <= (left_margin+2)*20+22+116 &&
                                               e1.button.y >= 150*2-2 && e1.button.y <= 150*2-2 + 23);
                                if(checkk)
                                {
                                    SDL_Rect rect;
                                    rect.x = (left_margin+2)*20+22;
                                    rect.y = 150*2-2;
                                    rect.w = 116;
                                    rect.h = 23;
                                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                                    SDL_RenderDrawRect(renderer,&rect);
                                    SDL_RenderPresent(renderer);
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
                        a=start;
                        b=width/2-1;
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
    Print_Background(renderer1);
    SDL_Rect filled_rect;
    filled_rect.x = 20*(left_margin+1)+20;
    filled_rect.y = SCREEN_HEIGHT/2 - 180;
    filled_rect.w = 160;
    filled_rect.h = 200;
    SDL_SetRenderDrawColor(renderer1,0, 170, 170, 0);
    SDL_RenderFillRect(renderer1,&filled_rect);

    filled_rect.x = 20*(left_margin+1)+36;
    filled_rect.y = SCREEN_HEIGHT/2 - 165;
    filled_rect.w = 124;
    filled_rect.h = 80;
    SDL_SetRenderDrawColor(renderer1, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer1,&filled_rect);

}
int main(int argc, char* argv[])
{
    srand(time(NULL));
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
    SDL_Rect dstrect = { 20*(left_margin+1)+55, SCREEN_HEIGHT/2 - 165, 90, 18 };
    SDL_RenderCopy(renderer1, texture, NULL, &dstrect);
    //hien thi high score
    fstream f;
    f.open("high_score.txt",ios::in);
    string data;
    getline(f, data);
    int num = stoi(data);
    const char *highScore = data.c_str();
    color = {255,255,255};
    surface = TTF_RenderText_Solid(font,highScore, color);
    texture = SDL_CreateTextureFromSurface(renderer1, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    if(num < 10 )
    {
        dstrect = { 20*(left_margin+1)+97-6,  SCREEN_HEIGHT/2 - 145, 10, 19 };
    }
    else if(num < 100)
    {
        dstrect = { 20*(left_margin+1)+97-13,  SCREEN_HEIGHT/2 - 145, 20, 19 };
    }
    else
    {
        dstrect = { 20*(left_margin+1)+97-18,  SCREEN_HEIGHT/2 - 145, 30, 19 };
    }
    SDL_RenderCopy(renderer1, texture, NULL, &dstrect);

    //ghi lai score vao file
    f << data;
    f.close();
    //ve nut PLAY
    SDL_Rect filled_rect;
    filled_rect.x = 20*(left_margin+1)+60;
    filled_rect.y = SCREEN_HEIGHT/2 - 40;
    filled_rect.w = 80;
    filled_rect.h = 40;
    SDL_SetRenderDrawColor(renderer1, 0,0,0,0);
    SDL_RenderFillRect(renderer1,&filled_rect);
    //vien nut
    filled_rect.x = 20*(left_margin+1)+60;
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
    dstrect = { 20*(left_margin+1)+64, SCREEN_HEIGHT/2 - 38, 72, 32 };
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
            bool checkk = (e1.button.x >= 20*(left_margin+1)+60 && e1.button.x <= 20*(left_margin+1)+60+80 &&
                           e1.button.y >= SCREEN_HEIGHT/2 - 40 && e1.button.y <= SCREEN_HEIGHT/2);
            if(checkk)
            {
                SDL_Rect rect;
                rect.x = 20*(left_margin+1)+60;
                rect.y = SCREEN_HEIGHT/2 - 40;
                rect.w = 80;
                rect.h = 40;
                SDL_SetRenderDrawColor(renderer1, 0, 0, 0, 0);
                SDL_RenderDrawRect(renderer1,&rect);
                SDL_RenderPresent(renderer1);
                SDL_Delay(50);
                play = true;
                SDL_RenderClear(renderer1);
                break;
            }
            else continue;
        }
    }
    if(play == true)
    {
        quitSDL(window1, renderer1);
        playGame();
    }

    return 0;
}
