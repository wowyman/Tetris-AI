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
        SDL_RenderDrawRect(renderer, &rect01);

        SDL_Rect rect02;
        rect02.x = B.y*size;
        rect02.y = B.x*size;
        rect02.h = size;
        rect02.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect02);

        SDL_Rect rect03;
        rect03.x = C.y*size;
        rect03.y = C.x*size;
        rect03.h = size;
        rect03.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect03);

        SDL_Rect rect04;
        rect04.x = D.y*size;
        rect04.y = D.x*size;
        rect04.h = size;
        rect04.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect04);
    }
};

