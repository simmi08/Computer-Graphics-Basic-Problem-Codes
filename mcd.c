#include<stdio.h>
#include<math.h>
#include<graphics.h>
void pcircle(int xc, int yc, int x, int y);
void mcd(int xc, int yc, int r)
{
	int x = 0;
	int y = r;
	int p = 1-r;
	pcircle(xc,yc,x,y);
	while(x<y)
	{
		x++;
		if(p<0)
		{
			pcircle(xc,yc,x,y);
			p = p + 2*x + 1;
		}
		else
		{
			pcircle(xc,yc,x,y--);
			p = p + 2*(x-y) +1;
		}
		delay(100);
	}

}
void pcircle(int xc, int yc, int x, int y)
{
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(xc+y,yc+x,WHITE);
	putpixel(xc+y,yc-x,WHITE);
	putpixel(xc-y,yc+x,WHITE);
	putpixel(xc-y,yc-x,WHITE);
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"");
	mcd (50,50,20);
	closegraph();
}
