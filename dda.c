#include<stdio.h>
#include<math.h>
#include<graphics.h>
 
void dda(int x1, int y1, int x2, int y2)
{
	float x,y; int steps;
	int dx = (x2-x1);
	int dy = (y2-y1);
	if(dx > dy) steps = abs(dx);
	else
	steps = abs(dy);
	float xinc = dx/(float)steps;
	float yinc = dy/(float)steps;
	putpixel(x1,y1,WHITE);
	for(int i=1;i<=steps;i++)
	{
		x = x+ xinc;
		y =y+ yinc;
		putpixel((int)x,(int)y,WHITE);
		delay(100);
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,NULL);
	dda(1,1,100,50);
}

