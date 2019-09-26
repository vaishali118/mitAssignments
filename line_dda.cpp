#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

double xa,ya,xb,yb;

float round(float v)
{
	return floor(v+0.5);
}

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,0.0,0.0);
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

int dda(int xa, int ya, int xb, int yb)
{
	double dx = xb - xa;
	double dy = yb - ya;
	double steps;
	float xinc,yinc, x= xa, y=ya;
	
	steps = (abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
	
	xinc = dx/(float)steps;
	yinc = dy/(float)steps;
	
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	
	for(int k=0; k<steps; k++)
	{
		x += xinc;
		y += yinc;
		
		glVertex2d(round(x),round(y));
	}
	
	glEnd();
	
	
	glFlush();
	
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	dda(xa,ya,xb,ya);
	dda(xb,ya,xb,yb);
	dda(xb,yb,xa,yb);
	dda(xa,yb,xa,ya);
	dda((xa+xb)/2,ya,xb,(ya+yb)/2);
	dda(xb,(ya+yb)/2,(xa+xb)/2,yb);
	dda((xa+xb)/2,yb,xa,(ya+yb)/2);
	dda(xa,(ya+yb)/2,(xa+xb)/2,ya);
	dda( ((xa+xb)/2+xa)/2, ((ya+yb)/2+ya)/2, ((xa+xb)/2+xb)/2, ((ya+yb)/2+ya)/2 );
	dda( ((xa+xb)/2+xb)/2, ((ya+yb)/2+ya)/2, ((xa+xb)/2+xb)/2, ((ya+yb)/2+yb)/2 );
	dda( ((xa+xb)/2+xb)/2, ((ya+yb)/2+yb)/2, ((xa+xb)/2+xa)/2, ((ya+yb)/2+yb)/2 );
	dda( ((xa+xb)/2+xa)/2, ((ya+yb)/2+yb)/2, ((xa+xb)/2+xa)/2, ((ya+yb)/2+ya)/2 );
}
	


int main(int argc, char** argv)
{
	cout<<"Enter P1(xa,ya) : "<<"\n";
	cin>>xa;
	cin>>ya;
	
	cout<<"\n";
	
	cout<<"Enter P2(xb,yb) : "<<"\n";
	cin>>xb;
	cin>>yb;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(20.0,20.0);
	glutInitWindowSize(640.0,480.0);
	glutCreateWindow("DDA");
	init();
	
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
	
}
