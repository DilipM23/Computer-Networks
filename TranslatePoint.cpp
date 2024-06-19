#include<GL/glut.h>

int vx = 50, vy = 50;

void myinit()
{
	gluOrtho2D(0, 500, 0, 500);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(vx, vy);
	glEnd();
	
	glColor3f(1, 0, 0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(vx + 50 , vy + 50);
	glEnd();

	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Translate Point");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}