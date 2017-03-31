#ifndef __ST_RECT_H__
#define __ST_RECT_H__

#include "stShape.h"

class Rect : public Shape
{
private:
	GLfloat originX;
	GLfloat originY;
	GLfloat originZ;
	GLfloat width;
	GLfloat height;
	
public:
	Rect(GLfloat originX, GLfloat originY, GLfloat originZ, GLfloat width, GLfloat height);
	Rect(GLfloat originX, GLfloat originY, GLfloat width, GLfloat height) : Rect(originX, originY, 0.0f, width, height) {};
	Rect(GLfloat originX, GLfloat originY, GLfloat edge) : Rect(originX, originY, 0.0f, edge, edge) {};
	//Ack! X, Y, Z, width and height are all GLfloats. I have a Rect that takes three GLfloats, one that takes four, and one that takes five.
	//This means that I can't further overload the constructor! I can't make a constructor that makes a square at any level other than Z=0!
	~Rect() override;
	GLfloat* getVerts() override {return this->verts.data();};
	GLubyte* getColors() override {return this->colors.data();};
	GLushort* getIndices() override {return this->indices.data();};
	
	GLfloat getOriginX() override {return this->originX;};
	GLfloat getOriginY() override {return this->originY;};
	GLfloat getOriginZ() override {return this->originZ;};
	
	GLfloat getWidth() {return this->width;};
	GLfloat getHeight() {return this->height;};
	
	void genVerts() override;
	void genIndices() override;
	bool setColors(GLubyte** colors) override;
	void setColorToGLColor() override;
	void render() override;
	void update() override;
	void translate(GLfloat x, GLfloat y, GLfloat z) override;
};



#endif
