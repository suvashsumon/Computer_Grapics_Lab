#include<graphics.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int gm, gd;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBO\\BGI");
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1, 1, WHITE);
	
	// line properties
	int x1 = 50, y1 = 50;
	int x2 = 300, y2 = 200;
	
	// draw original line
	setcolor(RED);
	line(x1, y1, x2, y2);
	
	// translation factor
	int tx = 50, ty = 150;
	
	// after translation line properties
	x1 = x1 + tx;
	y1 = y1 + ty;
	x2 = x2 + tx;
	y2 = y2 + ty;
	
	// draw translated line
	setcolor(GREEN);
	line(x1, y1, x2, y2);
	
	getchar();
	return 0;
}
