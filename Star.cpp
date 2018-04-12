#include <windows.h>
#include <GL/glut.h>

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(7.5);
    glVertex2f(0.0f,5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();


    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(.5);
    glVertex2f(-0.02f,-0.03f);
    glVertex2f(-0.5f,.5f);
    glEnd();

    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(7.5);
    glVertex2f(-0.3f,-0.3f);
    glVertex2f(-0.5f,.5f);
    glEnd();

    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(7.5);
    glVertex2f(-0.3f,-0.3f);
    glVertex2f(-0.2f,.5f);
    glEnd();

    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(7.5);
    glVertex2f(-0.6f,-0.03f);
    glVertex2f(-0.2f,.5f);
    glEnd();

    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(7.5);
    glVertex2f(-0.6f,-0.03f);
    glVertex2f(-0.02f,-0.03f);
    glEnd();



	/*glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex2f(.25f, -0.25f);
	glVertex2f(0.5f, -0.45f);*/

    glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex2f(.35f, 0.0f);
	glVertex2f(.65f, -0.25f);


	glVertex2f(0.55f, 0.10f);
	glVertex2f(0.70f, 0.30f);

	glVertex2f(0.45f, 0.30f);
	glVertex2f(0.35f, 0.5f);


	glVertex2f(0.25f, 0.30f);
	glVertex2f(0.05f, 0.30f);

	glVertex2f(0.15f, 0.10f);
	glVertex2f(0.10f, -0.25f);


	 glEnd();


	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	GLint width;
    GLint height;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    width = glutGet(GLUT_SCREEN_WIDTH);
    height = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(height, height);
    glutCreateWindow("ChessBoard");
    glutDisplayFunc(display);
    glutMainLoop();

	return 0;
}


