#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#ifndef M_PI 
#define M_PI 3.1415926535 
#endif

int tx, ty;
int sx, sy;
double angle;

void initialSquare()
{
	glColor3f(1,1,1);
    	glBegin(GL_LINES);
    	glVertex2i(200,200);
    	glVertex2i(200,400);
    	glVertex2i(400,400);
    	glVertex2i(400,200);
	glVertex2i(400,400);
    	glVertex2i(200,400);
	glVertex2i(200,200);
    	glVertex2i(400,200);
    	glEnd();
	glFlush();
}

void translatedSquare()
{
	glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2i(200 + tx,200 + ty);
    glVertex2i(200 + tx,400 + ty);
    glVertex2i(400 + tx,400 + ty);
    glVertex2i(400 + tx,200 + ty);
    glVertex2i(400 + tx,400 + ty);
    glVertex2i(200 + tx,400 + ty);
    glVertex2i(200 + tx,200 + ty);
    glVertex2i(400 + tx,200 + ty);
    glEnd();
    glFlush();
}
void translation()
{
	initialSquare();
	translatedSquare();
}
void scaledSquare()
{
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2i(200 * sx,200 * sy);
    glVertex2i(200 * sx,400 * sy);
    glVertex2i(400 * sx,400 * sy);
    glVertex2i(400 * sx,200 * sy);
    glVertex2i(400 * sx,400 * sy);
    glVertex2i(200 * sx,400 * sy);
    glVertex2i(200 * sx,200 * sy);
    glVertex2i(400 * sx,200 * sy);
    glEnd();
    glFlush();
}
void scaling()
{
	initialSquare();
	scaledSquare();
}
void rotatedSquare()
{
    double cx = 200;
    double cy = 200;
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(cx + (200 - cx) * cos(angle) - (200 - cy) * sin(angle),cx + (200 - cx) * sin(angle) + (200 - cy) * cos(angle));
    glVertex2d(cx + (200 - cx) * cos(angle) - (400 - cy) * sin(angle),cx + (200 - cx) * sin(angle) + (400 - cy) * cos(angle));
    glVertex2d(cx + (400 - cx) * cos(angle) - (400 - cy) * sin(angle),cx + (400 - cx) * sin(angle) + (400 - cy) * cos(angle));
    glVertex2d(cx + (400 - cx) * cos(angle) - (200 - cy) * sin(angle),cx + (400 - cx) * sin(angle) + (200 - cy) * cos(angle));
    glVertex2d(cx + (400 - cx) * cos(angle) - (400 - cy) * sin(angle),cx + (400 - cx) * sin(angle) + (400 - cy) * cos(angle));
    glVertex2d(cx + (200 - cx) * cos(angle) - (400 - cy) * sin(angle),cx + (200 - cx) * sin(angle) + (400 - cy) * cos(angle));
    glVertex2d(cx + (200 - cx) * cos(angle) - (200 - cy) * sin(angle),cx + (200 - cx) * sin(angle) + (200 - cy) * cos(angle));
    glVertex2d(cx + (400 - cx) * cos(angle) - (200 - cy) * sin(angle),cx + (400 - cx) * sin(angle) + (200 - cy) * cos(angle));
    glEnd();
    glFlush();
}
void rotation()
{
	initialSquare();
	rotatedSquare();
}

void myInit() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 600,0,600);
}
int main(int argc, char **argv)
{
	int ch,ch1;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	printf("\n1.TRANSLATION");
	printf("\n2.SCALING");
	printf("\n3.ROTATION");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	do
	{
	switch(ch)
	{
		case 1:
			printf("How much to move horizontally?");
			scanf("%d",&tx);
			printf("How much to move vertically?");
			scanf("%d",&ty);
			glutCreateWindow("Translation");
			myInit();
			glutDisplayFunc(translation);
			glutMainLoop();
			break;
		case 2:
			printf("How much to scale horizontally?");
			scanf("%d",&sx);
			printf("How much to scale vertically?");
			scanf("%d",&sy);
			glutCreateWindow("Scaling");
			myInit();
			glutDisplayFunc(scaling);
			glutMainLoop();
			break;
		case 3:
			printf("Enter Angle of rotation: ");
    		scanf("%lf",&angle);
   			angle = angle * M_PI / 180;
			glutCreateWindow("Rotation");
			myInit();
			glutDisplayFunc(rotation);
			glutMainLoop();
			break;
		default:
			printf("Invalid Choice");
			break;
			
	}
	printf("Do you want to continue(1/0)??");
	scanf("%d",&ch1);
}
while(ch1!=0);
return 0;
}
