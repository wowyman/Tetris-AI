#include <iostream>
#include "function.h"
using namespace std;
int board_clone[height][width];
double score_AI[4][10];
int a2;//clone cua a
double MAXXX = -9999.0;
//0.510066, 0.760666, 0.35663, 0.184483
const double hs1 = -0.5,hs2 = 0.75, hs3 = -0.35, hs4 = - 0.15,hs5 = 0;
void init_clone(brick &box,int &a,int &b)
{
    a2 = a;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            board_clone[i][j] = board_game[i][j];
        }
    }

    //cout<<max_high<<endl;
}

bool inside_AI(brick box,point A,point B,point C,point D)
{
    bool checkA = (A.y > left_margin && A.y < right_margin);
    bool checkB = (B.y > left_margin && B.y < right_margin);
    bool checkC = (C.y > left_margin && C.y < right_margin);
    bool checkD = (D.y > left_margin && D.y < right_margin);
    bool check = (checkA && checkB && checkC && checkD);
    return check;
}
bool IsMove_AI(brick &box,point &A,point &B,point &C,point &D)
{
    point a,b,c,d;
    bool check=true,check1=true,check2=true,check3=true,check4=true;
        a.x = A.x + 1;
        a.y = A.y;
        b.x = B.x + 1;
        b.y = B.y;
        c.x = C.x + 1;
        c.y = C.y;
        d.x = D.x + 1;
        d.y = D.y;

    if(Is_part_of_brick(box,a,A,B,C,D)== true)
    {
        check1=true;
    }
    else
    {
        if(board_clone[a.x][a.y]==-1 || (board_clone[a.x][a.y] >= 1 && board_clone[a.x][a.y] <= 7 ))
        {
            check1 = false;
        }
        if(board_clone[a.x][a.y]==0)
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
        if(board_clone[b.x][b.y]==-1 || (board_clone[b.x][b.y] >= 1 && board_clone[b.x][b.y] <= 7 ))
        {
            check1 = false;
        }
        if(board_clone[b.x][b.y]==0)
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
        if(board_clone[c.x][c.y]==-1 || (board_clone[c.x][c.y] >= 1 && board_clone[c.x][c.y] <= 7 ))
        {
            check1 = false;
        }
        if(board_clone[c.x][c.y]==0)
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
        if(board_clone[d.x][d.y]==-1 || (board_clone[d.x][d.y] >= 1 && board_clone[d.x][d.y] <= 7 ))
        {
            check1 = false;
        }
        if(board_clone[d.x][d.y]==0)
        {
            check4 = true;
        }
    }
    check = (check1 && check2 && check3 && check4);
    return check;
}
