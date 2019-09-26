#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;

int tx, ty;
float sx,sy;
double angle;
int choice;

void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0,500.0,0,500.0);
}

void shape()
{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0,0.0,0.0);
	glVertex2d(50,50);
	glVertex2d(100,50);
	glVertex2d(100,100);
	glVertex2d(50,100);
	
	glEnd();
	glFlush();
}

void translate(int tx,int ty)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,0.0,0.0);
	glVertex2d(50+tx,50+ty);
	glVertex2d(100+tx,50+ty);
	glVertex2d(100+tx,100+ty);
	glVertex2d(50+tx,100+ty);
	
	glEnd();
	glFlush();
	
}

void scale(float sx,float sy)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,0.0,0.0);
	glVertex2d(50*sx,50*sy);
	glVertex2d(100*sx,50*sx);
	glVertex2d(100*sx,100*sx);
	glVertex2d(50*sx,100*sx);
	
	glEnd();
	glFlush();
	
}

void rotate(double angle)
{
	double cx=50;
	double cy=50;
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,0.0,0.0);
	glVertex2d(cx+(50-cx)*cos(angle)-(50-cy)*sin(angle),cx+(50-cx)*sin(angle)+(50-cy)*cos(angle));
	glVertex2d(cx+(50-cx)*cos(angle)-(100-cy)*sin(angle),cx+(50-cx)*sin(angle)+(100-cy)*cos(angle));
	glVertex2d(cx+(100-cx)*cos(angle)-(100-cy)*sin(angle),cx+(100-cx)*sin(angle)+(100-cy)*cos(angle));
	glVertex2d(cx+(100-cx)*cos(angle)-(50-cy)*sin(angle),cx+(100-cx)*sin(angle)+(50-cy)*cos(angle));
	
	glEnd();
	glFlush();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	shape();
	
	if(choice == 1)
		translate(tx,ty);
	
	if(choice == 2)
		scale(sx,sy);
		
	if(choice == 3)
		rotate(angle);
	
	
	
}
int main(int argc, char **argv)
{
	
	

	cout<<" 1.Translate \n 2.Scale \n 3.Rotate \n ";
	cout<<"Enter Your Choice : "<<"\n";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			
			cout<<"enter tx :"<<"\n";
			cin>>tx;
	
			cout<<"enter ty :"<<"\n";
			cin>>ty;
			
			
		break;
		
		case 2:
			
			cout<<"enter sx :"<<"\n";
			cin>>sx;
	
			cout<<"enter sy :"<<"\n";
			cin>>sy;
		
		break;
		
		case 3:
			
			cout<<"enter angle : "<<"\n";
			cin>>angle;
			
			angle  = angle *3.14/180;
					
		break;
		
		default:
		
		break;
		
	}
	
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("2d");
	glutInitWindowPosition(10,10);
	glutInitWindowSize(500,500);
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

