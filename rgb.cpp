// Color image RGB

#include<bits/stdc++.h>
using namespace std;
int red[201][201],green[201][201],blue[201][201];
void putpix(int x,int y,int r,int g,int b){
	red[y][x]=r;
	green[y][x]=g;
	blue[y][x]=b;
}
void floodFill(int x,int y,int r,int g,int b){
	
	if(x<1||y<1||x>200||y>200||red[y][x]||green[y][x]||blue[y][x])
		return;
	putpix(x,y,r,g,b);
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			if(i==j||i==-j)
				continue;
			else
				floodFill(x+i,y+j,r,g,b);
}		
void putcir(int x,int y,int p,int q){
	putpix(p+x,q+y,200,50,10);
	putpix(p+x,q-y,200,50,10);
	putpix(p-x,q+y,200,50,10);
	putpix(p-x,q-y,200,50,10);
	putpix(p+y,q+x,200,50,10);
	putpix(p+y,q-x,200,50,10);
	putpix(p-y,q+x,200,50,10);
	putpix(p-y,q-x,200,50,10);
	
}	
void BRC(){
	int xc=100,yc=100,r=25;
	int x=0,y=r;
	int d=3-2*r;
	while(x<=y){
		putcir(x,y,xc,yc);
		x++;
		if(d<0){
			d+=4*x+6;
		}
		else{
			y--;			
			d+=4*(x-y)+10;
		}
		
	}	
	return ;
}
void DE(int x,int y,int xc,int yc){
	putpix(xc+x,yc+y,10,200,50);
	putpix(xc-x,yc+y,10,200,50);
	putpix(xc+x,yc-y,10,200,50);
	putpix(xc-x,yc-y,10,200,50);
}
void MPE(){
	int xc=100,yc=100;
	int rx=50,ry=35;
	int x=0,y=ry;
	double p=ry*ry+0.25*rx*rx-rx*ry*ry;
	DE(x,y,xc,yc);
	while(2*ry*ry*x<2*rx*rx*y){
		x++;
		if(p<0){
			p+=2*ry*ry*x+ry*ry;
		}else{
			y--;
			p+=2*ry*ry*x-2*rx*rx*y+ry*ry;
		}
		DE(x,y,xc,yc);
		
	}
	p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1.0)*(y-1.0)-1.0*rx*rx*ry*ry;
		
	DE(x,y,xc,yc);
	while(y>0){
		y--;
		if(p>0){
			p+=-2*rx*rx*y+rx*rx;
		}else{
			x++;
			p+=2*ry*ry*x-2*rx*rx*y+rx*rx;
		}
		DE(x,y,xc,yc);
	}
			
	return ;		
}
int main(){
	BRC();
	cerr<<"Circle"<<endl;
	floodFill(100,100,200,50,10);
	cerr<<"Circle filled"<<endl;
	MPE();
	floodFill(148,100,10,200,50);
	floodFill(1,1,50,10,200);
	ofstream op("q1.ppm");
	op<<"P3# CREATOR: GIMP PNM Filter Version 1.1"<<endl;
	op<<"200 200"<<endl;
	op<<"255"<<endl;
	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++)
			op<<red[i][j]<<" "<<green[i][j]<<" "<<blue[i][j]<<"\t";
		op<<endl;
	};
	op.close();
	cout<<"done"<<endl;	
	return 0;
}
	
	
//RGB TO HSI

#include<bits/stdc++.h>
using namespace std;
int red[201][201],green[201][201],blue[201][201];
double hue[201][201],sat[201][201],inten[201][201];
double PI=acos(-1);
void RGBTOHSI(int i,int j){
	double r=red[i][j],g=green[i][j],b=blue[i][j];
	double th=acos(0.5*(r-g+r-b)/sqrt((r-g)*(r-g)+(r-b)*(g-b)));
	th*=180;
	th/=PI;
	if(b<=g)
		hue[i][j]=th;
	else
		hue[i][j]=360-th;
	sat[i][j]=1-3.0*min(min(r,g),b)/(r+g+b);
	inten[i][j]=(r+g+b)/3;
}
double toRad(double deg){
	return deg*PI/180;
}
void HSITORGB(int i,int j){
	double h=hue[i][j];
	double s=sat[i][j];
	double I=inten[i][j];
	if(h<120){
		red[i][j]=I*(1+s*cos(toRad(h))/(cos(toRad(60-h))));
		blue[i][j]=I*(1-s);
		green[i][j]=3*I-red[i][j]-blue[i][j];
	}else if(h<240){
		h-=120;
		red[i][j]=I*(1-s);
		green[i][j]=I*(1+s*cos(toRad(h))/(cos(toRad(60-h))));
		blue[i][j]=3*I-red[i][j]-green[i][j];
	}else{
		h-=240;	
		blue[i][j]=I*(1+s*cos(toRad(h))/(cos(toRad(60-h))));;
		green[i][j]=I*(1-s);
		red[i][j]=3*I-green[i][j]-blue[i][j];
	}

}			
void modify(int i,int j){
	sat[i][j]*=1.1;
	inten[i][j]+=50;
}

int main(){
	ifstream ip("q1.ppm");
	string s;
	getline(ip,s);
	int v;
	ip>>v>>v>>v;
	for(int i=1;i<=200;i++)
		for(int j=1;j<=200;j++)
			ip>>red[i][j]>>green[i][j]>>blue[i][j];	
	for(int i=1;i<=200;i++)
		for(int j=1;j<=200;j++){
			RGBTOHSI(i,j);
			modify(i,j);
		}
	for(int i=1;i<=200;i++)
		for(int j=1;j<=200;j++){
			HSITORGB(i,j);
		}
	ofstream op("q2.ppm");
	op<<"P3# CREATOR: GIMP PNM Filter Version 1.1"<<endl;
	op<<"200 200"<<endl;
	op<<"255"<<endl;
	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++)
			op<<red[i][j]<<" "<<green[i][j]<<" "<<blue[i][j]<<"\t";
		op<<endl;
	};
	op.close();
	cout<<"done"<<endl;	
	return 0;	
}


