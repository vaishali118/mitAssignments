#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

float X1,Y1,X2,Y2;

void setpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,0.0,0.0);
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

int bres(int X1,int Y1, int X2, int Y2)
{
	int dx,dy,i,p;
	int xinc,yinc,inc1,inc2;
	int x,y;
	
	dx = X2-X1;
	dy = Y2-Y1;
	
	if(dx<0) dx = -dx;
	if(dy<0) dy = -dy;
	
	xinc=1;
	yinc=1;
	
	if(X2<X1) xinc=-1;
	if(Y2<Y1) yinc= -1;
	
	x=X1,y=Y1;
	
	if(dx>dy)
	{
		setpixel(x,y);
		p=2*dy-dx;
		inc1=2*(dy-dx);
		inc2=2*dy;
		
		for(i=0;i<dx;i++)
		{
			if(p>0)
			{
				y += yinc;
				p += inc1;
			}
			else
			{
				p += inc2;
			}
			
		x += xinc;
		setpixel(x,y);
		}
		
		
	}
	
	else
	{
		setpixel(x,y);
		p=2*dx-dy;
		inc1=2*(dx-dy);
		inc2=2*dx;
		
		for(i=0;i<dy;i++)
		{
			if(p>0)
			{
				x += xinc;
				p += inc1;
			}
			else
			{
				p += inc2;
			}
			
			y += yinc;
		setpixel(x,y);
		}
		
		
	}
	
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	bres(X1,Y1,X2,Y1);
	bres(X2,Y1,X2,Y2);
	bres(X2,Y2,X1,Y2);
	bres(X1,Y2,X1,Y1);
	glFlush();
}

int main(int argc, char**argv)
{
	cout<<"enter pt1 (X1,Y1)"<<"\n";
	cin>>X1;
	cin>>Y1;
	
	cout<<"\n";
	
	cout<<"enter pt1 (X2,Y2)"<<"\n";
	cin>>X2;
	cin>>Y2;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(640,480);
	glutCreateWindow("Bresehnam");
	init();
	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
