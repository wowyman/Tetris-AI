#include <iostream>
using namespace std;

int score = 0;
//int k=0;
const int height = 29;
const int width = 34;
int count_dark = -1;
bool run_AI = false;
bool dark = false;
const int SCREEN_WIDTH = width*20;
const int SCREEN_HEIGHT = height*20;
int left_margin = (width - 10)/2 -1;
int right_margin = left_margin + 11;
int board_game[height][width];

int a,b;//toa do tam
brick box;



void init()//khoi tao mang luu ban choi
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            board_game[i][j] = -1;
        }
    }
    for(int i=0; i<height-1; i++)
    {
        for(int j= left_margin+1; j<=right_margin-1; j++)
        {
            board_game[i][j] = 0;
        }
    }

}
bool Is_part_of_brick(brick &box,point E,point &A,point &B,point &C,point &D)//kiem tra o nhan vao co la 1 trong 4 o cua khoi gach khong, neu co tra ve true ,khong tra ve false
{
    bool check = ((E.x == A.x && E.y == A.y) || (E.x == B.x && E.y == B.y )|| (E.x == C.x && E.y == C.y) || (E.x == D.x && E.y == D.y) );

    return check;
}
bool IsMove(brick &box,point &A,point &B,point &C,point &D,int direction)//direction: 0 la xuong,1 la sang trai,2 la sang phai
{
    //dung de kiem tra co di chuyen theo huong dc khong
    point a,b,c,d;
    bool check=true,check1=true,check2=true,check3=true,check4=true;

    if(direction == 0)
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
    else if(direction == 1)
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
    else if(direction == 2)
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

    if(Is_part_of_brick(box,a,A,B,C,D)== true)
    {
        check1=true;
    }
    else
    {
        if(board_game[a.x][a.y]==-1 || board_game[a.x][a.y] == 1 || board_game[a.x][a.y] == 2 || board_game[a.x][a.y] == 3 || board_game[a.x][a.y] == 4 || board_game[a.x][a.y] == 5||board_game[a.x][a.y] == 6|| board_game[a.x][a.y] == 7)
        {
            check1 = false;
        }
        if(board_game[a.x][a.y]==0)
        {
            check1 = true;
        }
    }
    if(Is_part_of_brick(box,b,A,B,C,D)== true)
    {

        check2=true;
    }
    else
    {
        if(board_game[b.x][b.y]==-1 || board_game[b.x][b.y] == 1|| board_game[b.x][b.y] == 2|| board_game[b.x][b.y] == 3 || board_game[b.x][b.y] == 4 || board_game[b.x][b.y] == 5 || board_game[b.x][b.y] == 6 || board_game[b.x][b.y] == 7)
        {
            check2 = false;
        }

        if(board_game[b.x][b.y]==0)
        {
            check2 = true;
        }

    }
    if(Is_part_of_brick(box,c,A,B,C,D)== true)
    {
        check3=true;
    }

    else
    {
        if(board_game[c.x][c.y]==-1 || board_game[c.x][c.y] == 1|| board_game[c.x][c.y] == 2|| board_game[c.x][c.y] == 3|| board_game[c.x][c.y] == 4|| board_game[c.x][c.y] == 5|| board_game[c.x][c.y] == 6|| board_game[c.x][c.y] == 7)
        {
            check3 = false;
        }
        if(board_game[c.x][c.y]==0)
        {
            check3 = true;
        }
    }
    if(Is_part_of_brick(box,d,A,B,C,D)== true)
    {
        check4=true;
    }
    else
    {
        if(board_game[d.x][d.y]==-1 || board_game[d.x][d.y] == 1|| board_game[d.x][d.y] == 2|| board_game[d.x][d.y] == 3|| board_game[d.x][d.y] == 4|| board_game[d.x][d.y] == 5|| board_game[d.x][d.y] == 6|| board_game[d.x][d.y] == 7)
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

void rotate(brick& box,point& A,point& B,point& C,point& D)
{
    int Xtemp=A.x;
    A.x=-A.y+box.center.x+box.center.y;
    A.y=Xtemp-box.center.x+box.center.y;

    Xtemp=B.x;
    B.x=-B.y+box.center.x+box.center.y;
    B.y=Xtemp-box.center.x+box.center.y;

    Xtemp=C.x;
    C.x=-C.y+box.center.x+box.center.y;
    C.y=Xtemp-box.center.x+box.center.y;

    Xtemp=D.x;
    D.x=-D.y+box.center.x+box.center.y;
    D.y=Xtemp-box.center.x+box.center.y;


}
void shape_of_you(brick box,point &A,point &B,point &C,point &D)//khoi tao hinh dang khoi gach bang toa do 4 o gach
{
    if(box.type == 1)//L
    {
        A.x = box.center.x - 1;
        A.y = box.center.y;
        B.x = box.center.x;
        B.y = box.center.y;
        C.x = box.center.x + 1;
        C.y = box.center.y;
        D.x = box.center.x + 1;
        D.y = box.center.y + 1;
    }
    if(box.type == 2)//J
    {
        A.x = box.center.x - 1;
        A.y = box.center.y ;
        B.x = box.center.x;
        B.y = box.center.y;
        C.x = box.center.x + 1;
        C.y = box.center.y;
        D.x = box.center.x + 1;
        D.y = box.center.y - 1;
    }
    if(box.type == 3)//Z
    {
        A.x = box.center.x + 1;
        A.y = box.center.y - 1;
        B.x = box.center.x + 1;
        B.y = box.center.y;
        C.x = box.center.x ;
        C.y = box.center.y;
        D.x = box.center.x;
        D.y = box.center.y+1;
    }
    if(box.type == 4)//S
    {
        A.x = box.center.x;
        A.y = box.center.y - 1;
        B.x = box.center.x;
        B.y = box.center.y;
        C.x = box.center.x + 1;
        C.y = box.center.y;
        D.x = box.center.x + 1;
        D.y = box.center.y + 1;
    }
    if(box.type == 5)//T
    {
        A.x = box.center.x - 1;
        A.y = box.center.y;
        B.x = box.center.x;
        B.y = box.center.y - 1;
        C.x = box.center.x;
        C.y = box.center.y;
        D.x = box.center.x;
        D.y = box.center.y + 1;
    }
    if(box.type == 6)//O
    {
        A.x = box.center.x;
        A.y = box.center.y;
        B.x = box.center.x;
        B.y = box.center.y + 1;
        C.x = box.center.x + 1;
        C.y = box.center.y;
        D.x = box.center.x + 1;
        D.y = box.center.y + 1;
    }
    if(box.type == 7)//I
    {
        A.x = box.center.x - 2;
        A.y = box.center.y;
        B.x = box.center.x - 1;
        B.y = box.center.y ;
        C.x = box.center.x;
        C.y = box.center.y;
        D.x = box.center.x + 1;
        D.y = box.center.y;
    }
}
void turnLeft(brick &box,point &A,point &B,point &C,point &D,int &b)
{
    if(IsMove(box,A,B,C,D,1))
    {
        b --;
        box.center.y -= 1;
        A.y -= 1;
        B.y -= 1;
        C.y -= 1;
        D.y -= 1;
    }
    else;
}
void turnRight(brick &box,point &A,point &B,point &C,point &D,int &b)
{
    if(IsMove(box,A,B,C,D,2))
    {
        b ++;
        box.center.y += 1;
        A.y += 1;
        B.y += 1;
        C.y += 1;
        D.y += 1;
    }
    else;
}
void goDown(brick &box,point &A,point &B,point &C,point &D,int &a,SDL_Renderer *renderer)//di xuong
{
    if(IsMove(box,A,B,C,D,0))
    {
        a+=1;
        box.center.x -= 1;
        A.x += 1;
        B.x += 1;
        C.x += 1;
        D.x += 1;
    }
    else;
}
void Print_Background(SDL_Renderer *renderer)//ve nen ban choi
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = (SCREEN_WIDTH-10*20)/2 ;
    rect.h = SCREEN_HEIGHT;
    SDL_SetRenderDrawColor(renderer, 191,201,217,0);
    SDL_RenderFillRect(renderer, &rect);

    SDL_Rect rect2;
    rect2.x = SCREEN_WIDTH-(SCREEN_WIDTH-10*20)/2+1;
    rect2.y = 0;
    rect2.w = (SCREEN_WIDTH-10*20)/2;
    rect2.h = SCREEN_HEIGHT;
    SDL_SetRenderDrawColor(renderer, 191,201,217,0);
    SDL_RenderFillRect(renderer, &rect2);

    SDL_Rect rect3;
    rect3.x = (SCREEN_WIDTH-10*20)/2 ;
    rect3.y = SCREEN_HEIGHT-20+1;
    rect3.w = 10*20 + 1;
    rect3.h = 20;
    SDL_SetRenderDrawColor(renderer,191,201,217,0);
    SDL_RenderFillRect(renderer, &rect3);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    rect.x = 15;
    rect.y = 15;
    rect.w = SCREEN_WIDTH - 30;
    rect.h = SCREEN_HEIGHT - 30;
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderDrawRect(renderer,&rect);
    SDL_Rect rect5;
    rect5.x = (SCREEN_WIDTH-10*20)/2 ;
    rect5.y = 0;
    rect5.w = 10*20+1;
    rect5.h = 4*20;
    SDL_SetRenderDrawColor(renderer, 191,201,217,0);
    SDL_RenderFillRect(renderer, &rect5);

    TTF_Init();
    TTF_Font * font = TTF_OpenFont("vgafix.fon", 500);
    SDL_Color color = { 255,0, 255};
    SDL_Surface * surface = TTF_RenderText_Solid(font,
                            "TETRIS", color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { (left_margin-1)*20, 0, 14*20, 3*20 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}

bool inside(SDL_Renderer *renderer,brick &box,point A,point B,point C,point D)// kiem tra neu xoay thi khoi gach co ra ngoai ban choi khong
{
    rotate(box,A,B,C,D);
    int le_trai1 = ((SCREEN_WIDTH-10*box.size)/2)/box.size;
    int le_phai1 = le_trai1+9;
    bool checkA = (A.y <= le_phai1 && A.y >= le_trai1 && board_game[A.x][A.y] == 0);
    bool checkB = (B.y <= le_phai1 && B.y >= le_trai1 && board_game[B.x][B.y] == 0);
    bool checkC = (C.y <= le_phai1 && C.y >= le_trai1 && board_game[C.x][C.y] == 0);
    bool checkD = (D.y <= le_phai1 && D.y >= le_trai1 && board_game[D.x][D.y] == 0);
    bool check = (checkA && checkB && checkC && checkD);
    return check;
}
void Fixed_Block(point A,point B,point C,point D,brick &box)//co dinh gach khi no dung lai
{

    board_game[A.x][A.y] = box.type;
    board_game[B.x][B.y] = box.type;
    board_game[C.x][C.y] = box.type;
    board_game[D.x][D.y] = box.type;
}
void Print_Fixed_Block(SDL_Renderer *renderer,brick &box)//ve gach da co dinh
{
    for(int i=2; i<height-1; i++)
    {
        for(int j=left_margin+1; j<=right_margin-1; j++)
        {
            if(board_game[i][j] != 0)
            {
                if(board_game[i][j] == 1)
                    SDL_SetRenderDrawColor(renderer, 39, 200, 0, 0);
                else if (board_game[i][j] == 2)
                    SDL_SetRenderDrawColor(renderer, 254,245, 6, 0);
                else if (board_game[i][j] == 3)
                    SDL_SetRenderDrawColor(renderer,0, 145, 222, 0);
                else if (board_game[i][j] == 4)
                    SDL_SetRenderDrawColor(renderer, 239, 165, 4, 0);
                else if (board_game[i][j] == 5)
                    SDL_SetRenderDrawColor(renderer, 3, 135, 68,0);
                else if (board_game[i][j] == 6)
                    SDL_SetRenderDrawColor(renderer,196, 13, 241, 0);
                else
                    SDL_SetRenderDrawColor(renderer, 247, 15, 3, 0);
                SDL_Rect rect;
                rect.x = j*box.size;
                rect.y = i*box.size;
                rect.h = box.size;
                rect.w = box.size;
                SDL_RenderFillRect(renderer, &rect);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
                SDL_RenderDrawLine(renderer,j*box.size,i*box.size,j*box.size+box.size,i*box.size);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
                SDL_RenderDrawLine(renderer,j*box.size+box.size,i*box.size,j*box.size+box.size,i*box.size+box.size);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
                SDL_RenderDrawLine(renderer,j*box.size+box.size,i*box.size+box.size,j*box.size,i*box.size+box.size);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
                SDL_RenderDrawLine(renderer,j*box.size,i*box.size+box.size,j*box.size,i*box.size);
            }

        }
    }
}

void delete_row(SDL_Renderer *renderer,brick &box)//tinh diem va ve lai ban choi khi nhung dong da full bien mat
{
    int old_score = score;
    int count[height-1];
    for(int i=0; i<height-1; i++)
    {
        count[i]=0;
    }
    for(int i=left_margin+1; i<=right_margin-1; i++)
    {
        for(int j=4; j<height-1; j++)
        {
            if(board_game[j][i] ==1 || board_game[j][i] ==2 || board_game[j][i] ==3 || board_game[j][i] ==4 || board_game[j][i] ==5 || board_game[j][i] ==6 || board_game[j][i] ==7)
                count[j]++;
        }
    }
    for(int i = height-2; i>=5;)
    {
        if(count[i]== 10)
        {
            for(int j=i; j>=4; j--)
            {
                for(int k=left_margin+1; k<=right_margin-1; k++)
                {
                    board_game[j][k] = board_game[j-1][k];
                    board_game[4][k]=0;
                }
                count[j]=count[j-1];
                count[4]=0;
            }
            score+=1;
        }
        else i--;
    }
    if(run_AI == false){
        if(score != old_score) SDL_Delay(180);
    }
    Print_Fixed_Block(renderer,box);
}

bool End_Game(brick &box)//kiem tra co phan nao cua khoi gach cham dinh chua
{
    for(int i=left_margin+1; i<=right_margin-1; i++)
    {
        if(board_game[4][i] == 1 || board_game[4][i] == 2 || board_game[4][i] == 3 || board_game[4][i] == 4 || board_game[4][i] == 5 || board_game[4][i] == 6 || board_game[4][i] == 7)
            return true;
    }
    return false;
}

void Print_Next_Block(brick box,SDL_Renderer *renderer,int hinh_truoc)// hien thi khoi gach tiep theo xuat hien
{
    SDL_Rect rect;
    rect.x = (right_margin+1)*box.size;
    rect.y = 4*box.size;
    rect.w = 5*box.size;
    rect.h = 6*box.size;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer,&rect);
    if(box.type == 1)
        SDL_SetRenderDrawColor(renderer, 39, 200, 0, 0);
    else if (box.type == 2)
        SDL_SetRenderDrawColor(renderer, 254,245, 6, 0);
    else if (box.type == 3)
        SDL_SetRenderDrawColor(renderer, 0, 145, 222, 0);
    else if (box.type == 4)
        SDL_SetRenderDrawColor(renderer,  239, 165, 4, 0);
    else if (box.type == 5)
        SDL_SetRenderDrawColor(renderer, 3, 135, 68,0);
    else if (box.type == 6)
        SDL_SetRenderDrawColor(renderer,196, 13, 241, 0);
    else
        SDL_SetRenderDrawColor(renderer,  247, 15, 3, 0);
    point a,b,c,d;
    box.Get_Center_Brick(7,right_margin+3);
    box.getType(hinh_truoc);
    shape_of_you(box,a,b,c,d);
    box.render(renderer,a,b,c,d,box.type);
}

void printScore(SDL_Renderer *renderer,int number)
{
    SDL_Rect rect;
    rect.x = (right_margin+1)*20;
    rect.y = 11*20;
    rect.w = 7*20;
    rect.h = 2*20;
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderFillRect(renderer,&rect);
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("vgafix.fon", 80);
    SDL_Color color = { 3, 87, 231 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,"SCORE: ", color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { (right_margin+2)*20-10, 12*20-10, 60, 20 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    color = { 255, 0, 255 };
    string s = to_string(number);
    const char *diem = s.c_str();
    surface = TTF_RenderText_Solid(font,diem, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    if(number < 10 )
    {
        dstrect = { (right_margin+5)*20-10, 120*2-10, 10, 20 };
    }
    else if(number < 100)
    {
        dstrect = { (right_margin+5)*20-10, 120*2-10, 20, 20 };
    }
    else
    {
        dstrect = { (right_margin+5)*20-10, 120*2-10, 30, 20 };
    }
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    //hien thi o reset game
    rect.x = (right_margin+1)*20;
    rect.y = 14*20;
    rect.w = 5*20;
    rect.h = 2*20;
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderFillRect(renderer,&rect);
    color = { 3, 87, 231 };
    surface = TTF_RenderText_Solid(font,
                                   "DARK", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    texW = 0;
    texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = { (right_margin+2)*20+5, 15*20-10, 50, 20 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    rect.x = (right_margin+1)*20;
    rect.y = 17*20;
    rect.w = 5*20;
    rect.h = 2*20;
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderFillRect(renderer,&rect);
    color = { 3, 87, 231 };
    surface = TTF_RenderText_Solid(font,
                                   "RESET", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    texW = 0;
    texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = { (right_margin+2)*20+3, 18*20-10, 55, 20 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    rect.x = (right_margin+1)*20;
    rect.y = 20*20;
    rect.w = 5*20;
    rect.h = 2*20;
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderFillRect(renderer,&rect);
    color = { 3, 87, 231 };
    surface = TTF_RenderText_Solid(font,
                                   "RUN AI", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    texW = 0;
    texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = { (right_margin+2)*20+3, 21*20-10, 60, 20 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
}
void printEndgame(SDL_Renderer *renderer,int number)// hien thi cua so khi thua
{
    SDL_Rect rect = { left_margin*20, 11*20, 12*20, 6*20};
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderFillRect(renderer,&rect);

    rect = { left_margin*20+1, 11*20+1, 12*20-2, 6*20-2};
    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawRect(renderer,&rect);

    rect = { (left_margin+1)*20-10, 12*20-10, 12*20-20, 6*20-20};
    SDL_SetRenderDrawColor(renderer, 255, 160, 0, 255);
    SDL_RenderDrawRect(renderer,&rect);

    TTF_Init();
    TTF_Font * font = TTF_OpenFont("vgafix.fon", 80);
    SDL_Color color = { 255, 0, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font," YOU LOSE !", color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { (left_margin+4)*20-1, 120*2-10, 80, 19 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    surface = TTF_RenderText_Solid(font,"SCORE", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = {(left_margin+5)*20-2, 130*2-8, 45, 19 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    color = {255,0,0};
    string s = to_string(number);
    const char *diem = s.c_str();
    surface = TTF_RenderText_Solid(font,diem, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    if(number < 10 )
    {
        dstrect = { (left_margin+6)*20-6, 140*2-6, 10, 19 };
    }
    else if(number < 100)
    {
        dstrect = { (left_margin+6)*20-13, 140*2-6, 20, 19 };
    }
    else
    {
        dstrect = { (left_margin+6)*20-18, 140*2-6, 30, 19 };
    }
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    color = {39, 200, 0};
    surface = TTF_RenderText_Solid(font," PLAY AGAIN", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = { (left_margin+2)*20+20, 150*2, 110, 19 };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_Rect rect1 = { (left_margin+2)*20+22, 150*2-2, 116, 23 };
    SDL_SetRenderDrawColor(renderer,66, 103, 178,0);
    SDL_RenderDrawRect(renderer,&rect1);

}
