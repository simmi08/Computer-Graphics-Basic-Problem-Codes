#include<stdio.h>
#include<math.h>
#include<graphics.h>

void _ellipse(int xc, int yc, int rx, int ry)
{
	int x = 0;
	int y = ry;
	int p= (ry*ry) - (rx*rx*y) + (rx*rx)/4;
	while(2*ry*ry*x < 2*rx*rx*y)
	{
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		x = x+1;
		if(p<0)
		{
			p = p + (2*ry*ry*x) + ry*ry;
		}
		else{
			y = y-1;
			p = p+ (2*ry*ry*x) - (2*rx*rx*y) + rx*rx; 
		}
		delay(100);
	}
	p = (int)pow(((float)x+0.5)*ry,2)+ pow(rx*(y-1),2)-pow(rx*ry,2);
	while(y>=0)
	{
		y = y-1;
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		if(p>0)
		{
			x = x+1 ;
			p = p - (2*rx*rx*y) +rx*rx;
		}
		else
		{
			p = p + (2*ry*ry*x) - (2*rx*rx*y) +rx*rx;
		}
		delay(100);
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"");
	_ellipse(200,300,15,10);
	closegraph();
}
