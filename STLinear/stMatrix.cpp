#include "stMatrix.h"

/*	STMatrix33f
	3x3 column-major matrix with floats
 */

STMatrix33f::STMatrix33f(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{	
	this->data.push_back(x1);
	this->data.push_back(x2);
	this->data.push_back(x3);
	this->data.push_back(y1);
	this->data.push_back(y2);
	this->data.push_back(y3);
	this->data.push_back(z1);
	this->data.push_back(z2);
	this->data.push_back(z3);

}

STMatrix33f* STMatrix33f::mul(STMatrix33f* m2)
{
	STMatrix33f* result = new STMatrix33f();
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			float val = (this->get(i,0) * m2->get(0,j)) + (this->get(i,1) * m2->get(1,j)) + (this->get(i,2) * m2->get(2,j));
			result->set(i,j,val);
		}
	}
	return result;
}

STVec3f* STMatrix33f::mulVector(STVec3f* vec)
{
	STVec3f* result = new STVec3f();
	
	float x = vec->getX();
	float y = vec->getY();
	float z = vec->getZ();
	
	result->setX((this->get(0,0) * x) + (this->get(0,1) * y) + (this->get(0,2) * z));
	result->setY((this->get(1,0) * x) + (this->get(1,1) * y) + (this->get(1,2) * z));
	result->setZ((this->get(2,0) * x) + (this->get(2,1) * y) + (this->get(2,2) * z));
	
	return result;
}
	
void STMatrix33f::loadIdentity()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i == j)
			{
				this->set(i,j,1.0f);
			}
			else
			{
				this->set(i,j,0.0f);
			}
		}
	}
}

void STMatrix33f::loadRotationMatrix(float angle, float x, float y, float z)
{


}

void STMatrix33f::loadTranslationMatrix(float x, float y, float z)
{


}

void STMatrix33f::loadScaleMatrix(float x, float y, float z)
{


}

void STMatrix33f::loadPerspectiveMatrix(float fov, float aspect, float zMin, float zMax)
{


}

void STMatrix33f::loadOrthoMatrix(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax)
{



}

/*  STMatrix44f
	4x4 column-major matrix with floats
 */
 
STMatrix44f::STMatrix44f(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2, float x3, float y3, float z3, float w3, float x4, float y4, float z4, float w4)
{
	this->data.push_back(x1);
	this->data.push_back(x2);
	this->data.push_back(x3);
	this->data.push_back(x4);
	this->data.push_back(y1);
	this->data.push_back(y2);
	this->data.push_back(y3);
	this->data.push_back(y4);
	this->data.push_back(z1);
	this->data.push_back(z2);
	this->data.push_back(z3);
	this->data.push_back(z4);
	this->data.push_back(w1);
	this->data.push_back(w2);
	this->data.push_back(w3);
	this->data.push_back(w4);
}

STMatrix44f* STMatrix44f::mul(STMatrix44f* m2)
{
	STMatrix44f* result = new STMatrix44f();
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			float val = (this->get(i,0) * m2->get(0,j)) + (this->get(i,1) * m2->get(1,j)) + (this->get(i,2) * m2->get(2,j)) + (this->get(i,3) * m2->get(3,j));
			result->set(i,j,val);
		}
	}
	return result;
}

STVec4f* STMatrix44f::mulVector(STVec4f* vec)
{
	STVec4f* result = new STVec4f();
	
	float x = vec->getX();
	float y = vec->getY();
	float z = vec->getZ();
	float w = vec->getW();
	
	result->setX((this->get(0,0) * x) + (this->get(0,1) * y) + (this->get(0,2) * z) + (this->get(0,3) * w));
	result->setY((this->get(1,0) * x) + (this->get(1,1) * y) + (this->get(1,2) * z) + (this->get(1,3) * w));
	result->setZ((this->get(2,0) * x) + (this->get(2,1) * y) + (this->get(2,2) * z) + (this->get(2,3) * w));
	result->setW((this->get(3,0) * x) + (this->get(3,1) * y) + (this->get(3,2) * z) + (this->get(3,3) * w));
	
	return result;
}

void STMatrix44f::loadIdentity()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(i == j)
			{
				this->set(i,j,1.0f);
			}
			else
			{
				this->set(i,j,0.0f);
			}
		}
	}
}

void STMatrix44f::loadRotationMatrix(float angle, float x, float y, float z)
{


}

void STMatrix44f::loadTranslationMatrix(float x, float y, float z)
{


}

void STMatrix44f::loadScaleMatrix(float x, float y, float z)
{


}

void STMatrix44f::loadPerspectiveMatrix(float fov, float aspect, float zMin, float zMax)
{


}

void STMatrix44f::loadOrthoMatrix(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax)
{



}

