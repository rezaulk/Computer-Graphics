#include<cstdio>
#include<windows.h>

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat up,down;
GLfloat y=0.0f;
GLfloat position = 0.0f;
GLfloat speed = 0.1f;

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

//1st quad water level
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-1,-1);
    glVertex2f(1,-1 );
    glVertex2f(1,-.7 );
    glVertex2f(-1,-.7);
    glEnd();

    glPushMatrix();
    glTranslatef(position,y, 0.0f);

//2nd
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-.5f,-.7f);
    glVertex2f(.5f,-.7f );
    glVertex2f(.7f,-.4f );
    glVertex2f(-.7,-.4f);
    glEnd();
//3rd
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex2f(-.5f,-.4f);
    glVertex2f(.5f,-.4f );
    glVertex2f(.5f,-.2f );
    glVertex2f(-.5f,-.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, 0.6f);
    glVertex2f(-.4f,-.2f);
    glVertex2f(.4f,-.2f );
    glVertex2f(.4f,-.1f );
    glVertex2f(-.4f,-.1f);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-.40f,-.27f);
    glVertex2f(-.20f,-.27f );
    glVertex2f(-.20f,-.23f );
    glVertex2f(-.40f,-.23f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-.10f,-.27f);
    glVertex2f(.1f,-.27f );
    glVertex2f(.1f,-.23f );
    glVertex2f(-.10f,-.23f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(.15f,-.27f);
    glVertex2f(.35f,-.27f );
    glVertex2f(.35f,-.23f );
    glVertex2f(.15f,-.23f);
    glEnd();

//pillar
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-.30f,-.1f);
    glVertex2f(-.20f,-.1f );
    glVertex2f(-.20f,.2f );
    glVertex2f(-.30f,.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.5f,0);
    glVertex2f(-.30f,.2f);
    glVertex2f(-.20f,.2f );
    glVertex2f(-.20f,.25f );
    glVertex2f(-.30f,.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-.15f,-.1f);
    glVertex2f(-.05f,-.1f );
    glVertex2f(-.05f,.2f );
    glVertex2f(-.15f,.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.5f,0);
    glVertex2f(-.15f,.2f);
    glVertex2f(-.05f,.2f );
    glVertex2f(-.05f,.25f );
    glVertex2f(-.15f,.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(0.05f,-.1f);
    glVertex2f(.15f,-.1f );
    glVertex2f(.15f,.2f );
    glVertex2f(.05f,.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,.5f,0);
    glVertex2f(0.05f,.2f);
    glVertex2f(.15f,.2f );
    glVertex2f(.15f,.25f );
    glVertex2f(.05f,.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(.20f,-.1f);
    glVertex2f(.30f,-.1f );
    glVertex2f(.30f,.2f );
    glVertex2f(.20f,.2f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,.5f,0);
    glVertex2f(.20f,.2f);
    glVertex2f(.30f,.2f );
    glVertex2f(.30f,.25f );
    glVertex2f(.20f,.25f);
    glEnd();

    glPopMatrix();
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
    glutInitWindowSize(1500, 1500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Basic Animation");
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}
