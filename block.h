#include <iostream>
struct brick
{
    int size = 20;
    double x,y;//toa do khoi tam
    void getXY(int _x,int _y)
    {
        x = _x*1.0;
        y = _y*1.0;
    }
    double X1=0,Y1=0,X2=0,Y2=0,X3=0,Y3=0,X4=0,Y4=0;
    int signal=0;
    void render1(SDL_Renderer* renderer)
    {
        //hinh chu L
        X1=x-1;
        Y1=y-1;
        X2=x-1;
        Y2=y;
        X3=x-1;
        Y3=y+1;
        X4=x;
        Y4=y+1;

        if(signal > 0)
        {
            for(int i=1; i<=signal; i++)
            {
                double Xtemp=X1;
                X1=-Y1+x+y;
                Y1=Xtemp-x+y;

                Xtemp=X2;
                X2=-Y2+x+y;
                Y2=Xtemp-x+y;

                Xtemp=X3;
                X3=-Y3+x+y;
                Y3=Xtemp-x+y;

                Xtemp=X4;
                X4=-Y4+x+y;
                Y4=Xtemp-x+y;
            }
        }
        SDL_Rect rect01;
        rect01.x = X1*size;
        rect01.y = Y1*size;
        rect01.h = size;
        rect01.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect01);

