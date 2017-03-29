#include "glutTest.h"


//using namespace std;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("GLUT Playground");
	glutDisplayFunc(render);
	glutReshapeFunc(resize);
	initGL();
	
	glutMainLoop();
	
	return 0;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	
	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
	
	//glutSwapBuffers();
	glFlush();
}

void update()
{
	

}

void resize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio = 0.0f; 

	//This is where, in the SuperBible, they check to make sure height isn't zero.
	//However, I haven't been able to create a window with a height less than one.
	//That is an...'improvement', let's call it, from SDL, which just closed the window the moment either height or width went below 21.
	//Still, I don't see how height can be zero in any case.
	//But...thinking about it, let's not underestimate the power of fools when foolproofing. Just because I can't do it doesn't mean it can't be done!
	//It's something to remember -- something I think a lot of people don't really take to heart -- but it applies to *stupid* things, too.
	if(h == 0)
	{
		h = 1;
	}
	
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	aspectRatio = (GLfloat)w / (GLfloat)h;
	
	glOrtho(-100.0f, 100.0f, -100.0f / aspectRatio, 100.0f / aspectRatio, -1.0f, 1.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	GLenum error = glGetError();
	if(error != NO_ERROR)
	{
		std::cout << "Error: " << gluErrorString(error);
	}
}

void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //So sue me, I like to start a window off like a blank canvas.

}
