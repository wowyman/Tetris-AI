#include <iostream>
#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "gach.h"
using namespace std;
const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 620;
int k,score = 0,diem=0;
int board_game[31][42];
void init(int &le_trai,int &le_phai)
{
    for(int i=0; i<30; i++)
    {
        for(int j=1; j<41; j++)
        {
            board_game[i][j] = 0;
        }
    }
    for(int i=0; i<31; i++)
    {
        board_game[i][le_trai] = -1;
        board_game[i][le_phai] = -1;
    }
    for(int i=1; i<=40; i++)
    {
        board_game[30][i] = -1;
    }
}
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
bool la_o_thanh_phan(gach &box,point E,point &A,point &B,point &C,point &D)//kiem tra o nhan vao co la 1 trong 4 o cua khoi gach khong, neu co tra ve true ,khong tra ve false
{
    bool check = ((E.x == A.x && E.y == A.y) || (E.x == B.x && E.y == B.y )|| (E.x == C.x && E.y == C.y) || (E.x == D.x && E.y == D.y) );

    return check;
}
bool IsMove(gach &box,point &A,point &B,point &C,point &D,int huong)//huong: 0 la xuong,1 la sang trai,2 la sang phai
{
    point a,b,c,d;
    bool check=true,check1=true,check2=true,check3=true,check4=true;
    if(huong == 0)
    {
        a.x = A.x + 1;
        a.y = A.y;
        b.x = B.x + 1;
        b.y = B.y;
        c.x = C.x + 1;
        c.y = C.y;
        d.x = D.x + 1;
        d.y = D.y;
    }
    else if(huong == 1)
    {
        a.x = A.x;
        a.y = A.y - 1;
        b.x = B.x;
        b.y = B.y - 1;
        c.x = C.x;
        c.y = C.y - 1;
        d.x = D.x;
        d.y = D.y - 1;
    }
    else if(huong == 2)
    {
        a.x = A.x;
        a.y = A.y + 1;
        b.x = B.x;
        b.y = B.y + 1;
        c.x = C.x;
        c.y = C.y + 1;
        d.x = D.x;
        d.y = D.y + 1;
    }

    if(la_o_thanh_phan(box,a,A,B,C,D)== true)
    {
        check1=true;
    }
    else
    {
        if(board_game[a.x][a.y]==-1 || board_game[a.x][a.y] == 1)
        {
            check1 = false;
        }
        if(board_game[a.x][a.y]==0)
        {
            check1 = true;
        }
    }
    if(la_o_thanh_phan(box,b,A,B,C,D)== true)
    {

        check2=true;
    }
    else
    {
        if(board_game[b.x][b.y]==-1 || board_game[b.x][b.y] == 1)
        {
            check2 = false;
        }

        if(board_game[b.x][b.y]==0)
        {
            check2 = true;
        }

    }
    if(la_o_thanh_phan(box,c,A,B,C,D)== true)
    {
        check3=true;
    }

    else
    {
        if(board_game[c.x][c.y]==-1 || board_game[c.x][c.y] == 1)
        {
            check3 = false;
        }
        if(board_game[c.x][c.y]==0)
        {
            check3 = true;
        }
    }
    if(la_o_thanh_phan(box,d,A,B,C,D)== true)
    {
        check4=true;
    }
    else
    {
        if(board_game[d.x][d.y]==-1 || board_game[d.x][d.y] == 1)
        {
            check4 = false;
        }
        if(board_game[d.x][d.y]==0)
        {
            check4 = true;
        }
    }
    check = (check1 && check2 && check3 && check4);
    return check;
}
void xoay(SDL_Renderer *renderer,gach &box,int &k,point &A,point &B,point &C,point &D)
{
    if(box.type == 1 || box.type == 2 || box.type == 5 )
    {
        int Xtemp=A.x;
        A.x=-A.y+box.tam.x+box.tam.y;
        A.y=Xtemp-box.tam.x+box.tam.y;

        Xtemp=B.x;
        B.x=-B.y+box.tam.x+box.tam.y;
        B.y=Xtemp-box.tam.x+box.tam.y;

        Xtemp=C.x;
        C.x=-C.y+box.tam.x+box.tam.y;
        C.y=Xtemp-box.tam.x+box.tam.y;

        Xtemp=D.x;
        D.x=-D.y+box.tam.x+box.tam.y;
        D.y=Xtemp-box.tam.x+box.tam.y;
    }
    else if(box.type == 3 || box.type == 4 || box.type == 7)
    {
        if(k % 2 == 1)
        {
            int Xtemp=A.x;
            A.x=-A.y+box.tam.x+box.tam.y;
            A.y=Xtemp-box.tam.x+box.tam.y;

            Xtemp=B.x;
            B.x=-B.y+box.tam.x+box.tam.y;
            B.y=Xtemp-box.tam.x+box.tam.y;

            Xtemp=C.x;
            C.x=-C.y+box.tam.x+box.tam.y;
            C.y=Xtemp-box.tam.x+box.tam.y;

            Xtemp=D.x;
            D.x=-D.y+box.tam.x+box.tam.y;
            D.y=Xtemp-box.tam.x+box.tam.y;
        }
        if(k % 2 == 0 && k > 0)
        {
            int Xtemp=A.x;
            A.x=A.y+box.tam.x-box.tam.y;
            A.y=-Xtemp+box.tam.x+box.tam.y;

            Xtemp=B.x;
            B.x=B.y+box.tam.x-box.tam.y;
            B.y=-Xtemp+box.tam.x+box.tam.y;

            Xtemp=C.x;
            C.x=C.y+box.tam.x-box.tam.y;
            C.y=-Xtemp+box.tam.x+box.tam.y;

            Xtemp=D.x;
            D.x=D.y+box.tam.x-box.tam.y;
            D.y=-Xtemp+box.tam.x+box.tam.y;
        }
    }
    else if(box.type == 6);
}
void getABCD(gach &box,point &A,point &B,point &C,point &D)
{

    if(box.type == 1)
    {
        A.x = box.tam.x - 1;
        A.y = box.tam.y - 1;
        B.x = box.tam.x;
        B.y = box.tam.y - 1;
        C.x = box.tam.x + 1;
        C.y = box.tam.y - 1;
        D.x = box.tam.x + 1;
        D.y = box.tam.y;

    }
    if(box.type == 2)
    {
        A.x = box.tam.x - 1;
        A.y = box.tam.y + 1;
        B.x = box.tam.x;
        B.y = box.tam.y +1;
        C.x = box.tam.x + 1;
        C.y = box.tam.y + 1;
        D.x = box.tam.x + 1;
        D.y = box.tam.y;

    }
    if(box.type == 3)
    {
        A.x = box.tam.x + 1;
        A.y = box.tam.y - 1;
        B.x = box.tam.x + 1;
        B.y = box.tam.y;
        C.x = box.tam.x ;
        C.y = box.tam.y;
        D.x = box.tam.x;
        D.y = box.tam.y+1;

    }
    if(box.type == 4)
    {
        A.x = box.tam.x;
        A.y = box.tam.y - 1;
        B.x = box.tam.x;
        B.y = box.tam.y;
        C.x = box.tam.x + 1;
        C.y = box.tam.y;
        D.x = box.tam.x + 1;
        D.y = box.tam.y + 1;

    }
    if(box.type == 5)
    {
        A.x = box.tam.x - 1;
        A.y = box.tam.y;
        B.x = box.tam.x;
        B.y = box.tam.y - 1;
        C.x = box.tam.x;
        C.y = box.tam.y;
        D.x = box.tam.x;
        D.y = box.tam.y + 1;

    }
    if(box.type == 6)
    {
        A.x = box.tam.x;
        A.y = box.tam.y;
        B.x = box.tam.x;
        B.y = box.tam.y + 1;
        C.x = box.tam.x + 1;
        C.y = box.tam.y;
        D.x = box.tam.x + 1;
        D.y = box.tam.y + 1;

    }
    if(box.type == 7)
    {
        A.x = box.tam.x - 2;
        A.y = box.tam.y;
        B.x = box.tam.x - 1;
        B.y = box.tam.y ;
        C.x = box.tam.x;
        C.y = box.tam.y;
        D.x = box.tam.x + 1;
        D.y = box.tam.y;
    }
}
void turnLeft(gach &box,point &A,point &B,point &C,point &D,int &b)
{
    if(IsMove(box,A,B,C,D,1))
    {
        b --;
        box.tam.y -= 1;
        A.y -= 1;
        B.y -= 1;
        C.y -= 1;
        D.y -= 1;
    }
    else;
}
void turnRight(gach &box,point &A,point &B,point &C,point &D,int &b)
{
    if(IsMove(box,A,B,C,D,2))
    {
        b ++;
        box.tam.y += 1;
        A.y += 1;
        B.y += 1;
        C.y += 1;
        D.y += 1;
    }
    else;
}
void goDown(gach &box,point &A,point &B,point &C,point &D,int &a)
{
    int v=1;
    a+=v;
    box.tam.x += v;
    A.x += v;
    B.x += v;
    C.x += v;
    D.x += v;
}
void ve_le(SDL_Renderer *renderer,gach &box)
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = (SCREEN_WIDTH-10*box.size)/2 ;
    rect.h = SCREEN_HEIGHT;
    SDL_SetRenderDrawColor(renderer, 123, 234, 100, 200);
    SDL_RenderFillRect(renderer, &rect);

    SDL_Rect rect2;
    rect2.x = SCREEN_WIDTH-(SCREEN_WIDTH-10*box.size)/2;
    rect2.y = 0;
    rect2.w = (SCREEN_WIDTH-10*box.size)/2;
    rect2.h = SCREEN_HEIGHT;
    SDL_SetRenderDrawColor(renderer, 123, 234, 100, 200);
    SDL_RenderFillRect(renderer, &rect2);

    SDL_Rect rect3;
    rect3.x = (SCREEN_WIDTH-10*box.size)/2 ;
    rect3.y = SCREEN_HEIGHT-box.size;
    rect3.w = 10*box.size;
    rect3.h = box.size;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &rect3);
    SDL_Rect rect4[10];
    for(int i=0; i<10; i++)
    {
        rect4[i].x = (SCREEN_WIDTH-10*box.size)/2 + i*box.size;
        rect4[i].y = SCREEN_HEIGHT-box.size;
        rect4[i].w = box.size;
        rect4[i].h = box.size;
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawRect(renderer, &rect4[i]);
    }

}
bool inside(SDL_Renderer *renderer,gach box,point A,point B,point C,point D)
{
    xoay(renderer,box,k,A,B,C,D);
    int le_trai = ((SCREEN_WIDTH-10*box.size)/2)/box.size;
    int le_phai = le_trai+9;
    bool checkA = (A.y <= le_phai && A.y >= le_trai);
    bool checkB = (B.y <= le_phai && B.y >= le_trai);
    bool checkC = (C.y <= le_phai && C.y >= le_trai);
    bool checkD = (D.y <= le_phai && D.y >= le_trai);
    bool check = (checkA && checkB && checkC && checkD);
    //cout<<checkA<<","<<checkB<<","<<checkC<<","<<checkD<<endl;
    return check;
}
void co_dinh_gach(point A,point B,point C,point D)
{
    board_game[A.x][A.y] = 1;
    board_game[B.x][B.y] = 1;
    board_game[C.x][C.y] = 1;
    board_game[D.x][D.y] = 1;
}
void ve_gach_da_co_dinh(SDL_Renderer *renderer,gach &box)
{
    for(int i=1; i<30; i++)
    {
        for(int j=1; j<41; j++)
        {
            if(board_game[i][j] == 1)
            {
                SDL_Rect rect;
                rect.x = j*box.size;
                rect.y = i*box.size;
                rect.h = box.size;
                rect.w = box.size;
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
}
//void lui_dong_cu(SDL_Renderer *renderer,gach &box)
//{
//    int le_trai = ((SCREEN_WIDTH-10*box.size)/2)/box.size;
//    int le_phai = le_trai+9;
//    int count1=0,count2=0,count3=0,count4=0;
//    for(int i=le_trai; i<=le_phai; i++)
//    {
//        if(board_game[29][i] == 1)
//            count1++;
//        if(board_game[28][i] == 1)
//            count2++;
//        if(board_game[27][i] == 1)
//            count3++;
//        if(board_game[26][i] == 1)
//            count4++;
//    }
//    cout<<count1<<","<<count2<<","<<count3<<","<<count4<<" ";
//    if(count4 == 10)
//    {
//        for(int i=29; i>= 4; i--)
//        {
//            for(int j=le_trai; j<=le_phai; j++)
//            {
//                board_game[i][j] = board_game[i-4][j];
//            }
//        }
//        for(int i=0; i<4; i++)
//        {
//            for(int j=le_trai; j<=le_phai; j++)
//            {
//                board_game[i][j] = 0;
//            }
//        }
//        score+=40;
//    }
//    if(count3 == 10 && count4 <10)
//    {
//        for(int i=29; i>= 3; i--)
//        {
//            for(int j=le_trai; j<=le_phai; j++)
//            {
//                board_game[i][j] = board_game[i-3][j];
//            }
//        }
//        for(int i=0; i<3; i++)
//        {
//            for(int j=le_trai; j<=le_phai; j++)
//            {
//                board_game[i][j] = 0;
//            }
//        }
//        score+=30;
//    }
//    if(count2 == 10 && count4 <10 && count3 <10)
//    {
//        for(int i=29; i>= 2; i--)
//        {
//            for(int j=le_trai; j<=le_phai; j++)
//            {
//                board_game[i][j] = board_game[i-2][j];
//            }
//        }
//        for(int i=0; i<2; i++)
//        {
//            for(int j=le_trai; j<=le_phai; j++)
//            {
//                board_game[i][j] = 0;
//            }
//        }
//        score+=20;
//    }
//    if(count1 == 10 && count4 <10 && count3 <10 && count2<10)
//    {
//        for(int i=29; i>= 1; i--)
//        {
//            for(int j=le_trai; j<=le_phai; j++)
//            {
//                board_game[i][j] = board_game[i-1][j];
//            }
//        }
//        for(int i=0; i<1; i++)
//        {
//            for(int j=le_trai; j<=le_phai; j++)
//            {
//                board_game[i][j] = 0;
//            }
//        }
//        score+=10;
//    }
//    cout<<score<<endl;
//    ve_gach_da_co_dinh(renderer,box);
//}
void lui_dong(SDL_Renderer *renderer,gach &box)
{
    int le_trai = ((SCREEN_WIDTH-10*box.size)/2)/box.size;
    int le_phai = le_trai+9;
    int count[30];
    for(int i=0; i<30; i++)
    {
        count[i]=0;
    }
    for(int i=le_trai; i<=le_phai; i++)
    {
        for(int j=0; j<30; j++)
        {
            if(board_game[j][i] == 1)
                count[j]++;
        }
    }
    for(int i = 29; i>=1; i--)
    {
        if(count[i]== 10)
        {
            for(int j=i; j>= 1; j--)
            {
                for(int k=le_trai; k<=le_phai; k++)
                {
                    board_game[j][k] = board_game[j-1][k];
                }
            }
            for(int k=le_trai; k<=le_phai; k++)
            {
                board_game[0][k] = 0;
            }
            diem++;
        }
    }
    score = diem*10;
    cout<<score<<endl;
    ve_gach_da_co_dinh(renderer,box);
}
int main(int argc, char* argv[])
{
    SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool quit = false;
    initSDL(window, renderer);

    point A,B,C,D;

    gach box;
    int a,b;//toa do tam

    a=1;
    b=20;

    box.get_toa_do_Tam(a,b);

    int le_trai = ((SCREEN_WIDTH-10*box.size)/2)/box.size-1;
    int le_phai = le_trai+11;
    init(le_trai,le_phai);

    SDL_Event e;
    int i=0,sig = 0;
    while(true)
    {
        k=0;//dung de quay truong hop 7,3,4
        srand(time(0));

        int random = rand() % 7 + 1;
        box.getType(random);
        box.get_toa_do_Tam(a,b);
        getABCD(box,A,B,C,D);
        while(!quit)
        {

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderClear(renderer);
            goDown(box,A,B,C,D,a);
            ve_le(renderer,box);
            box.render(renderer,A,B,C,D);

            lui_dong(renderer,box);
            ve_gach_da_co_dinh(renderer,box);
            int time_delay = 200;

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
                        turnLeft(box,A,B,C,D,b);
                        break;
                    case SDLK_d:
                        turnRight(box,A,B,C,D,b);
                        break;
                    //case SDLK_s: box.turnDown(); break;
                    case SDLK_w:

                        if(IsMove(box,A,B,C,D,0) && inside(renderer,box,A,B,C,D))
                        {
                            xoay(renderer,box,k,A,B,C,D);
                            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                            SDL_RenderClear(renderer);
                            ve_le(renderer,box);
                            ve_gach_da_co_dinh(renderer,box);
                            box.render(renderer,A,B,C,D);
                            SDL_RenderPresent(renderer);
                            SDL_Delay(time_delay/4);
                            k++;
                        }
                        break;
                    }
                }
            }
//            cout<<A.x<<":"<<A.y<<endl;
            if(i>=1)
            {
                if(!IsMove(box,A,B,C,D,0))
                {
                    co_dinh_gach(A,B,C,D);
                    a=0;
                    b=20;
                    break;
                }
            }
            else
            {
                if(max(A.x,B.x,C.x,D.x)>=29)
                {
                    co_dinh_gach(A,B,C,D);
                    a=0;
                    b=20;
                    break;
                }
            }
        }
        i++;
        if(i>100)
            i=2;
    }
    quitSDL(window, renderer);
    return 0;
}

