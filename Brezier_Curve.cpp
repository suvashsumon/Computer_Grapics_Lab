#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void drawCurve(int x[4], int y[4])
{
	double px, py;
	for(double i=0; i<=1; i+=0.0001)
	{
		px = x[0]*pow(1-i, 3) + x[1]*3*i*pow(1-i, 2) + x[2]*3*pow(i, 2)*(1-i) + x[3]*pow(i, 3);
		py = y[0]*pow(1-i, 3) + y[1]*3*i*pow(1-i, 2) + y[2]*3*pow(i, 2)*(1-i) + y[3]*pow(i, 3);
		putpixel(px, py, WHITE);
	}
}


int main()
{
	int gd, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, "C:\\TURBO\\BGI");
	
	int x[4], y[4];
	for(int i=0; i<4; i++)
	{
		cout << "Enter x and y : ";
		cin >> x[i] >> y[i];
	}
	
	drawCurve(x, y);
	
	getch();
	closegraph();
	return 0;
}
