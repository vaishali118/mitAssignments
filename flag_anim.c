#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

int state=1;
float flag_position=-6.0;
float y_position=-10.0;

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_POLYGON);			// Ground
	glColor3f(0.0,0.9,0.0);
	glVertex2f(-10.0,-10.0);
	glVertex2f(10.0,-10.0);
	glVertex2f(10.0,-5.0); 
	glVertex2f(-10.0,-5.0);
 	glEnd();


	glBegin(GL_POLYGON);			// Box
	glColor3f(0.4, 0.5, 0.4);
	glVertex2f(-3.0,y_position);
	glVertex2f(3.0,y_position);
	glVertex2f(3.0,y_position+2.0); 
	glVertex2f(-3.0,y_position+2.0);
 	glEnd();

	
	glBegin(GL_POLYGON);			// Rod
	glColor3f(0.1, 0.1, 0.1);
	glVertex2f(-0.7,-8.0);
	glVertex2f(0.0,-8.0);
	glVertex2f(0.0,6.0); 
	glVertex2f(-0.7,6.0);
 	glEnd();

	
float PI=3.4;				// Sky
float X = -5.0;
float Y = 7.0;
float radius1 = 0.9;
int i=6;
int triangleAmount = 1000;
GLfloat twicePi = 2.0f * PI;

glEnable(GL_LINE_SMOOTH);
glLineWidth(5.0);

glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
for(int j=0; j<=1; j++)
{
for(i = 0; i <= triangleAmount; i++)
{
glVertex2f( X, Y);
glVertex2f(X + (radius1 * cos(i * twicePi / triangleAmount)), Y + (radius1 * sin(i * twicePi / triangleAmount)));
}
    X = X-3;
    Y = Y;
}
X = -6.0;
Y = 6;
for(int j=0; j<=1; j++)
{
for(i = 0; i <= triangleAmount; i++)
{
glVertex2f( X, Y);
glVertex2f(X + (radius1 * cos(i * twicePi / triangleAmount)), Y + (radius1 * sin(i * twicePi / triangleAmount)));
}
    X = X;
    Y = Y+2;
}

X = -7.0;
Y = 6;
for(int j=0; j<=1; j++)
{
for(i = 0; i <= triangleAmount; i++)
{
glVertex2f( X, Y);
glVertex2f(X + (radius1 * cos(i * twicePi / triangleAmount)), Y + (radius1 * sin(i * twicePi / triangleAmount)));
}
    X = X;
    Y = Y+2;
}

X = -6.5;
Y = 6.5;
for(i = 0; i <= triangleAmount; i++)
{
glVertex2f( X, Y);
glVertex2f(X + (radius1 * cos(i * twicePi / triangleAmount)), Y + (radius1 * sin(i * twicePi / triangleAmount)));
}
glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.3, 0.0);
	glVertex2f(0.0,flag_position);
	glVertex2f(5.0,flag_position);
	glVertex2f(5.0,flag_position+1);
 	glVertex2f(0.0,flag_position+1);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.0,flag_position+1);
	glVertex2f(5.0,flag_position+1);
	glVertex2f(5.0,flag_position+2);
 	glVertex2f(0.0,flag_position+2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex2f(0.0,flag_position+2);
	glVertex2f(5.0,flag_position+2);
	glVertex2f(5.0,flag_position+3);
 	glVertex2f(0.0,flag_position+3);
	glEnd();

float x = 2.5;
float y= flag_position+1.5;
float radius = 0.45;


glEnable(GL_LINE_SMOOTH);
glLineWidth(5.0);

glBegin(GL_LINES);
glColor3f(0.0, 0.0, 1.0);
for(i = 0; i <= triangleAmount; i++)
{
glVertex2f( x, y);
glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
}
glEnd();

	glFlush();
	glutSwapBuffers();
}

void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}
void timer(int t)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);
	

if(flag_position<3)
flag_position+=0.15;
else
state=2;
}

void init()
{
glClearColor(0.0,0.9,0.9,0.0);
}



int main(int argc,char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Animation");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	init();
	glutMainLoop();
}

