#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdio>

#include <GL/gl.h>
#include <GL/glut.h>


void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

float SunRotation= 0.0;
float planetARotation= 0.0;
float planetBRotation= 0.0;
float planetCRotation= 0.0;

void drawCircle(float r, bool solid= false)
{
    if(solid) glBegin(GL_POLYGON);
    else glBegin(GL_LINES);

	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
	glEnd();
}

void drawPlanetA(){
    glColor3f(.2,.3,.2);
   // glPushMatrix();
    glTranslatef(0, 1, 0);

    glRotatef(planetARotation, 0, 0, 1);
    drawCircle(.15, true);
    //glPopMatrix();

}

void drawPlanetB(){
    glColor3f(.3,.5,.2);

    //glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glRotatef(planetBRotation, 0, 0, - 1);

    drawCircle(.2, true);
    //glPopMatrix();
}

void drawPlanetC(){
    glColor3f(.2,.7,0);
    //glPushMatrix();
    glTranslatef(0, 2, 0);
    glRotatef(planetCRotation, 0, 0, -1);
    drawCircle(.1, true);
    //glPopMatrix();
}

void drawOrbits(){
    glColor3f(1,1,1);

    drawCircle(1);
    drawCircle(1.5);
    drawCircle(2);
}

void drawSolarSystem(){
    glColor3f(1,0,.5);

    drawOrbits();
    glColor3f(1,1,0);

    //sun
    glRotatef(SunRotation, 0,0,1);
    drawCircle(.3, true);

    glPushMatrix();
    drawPlanetA();
    glPopMatrix();

    glPushMatrix();
    drawPlanetB();
    glPopMatrix();

    glPushMatrix();
    drawPlanetC();
    glPopMatrix();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0, 0.0, -7.0);
    drawSolarSystem();

	glutSwapBuffers();
}

void update(int value) {
    SunRotation += .5;
    planetARotation += 1;
    planetBRotation += 20;
    planetCRotation += 30;

	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200,100);

	glutCreateWindow("Solar");
	initRendering();

	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutTimerFunc(50, update, 0);

	glutMainLoop();
	return 0;
}
