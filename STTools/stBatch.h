#ifndef __ST_BATCH_H__
#define __ST_BATCH_H__

/*
	I can certainly understand the virtue of having a base class for these batches...but calling it BatchBase is a bit much.
	Also, a trick I recall from my compilers class, sometimes you want to know the type of subclass you're working with.
 */
 
#define GLEW_STATIC
#include <GL/glew.h>
#include <vector>

enum BATCH_TYPE {TRIANGLE, PRIMITIVE};

class STBatch
{
protected:
	BATCH_TYPE type;
	//We're low-level enough here that we can dispense with the custom containers. The batch processing 
	//system expects arrays of floats or doubles, which can be grabbed from vectors, so it's easier to use the raw info.
	//Still don't want to go the C route unless I find there's a significant performance penalty. There's a value in readability, after all.
	//Also, I suspect the STL has improved in the past fifteen years in terms of performance, both memory- and time-wise.
	std::vector<GLdouble> verts;
	std::vector<GLdouble> norms;
	std::vector<std::vector<GLdouble>> texCoords;	//Not sure about this....
	std::vector<GLfloat> colors;	//Really doesn't need *that* much precision
	std::vector<GLuint> indices;
	 
public:
	virtual void draw() = 0;
}; 


#endif //__ST_BATCH_H__
