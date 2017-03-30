#include "headers.h"
#include "stRect.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;
const int MIN_WIDTH = 50;
const int MIN_HEIGHT = 50;

void render();
void update();
void resize(GLsizei w, GLsizei h);
void initGL();
void handleKeys(unsigned char key, int x, int y);
