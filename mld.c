#include<stdio.h>
#include<graphics.h>
#include<math.h>
void mid(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;int x = x1; int y = y1;int D;
	putpixel(x,y,WHITE);
	int dy = y2 - y1;
	D = dx>dy ? dy - (dx/2) : dx - (dy/2);
	if(dx > dy)
	{
		while(x<x2){x = x+1 ;
		if(D<0){
		putpixel(x,y,WHITE);D= D+dy;}
		else
		{
			putpixel(x,y++,WHITE);
			D = D + dy - dx;
		}
		delay(100);
	}}
	else
	{
		while(y<y2) { y = y+1;
		if(D<0)
		{
			putpixel(x,y,WHITE);
			D = D + dx;
		}
		else
		{
			putpixel(x++,y,WHITE);
			D = D + dx - dy;
		}
		delay(100);
	}}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"");
	mid(10,8,100,40);
}
