#include<graphics.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void draw_rectangle()
{
	setcolor(GREEN);
	rectangle(50, 50, 400, 250);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(51, 52, GREEN);
}

void draw_triangle()
{
	setcolor(BLACK);
	line(230, 150, 70, 350);
	line(70, 350, 400, 350);
	line(400, 350, 230, 150);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(395, 349, BLACK);
}

void draw_circle()
{
	setcolor(RED);
	circle(350, 250, 110);
	setfillstyle(SOLID_FILL, RED);
	floodfill(350, 250, RED);
}

int main()
{
	int gm, gd;
	detectgraph(&gm, &gd);
	initgraph(&gm, &gd, "C:\\TURBO\\BGI");
	
	// Seting the background color white
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1, 1, WHITE);
	
	string pattern = "RCT";
	for(int i=0; i<3; i++)
	{
		if(pattern[i]=='C') draw_circle();
		else if(pattern[i]=='R') draw_rectangle();
		else draw_triangle();
	}
	
	
	getchar();
	return 0;
}
