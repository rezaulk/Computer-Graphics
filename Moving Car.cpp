#include<cstdio>
#include<windows.h>

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

int h=1,m=0;

GLfloat up,down;
GLfloat y=0.0f;
GLfloat position = 0.0f;
GLfloat speed = 0.1f;

float ballX = -0.5f;
float ballY = -0.012f;
float ballZ = 0.0f;


void update(int value)
{
    if(position > 1.0)
        position = -1.2f;
    else if(position < -1.2)
        position = 1.0f;

    if(down==3)
    {
        y=-.20f;
        up=0;
    }
    if(up==3)
    {
        y=-.00f;
        down=0;
    }
    position += speed;

    glutPostRedisplay();


    glutTimerFunc(100, update, 0);
}

void drawBall(void) {
        glColor3f(0.0, 1.0, 0.0); //set ball colour
        glTranslatef(-.5f,-.25f,0.0f); //moving it toward the screen a bit on creation
        //glRotatef(ballX,ballX,ballY,ballZ);
        glutSolidSphere (0.08, 30, 30); //create ball.
        glTranslatef(ballX+1,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.08, 30, 30); //

        }


void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            speed += 0.1f;
            printf("clicked at (%d, %d)\n", x, y);
        }
    }

    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'a':
        speed = 0.0f;
        break;
    case 'w':
        speed = 0.1f;
        break;

    case 'l':
        speed = -0.1f;
        break;

    case 'r':
        speed = 0.1f;
        break;

    case '+':

        speed += 0.1f;
        break;

    case '-':
        if(speed<=0)
        {
            speed = 0.0f;
        }
        else
        {
            speed-=.10f;
        }
        break;
    case 'd':
        down=3;
        up=0;
        break;

    case 'u':
        up=3;
        down=0;
        break;
        glutPostRedisplay();


    }
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

//1st quad
    glBegin(GL_POLYGON);
    glColor3f(0.827f, 0.827f, 0.827f);
    glVertex2f(-1,-1);
    glVertex2f(1,-1 );
    glVertex2f(1,-.4 );
    glVertex2f(-1,-.4);
    glEnd();


//2nd quad
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1,-.35);
    glVertex2f(1,-.35 );
    glVertex2f(1,-.0 );
    glVertex2f(-1,-.0);
    glEnd();


    //dash line

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-.9,-.2);
    glVertex2f(-.8,-.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-.75,-.2);
    glVertex2f(-.65,-.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-.6,-.2);
    glVertex2f(-.5,-.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-.45,-.2);
    glVertex2f(-.35,-.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-.3,-.2);
    glVertex2f(-.2,-.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-.15,-.2);
    glVertex2f(-.05,-.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-.15,-.2);
    glVertex2f(-.05,-.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-.0,-.2);
    glVertex2f(.10,-.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.15,-.2);
    glVertex2f(.25,-.2);
    glEnd();


   glPushMatrix();
   glTranslatef(position,y, 0.0f);
   drawBall();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-.7f,-.012f);
    glVertex2f(.13f,-.012f );
    glVertex2f(.25f,.25f );
    glVertex2f(.13f,.38f);
    glVertex2f(-.7f,.38f);
    glEnd();


 glPopMatrix();
//3rd quad
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-1,0.3f);
    glVertex2f(1,0.3f );
    glVertex2f(1,1 );
    glVertex2f(-1,1);
    glEnd();




    /*glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f( 0.2f, -0.2f);
    glVertex2f( 0.2f,  0.2f);
    glVertex2f(-0.2f,  0.2f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.2f,-0.2f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.2f, 0.2f);
    glEnd();

    glPopMatrix();*/

    glFlush();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Basic Animation");
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}
