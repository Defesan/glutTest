#include "stVector.h"

/*
	STVec2f
	2 element vector with floats	
*/
STVec2f::STVec2f(float x, float y)
{
	this->x = x;
	this->y = y;
}

void STVec2f::addVec2f(STVec2f* v2)
{
	this->addX(v2->getX());
	this->addY(v2->getY());
}

void STVec2f::subVec2f(STVec2f* v2)
{
	this->subX(v2->getX());
	this->subY(v2->getY());
}

void STVec2f::mulScalar(float scale)
{
	this->mulX(scale);
	this->mulY(scale);
}

float STVec2f::dotProduct(STVec2f* v2)
{
	float product = 0.0f;
	
	product += this=>getX() * v2->getX();
	product += this=>getY() * v2->getY();

	return product;
}


/*
	STVec3f
	3 element vector with floats	
*/
STVec3f::STVec3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void STVec3f::addVec3f(STVec3f* v2)
{
	this->addX(v2->getX());
	this->addY(v2->getY());
	this->addZ(v2->getZ());
}

void STVec3f::subVec3f(STVec3f* v2)
{
	this->subX(v2->getX());
	this->subY(v2->getY());
	this->subZ(v2->getZ());
}

void STVec3f::mulScalar(float scale)
{
	this->mulX(scale);
	this->mulY(scale);
	this->mulZ(scale);
}

float STVec3f::dotProduct(STVec3f* v2)
{
	float product = 0.0f;
	
	product += this=>getX() * v2->getX();
	product += this=>getY() * v2->getY();
	product += this=>getZ() * v2->getZ();

	return product;
}

STVec3f* STVec3f::crossProduct(STVec3f* v2)
{
	STVec3f* result = new STVec3f();
	
	result->setX((this->getY() * v2->getZ()) - (this->getZ() * v2->getY()));
	result->setY((this->getZ() * v2->getX()) - (this->getX() * v2->getZ()));
	result->setZ((this->getX() * v2->getY()) - (this->getY() * v2->getX()));
	
	return result;
}

/*
	STVec4f
	4 element vector with floats	
*/

STVec4f::STVec4f(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void STVec4f::addVec4f(STVec4f* v2)
{
	this->addX(v2->getX());
	this->addY(v2->getY());
	this->addZ(v2->getZ());
	this->addW(v2->getW());
}

void STVec4f::subVec4f(STVec4f* v2)
{
	this->subX(v2->getX());
	this->subY(v2->getY());
	this->subZ(v2->getZ());
	this->subW(v2->getW());
}

void STVec4f::mulScalar(float scale)
{
	this->mulX(scale);
	this->mulY(scale);
	this->mulZ(scale);
	this->mulW(scale);
}

float STVec4f::dotProduct(STVec4f* v2)
{
	float product = 0.0f;
	
	product += this=>getX() * v2->getX();
	product += this=>getY() * v2->getY();
	product += this=>getZ() * v2->getZ();
	product += this=>getW() * v2->getW();

	return product;
}



/*
	STVec2d
	2 element vector with double	
*/
STVec2d::STVec2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

void STVec2d::addVec2d(STVec2d* v2)
{
	this->addX(v2->getX());
	this->addY(v2->getY());
}

void STVec2d::subVec2d(STVec2d* v2)
{
	this->subX(v2->getX());
	this->subY(v2->getY());
}

void STVec2d::mulScalar(double scale)
{
	this->mulX(scale);
	this->mulY(scale);
}

double STVec2d::dotProduct(STVec2d* v2)
{
	double product = 0.0;
	
	product += this=>getX() * v2->getX();
	product += this=>getY() * v2->getY();

	return product;
}



/*
	STVec3d
	3 element vector with doubles	
*/

STVec3d::STVec3d(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void STVec3d::addVec3d(STVec3d* v2)
{
	this->addX(v2->getX());
	this->addY(v2->getY());
	this->addZ(v2->getZ());
}

void STVec3d::subVec3d(STVec3d* v2)
{
	this->subX(v2->getX());
	this->subY(v2->getY());
	this->subZ(v2->getZ());
}

void STVec3d::mulScalar(double scale)
{
	this->mulX(scale);
	this->mulY(scale);
	this->mulZ(scale);

}

double STVec3d::dotProduct(STVec3d* v2)
{
	double product = 0.0;
	
	product += this=>getX() * v2->getX();
	product += this=>getY() * v2->getY();
	product += this=>getZ() * v2->getZ();

	return product;
}

STVec3d* STVec3d::crossProduct(STVec3d* v2)
{
	STVec3d* result = new STVec3d();
	
	result->setX((this->getY() * v2->getZ()) - (this->getZ() * v2->getY()));
	result->setY((this->getZ() * v2->getX()) - (this->getX() * v2->getZ()));
	result->setZ((this->getX() * v2->getY()) - (this->getY() * v2->getX()));
	
	return result;
}


/*
	STVec4d
	4 element vector with doubles	
*/

STVec4d::STVec4d(double x, double y, double z, double w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void STVec4d::addVec4d(STVec4d* v2)
{
	this->addX(v2->getX());
	this->addY(v2->getY());
	this->addZ(v2->getZ());
	this->addW(v2->getW());
}

void STVec4d::subVec4d(STVec4d* v2)
{
	this->subX(v2->getX());
	this->subY(v2->getY());
	this->subZ(v2->getZ());
	this->subW(v2->getW());
}

void STVec4d::mulScalar(double scale)
{
	this->mulX(scale);
	this->mulY(scale);
	this->mulZ(scale);
	this->mulW(scale);
}

double STVec4d::dotProduct(STVec4d* v2)
{
	double product = 0.0;
	
	product += this=>getX() * v2->getX();
	product += this=>getY() * v2->getY();
	product += this=>getZ() * v2->getZ();
	product += this=>getW() * v2->getW();
	
	return product;
}
