#include "headers.h"
#include "stRect.h"
#include "stCircle.h"
#include "stSphere.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;
const GLfloat PROJECTION_HEIGHT = 100.0f;
const GLfloat PROJECTION_WIDTH = 100.0f;
const GLfloat PROJECTION_DEPTH = 100.0f;
const int MIN_WIDTH = 50;
const int MIN_HEIGHT = 50;

//Ugh...globals. But they'll do for now.
std::vector<Shape*> geometry;
//Rect* rect;
bool generated = false;
GLfloat xVel = 0.0f;
GLfloat yVel = 0.0f;
GLfloat zVel = 0.0f;

GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
GLfloat zRot = 0.0f;

bool cwWinding = false;
bool backfaceCull = true;
bool depthTest = false;
bool backfaceLines = false;

void render();
void update();
void resize(GLsizei w, GLsizei h);
void initGL();
void handleKeys(unsigned char key, int x, int y);
void specialKeys(int key, int x, int y);
void specialKeysUp(int key, int x, int y);
void runLoop(int val);
void processMenu(int value);
void setSettings();

//Honestly, these are just convenience functions.
bool shiftDown();
bool controlDown();
