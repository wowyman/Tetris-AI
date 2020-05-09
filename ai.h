#include <iostream>
#include "function.h"
using namespace std;
int board_clone[height][width];
double score_AI[4][10];
int a2;//clone cua a
double MAXXX = -9999.0;
//0.510066, 0.760666, 0.35663, 0.184483, hs5 = -0.119
const double hs1 = -0.5,hs2 = 0.76, hs3 = -0.3567, hs4 = - 0.185;
void init_clone()
{
    a2 = a;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
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
bool IsFullRow(int row)
{
    for(int i = left_margin+1; i<=right_margin-1; i++)
    {
        if(board_clone[row][i] == 0)
            return false;
    }
    return true;
}
int High_Col(int col)
{
    int count1 = 0;
    for(int i=4; i<height - 1; i++)
    {
        if(board_clone[i][col] == 0 )
        {
            count1++;
        }
        else break;
    }
    return count1;
}
int AI_SCORE()
{
    int CCTH = 0;
    int high_cols[10];
    for(int i = left_margin +1; i <= right_margin-1; i++ )
    {
        int _height = (height-5) - High_Col(i);
        CCTH += _height;
        high_cols[i - left_margin - 1] = _height;
    }
    int Bumpiness = 0;
    for(int i = 0; i < 9; i ++)
    {
        Bumpiness = Bumpiness + abs(high_cols[i] - high_cols[i+1]);
    }
    int Holes=0;
    for(int i=5; i<height-1; i++)
    {
        for(int j = left_margin+1 ; j <= right_margin-1; j++)
        {
            if(board_clone[i][j] ==0 && board_clone[i-1][j] != 0) Holes+=1;
        }
    }
    int SDF = 0;
    for(int i=4; i<height-1; i++)
    {
        if(IsFullRow(i) == true)
        {
            SDF ++;
        }
    }
    double tong_Diem = hs1*CCTH + hs2*SDF + hs3*Holes + hs4*Bumpiness;
    //cout<<CCTH<<" "<<SDF<<" "<<Holes<<" "<<Bumpiness<<" TONG DIEM : "<<tong_Diem<<endl;
    return tong_Diem;
}


///------------------------------------------------
//-------------------Cai tien them----------------
//int Max_high()
//{
//
//    int col_high_max = -99;
//    int high_max = -100;
//// cot cao nhat
//    int Count1=0;
//    for(int i = left_margin +1; i <= right_margin-1; i++ )
//    {
//        Count1 = 0;
//        for(int j = 4; j < height-1 ; j++)
//        {
//            if(board_clone[j][i] == 0 )
//            {
//                Count1++;
//            }
//            else break;
//        }
//        int _height = (height-5) - Count1;
//        if(_height > high_max )
//        {
//            high_max = _height;
//            col_high_max = i;
//        }
//    }
//    return col_high_max;
//}
