#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;

int X,Y,R;

void setpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glEnd();
	glFlush();
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0,500.0,0,500.0);
}

void bres_cir(int X,int Y,int R)
{
	int d;
	int x=0;
	int y=R;
	
	d=3-2*R;
	while(x<=y)
	{
		setpixel(X+x,Y+y);
		setpixel(X+x,Y-y);
		setpixel(X-x,Y+y);
		setpixel(X-x,Y-y);
		setpixel(X+y,Y+x);
		setpixel(X+y,Y-x);
		setpixel(X-y,Y-x);
		setpixel(X-y,Y+x);
			
		
		
		if(d<0)
		{
			d = d+4*x+6;
		}
		else
		{
			d = d+4*(x-y)+10;
			y--;
		}
		
		x++;
	}
	
	glEnd();
	
	glFlush();
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	bres_cir(X,Y,R);
}
int main(int argc,char **argv)
{

cout<<"Enter centre points : "<<"\n";
cin>>X;
cin>>Y;

cout<<"\nEnter radius : ";
cin>>R;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500, 500);
glutCreateWindow("Bres_Circle");;
glutDisplayFunc(display);
Init();
glutMainLoop();
return 0;
}
