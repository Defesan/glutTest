#include "stVec3f.h"

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
