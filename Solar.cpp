#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdio>

#include <GL/gl.h>
#include <GL/glut.h>


//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
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

void drawCircle(float r, bool solid= false){

    if(solid) glBegin(GL_POLYGON);
    else glBegin(GL_LINES);

	for(int i=0;i<200;i++)
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

    glPushMatrix();
    glTranslatef(0, 1, 0);

    glRotatef(planetARotation, 0, 0, 1);

//    printf("%d\n", planetARotation);

    drawCircle(.15, true);

    glPopMatrix();

}

void drawPlanetB(){
    glColor3f(.3,.5,.2);

    glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glRotatef(planetBRotation, 0, 0, - 1);
//    printf("%d\n", planetARotation);
    drawCircle(.2, true);
    glPopMatrix();
}

void drawPlanetC(){
    glColor3f(.2,.7,0);

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glRotatef(planetCRotation, 0, 0, -1);
//    printf("%d\n", planetARotation);
    drawCircle(.1, true);
    glPopMatrix();
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
    glPushMatrix();
    glRotatef(SunRotation, 0,0,1);
    drawCircle(.3, true);
    //glPopMatrix();

    //glPushMatrix();
    glRotatef(planetARotation, 0,0,0);
    drawPlanetA();
    glPopMatrix();

    //glPushMatrix();
    glRotatef(planetBRotation, 0,0,1);
    drawPlanetB();
    //glPopMatrix();

    glPushMatrix();
    glRotatef(planetCRotation, 0,0,-1);
    drawPlanetC();
    glPopMatrix();
}

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units


    //glPushMatrix();
    //glRotatef(45, -1,-1,0);

    drawSolarSystem();
    //glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {
    SunRotation += .5;
    planetARotation += .5;
    planetBRotation += .8;
    planetCRotation += .4;

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200,100);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
