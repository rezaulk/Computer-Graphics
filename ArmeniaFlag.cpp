#include <windows.h>  
#include <GL/glut.h>  

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);      
	glLineWidth(7.5);

	glBegin(GL_QUADS);             
	glColor3f(1.0f, 0.0f, 0.0f); 
	
	   glVertex2f(-0.9f,0.9f);   
	   glVertex2f(0.4f,0.9f); 
	   glVertex2f(0.4f, 0.7f);   
	   glVertex2f(-0.9f, 0.7f);
	
	glColor3f(0.0f, 0.0f, 1.0f);
	
	   glVertex2f(-0.9f,0.7f);   
	   glVertex2f(0.4f,0.7f); 
	   glVertex2f(0.4f, 0.5f);   
	   glVertex2f(-0.9f, 0.5f);  
	
	glColor3f(1.0f, 1.0f, 0.0f); 
	
	   glVertex2f(-0.9f,0.5f);   
	   glVertex2f(0.4f,0.5f); 
	   glVertex2f(0.4f, 0.3f);   
	   glVertex2f(-0.9f, 0.3f);  
	
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

	glutCreateWindow("Armenia Flag");
	glutDisplayFunc(display); 
	glutMainLoop();       
	return 0;
}