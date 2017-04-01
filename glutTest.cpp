#include "glutTest.h"


//using namespace std;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("GLUT Playground");
	glutDisplayFunc(render);
	glutReshapeFunc(resize);
	glutKeyboardFunc(handleKeys);
	glutTimerFunc(1000 / SCREEN_FPS, runLoop, 0);
	initGL();
	
	glutMainLoop();
	
	return 0;
}

void runLoop(int val)
{
	update();
	render();
	
	glutPostRedisplay();
	glutTimerFunc(1000 / SCREEN_FPS, runLoop, val);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if(!generated)
	{
		geometry.push_back(new Rect(0.0f, 0.0f, 50.0f));
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		geometry[0]->setColorToGLColor();
		geometry.push_back(new Circle(-30.0f, 20.0f, 10.0f));
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		geometry[1]->setColorToGLColor();
		geometry.push_back(new Rect(0.0f, 0.0f, 20.0f));
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		geometry[2]->setColorToGLColor();
		
		generated = true;
		std::cout << "Name of first element in geometry vector: " << typeid(*geometry[0]).name() << "\n";
		std::cout << "Name of second element in geometry vector: " << typeid(*geometry[1]).name() << "\n";
		std::cout << "Name of third element in geometry vector: " << typeid(*geometry[2]).name() << std::endl;
	}
	for(unsigned int i = 0; i < geometry.size(); i++)
	{
		geometry[i]->render();
	}
	
	
	
	glutSwapBuffers();
	glFlush();
}

void update()
{
	//I have an idea for how to do this better, but it'll be a bit more work, and I want to get this working.
	
	//Or I *had* an idea on how to do it better, but it won't work.
	
	/*
	GLfloat offsetX = rect->getWidth() / 2;
	GLfloat offsetY = rect->getHeight() / 2;
	
	GLfloat posXBoundary = rect->getOriginX() + offsetX + xStep;
	GLfloat posYBoundary = rect->getOriginY() + offsetY + yStep;
	GLfloat negXBoundary = rect->getOriginX() - offsetX + xStep;
	GLfloat negYBoundary = rect->getOriginY() - offsetY + yStep;
	
	if(posXBoundary > PROJECTION_WIDTH || negXBoundary < -PROJECTION_WIDTH)
	{
		xStep *= -1;
	}
	if(posYBoundary > PROJECTION_HEIGHT || negYBoundary < -PROJECTION_HEIGHT)
	{
		yStep *= -1;
	}
	
	rect->translate(xStep, yStep, 0.0f);*/
	
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
		glOrtho(-PROJECTION_WIDTH, PROJECTION_WIDTH, -PROJECTION_HEIGHT / aspectRatio, PROJECTION_HEIGHT / aspectRatio, -PROJECTION_DEPTH, PROJECTION_DEPTH);
	}
	else
	{
		glOrtho(-PROJECTION_WIDTH * aspectRatio, PROJECTION_WIDTH * aspectRatio, -PROJECTION_HEIGHT, PROJECTION_HEIGHT, -PROJECTION_DEPTH, PROJECTION_DEPTH);
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
