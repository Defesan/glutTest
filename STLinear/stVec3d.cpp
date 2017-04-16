#include "stVec3d.h"

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
