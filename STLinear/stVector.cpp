#include "stVector.h"

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


