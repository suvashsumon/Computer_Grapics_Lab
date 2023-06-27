#include<graphics.h>
#include<stdio.h>
#include<iostream>
using namespace std;

/*
    length:width = 10:6
    radiaus = length/5;
    center = (9*length/20, width/2)
*/

int main()
{
	int gd, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBO\\BGI");
	
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1, 1, WHITE);
	
	setcolor(GREEN);
	rectangle(100, 100, 400, 280); // length = 400-100 = 300, width = 180
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(101, 101, GREEN);
	
	setcolor(BLACK);
	rectangle(90, 90, 99, 400);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(91, 91, BLACK);
	
	setcolor(RED);
	circle(235, 190, 60); // circle = (235, 190)  
	setfillstyle(SOLID_FILL, RED);
	floodfill(251, 186, RED);
	
	getchar();
	return 0;
}
