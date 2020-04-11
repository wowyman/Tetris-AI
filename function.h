#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 700;
int k=0,score = 0;
int board_game[35][42];
void init(int le_trai,int le_phai)
{
    for(int i=0; i<34; i++)
    {
        for(int j=1; j<41; j++)
        {
            board_game[i][j] = 0;
        }
    }
    for(int i=0; i<35; i++)
    {
        board_game[i][le_trai] = -1;
        board_game[i][le_phai] = -1;
    }
    for(int i=1; i<=40; i++)
    {
        board_game[34][i] = -1;
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
void xoay(SDL_Renderer *renderer,gach& box,int k,point& A,point& B,point& C,point& D)
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
        else if(k % 2 == 0 && k >=2 )
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
void getABCD(gach box,point &A,point &B,point &C,point &D)
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
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect4[i]);
    }
    SDL_Rect rect7;
    rect7.x = (SCREEN_WIDTH-10*box.size)/2 - box.size;
    rect7.y = 3*box.size;
    rect7.w = box.size;
    rect7.h = 39*box.size;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_RenderFillRect(renderer, &rect7);
    rect7.x = (SCREEN_WIDTH-10*box.size)/2 - box.size + 11*box.size;
    rect7.y = 3*box.size;
    rect7.w = box.size;
    rect7.h = 39*box.size;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &rect7);
    SDL_Rect rect5[39];
    SDL_Rect rect6[39];
    for(int i=3; i<=41; i++)
    {
        rect5[i].x = (SCREEN_WIDTH-10*box.size)/2 - box.size;
        rect5[i].y = i*box.size;
        rect5[i].w = box.size;
        rect5[i].h = box.size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect5[i]);
        rect6[i].x = (SCREEN_WIDTH-10*box.size)/2 - box.size + 11*box.size;
        rect6[i].y = i*box.size;
        rect6[i].w = box.size;
        rect6[i].h = box.size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect6[i]);
    }
}
void ve_le2(SDL_Renderer *renderer,gach &box)
{
    SDL_Rect rect5;
    rect5.x = (SCREEN_WIDTH-10*box.size)/2 ;
    rect5.y = 0;
    rect5.w = 10*box.size;
    rect5.h = 3*box.size;
    SDL_SetRenderDrawColor(renderer, 123, 234, 100, 200);
    SDL_RenderFillRect(renderer, &rect5);
    SDL_Rect rect3;
    rect3.x = (SCREEN_WIDTH-10*box.size)/2 ;
    rect3.y = 3*box.size;
    rect3.w = 10*box.size;
    rect3.h = box.size;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &rect3);
    SDL_Rect rect4[10];
    for(int i=0; i<10; i++)
    {
        rect4[i].x = (SCREEN_WIDTH-10*box.size)/2 + i*box.size;
        rect4[i].y = 3*box.size;
        rect4[i].w = box.size;
        rect4[i].h = box.size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect4[i]);
    }

}
bool inside(SDL_Renderer *renderer,gach &box,point A,point B,point C,point D)
{
    xoay(renderer,box,1,A,B,C,D);
    int le_trai = ((SCREEN_WIDTH-10*box.size)/2)/box.size;
    int le_phai = le_trai+9;
    bool checkA = (A.y <= le_phai && A.y >= le_trai && board_game[A.x][A.y] == 0);
    bool checkB = (B.y <= le_phai && B.y >= le_trai && board_game[B.x][B.y] == 0);
    bool checkC = (C.y <= le_phai && C.y >= le_trai && board_game[C.x][C.y] == 0);
    bool checkD = (D.y <= le_phai && D.y >= le_trai && board_game[D.x][D.y] == 0);
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
    for(int i=2; i<34; i++)
    {
        for(int j=16; j<=25; j++)
        {
            if(board_game[i][j] == 1)
            {
                SDL_Rect rect;
                rect.x = j*box.size;
                rect.y = i*box.size;
                rect.h = box.size;
                rect.w = box.size;
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
                SDL_RenderDrawLine(renderer,j*box.size,i*box.size,j*box.size+box.size,i*box.size);
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
                SDL_RenderDrawLine(renderer,j*box.size+box.size,i*box.size,j*box.size+box.size,i*box.size+box.size);
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
                SDL_RenderDrawLine(renderer,j*box.size+box.size,i*box.size+box.size,j*box.size,i*box.size+box.size);
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
                SDL_RenderDrawLine(renderer,j*box.size,i*box.size+box.size,j*box.size,i*box.size);
            }
        }
    }
}

void lui_dong(SDL_Renderer *renderer,gach &box)
{
    int le_trai = ((SCREEN_WIDTH-10*box.size)/2)/box.size;
    int le_phai = le_trai+9;
    int count[34];
    for(int i=0; i<34; i++)
    {
        count[i]=0;
    }
    for(int i=le_trai; i<=le_phai; i++)
    {
        for(int j=4; j<34; j++)
        {
            if(board_game[j][i] == 1)
                count[j]++;
        }
    }
    for(int i = 34; i>=5;)
    {
        if(count[i]== 10)
        {
            for(int j=i; j>=4; j--)
            {
                for(int k=le_trai; k<=le_phai; k++)
                {
                    board_game[j][k] = board_game[j-1][k];
                    board_game[4][k]=0;
                }
                count[j]=count[j-1];
                count[4]=0;
            }
            score+=10;
        }
        else i--;
    }
    //cout<<score<<endl;
    ve_gach_da_co_dinh(renderer,box);
}

