#include <GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(5, 0, 0);//cor em cordenada rgb
	//glPointSize(10);
	glLineWidth(5);
	/*glBegin(GL_TRIANGLES); //USE COMO PRAMETRO AS PRIMITIVAS 
		glVertex2f(-8, -5);
		glColor3f(0, 0, 1);
		glVertex2f(8, -5);
		glVertex2f(-8, 0);
		glColor3f(0, 5, 0);
		glVertex2f(8, 0);
		glVertex2f(-8, 5);
		glVertex2f(8, 5);
	glEnd();*/
	glBegin(GL_QUADS);
		
		
		
		  
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);//double animação single imagem estatica
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(display);
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1, 1, 1, 1);
	glutMainLoop();
	return 0;
}
