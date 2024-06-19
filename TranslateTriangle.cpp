#include<GL/glut.h>

int vx1 = 50, vy1 = 50, vx2 = 150, vy2 = 50, vx3 = 100, vy3 = 100;

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
	glBegin(GL_TRIANGLES);
	glVertex2i(vx1, vy1);
	glVertex2i(vx2, vy2);
	glVertex2i(vx3, vy3);
	glEnd();

	glColor3f(1, 0, 0);
	glPointSize(5);
	glBegin(GL_TRIANGLES);
	glVertex2i(vx1 + 50, vy1 + 50);
	glVertex2i(vx2 + 50, vy2 + 50);
	glVertex2i(vx3 + 50, vy3 + 50);
	glEnd();

	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Translate Triangle");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}