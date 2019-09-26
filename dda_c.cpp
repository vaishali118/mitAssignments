#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<iostream>

using namespace std;
int xc,yc,r;

void Init()
{
glClearColor(1.0,1.0,1.0,0);
glColor3f(1.0,0.0,0.0);
gluOrtho2D(0,640,480,0);

}

void dda_cir(int xc,int yc, int r)
{
	
	int xc1,yc1,xc2,yc2,sx,sy;
	int eps,val,i;
	
	xc1 = r;
	yc1 = 0;
	
	sx = xc1;
	sy = yc1;
	
	i=0;
	
	do
	{
		val = pow(2,i);
		i++;
	}while(val<r);
	
	eps = 1/pow(2,i-1);
	
	do
	{
		xc2 = xc1 + eps*yc1;
		yc2 = yc1 - eps*xc2;
		
		glBegin(GL_POINTS);
		glVertex2d(xc+xc2,yc+yc2);
		
		xc1 = xc2;
		yc1 = yc2;	
		
	}while((yc1-sy)<eps || (sx-xc1)>eps);
	
	glEnd();
	
	glFlush();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	dda_cir(xc,yc,r);
}

int main(int argc,char** argv)
{
	cout<<"Enter centre points : "<<"\n";
	cin>>xc,
	cin>>yc;
	cout<<"\nEnter radius : ";
	cin>>r;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("DDA CIRCLE");
	glutInitWindowPosition(10,10);
	glutInitWindowSize(500,500);
	
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
