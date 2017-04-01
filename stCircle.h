#ifndef __ST_CIRCLE_H__
#define __ST_CIRCLE_H__

#include "stShape.h"



class Circle : public Shape
{
private:
	GLfloat originX;
	GLfloat originY;
	GLfloat originZ;
	GLfloat radius;
	GLushort numSlices;
public:
	
	Circle(GLfloat originX, GLfloat originY, GLfloat originZ, GLfloat radius, GLushort numVerts);
	Circle(GLfloat originX, GLfloat originY, GLfloat radius) : Circle(originX, originY, 0.0f, radius, 12) {};
	~Circle() override;
	
	GLfloat* getVerts() override {return this->verts.data();};
	GLubyte* getColors() override {return this->colors.data();};
	GLushort* getIndices() override {return this->indices.data();};
	
	GLfloat getOriginX() override {return this->originX;};
	GLfloat getOriginY() override {return this->originY;};
	GLfloat getOriginZ() override {return this->originZ;};
	
	GLfloat getRadius() {return this->radius;};
	
	void genVerts() override;
	void genIndices() override;
	bool setColors(GLubyte** colors) override;
	void setColorToGLColor() override;
	void render() override;
	void update() override;
	void translate(GLfloat x, GLfloat y, GLfloat z) override;
};


#endif
