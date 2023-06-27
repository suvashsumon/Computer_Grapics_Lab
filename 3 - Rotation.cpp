#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int gd, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBO\\BGI");
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1, 1, WHITE);
	
	// line properties
    int x1 = 50, y1 = 300;
    int x2 = 300, y2 = 300;
    
    cout << "Original Length : " << sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) << endl;
    
    // draw the original line
    setcolor(GREEN);
    line(x1, y1, x2, y2);
    
    // reference point
    int xr = 50, yr = 300;
    
    // rotation angle
    int angle = -100;
    double theta = (angle*3.1416)/180;
    
    // perform rotation
    int xrr1 = xr + (x1-xr)*cos(theta) - (y1-yr)*sin(theta);
    int yrr1 = yr + (x1-xr)*sin(theta) + (y1-yr)*cos(theta);
    int xrr2 = xr + (x2-xr)*cos(theta) - (y2-yr)*sin(theta);
    int yrr2 = yr + (x2-xr)*sin(theta) + (y2-yr)*cos(theta);
    
    // draw the rotated line
    setcolor(RED);
    line(xrr1, yrr1, xrr2, yrr2);
    
    cout << "After Rotation Length : "<< sqrt((xrr1-xrr2)*(xrr1-xrr2)+(yrr1-yrr2)*(yrr1-yrr2)) << endl;

	
	
	getchar();
	closegraph();
	return 0;
}