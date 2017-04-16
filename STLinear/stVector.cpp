#include "stVector.h"

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
	product += this->getW() * v2->getW();

	return product;
}

STVec4f* STVec4f::crossProduct(STVec4f* v2)
{



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
	product += this->getW() * v2->getW();

	return product;
}

STVec4d* STVec4d::crossProduct(STVec4d* v2)
{



}
