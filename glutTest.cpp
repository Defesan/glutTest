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
	glutSpecialFunc(specialKeys);
	glutSpecialUpFunc(specialKeysUp);
	
	glutCreateMenu(processMenu);
	glutAddMenuEntry("Switch Winding Direction", 1);
	glutAddMenuEntry("Toggle Backface Culling", 2);
	glutAddMenuEntry("Toggle Depth Testing", 3);
	glutAddMenuEntry("Toggle Backface Line Mode", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	
	glutTimerFunc(1000 / SCREEN_FPS, runLoop, 0);
	initGL();
	
	glutMainLoop();
	
	return 0;
}

void runLoop(int val)
{
	update();
	
	glutPostRedisplay();
	glutTimerFunc(1000 / SCREEN_FPS, runLoop, val);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if(!generated)
	{
		geometry.push_back(new Rect(0.0f, 0.0f, -90.0f, 30.0f, 50.0f));
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		geometry[0]->setColorToGLColor();
		geometry[0]->setVelocity(0.15f, 0.1f, 0.04f);
		geometry.push_back(new Circle(25.0f, 0.0f, -30.0f, 10.0f, 40));
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		geometry[1]->setColorToGLColor();
		geometry[1]->setVelocity(0.05f, 0.3f, -2.0f);
		geometry.push_back(new Rect(0.0f, 0.0f, -100.0f, 20.0f, 20.0f));
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		geometry[2]->setColorToGLColor();
		geometry[2]->setVelocity(-0.2f, 0.05f, -0.3f);
		geometry.push_back(new Sphere(0.0f, 0.0f, -100.0f, 20.0f, 12, 40));
		geometry[3]->setVelocity(0.0f, 0.0f, 0.0f);
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
	
	setSettings();

	//More best practices practice.
	std::vector<Shape*>::iterator iter;

	for(iter = geometry.begin(); iter != geometry.end(); iter++)
	{
		(*iter)->update(); //Update calls render.
	}
	glTranslatef(xVel, yVel, zVel);
	//glTranslatef(0.0f, 0.0f, 100.0f);
	glRotatef(xRot, 0.0f, 1.0f, 0.0f);
	glRotatef(yRot, 1.0f, 0.0f, 0.0f);
	glRotatef(zRot, 0.0f, 0.0f, 1.0f);
	//glTranslatef(0.0f, 0.0f, -100.0f);
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
	//if(w <= h)
	//{
	//	glOrtho(-PROJECTION_WIDTH, PROJECTION_WIDTH, -PROJECTION_HEIGHT / aspectRatio, PROJECTION_HEIGHT / aspectRatio, -PROJECTION_DEPTH, PROJECTION_DEPTH);
	//}
	//else
	//{
	//	glOrtho(-PROJECTION_WIDTH * aspectRatio, PROJECTION_WIDTH * aspectRatio, -PROJECTION_HEIGHT, PROJECTION_HEIGHT, -PROJECTION_DEPTH, PROJECTION_DEPTH);
	//}
	
	gluPerspective(45.0f, aspectRatio, 1.0f, 200.0f);
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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_FLAT);
}

void processMenu(int value)
{
	switch(value)
	{
		case 1:
			//clockwise winding
			cwWinding = !cwWinding;
			if(cwWinding)
			{
				std::cout << "Clockwise Winding." << std::endl;
			}
			else
			{
				std::cout << "Counterclockwise Winding." << std::endl;
			}
			break;
		case 2:
			//backface culling
			backfaceCull = !backfaceCull;
			if(backfaceCull)
			{
				std::cout << "Culling Backfaces." << std::endl;
			}
			else
			{
				std::cout << "Not culling." << std::endl;
			}
			break;
		case 3:
			//depth testing
			depthTest = !depthTest;
			if(depthTest)
			{
				std::cout << "Depth test enabled." << std::endl;
			}
			else
			{
				std::cout << "Depth test disabled." << std::endl;
			}
			break;
		case 4:
			//backface face/line drawing
			backfaceLines = !backfaceLines;
			if(backfaceLines)
			{
				std::cout << "Wireframe backfaces." << std::endl;
			}
			else
			{
				std::cout << "Filled backfaces." << std::endl;
			}
			break;
		default:
			break;
	
	}

}

bool shiftDown()
{
	if(glutGetModifiers() & GLUT_ACTIVE_SHIFT)
	{
		return true;
	}
	return false;
}

bool controlDown()
{
	if(glutGetModifiers() & GLUT_ACTIVE_CTRL)
	{
		return true;
	}
	return false;
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

void specialKeys(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			if(controlDown())	//handle rotations
			{
				if(shiftDown())	//Y/Z switch
				{
					zRot = 0.1f;
				}
				else
				{
					yRot = 0.1f;
				}
			}
			else				//handle translations
			{
				if(shiftDown())
				{
					zVel = 0.1f;
				}
				else
				{
					yVel = 0.1f;
				}
			}
			break;
		case GLUT_KEY_DOWN:
			if(controlDown())	//handle rotations
			{
				if(shiftDown())	//Y/Z switch
				{
					zRot = -0.1f;
				}
				else
				{
					yRot = -0.1f;
				}
			}
			else				//handle translations
			{
				if(shiftDown())
				{
					zVel = -0.1f;
				}
				else
				{
					yVel = -0.1f;
				}
			}
			break;
		case GLUT_KEY_LEFT:
			if(controlDown())
			{
				xRot = -0.1f;
			}
			else
			{
				xVel = -0.1f;
			}
			break;
		case GLUT_KEY_RIGHT:
			if(controlDown())
			{
				xRot = 0.1f;
			}
			else
			{
				xVel = 0.1f;
			}
			break;
		default:
			break;
	}
}

void specialKeysUp(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN:
			yVel = 0.0f;
			zVel = 0.0f;
			yRot = 0.0f;
			zRot = 0.0f;
			break;
		case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT:
			xVel = 0.0f;
			xRot = 0.0f;
			break;
		default:
			break;
	}

}


void setSettings()
{
	if(depthTest)
	{
		glEnable(GL_DEPTH_TEST);
	}
	else
	{
		glDisable(GL_DEPTH_TEST);
	}
	
	if(backfaceCull)
	{
		glEnable(GL_CULL_FACE);
	}
	else
	{
		glDisable(GL_CULL_FACE);
	}
	
	if(backfaceLines)
	{
		glPolygonMode(GL_BACK, GL_LINE);
	}
	else
	{
		glPolygonMode(GL_BACK, GL_FILL);
	}
	
	if(cwWinding)
	{
		glFrontFace(GL_CW);
	}
	else
	{
		glFrontFace(GL_CCW);
	}	

}
