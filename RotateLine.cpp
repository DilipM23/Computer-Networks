#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

int vx1 = 0, vy1 = -10, vx2 = 0, vy2 = 10;

float rotatedvx1, rotatedvy1, rotatedvx2, rotatedvy2;

void myinit()
{
	gluOrtho2D(-20, 20, -20, 20);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(vx1, vy1);
	glVertex2i(vx2, vy2);
	glEnd();

	float angle = 90.0;
	float radians = angle * 3.14 / 180;

	rotatedvx1 = vx1 * cos(radians) - vy1 * sin(radians);
	rotatedvy1 = vx1 * sin(radians) + vy1 * cos(radians);
	rotatedvx2 = vx2 * cos(radians) - vy2 * sin(radians);
	rotatedvy2 = vx2 * sin(radians) + vy2 * cos(radians);

	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
		glVertex2f(rotatedvx1, rotatedvy1);
		glVertex2f(rotatedvx2, rotatedvy2);
	glEnd();

	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotate Line");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}