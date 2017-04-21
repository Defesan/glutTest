#include "stMatrix.h"

/*	STMatrix33f
	3x3 column-major matrix with floats
 */

STMatrix33f::STMatrix33f(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	//Remember, OpenGL uses COLUMN-major ordering.
	//Therefore, this matrix should look alike this:
	//0  3  6
	//1  4  7
	//2  5  8
	//Which means pushing x1, then x2, then x3, then y1, etc.
	
	this->data.push_back(x1);
	this->data.push_back(x2);
	this->data.push_back(x3);
	this->data.push_back(y1);
	this->data.push_back(y2);
	this->data.push_back(y3);
	this->data.push_back(z1);
	this->data.push_back(z2);
	this->data.push_back(z3);

	//But at least for now, that's about it.
}

STMatrix33f* STMatrix33f::mul(STMatrix33f* m2)
{
	//These are made considerably easier by the fact that we'll only ever multiply matrices of the same dimensions, leading to a matrix...of the same dimensions.
	//So the product of two matrices,
	//		|a1  a2  a3|			|b1  b2  b3|
	//A =	|a4  a5  a6|   and B =  |b4  b5  b6|
	//		|a7  a8  a9|			|b7  b8  b9|
	//is equal to the 3x3 matrix(hold on to your hats)
	//      |(a1b1 + a2b4 + a3b7)  (a1b2 + a2b5 + a3b8)  (a1b3 + a2b6 + a3b9)|
	//      |																 |
	//AB =  |(a4b1 + a5b4 + a6b7)  (a4b2 + a5b5 + a6b8)  (a4b3 + a5b6 + a6b9)|
	//      |																 |
	//      |(a7b1 + a8b4 + a9b7)  (a7b2 + a8b5 + a9b8)  (a7b3 + a8b6 + a9b9)|
	STMatrix33f* result = new STMatrix33f();
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			//This had better dang well work. I trust the math, and I trust the code, but reality bites back sometimes.
			float val = (this->get(i,0) * m2->get(0,j)) + (this->get(i,1) * m2->get(1,j)) + (this->get(i,2) * m2->get(2,j));
			result->set(i,j,val);
		}
	}
	return result;
}

STVec3f* STMatrix33f::mulVector(STVec3f* vec)
{
	//Now for matrix-vector multiplication. No ambiguity at all here, since it only works one way.
	STVec3f* result = new STVec3f();
	
	//Let's try keeping the calls to a minimum.
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
