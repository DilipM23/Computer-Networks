#include<GL/glut.h>
#include<math.h>

int vx1 = -10, vy1 = -10, vx2 = 10, vy2 = -10, vx3 = 0, vy3 = 10;
float angle;
void myinit()
{
	gluOrtho2D(-20, 20, -20, 20);
}

void rotate(int &x, int &y, float ang)
{
	float radians = ang * 3.14 / 180.0;
	float newX = x * cos(radians) - y * sin(radians);
	float newY = x * sin(radians) + y * cos(radians);
	x = newX;
	y = newY;
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(vx1, vy1);
	glVertex2i(vx2, vy2);
	glVertex2i(vx3, vy3);
	glEnd();

	rotate(vx1, vy1, 360);
	rotate(vx2, vy2, 360);
	rotate(vx3, vy3, 360);

	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(vx1, vy1);
	glVertex2i(vx2, vy2);
	glVertex2i(vx3, vy3);
	glEnd();

	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotate Triangle");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}