        SDL_Rect rect02;
        rect02.x = X2*size;
        rect02.y = Y2*size;
        rect02.h = size;
        rect02.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect02);

        SDL_Rect rect03;
        rect03.x = X3*size;
        rect03.y = Y3*size;
        rect03.h = size;
        rect03.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect03);

        SDL_Rect rect04;
        rect04.x = X4*size;
        rect04.y = Y4*size;
        rect04.h = size;
        rect04.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect04);
    }

    void render2(SDL_Renderer* renderer)
    {
        //hinh chu L nguoc
        X1=x+1;
        Y1=y-1;
        X2=x+1;
        Y2=y;
        X3=x+1;
        Y3=y+1;
        X4=x;
        Y4=y+1;

        if(signal > 0)
        {
            for(int i=1; i<=signal; i++)
            {
                double Xtemp=X1;
                X1=-Y1+x+y;
                Y1=Xtemp-x+y;

                Xtemp=X2;
                X2=-Y2+x+y;
                Y2=Xtemp-x+y;

                Xtemp=X3;
                X3=-Y3+x+y;
                Y3=Xtemp-x+y;

                Xtemp=X4;
                X4=-Y4+x+y;
                Y4=Xtemp-x+y;
            }
        }
        SDL_Rect rect01;
        rect01.x = X1*size;
        rect01.y = Y1*size;
        rect01.h = size;
        rect01.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect01);

        SDL_Rect rect02;
        rect02.x = X2*size;
        rect02.y = Y2*size;
        rect02.h = size;
        rect02.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect02);

        SDL_Rect rect03;
        rect03.x = X3*size;
        rect03.y = Y3*size;
        rect03.h = size;
        rect03.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect03);

        SDL_Rect rect04;
        rect04.x = X4*size;
        rect04.y = Y4*size;
        rect04.h = size;
        rect04.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect04);
    }

    void render3(SDL_Renderer* renderer)
    {
        X1=x-1;
        Y1=y+1;
        X2=x;
        Y2=y+1;
        X3=x;
        Y3=y;
        X4=x+1;
        Y4=y;

        if(signal > 0)
        {
            for(int i=1; i<=signal; i++)
            {
                double Xtemp=X1;
                X1=-Y1+x+y;
                Y1=Xtemp-x+y;

                Xtemp=X2;
                X2=-Y2+x+y;
                Y2=Xtemp-x+y;

                Xtemp=X3;
                X3=-Y3+x+y;
                Y3=Xtemp-x+y;

                Xtemp=X4;
                X4=-Y4+x+y;
                Y4=Xtemp-x+y;
            }
        }
        SDL_Rect rect01;
        rect01.x = X1*size;
        rect01.y = Y1*size;
        rect01.h = size;
        rect01.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect01);

        SDL_Rect rect02;
        rect02.x = X2*size;
        rect02.y = Y2*size;
        rect02.h = size;
        rect02.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect02);

        SDL_Rect rect03;
        rect03.x = X3*size;
        rect03.y = Y3*size;
        rect03.h = size;
        rect03.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect03);

        SDL_Rect rect04;
        rect04.x = X4*size;
        rect04.y = Y4*size;
        rect04.h = size;
        rect04.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect04);
    }

    void render4(SDL_Renderer* renderer)
    {
        X1=x-1;
        Y1=y;
        X2=x;
        Y2=y;
        X3=x;
        Y3=y+1;
        X4=x+1;
        Y4=y+1;

        if(signal > 0)
        {
            for(int i=1; i<=signal; i++)
            {
                double Xtemp=X1;
                X1=-Y1+x+y;
                Y1=Xtemp-x+y;

                Xtemp=X2;
                X2=-Y2+x+y;
                Y2=Xtemp-x+y;

                Xtemp=X3;
                X3=-Y3+x+y;
                Y3=Xtemp-x+y;

                Xtemp=X4;
                X4=-Y4+x+y;
                Y4=Xtemp-x+y;
            }
        }
        SDL_Rect rect01;
        rect01.x = X1*size;
        rect01.y = Y1*size;
        rect01.h = size;
        rect01.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect01);

        SDL_Rect rect02;
        rect02.x = X2*size;
        rect02.y = Y2*size;
        rect02.h = size;
        rect02.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect02);

        SDL_Rect rect03;
        rect03.x = X3*size;
        rect03.y = Y3*size;
        rect03.h = size;
        rect03.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect03);

        SDL_Rect rect04;
        rect04.x = X4*size;
        rect04.y = Y4*size;
        rect04.h = size;
        rect04.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect04);
    }

    void render5(SDL_Renderer* renderer)
    {
        X1=x;
        Y1=y-1;
        X2=x-1;
        Y2=y;
        X3=x;
        Y3=y;
        X4=x+1;
        Y4=y;

        if(signal > 0)
        {
            for(int i=1; i<=signal; i++)
            {
                double Xtemp=X1;
                X1=-Y1+x+y;
                Y1=Xtemp-x+y;

                Xtemp=X2;
                X2=-Y2+x+y;
                Y2=Xtemp-x+y;

                Xtemp=X3;
                X3=-Y3+x+y;
                Y3=Xtemp-x+y;

                Xtemp=X4;
                X4=-Y4+x+y;
                Y4=Xtemp-x+y;
            }
        }
        SDL_Rect rect01;
        rect01.x = X1*size;
        rect01.y = Y1*size;
        rect01.h = size;
        rect01.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect01);

        SDL_Rect rect02;
        rect02.x = X2*size;
        rect02.y = Y2*size;
        rect02.h = size;
        rect02.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect02);

        SDL_Rect rect03;
        rect03.x = X3*size;
        rect03.y = Y3*size;
        rect03.h = size;
        rect03.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect03);

        SDL_Rect rect04;
        rect04.x = X4*size;
        rect04.y = Y4*size;
        rect04.h = size;
        rect04.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect04);
    }

    double min_x,max_x,max_y;
    bool inside(int minX,int maxX,int maxY)
    {
//        min_x = X1;
//        if(min_x > X2)
//            min_x = X2;
//        if(min_x > X3)
//            min_x = X3;
//        if(min_x > X4)
//            min_x = X4;
//        max_x = X1;
//        if(max_x < X2)
//            max_x = X2;
//        if(max_x < X3)
//            max_x = X3;
//        if(max_x < X4)
//            max_x = X4;
//        max_y = Y1;
//        if(max_y < Y2)
//            max_y = Y2;
//        if(max_y < Y3)
//            max_y = Y3;
//        if(max_y < Y4)
//            max_y = Y4;
        bool check = (minX <= x*size && x*size <= maxX && y*size <= maxY);
        if(check == true)
            return true;
        else
            return false;
    }

    void turnLeft()
    {
        x -= 1;
    }
    void turnRight()
    {
        x += 1;
    }
    void goDown()
    {
        y += 0.3;

    }
    void xoay_nguoc()
    {
        if(signal < 4)
        {
            signal ++;
        }
        else
        {
            signal = 0;
            signal++;
        }
    }
};

