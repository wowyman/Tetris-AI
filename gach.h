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

    void render(SDL_Renderer *renderer,point A,point B,point C,point D,int type)
    {
        if(type == 1)
            SDL_SetRenderDrawColor(renderer, 39, 200, 0, 0);
        else if (type == 2)
            SDL_SetRenderDrawColor(renderer, 254,245, 6, 0);
        else if (type == 3)
            SDL_SetRenderDrawColor(renderer,0, 145, 222, 0);
        else if (type == 4)
            SDL_SetRenderDrawColor(renderer, 239, 165, 4, 0);
        else if (type == 5)
            SDL_SetRenderDrawColor(renderer,  3, 135, 68,0);
        else if (type == 6)
            SDL_SetRenderDrawColor(renderer,196, 13, 241, 0);
        else
            SDL_SetRenderDrawColor(renderer, 247, 15, 3, 0);
        SDL_Rect rect01;
        rect01.x = A.y*size;
        rect01.y = A.x*size;
        rect01.h = size;
        rect01.w = size;
        SDL_RenderFillRect(renderer, &rect01);

        SDL_Rect rect02;
        rect02.x = B.y*size;
        rect02.y = B.x*size;
        rect02.h = size;
        rect02.w = size;
        SDL_RenderFillRect(renderer, &rect02);


        SDL_Rect rect03;
        rect03.x = C.y*size;
        rect03.y = C.x*size;
        rect03.h = size;
        rect03.w = size;

        SDL_RenderFillRect(renderer, &rect03);


        SDL_Rect rect04;
        rect04.x = D.y*size;
        rect04.y = D.x*size;
        rect04.h = size;
        rect04.w = size;

        SDL_RenderFillRect(renderer, &rect04);


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,A.y*size,A.x*size,A.y*size+size,A.x*size);
        SDL_SetRenderDrawColor(renderer,  255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,A.y*size+size,A.x*size,A.y*size+size,A.x*size+size);
        SDL_SetRenderDrawColor(renderer,  255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,A.y*size+size,A.x*size+size,A.y*size,A.x*size+size);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,A.y*size,A.x*size+size,A.y*size,A.x*size);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,B.y*size,B.x*size,B.y*size+size,B.x*size);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,B.y*size+size,B.x*size,B.y*size+size,B.x*size+size);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,B.y*size+size,B.x*size+size,B.y*size,B.x*size+size);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,B.y*size,B.x*size+size,B.y*size,B.x*size);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,C.y*size,C.x*size,C.y*size+size,C.x*size);
        SDL_SetRenderDrawColor(renderer,  255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,C.y*size+size,C.x*size,C.y*size+size,C.x*size+size);
        SDL_SetRenderDrawColor(renderer,  255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,C.y*size+size,C.x*size+size,C.y*size,C.x*size+size);
        SDL_SetRenderDrawColor(renderer,  255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,C.y*size,C.x*size+size,C.y*size,C.x*size);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,D.y*size,D.x*size,D.y*size+size,D.x*size);
        SDL_SetRenderDrawColor(renderer,  255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,D.y*size+size,D.x*size,D.y*size+size,D.x*size+size);
        SDL_SetRenderDrawColor(renderer,  255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,D.y*size+size,D.x*size+size,D.y*size,D.x*size+size);
        SDL_SetRenderDrawColor(renderer,  255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,D.y*size,D.x*size+size,D.y*size,D.x*size);
    }
};
