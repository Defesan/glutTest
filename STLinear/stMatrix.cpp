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


}

STVec3f* STMatrix33f::mulVector(STVec3f* vec)
{


}
	
void STMatrix33f::loadIdentity()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i == j)
			{
				this->data[j + (3 * i)] = 1.0f;
			}
			else
			{
				this->data[j + (3 * i)] = 0.0f;
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
