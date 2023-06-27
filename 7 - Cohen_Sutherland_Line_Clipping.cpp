#include <bits/stdc++.h>
#include<graphics.h>
#include <cmath>
using namespace std;

// Definitions for the region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define the clipping window boundaries
const int X_MIN = 50;
const int X_MAX = 300;
const int Y_MIN = 50;
const int Y_MAX = 250;

// line points after clipping
int cx1, cy1, cx2, cy2;

// Compute the region code for a point (x, y)
int computeRegionCode(int x, int y)
{
    int code = INSIDE;

    if (x < X_MIN)
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;

    if (y < Y_MIN)
        code |= BOTTOM;
    else if (y > Y_MAX)
        code |= TOP;

    return code;
}

// Clip the line using Cohen-Sutherland algorithm
void cohenSutherland(int x1, int y1, int x2, int y2)
{
    int code1 = computeRegionCode(x1, y1);
    int code2 = computeRegionCode(x2, y2);
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0)) // Fully inside the window
        {
            accept = true;
            break;
        }
        else if (code1 & code2) // Fully outside the window and we ignore this line
        {
            break;
        }
        else
        {
            int x, y;
            int codeOut = (code1 != 0) ? code1 : code2;

            // Find intersection point
            if (codeOut & TOP)
            {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            }
            else if (codeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            }
            else if (codeOut & LEFT)
            {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            // Replace the outside point with the intersection point
            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeRegionCode(x2, y2);
            }
        }
    }

    if (accept)
    {
        cout << "Line segment after clipping: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;
        // store the clipped point
        cx1 = x1;
        cy1 = y1;
        cx2 = x2;
        cy2 = y2;
    }
    else
    {
        cout << "Line segment is outside the clipping window and rejected." << std::endl;
    }
}

int main()
{
	int gd, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBO\\BGI");
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(1, 1, WHITE);
    int x1, y1, x2, y2;

    cout << "Enter the endpoints of the line segment (x1, y1) to (x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    
    // before
    setcolor(BLACK);
    line(x1, y1, x2, y2);
    delay(500);
    
    // draw the window (not mandetory)
    line(X_MIN, Y_MIN, X_MIN, Y_MAX);
    line(X_MIN, Y_MAX, X_MAX, Y_MAX);
    line(X_MAX, Y_MAX, X_MAX, Y_MIN);
    line(X_MAX, Y_MIN, X_MIN, Y_MIN);
    

    cohenSutherland(x1, y1, x2, y2);
    
    // after
    setcolor(GREEN);
	line(cx1, cy1, cx2, cy2);
	
	getch();
	closegraph();
    return 0;
}

