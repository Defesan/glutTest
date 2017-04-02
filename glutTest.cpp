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
	//render();
	
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
		geometry[0]->setVelocity(0.15f, 0.1f, 0.0f);
		//geometry.push_back(new Circle(-30.0f, 20.0f, 10.0f));
		//glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		//geometry[1]->setColorToGLColor();
		geometry.push_back(new Rect(0.0f, 0.0f, 20.0f));
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		geometry[1]->setColorToGLColor();
		geometry[1]->setVelocity(-0.2f, 0.05f, 0.0f);
		
		
		generated = true;
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//More best practices practice.
	std::vector<Shape*>::iterator iter;
	int i = 0;
	for(iter = geometry.begin(); iter != geometry.end(); iter++)
	{
		(*iter)->update(); //Update calls render.
		std::cout << "Object " << i << " z-value = " << (*iter)->getOriginZ() << "\n";
		i++;
	}
	std::cout << std::endl;
	glutSwapBuffers();
	glFlush();
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
