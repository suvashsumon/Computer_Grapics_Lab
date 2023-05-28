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
    int x1 = 70, y1 = 70;
    int x2 = 70, y2 = 100;
    
    cout << "Original Length : " << sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) << endl;
    
    // draw the original line
    setcolor(GREEN);
    line(x1, y1, x2, y2);
    
    // fixed point
    int xf = 70, yf = 70;
    
    // scaling factors
    int sx = 2, sy = 2;
    
    // perform scaling
    int xss1 = x1*sx + xf*(1-sx);
    int yss1 = y1*sy + yf*(1-sy);
    int xss2 = x2*sx + xf*(1-sx);
    int yss2 = y2*sy + yf*(1-sy);
    
    // draw the rotated line
    setcolor(RED);
    line(xss1, yss2, xss2, yss2);
    
    cout << "After Rotation Length : "<< sqrt((xss1-xss2)*(xss1-xss2)+(yss1-yss2)*(yss1-yss2)) << endl;

	
	
	getchar();
	closegraph();
	return 0;
}
