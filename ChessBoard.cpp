#include <windows.h>  
#include <GL/glut.h>  

void display() {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);        

	glBegin(GL_QUADS);        
	glColor3f(1.0f, 1.0f, 1.0f); 

	double k=-0.9,l=-0.7;
	double m=0.9,n=.7;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			glVertex2f(k, m);  
			glVertex2f(l, m);
			glVertex2f(l, n);
			glVertex2f(k, n);

			k=k+0.4;
			l=l+0.4;
		}
		m=m-0.4;
		n=n-0.4;
		k=-0.9,l=-0.7;
	}
	glColor3f(1.0f, 1.0f, 1.0f);
	 
	k=-0.7,l=-0.5;
    m=0.7,n=0.5;

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			glVertex2f(k, m);    
			glVertex2f(l, m);
			glVertex2f(l, n);
			glVertex2f(k, n);

			k=k+0.4;
			l=l+0.4;
		}
		m=m-0.4;
		n=n-0.4;
		k=-0.7,l=-0.5;
	}
	glEnd();

	//////
	glBegin(GL_QUADS);        
	glColor3f(0.0f, 0.0f, 0.0f); 

	 k=-0.7,l=-0.5;
	 m=0.9,n=.7;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			glVertex2f(k, m);  
			glVertex2f(l, m);
			glVertex2f(l, n);
			glVertex2f(k, n);

			k=k+0.4;
			l=l+0.4;
		}
		m=m-0.4;
		n=n-0.4;
		k=-0.7,l=-0.5;
	}
	glColor3f(0.0f, 0.0f, 0.0f);
	 
	k=-0.9,l=-0.7;
    m=0.7,n=0.5;

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			glVertex2f(k, m);    
			glVertex2f(l, m);
			glVertex2f(l, n);
			glVertex2f(k, n);

			k=k+0.4;
			l=l+0.4;
		}
		m=m-0.4;
		n=n-0.4;
		k=-0.9,l=-0.7;
	}
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
