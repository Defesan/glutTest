#include "glutTest.h"


//using namespace std;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("GLUT Playground");
	glutDisplayFunc(render);
	glutReshapeFunc(resize);
	glutKeyboardFunc(handleKeys);
	initGL();
	
	glutMainLoop();
	
	return 0;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	Rect* rect = new Rect(0.0f, 0.0f, 50.0f);
	rect->translate(20.0f, 30.0f, 0.0f);
	rect->setColorToGLColor();
	rect->render();

	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	Rect* rect2 = new Rect(0.0f, 0.0f, 50.0f);
	rect2->translate(-20.0f, -30.0f, 0.0f);
	rect2->setColorToGLColor();
	rect2->render();
	
	glutSwapBuffers();
	glFlush();
}

void update()
{
	

}

void resize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio = 0.0f; 

	if(h == 0)
	{
		h = 1;
	}

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (GLfloat)w / (GLfloat)h;
	if(w <= h)
	{
		glOrtho(-100.0f, 100.0f, -100.0f / aspectRatio, 100.0f / aspectRatio, -1.0f, 1.0f);
	}
	else
	{
		glOrtho(-100.0f * aspectRatio, 100.0f * aspectRatio, -100.0f, 100.0f, -100.0f, 100.0f);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLenum error = glGetError();
	if(error != GL_NO_ERROR)
	{
		std::cout << "Error: " << gluErrorString(error);
	}
}

void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //So sue me, I like to start a window off like a blank canvas.

}

void handleKeys(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			glutDestroyWindow(glutGetWindow());
			exit(0);
			break;
		default:
			break;
	}
}
