#include <iostream>
#include "function.h"
using namespace std;
int board_ao[cao][dai];
double diem_AI[4][10];
int a2;//clone cua a
double MAXXX = -9999.0;
//0.510066, 0.760666, 0.35663, 0.184483
const double hs1 = -0.5,hs2 = 0.75, hs3 = -0.35, hs4 = - 0.15,hs5 = 0.15;
void init_clone(gach &box,int &a,int &b)
{
    a2 = a;


    for(int i=0;i<cao;i++)
    {
        for(int j=0;j<dai;j++)
        {
            board_ao[i][j] = board_game[i][j];
        }
    }

    //cout<<max_high<<endl;
}

bool inside_AI(gach box,point A,point B,point C,point D)
{
    bool checkA = (A.y > le_trai && A.y < le_phai);
    bool checkB = (B.y > le_trai && B.y < le_phai);
    bool checkC = (C.y > le_trai && C.y < le_phai);
    bool checkD = (D.y > le_trai && D.y < le_phai);
    bool check = (checkA && checkB && checkC && checkD);
    //cout<<check<<endl;
    return check;
}
bool IsMove_AI(gach &box,point &A,point &B,point &C,point &D)
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

    if(la_o_thanh_phan(box,a,A,B,C,D)== true)
    {
        check1=true;
    }
    else
    {
        if(board_ao[a.x][a.y]==-1 || (board_ao[a.x][a.y] >= 1 && board_ao[a.x][a.y] <= 7 ))
        {
            check1 = false;
        }
        if(board_ao[a.x][a.y]==0)
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
        if(board_ao[b.x][b.y]==-1 || (board_ao[b.x][b.y] >= 1 && board_ao[b.x][b.y] <= 7 ))
        {
            check1 = false;
        }
        if(board_ao[b.x][b.y]==0)
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
        if(board_ao[c.x][c.y]==-1 || (board_ao[c.x][c.y] >= 1 && board_ao[c.x][c.y] <= 7 ))
        {
            check1 = false;
        }
        if(board_ao[c.x][c.y]==0)
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
        if(board_ao[d.x][d.y]==-1 || (board_ao[d.x][d.y] >= 1 && board_ao[d.x][d.y] <= 7 ))
        {
            check1 = false;
        }
        if(board_ao[d.x][d.y]==0)
        {
            check4 = true;
        }
    }
    check = (check1 && check2 && check3 && check4);
    return check;
}
