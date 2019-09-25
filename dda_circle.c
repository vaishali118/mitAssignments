#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include <stdlib.h>
#include<math.h>

float x,y;
float initx1,inity1,radius;

void display(){
       initx1=radius;
       inity1=0;
       float xn=initx1;
       float yn=inity1;

       glClear(GL_COLOR_BUFFER_BIT);
       int n=log2(radius);
       if(pow(2,n)<radius){
               n++;
       }
       float ipso=1/(pow(2,n));

       glBegin(GL_POINTS);
       glColor3f(0.0,1.0,0.0);
       glPointSize(30.0f);
       glVertex2f(initx1,inity1);
       do
       {
       initx1=initx1+(ipso*inity1);
       inity1=inity1-(ipso*initx1);
       glVertex2f(initx1+x,inity1+y);
       }while((xn-initx1)>ipso || (inity1-yn)<ipso);
       glEnd();
       glFlush();

}

void init(void){       
	glClearColor(1.0,1.0,1.0,0.0);
       	glMatrixMode(GL_PROJECTION);
       	glLoadIdentity();
       	gluOrtho2D(0,640,0,640);
}

int main(int argc, char *argv[]){
       	printf("Enter Space seperated points(x1,y1,radius  :)");
       	scanf("%f%f%f",&x,&y, &radius);
       	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("DDA CIRCLE");
       	init();
       	glutDisplayFunc(display);
	glutMainLoop();
       	return 0;
}