bool end_game(gach &box)
{
    int le_trai = ((SCREEN_WIDTH-10*box.size)/2)/box.size;
    int le_phai = le_trai+9;
    for(int i=le_trai; i<=le_phai; i++)
    {
        if(board_game[4][i] == 1)
            return true;
    }
    return false;
}
//void nhap_nhay(SDL_Renderer *renderer,gach box, point A, point B, point C, point D)
//{
//    int time = 50;
//    SDL_Rect rect;
//    for(int i=0; i<time; i++)
//    {
//        rect.x = A.y*box.size;
//        rect.y = A.x*box.size;
//        rect.w = box.size;
//        rect.h = box.size;
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//        SDL_RenderDrawRect(renderer, &rect);
//        rect.x = B.y*box.size;
//        rect.y = B.x*box.size;
//        rect.w = box.size;
//        rect.h = box.size;
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//        SDL_RenderDrawRect(renderer, &rect);
//        rect.x = C.y*box.size;
//        rect.y = C.x*box.size;
//        rect.w = box.size;
//        rect.h = box.size;
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//        SDL_RenderDrawRect(renderer, &rect);
//        rect.x = D.y*box.size;
//        rect.y = D.x*box.size;
//        rect.w = box.size;
//        rect.h = box.size;
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//        SDL_RenderDrawRect(renderer, &rect);
//
//        SDL_RenderPresent(renderer);
//        box.render(renderer,A,B,C,D);
//        SDL_RenderPresent(renderer);
//    }
//}
void khoi_gach_tiep_theo(gach box,SDL_Renderer *renderer,int hinh_truoc)
{
    SDL_Rect rect;
    rect.x = 29*box.size;
    rect.y = 4*box.size;
    rect.w = 5*box.size;
    rect.h = 6*box.size;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer,&rect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,29*box.size,4*box.size,34*box.size,4*box.size);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,34*box.size,4*box.size,34*box.size,10*box.size);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,29*box.size,10*box.size,34*box.size,10*box.size);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,29*box.size,4*box.size,29*box.size,10*box.size);
    point a,b,c,d;
    box.get_toa_do_Tam(7,31);
    box.getType(hinh_truoc);
    getABCD(box,a,b,c,d);
    box.render(renderer,a,b,c,d);

}
void print_score(gach box,SDL_Renderer *renderer,SDL_Surface *surface, SDL_Texture * texture,TTF_Font * font)
{

    SDL_Rect rect;
    rect.x = 29*box.size;
    rect.y = 11*box.size;
    rect.w = 5*box.size;
    rect.h = 6*box.size;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer,&rect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,29*box.size,11*box.size,34*box.size,11*box.size);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,34*box.size,11*box.size,34*box.size,17*box.size);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,29*box.size,17*box.size,34*box.size,17*box.size);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,29*box.size,11*box.size,29*box.size,17*box.size);

    SDL_Color color = { 255, 0, 255 };
    surface = TTF_RenderText_Solid(font,"SCORE", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 290*2, 110*2, 60, 20 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);
}
void printScore(SDL_Renderer *renderer,int number)
{
    SDL_Rect rect = { 29*20, 20*11, 5*20, 6*20};
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderFillRect(renderer,&rect);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,29*20,11*20,34*20,11*20);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,34*20,11*20,34*20,17*20);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,29*20,17*20,34*20,17*20);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,29*20,11*20,29*20,17*20);
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("vgafix.fon", 80);
    SDL_Color color = { 255, 0, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,
                            "SCORE", color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 300*2, 120*2, 60, 20 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    color = { 255, 0, 255 };
    string s = to_string(number);
    const char *diem = s.c_str();
    surface = TTF_RenderText_Solid(font,diem, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    if(number == 0)
    {
        dstrect = { 313*2, 140*2, 10, 20 };
    }
    else if(number < 100 )
    {
        dstrect = { 310*2, 140*2, 20, 20 };
    }
    else if(number < 1000)
    {
        dstrect = { 305*2, 140*2, 30, 20 };
    }
    else
    {
        dstrect = { 305*2, 140*2, 40, 20 };
    }
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);


}
void printEndgame(SDL_Renderer *renderer,int number)
{
    SDL_Rect rect = { 15*20, 11*20, 12*20, 6*20};
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderFillRect(renderer,&rect);
    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawLine(renderer,15*20+2,11*20+2,27*20-2,11*20+2);
    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawLine(renderer,27*20-2,11*20+2,27*20-2,17*20-2);
    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawLine(renderer,15*20+2,17*20-2,27*20-2,17*20-2);
    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawLine(renderer,15*20+2,11*20+2,15*20+2,17*20-2);

    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawLine(renderer,16*20-10,12*20-10,26*20+10,12*20-10);
    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawLine(renderer,26*20+10,12*20-10,26*20+10,16*20+10);
    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawLine(renderer,16*20-10,16*20+10,26*20+10,16*20+10);
    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawLine(renderer,16*20-10,12*20-10,16*20-10,16*20+10);

    TTF_Init();
    TTF_Font * font = TTF_OpenFont("vgafix.fon", 80);
    SDL_Color color = { 255, 0, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font," YOU LOSE!", color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 19*20, 120*2-10, 80, 19 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    surface = TTF_RenderText_Solid(font,"SCORE", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = {20*20, 130*2-8, 45, 19 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    string s = to_string(number);
    const char *diem = s.c_str();
    surface = TTF_RenderText_Solid(font,diem, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    if(number == 0)
    {
        dstrect = { 21*20-2, 140*2-6, 10, 19 };
    }
    else if(number < 100 )
    {
        dstrect = { 21*20-8, 140*2-6, 20, 19 };
    }
    else if(number < 1000)
    {
        dstrect = { 21*20-13, 140*2-6, 30, 19 };
    }
    else
    {
        dstrect = { 21*20-18, 140*2-6, 40, 19 };
    }
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    surface = TTF_RenderText_Solid(font," PLAY AGAIN ? (Y/N)", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = { 17*20+5, 150*2, 140, 19 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}