/*	STMatrix33d
	3x3 column-major matrix with doubles
 */
 
STMatrix33d::STMatrix33d(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{
	this->data.push_back(x1);
	this->data.push_back(x2);
	this->data.push_back(x3);
	this->data.push_back(y1);
	this->data.push_back(y2);
	this->data.push_back(y3);
	this->data.push_back(z1);
	this->data.push_back(z2);
	this->data.push_back(z3);
}

STMatrix33d* STMatrix33d::mul(STMatrix33d* m2)
{
	STMatrix33d* result = new STMatrix33d();
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			double val = (this->get(i,0) * m2->get(0,j)) + (this->get(i,1) * m2->get(1,j)) + (this->get(i,2) * m2->get(2,j));
			result->set(i,j,val);
		}
	}
	return result;
	
}

STVec3d* STMatrix33d::mulVector(STVec3d* vec)
{
	STVec3d* result = new STVec3d();
	
	double x = vec->getX();
	double y = vec->getY();
	double z = vec->getZ();
	
	result->setX((this->get(0,0) * x) + (this->get(0,1) * y) + (this->get(0,2) * z));
	result->setY((this->get(1,0) * x) + (this->get(1,1) * y) + (this->get(1,2) * z));
	result->setZ((this->get(2,0) * x) + (this->get(2,1) * y) + (this->get(2,2) * z));
	
	return result;
}
	
void STMatrix33d::loadIdentity()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i == j)
			{
				this->set(i,j,1.0);
			}
			else
			{
				this->set(i,j,0.0);
			}
		}
	}
}

void STMatrix33d::loadRotationMatrix(double angle, double x, double y, double z)
{


}

void STMatrix33d::loadTranslationMatrix(double x, double y, double z)
{


}

void STMatrix33d::loadScaleMatrix(double x, double y, double z)
{


}

void STMatrix33d::loadPerspectiveMatrix(double fov, double aspect, double zMin, double zMax)
{


}

void STMatrix33d::loadOrthoMatrix(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax)
{


}

/*  STMatrix44d
	4x4 column-major matrix with doubles
 */
 
STMatrix44d::STMatrix44d(double x1, double y1, double z1, double w1, double x2, double y2, double z2, double w2, double x3, double y3, double z3, double w3, double x4, double y4, double z4, double w4)
{
	this->data.push_back(x1);
	this->data.push_back(x2);
	this->data.push_back(x3);
	this->data.push_back(x4);
	this->data.push_back(y1);
	this->data.push_back(y2);
	this->data.push_back(y3);
	this->data.push_back(y4);
	this->data.push_back(z1);
	this->data.push_back(z2);
	this->data.push_back(z3);
	this->data.push_back(z4);
	this->data.push_back(w1);
	this->data.push_back(w2);
	this->data.push_back(w3);
	this->data.push_back(w4);
}

STMatrix44d* STMatrix44d::mul(STMatrix44d* m2)
{
	STMatrix44d* result = new STMatrix44d();
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			double val = (this->get(i,0) * m2->get(0,j)) + (this->get(i,1) * m2->get(1,j)) + (this->get(i,2) * m2->get(2,j)) + (this->get(i,3) * m2->get(3,j));
			result->set(i,j,val);
		}
	}
	return result;
}

STVec4d* STMatrix44d::mulVector(STVec4d* vec)
{
	STVec4d* result = new STVec4d();
	
	double x = vec->getX();
	double y = vec->getY();
	double z = vec->getZ();
	double w = vec->getW();
	
	result->setX((this->get(0,0) * x) + (this->get(0,1) * y) + (this->get(0,2) * z) + (this->get(0,3) * w));
	result->setY((this->get(1,0) * x) + (this->get(1,1) * y) + (this->get(1,2) * z) + (this->get(1,3) * w));
	result->setZ((this->get(2,0) * x) + (this->get(2,1) * y) + (this->get(2,2) * z) + (this->get(2,3) * w));
	result->setW((this->get(3,0) * x) + (this->get(3,1) * y) + (this->get(3,2) * z) + (this->get(3,3) * w));
	
	return result;
}

void STMatrix44d::loadIdentity()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(i == j)
			{
				this->set(i,j,1.0);
			}
			else
			{
				this->set(i,j,0.0);
			}
		}
	}
}

void STMatrix44d::loadRotationMatrix(double angle, double x, double y, double z)
{


}

void STMatrix44d::loadTranslationMatrix(double x, double y, double z)
{


}

void STMatrix44d::loadScaleMatrix(double x, double y, double z)
{


}

void STMatrix44d::loadPerspectiveMatrix(double fov, double aspect, double zMin, double zMax)
{


}

void STMatrix44d::loadOrthoMatrix(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax)
{


}
