#include<windows.h>
#include<iostream>
#include<math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <time.h>

using namespace std;
GLint  positionX=0,birdY=0,speed=30;
int up=400,down=300;
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(0.0, 1000.0, 0.0, 600.0, -1.0, 1.0);
}
int random(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand( time(NULL) );
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}
void Newpoint()
{
    down=random(50,300);

    if(down>=250)
    {
        up=random(370,55);
    }
    else
    {
        up=random(down+120,550);
    }
}

void update(int value)
{
    if(positionX <=-1000)
    {
        positionX=0;
        Newpoint();
    }

    positionX-=speed;

    if(birdY<up&&birdY>down)
    {
        cout<<"finish"<<endl;
    }

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glTranslatef(0.0f,birdY, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(100,200);
    glVertex2f(150,200);
    glVertex2f(150,250);
    glVertex2f(100,250);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(200,225);
    glVertex2f(150,200);
    glVertex2f(150,250);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(75,210);
    glVertex2f(100,210);
    glVertex2f(100,240);
    glVertex2f(75,240);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(positionX,0.0f, 0.0f);

    glBegin(GL_QUADS);
    glVertex2f(900,up);
    glVertex2f(950,up);
    glVertex2f(950,600);
    glVertex2f(900,600);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(900,0);
    glVertex2f(950,0);
    glVertex2f(950,down);
    glVertex2f(900,down);
    glEnd();

    glPopMatrix();


    glFlush();
}
void SpecialFunc(int key, int x, int y)
{

        if(key == GLUT_KEY_UP)
        {
            birdY+=10;
        }
        else if(key == GLUT_KEY_DOWN)
        {
            birdY-=10;
        }

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Flappy Bird");
    glutDisplayFunc(display);
    init();

    glutSpecialFunc(SpecialFunc);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
