#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void drawCircle(int cx, int cy, int r)
{
	int p, x=r, y=0;
	while(x>=y)
	{
		putpixel(cx+x, cy+y, WHITE);
		putpixel(cx+y, cy+x, WHITE);
		putpixel(cx-x, cy+y, WHITE);
		putpixel(cx-y, cy+x, WHITE);
		putpixel(cx-x, cy-y, WHITE);
		putpixel(cx-y, cy-x, WHITE);
		putpixel(cx+x, cy-y, WHITE);
		putpixel(cx+y, cy-x, WHITE);
		
		if(p<=0)
		{
			y = y + 1;
			p = p + 2*y + 1;
		}
		else
		{
			x = x - 1;
			p = p - 2*x + 1;
		}
	}
}


int main()
{
	int gd, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBO\\BGI");
	
	int x, y, r;
	cout << "Enter center : ";
	cin >> x >> y;
	cout << "Enter radiaus : ";
	cin >> r;
	
	drawCircle(x, y, r);
	
	getch();
	closegraph();
	return 0;
}
