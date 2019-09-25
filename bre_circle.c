#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<math.h>

int xc,yc,r;

void pixel(int x,int y) {
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void circle(int xc,int yc,int r) {
	glClear(GL_COLOR_BUFFER_BIT);
	int x=0,y=r;
	float p=3-(2*r);
	pixel(x,y);
	while(x<=y)
	{
		pixel(xc+x,yc+y);
		pixel(xc+y,yc+x);
		pixel(xc+x,yc-y);
		pixel(xc-y,yc+x);
		pixel(xc-x,yc-y);
		pixel(xc-y,yc-x);
		pixel(xc-x,yc+y);
		pixel(xc+y,yc-x);
		
		if(p<0){
			p+=4*x+6;
		}
		
		else {
			p+=4*(x-y)+10;
			y-=1;
		}

		x=x+1;
	}
}

void display() {
	circle(xc,yc,r);
	glEnd();
	glFlush();
}

void Init() {
	glClearColor(1.0,1.0,1.0,0);
 	glColor3f(0.0,1.0,0.0);
 	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char *argv[]){
	printf("Enter the value of center :");
        scanf("%d",&xc);
        scanf("%d",&yc);
        printf("Enter the radius of circle :");
        scanf("%d",&r);
        glutInit(&argc, argv);
        glutInitWindowSize(500,500);
        glutInitWindowPosition(100,100);
        glutCreateWindow("BRESENHAM'S CIRCLE");
        Init();
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;
}
