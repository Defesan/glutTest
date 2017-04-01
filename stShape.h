#ifndef __ST_SHAPE_H__
#define __ST_SHAPE_H__

#include <cmath>
#include <iostream>
#include <vector>

#if defined(__IPHONEOS__) || defined(__ANDROID__)
#define USING_OPENGLES
#endif

#ifdef USING_OPENGLES
#include "SDL_opengles.h"
#else
#include "SDL2/SDL_opengl.h"
#endif

#define PI 3.1415926

//Ah, the prototypical abstract class. But... I am making shapes here, so I need one.
class Shape
{
	//These shapes are going to be defined in terms of vertices, triangles, and colors. So...each one has to have all three. Doesn't matter what it is.
protected:
	//GLfloat* verts;
	//GLubyte* colors;
	//GLushort* indices;
	
	//The c-style arrays were okay, but not good enough.
	std::vector<GLfloat> verts;
	std::vector<GLubyte> colors;
	std::vector<GLushort> indices;
	
	//To be honest, EVERY shape will have these!
	GLfloat originX;
	GLfloat originY;
	GLfloat originZ;
		
	//Generate the vertices of the object.
	virtual void genVerts() = 0;
	
	//Take the vertices and try and piece them together in such a way that it generates a shape.
	virtual void genIndices() = 0;
	
public:
	
	virtual bool setColors(GLubyte** colors) = 0;
	
	virtual void setColorToGLColor() = 0;
	
	virtual GLubyte* getColors() = 0;
	virtual GLfloat* getVerts() = 0;
	virtual GLushort* getIndices() = 0;
	
	virtual GLfloat getOriginX() = 0;
	virtual GLfloat getOriginY() = 0;
	virtual GLfloat getOriginZ() = 0;
	
	virtual void render() = 0;
	virtual void update() = 0;
	
	virtual void translate(GLfloat x, GLfloat y, GLfloat z) = 0;
	

	virtual ~Shape() {};
};


#endif
