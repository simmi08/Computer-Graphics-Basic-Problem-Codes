#include<stdio.h>
#include<math.h>
#include<graphics.h>

void bres(int x1, int x2, int y1, int y2)
{
	int pk, dx, dy,x,y;
        dx = x2 - x1;
	dy = y2 - y1;putpixel(x1,y1,WHITE);
	pk = 2*dy - dx;x = x1;y=y1;
	for(int i=1 ;i<dx; i++)
	{
		if(pk < 0){
		putpixel(x++, y ,WHITE);pk = pk + 2*dy ;}
		else{
		putpixel(x++,y++, WHITE);pk = pk + 2*dy - 2*dx;}
		delay(100);
	}
}
int main()
{
		int gd = DETECT, gm;
		initgraph(&gd,&gm,"");
		bres(1,100,10,40);
}
