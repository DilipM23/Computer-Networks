#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<string.h>

int xmin = 0, xmax = 200, ymin = 0, ymax = 200;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xmin, xmax, ymin, ymax);
	glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	if (w > h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xmin * w / h, xmax * w / h, ymin, ymax);
		glMatrixMode(GL_MODELVIEW);
	}
	else
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xmin, xmax, ymin * h / w, ymax * h / w);
		glMatrixMode(GL_MODELVIEW);
	}
	glutPostRedisplay();
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
		glVertex2i(20, 20);
		glVertex2i(20, 40);
		glVertex2i(40, 40);
		glVertex2i(40, 20);
	glEnd();
	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Reshape Function");
	myinit();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}