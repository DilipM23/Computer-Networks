#include<GL/glut.h>

int vx1 = 50, vy1 = 50, vx2 = 100, vy2 = 100;

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
	glBegin(GL_LINES);
		glVertex2i(vx1, vy1);
		glVertex2i(vx2, vy2);
	glEnd();

	glColor3f(1, 0, 0);
	glPointSize(5);
	glBegin(GL_LINES);
		glVertex2i(vx1 + 50, vy1);
		glVertex2i(vx2 + 50, vy2);
	glEnd();

	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Translate Line");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}