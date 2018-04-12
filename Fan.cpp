#include<windows.h>
#include<gl/glut.h>
#include<stdio.h>

float min=0,hour=0,count=0,a=0;
int h=1,m=0;
int speed=1000,hm=1000;
float r,g,b,x,y;
bool check=true;
void f1()
{
    glPushMatrix();
    glRotatef(m,0,0,1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(40,-20);
    glVertex2f(200,0);
    glVertex2f(200,15);
    glVertex2f(40, 25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(m+120,0,0,1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(40,-20);
    glVertex2f(200,0);
    glVertex2f(200,15);
    glVertex2f(40, 25);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(m+240,0,0,1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(40,-20);
    glVertex2f(200,0);
    glVertex2f(200,15);
    glVertex2f(40, 25);
    glEnd();
    glPopMatrix();
    m-=10;

    /*glPushMatrix();
    glRotatef(m+=60,0,0,1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(40,-20);
    glVertex2f(200,0);
    glVertex2f(200,15);
    glVertex2f(40, 25);
    glEnd();
    glPopMatrix();/*/
}


void drawCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glColor3f(1.0,0.0,0.0);

    int x=0,y=40;
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
        glBegin(GL_POLYGON);
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

    glColor3f(1.0,1.0,0.0);

    x=0,y=30;
    d=1-h;
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
        glBegin(GL_POLYGON);
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

    glColor3f(1.0,0.0,1.0);

    x=0,y=20;
    d=1-h;
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
        glBegin(GL_POLYGON);
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

	 //glEnd();


    f1();
    glFlush ();


}


void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON)
    {
        speed-=250;
    }

    else if(button==GLUT_RIGHT_BUTTON)
    {
       speed+=250;
    }
    glutPostRedisplay();
}

void timer(int value)
{
    glutPostRedisplay();
     if(speed<0)
     {
         speed=0;
     }

    glutTimerFunc(speed,timer,0);
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}


int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Fan");
    glutTimerFunc(0,timer,0);

    glutDisplayFunc(drawCircle);
    glutMouseFunc(mouse);

    myInit();
    glutMainLoop();
}
