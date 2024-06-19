#include<GL/glut.h>
#include<math.h>

int vx1 = 2, vy1 = 2, vx2 = 8, vy2 = 2, vx3 = 8, vy3 = 8, vx4 = 2, vy4 = 8;
int vx5 = 2, vy5 = 8, vx6 = 8, vy6 = 8, vx7 = 5, vy7 = 13;

void myinit()
{
	gluOrtho2D(0, 20, 0, 20);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(vx1, vy1);
	glVertex2i(vx2, vy2);
	glVertex2i(vx3, vy3);
	glVertex2i(vx4, vy4);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(vx5, vy5);
	glVertex2i(vx6, vy6);
	glVertex2i(vx7, vy7);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(vx1 + 2, vy1 + 2);
	glVertex2i(vx2 + 2, vy2 + 2);
	glVertex2i(vx3 + 2, vy3 + 2);
	glVertex2i(vx4 + 2, vy4 + 2);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(vx5 + 2, vy5 + 2);
	glVertex2i(vx6 + 2, vy6 + 2);
	glVertex2i(vx7 + 2, vy7 + 2);
	glEnd();

	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Translate House");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}