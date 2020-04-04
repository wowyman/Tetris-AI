#include <iostream>

int max(int a,int b,int c,int d)
{
    int max=a;
    if(max<b)
        max=b;
    if(max<c)
        max=c;
    if(max<d)
        max=d;
    return max;
}
int min(int a,int b,int c,int d)
{
    int min=a;
    if(min>b) min=b;
    if(min>c) min=c;
    if(min>d) min = d;
    return min;
}
struct point
{
    int x,y;
};
struct gach
{
    int size = 20;
    point tam;
    int type;
    void get_toa_do_Tam(int _x,int _y)
    {
        tam.x = _x;
        tam.y = _y;
    }
    void getType(int _type)
    {
        type = _type;
    }

    void render(SDL_Renderer *renderer,point A,point B,point C,point D)
    {

        SDL_Rect rect01;
        rect01.x = A.y*size;
        rect01.y = A.x*size;
        rect01.h = size;
        rect01.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect01);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,A.y*size,A.x*size,A.y*size+size,A.x*size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,A.y*size+size,A.x*size,A.y*size+size,A.x*size+size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,A.y*size+size,A.x*size+size,A.y*size,A.x*size+size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,A.y*size,A.x*size+size,A.y*size,A.x*size);

        SDL_Rect rect02;
        rect02.x = B.y*size;
        rect02.y = B.x*size;
        rect02.h = size;
        rect02.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect02);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,B.y*size,B.x*size,B.y*size+size,B.x*size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,B.y*size+size,B.x*size,B.y*size+size,B.x*size+size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,B.y*size+size,B.x*size+size,B.y*size,B.x*size+size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,B.y*size,B.x*size+size,B.y*size,B.x*size);

        SDL_Rect rect03;
        rect03.x = C.y*size;
        rect03.y = C.x*size;
        rect03.h = size;
        rect03.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect03);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,C.y*size,C.x*size,C.y*size+size,C.x*size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,C.y*size+size,C.x*size,C.y*size+size,C.x*size+size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,C.y*size+size,C.x*size+size,C.y*size,C.x*size+size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,C.y*size,C.x*size+size,C.y*size,C.x*size);

        SDL_Rect rect04;
        rect04.x = D.y*size;
        rect04.y = D.x*size;
        rect04.h = size;
        rect04.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect04);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,D.y*size,D.x*size,D.y*size+size,D.x*size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,D.y*size+size,D.x*size,D.y*size+size,D.x*size+size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,D.y*size+size,D.x*size+size,D.y*size,D.x*size+size);
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
        SDL_RenderDrawLine(renderer,D.y*size,D.x*size+size,D.y*size,D.x*size);
    }
};
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
