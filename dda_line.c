#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>

float x1,x2,y1,y2;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
 	glColor3f(0.0f,1.0f,0.0f);
	float dx, dy, len,i,xinc,yinc;
	dx=abs(x2-x1);
	dy=abs(y2-y1);

	if(dx>=dy)
	   len = dx;
	else
	   len = dy;

	xinc=(x2-x1)/len;
	yinc=(y2-y1)/len;

	for(i=0; i<=len; i++) {
		x1=x1+xinc;
		y1=y1+yinc;
		glVertex2f(x1,y1);
	}
	glEnd();
	glFlush();
}

void Init() {
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char *argv[]){
	printf("Enter the value of x1,y1");
	scanf("%f",&x1);
	scanf("%f",&y1);
	printf("Enter the value of x2,y2");
	scanf("%f",&x2);
	scanf("%f",&y2);
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("DDA LINE");
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
