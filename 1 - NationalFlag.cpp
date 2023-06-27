#include<graphics.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int gd, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBO\\BGI");
	
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1, 1, WHITE);
	
	setcolor(GREEN);
	rectangle(100, 100, 400, 270);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(101, 101, GREEN);
	
	setcolor(BLACK);
	rectangle(90, 90, 99, 400);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(91, 91, BLACK);
	
	setcolor(RED);
	circle(240, 185, 60);
	setfillstyle(SOLID_FILL, RED);
	floodfill(251, 186, RED);
	
	getchar();
	return 0;
}
