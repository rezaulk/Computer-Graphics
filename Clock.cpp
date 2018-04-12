#include<windows.h>
#include <stdio.h>
#include <GL/glut.h>

float min=0,hour=0,count=0;
float a=0;
int h;
void rotate1()
{
    glPushMatrix();
    float a=0;
    min-=25;
    glRotatef(min,0,0,1);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(1,1);
    glVertex2f(100,100);
    glEnd();
     glPopMatrix();
}
void rotate2()
{
    glPushMatrix();
    glRotatef(hour,0,0,1);
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(1,1);
    glVertex2f(1,100);
    glEnd();
    glPopMatrix();
}



void drawCircle(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glColor3f(1.0,0.0,0.0);

    int x=0,y=150;
    int d=1-h;
    while(y>x)
    {
        if(d>=0)
        {
            d+=2*x-2*y+5;
            y-=1;

        }
        else
        {
            d+=2*x+3;
        }
        x+=1;
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glVertex2i(-x,-y);
        glVertex2i(-x,y);
        glVertex2i(x,-y);
        glVertex2i(y,x);
        glVertex2i(-y,-x);
        glVertex2i(-y,x);
        glVertex2i(y,-x);
        glVertex2i(-x,-y);
        glEnd();
    }

    rotate1();

    rotate2();
    count++;
    if(count==60)
      {
          hour-=.5;
          count=0;
      }



    glFlush ();

}
void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(1000,timer,0);
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    //glClearColor3f(0,100,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutCreateWindow ("Mid Point Circle Algorithm");
    glutTimerFunc(0,timer,0);
    glutDisplayFunc(drawCircle);
    myInit ();
    glutMainLoop();
}