struct gach6
{
    int size = 40;
    double x,y;//toa do khoi tam
    void getXY(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    double X1=0,Y1=0,X2=0,Y2=0,X3=0,Y3=0,X4=0,Y4=0;
    int signal=0;
    void render(SDL_Renderer* renderer)
    {
        X1=x;
        Y1=y;
        X2=x+1;
        Y2=y;
        X3=x;
        Y3=y+1;
        X4=x+1;
        Y4=y+1;
        SDL_Rect rect01;
        rect01.x = X1*size;
        rect01.y = Y1*size;
        rect01.h = size;
        rect01.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect01);

        SDL_Rect rect02;
        rect02.x = X2*size;
        rect02.y = Y2*size;
        rect02.h = size;
        rect02.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect02);

        SDL_Rect rect03;
        rect03.x = X3*size;
        rect03.y = Y3*size;
        rect03.h = size;
        rect03.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect03);

        SDL_Rect rect04;
        rect04.x = X4*size;
        rect04.y = Y4*size;
        rect04.h = size;
        rect04.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect04);
    }

    bool inside(int minX,int minY,int maxX,int maxY)
    {
        return (minX <= (x-1)*size && minY <= (y-1)*size && (x+1)*size <= maxX && (y+1)*size <= maxY);
    }

    void turnLeft()
    {
        x -= 1;
    }
    void turnRight()
    {
        x += 1;
    }
    void goDown()
    {
        y += 1;
    }
    void xoay_nguoc()
    {

    }
};


struct gach7
{
    int size = 40;
    double x,y;//toa do khoi tam
    void getXY(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    double X1=0,Y1=0,X2=0,Y2=0,X3=0,Y3=0,X4=0,Y4=0;
    int signal=0;
    void render(SDL_Renderer* renderer)
    {
        //hinh chu L nguoc
        X1=x;
        Y1=y-1;
        X2=x;
        Y2=y;
        X3=x;
        Y3=y+1;
        X4=x;
        Y4=y+2;
        if(signal == 1)
        {
            double Xtemp=X1;
            X1=-Y1+x+y;
            Y1=Xtemp-x+y;

            Xtemp=X2;
            X2=-Y2+x+y;
            Y2=Xtemp-x+y;

            Xtemp=X3;
            X3=-Y3+x+y;
            Y3=Xtemp-x+y;

            Xtemp=X4;
            X4=-Y4+x+y;
            Y4=Xtemp-x+y;
        }
        else if( signal == 2)
        {
            for(int i=1; i<=signal; i++)
            {
                double Xtemp=X1;
                X1=Y1+x-y;
                Y1=-Xtemp+x+y;

                Xtemp=X2;
                X2=Y2+x-y;
                Y2=-Xtemp+x+y;

                Xtemp=X3;
                X3=Y3+x-y;
                Y3=-Xtemp+x+y;

                Xtemp=X4;
                X4=Y4+x-y;
                Y4=-Xtemp+x+y;
            }
        }

        SDL_Rect rect01;
        rect01.x = X1*size;
        rect01.y = Y1*size;
        rect01.h = size;
        rect01.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect01);

        SDL_Rect rect02;
        rect02.x = X2*size;
        rect02.y = Y2*size;
        rect02.h = size;
        rect02.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect02);

        SDL_Rect rect03;
        rect03.x = X3*size;
        rect03.y = Y3*size;
        rect03.h = size;
        rect03.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect03);

        SDL_Rect rect04;
        rect04.x = X4*size;
        rect04.y = Y4*size;
        rect04.h = size;
        rect04.w = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &rect04);
    }

    bool inside(int minX,int minY,int maxX,int maxY)
    {
        return (minX <= (x-2)*size && minY <= (y-1)*size && (x+1)*size <= maxX && (y+1)*size <= maxY);
    }

    void turnLeft()
    {
        x -= 1;
    }
    void turnRight()
    {
        x += 1;
    }
    void goDown()
    {
        y += 1;
    }
    void xoay_nguoc()
    {
        if(signal < 2)
            signal ++;
        else
        {
            signal = 0;
            signal++;
        }
    }
};

