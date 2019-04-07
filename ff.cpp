#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void fillcolor(int x, int y, int ocolor, int ncolor)
{
	if(getpixel(x,y)==ocolor)
	{
		putpixel(x,y,ncolor);
		fillcolor(x,y+1,ocolor,ncolor);
		fillcolor(x,y-1,ocolor,ncolor);
		fillcolor(x+1,y,ocolor,ncolor);
		fillcolor(x-1,y,ocolor,ncolor);
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,NULL);
	line(100,30,50,70);
	line(50,70,70,70);
	line(70,70,30,150);
	line(30,150,150,150);
	line(150,150,100,30);
	fillcolor(63,65,0,15);
	delay(5000);
	closegraph();
}
