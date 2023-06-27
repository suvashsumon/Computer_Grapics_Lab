#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void bresenhamsLine(int x0,int y0,int x1,int y1)
{
    int p,x,y,dx,dy;
    dx=x1-x,dy=y1-y;
    x=x0,y=y0;
    p=2*dy-dx;

    while(x<=x1)
    {
        putpixel(x,y,BLACK);
        x++;

        if(p>=0)
        {
           p += 2*dy-2*dx;
           y++ ;
        }
        else
            p+=2*dy;
    }
}

int main()
{
    int gm,gd;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C:\\TURBO\\BGI");
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1, 1, WHITE);
	
    bresenhamsLine(50, 50, 450, 450);

    getch();
    closegraph();
    return 0;
}
