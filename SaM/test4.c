#include<iostream>
#include<graphics.h>
using namespace std;
void bresen(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
    dx=x1-x0;
    dy=y1-y0;
    x=x0;
    y=y0;
    p=2*dy-dx;
    while(x<x1)
    {
        if(p>=0)
        {
            putpixel(x,y,RED);
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            putpixel(x,y,BLUE);
            p=p+2*dy;
        }
        x=x+1;
    }
}
int main()
{
    initwindow(1024, 700);
    bresen(100,100,200,200);
    cin.get();
    return 0;
}
