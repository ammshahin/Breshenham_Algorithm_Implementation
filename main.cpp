#include<stdio.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1,x2,y1,y2,p,dx,dy,i,j;

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);

glColor3ub(120,45,125);

for(i = x1,j = y1; i<=x2,j<=y2;i++,j++){
    if ( p < 0 ){
    i = i +1;

    glVertex3f(i,j,0);
    p = p + (2*dy);

   }
   if ( p >= 0 ){
    i = i +1;
    j = j + 1;
    glVertex3f(i,j,0);
    p = p + (2*dy)- (2*dx);

   }
}




glEnd();
glFlush ();
}


void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, 100, 0, 100, -10.0, 10.0);
}




int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow ("PC_B");

printf("value of x1: ");
scanf("%f",&x1);

printf("value of y1: ");
scanf("%f",&y1);

printf("value of x2: ");
scanf("%f",&x2);

printf("value of x2: ");
scanf("%f",&y2);

//Finding the value of slope, m-
dy = y2-y1;
dx = x2-x1;
p = (2*dy) - dx;
printf("%f",p);

init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
