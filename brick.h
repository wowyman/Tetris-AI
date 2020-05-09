#include <iostream>

struct point
{
    int x,y;
};
struct brick
{
    int size = 20;

    point center;
    int type;
    void Get_Center_Brick(int _x,int _y)
    {
        center.x = _x;
        center.y = _y;
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


        rect01.x = B.y*size;
        rect01.y = B.x*size;
        rect01.h = size;
        rect01.w = size;
        SDL_RenderFillRect(renderer, &rect01);



        rect01.x = C.y*size;
        rect01.y = C.x*size;
        rect01.h = size;
        rect01.w = size;

        SDL_RenderFillRect(renderer, &rect01);


        rect01.x = D.y*size;
        rect01.y = D.x*size;
        rect01.h = size;
        rect01.w = size;

        SDL_RenderFillRect(renderer, &rect01);


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderDrawLine(renderer,A.y*size,A.x*size,A.y*size+size,A.x*size);
        SDL_RenderDrawLine(renderer,A.y*size+size,A.x*size,A.y*size+size,A.x*size+size);
        SDL_RenderDrawLine(renderer,A.y*size+size,A.x*size+size,A.y*size,A.x*size+size);
        SDL_RenderDrawLine(renderer,A.y*size,A.x*size+size,A.y*size,A.x*size);


        SDL_RenderDrawLine(renderer,B.y*size,B.x*size,B.y*size+size,B.x*size);
        SDL_RenderDrawLine(renderer,B.y*size+size,B.x*size,B.y*size+size,B.x*size+size);
        SDL_RenderDrawLine(renderer,B.y*size+size,B.x*size+size,B.y*size,B.x*size+size);
        SDL_RenderDrawLine(renderer,B.y*size,B.x*size+size,B.y*size,B.x*size);

        SDL_RenderDrawLine(renderer,C.y*size,C.x*size,C.y*size+size,C.x*size);
        SDL_RenderDrawLine(renderer,C.y*size+size,C.x*size,C.y*size+size,C.x*size+size);
        SDL_RenderDrawLine(renderer,C.y*size+size,C.x*size+size,C.y*size,C.x*size+size);
        SDL_RenderDrawLine(renderer,C.y*size,C.x*size+size,C.y*size,C.x*size);

        SDL_RenderDrawLine(renderer,D.y*size,D.x*size,D.y*size+size,D.x*size);
        SDL_RenderDrawLine(renderer,D.y*size+size,D.x*size,D.y*size+size,D.x*size+size);
        SDL_RenderDrawLine(renderer,D.y*size+size,D.x*size+size,D.y*size,D.x*size+size);
        SDL_RenderDrawLine(renderer,D.y*size,D.x*size+size,D.y*size,D.x*size);
    }
};
