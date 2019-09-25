#include<iostream>
#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>

float X1,X2,Y1,Y2;

void pixel(int x, int y) {
	glBegin(GL_POINTS);
 	glVertex2i(x,y);
 	glEnd();
 	glFlush();
}

void bresenham(void){       
	glClear(GL_COLOR_BUFFER_BIT);
        
	int dx, dy, i, p;
        int incx, incy, inc1, inc2;
        int x,y;

        dx = X2-X1;
        dy = Y2-Y1;

        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;
        incx = 1;
        if (X2 < X1) incx = -1;
        incy = 1;
        if (Y2 < Y1) incy = -1;
        x = X1; y = Y1;
        if (dx > dy) {
                pixel(x, y);
                p = 2 * dy-dx;
                inc1 = 2*(dy-dx);
                inc2 = 2*dy;
                for (i=0; i<dx; i++) {
                        if (p >= 0) {
                                y += incy;
                                p += inc1;
                        }
                        else
                                p += inc2;
                        x += incx;
                        pixel(x, y);
                }

        } else {
                pixel(x, y);
                p = 2*dx-dy;
                inc1 = 2*(dx-dy);
                inc2 = 2*dx;
                for (i=0; i<dy; i++) {
                        if (p >= 0) {
                                x += incx;
                                p += inc1;
                        }
                        else
                                p += inc2;
                        y += incy;
                        pixel(x, y);
                }
        }
}

void init(){
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glMatrixMode(GL_PROJECTION);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("BRESENHAM'S LINE");
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0f,1.0f,0.0f);
	gluOrtho2D(0,500,0,500);
}



int main(int argc, char **argv) {
	printf("Enter the values of  x1,y1 : ");
        scanf("%f", &X1);
        scanf("%f", &Y1);
        printf("Enter the values of  x2,y2 : ");
        scanf("%f", &X2);
        scanf("%f", &Y2);

        glutInit (&argc, argv);
        init();
        glutDisplayFunc(bresenham);
        glutMainLoop ();
        return 0;
}
