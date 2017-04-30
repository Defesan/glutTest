#ifndef __ST_VECTOR_H__
#define __ST_VECTOR_H__

#include <cmath>
#include <vector>
/*
	Apparently I can occasionally use a 2D vector?
 */
 
class STVec2f
{
private:
	std::vector<float> data;

public:
	STVec2f(float x, float y);
	STVec2f() : STVec2f(0.0f, 0.0f) {};
	
	std::vector<float> getData {return this->data;};
	
	float getX() {return this->data[0];};
	float getY() {return this->data[1];};

	void setX(float x) {this->data[0] = x;};
	void setY(float y) {this->data[1] = y;};
	
	void addX(float x) {this->data[0] += x;};
	void addY(float y) {this->data[1] += y;};
	
	void subX(float x) {this->data[0] -= x;};
	void subY(float y) {this->data[1] -= y;};
	
	void mulX(float scale) {this->data[0] *= scale;};
	void mulY(float scale) {this->data[1] *= scale;};
	
	void addVec2f(STVec2f* v2);
	void subVec2f(STVec2f* v2);
	STVec2f* sum(STVec2f* v2);		//Returns a new vector that is the sum of this vector and another.
	STVec2f* diff(STVec2f* v2);		//Returns a new vector that is the difference between this vector and another.
	void mulScalar(float scale);
	float dotProduct(STVec2f* v2);
	float length() {return sqrtf(this->dotProduct(this));};
	float distance(STVec2f* v2);
};


class STVec3f
{
private:
	std::vector<float> data;
	
public:
	STVec3f(float x, float y, float z);
	STVec3f() : STVec3f(0.0f, 0.0f, 0.0f) {};
	
	std::vector<float> getData {return this->data;};
	
	float getX() {return this->data[0];};
	float getY() {return this->data[1];};
	float getZ() {return this->data[2];};

	void setX(float x) {this->data[0] = x;};
	void setY(float y) {this->data[1] = y;};
	void setZ(float z) {this->data[2] = z;};
	
	void addX(float x) {this->data[0] += x;};
	void addY(float y) {this->data[1] += y;};
	void addZ(float z) {this->data[2] += z;};
	
	void subX(float x) {this->data[0] -= x;};
	void subY(float y) {this->data[1] -= y;};
	void subZ(float z) {this->data[2] -= z;};
	
	void mulX(float scale) {this->data[0] *= scale;};
	void mulY(float scale) {this->data[1] *= scale;};
	void mulZ(float scale) {this->data[2] *= scale;};
	
	void addVec3f(STVec3f* v2);
	void subVec3f(STVec3f* v2);
	void mulScalar(float scale);
	STVec3f* sum(STVec3f* v2);
	STVec3f* diff(STVec3f* v2);
	float dotProduct(STVec3f* v2);
	STVec3f* crossProduct(STVec3f* v2);
	float length() {return sqrtf(this->dotProduct(this));};	//I'm hoping this'll work... Also hoping to find a reason for its existence.
	float distance(STVec3f* v2);
};

class STVec4f
{
private:
	std::vector<float> data;
	
public:
	STVec4f(float x, float y, float z, float w);
	STVec4f() : STVec4f(0.0f, 0.0f, 0.0f, 0.0f) {};
	
	std::vector<float> getData {return this->data;};
	
	float getX() {return this->data[0];};
	float getY() {return this->data[1];};
	float getZ() {return this->data[2];};
	float getW() {return this->data[3];};

	void setX(float x) {this->data[0] = x;};
	void setY(float y) {this->data[1] = y;};
	void setZ(float z) {this->data[2] = z;};
	void setW(float w) {this->data[3] = w;};
	
	void addX(float x) {this->data[0] += x;};
	void addY(float y) {this->data[1] += y;};
	void addZ(float z) {this->data[2] += z;};
	void addW(float w) {this->data[3] += w;};
	
	void subX(float x) {this->data[0] -= x;};
	void subY(float y) {this->data[1] -= y;};
	void subZ(float z) {this->data[2] -= z;};
	void subW(float w) {this->data[3] -= w;};
	
	void mulX(float scale) {this->data[0] *= scale;};
	void mulY(float scale) {this->data[1] *= scale;};
	void mulZ(float scale) {this->data[2] *= scale;};
	void mulW(float scale) {this->data[3] *= scale;};
	
	void addVec4f(STVec4f* v2);
	void subVec4f(STVec4f* v2);
	void mulScalar(float scale);
	STVec4f* sum(STVec4f* v2);
	STVec4f* diff(STVec4f* v2);
	float dotProduct(STVec4f* v2);
	float length() {return sqrtf(this->dotProduct(this));};
	float distance(STVec4f* v2);
};


class STVec2d
{
private:
	std::vector<double> data;

public:
	STVec2d(double x, double y);
	STVec2d() : STVec2d(0.0, 0.0) {};
	
	std::vector<double> getData {return this->data;};
	
	double getX() {return this->data[0];};
	double getY() {return this->data[1];};

	void setX(double x) {this->data[0] = x;};
	void setY(double y) {this->data[1] = y;};
	
	void addX(double x) {this->data[0] += x;};
	void addY(double y) {this->data[1] += y;};
	
	void subX(double x) {this->data[0] -= x;};
	void subY(double y) {this->data[1] -= y;};
	
	void mulX(double scale) {this->data[0] *= scale;};
	void mulY(double scale) {this->data[1] *= scale;};
	
	void addVec2d(STVec2d* v2);
	void subVec2d(STVec2d* v2);
	void mulScalar(double scale);
	STVec2d* sum(STVec2d* v2);
	STVec2d* diff(STVec2d* v2);
	double dotProduct(STVec2d* v2);
	double length() {return sqrt(this->dotProduct(this));};
	float distance(STVec2d* v2);
};


class STVec3d
{
private:
	std::vector<double> data;
	
public:
	STVec3d(double x, double y, double z);
	STVec3d() : STVec3d(0.0, 0.0, 0.0) {};
	
	std::vector<double> getData {return this->data;};
	
	double getX() {return this->data[0];};
	double getY() {return this->data[1];};
	double getZ() {return this->data[2];};

	void setX(double x) {this->data[0] = x;};
	void setY(double y) {this->data[1] = y;};
	void setZ(double z) {this->data[2] = z;};
	
	void addX(double x) {this->data[0] += x;};
	void addY(double y) {this->data[1] += y;};
	void addZ(double z) {this->data[2] += z;};
	
	void subX(double x) {this->data[0] -= x;};
	void subY(double y) {this->data[1] -= y;};
	void subZ(double z) {this->data[2] -= z;};
	
	void mulX(double scale) {this->data[0] *= scale;};
	void mulY(double scale) {this->data[1] *= scale;};
	void mulZ(double scale) {this->data[2] *= scale;};
	
	void addVec3d(STVec3d* v2);
	void subVec3d(STVec3d* v2);
	void mulScalar(double scale);
	STVec3d* sum(STVec3d* v2);
	STVec3d* diff(STVec3d* v2);
	double dotProduct(STVec3d* v2);
	STVec3d* crossProduct(STVec3d* v2);
	double length() {return sqrt(this->dotProduct(this));};
	float distance(STVec3d* v2);
};

class STVec4d
{
private:
	std::vector<double> data;
	
public:
	STVec4d(double x, double y, double z, double w);
	STVec4d() : STVec4d(0.0, 0.0, 0.0, 0.0) {};
	
	std::vector<double> getData {return this->data;};
	
	double getX() {return this->data[0];};
	double getY() {return this->data[1];};
	double getZ() {return this->data[2];};
	double getW() {return this->data[3];};

	void setX(double x) {this->data[0] = x;};
	void setY(double y) {this->data[1] = y;};
	void setZ(double z) {this->data[2] = z;};
	void setW(double w) {this->data[3] = w;};
	
	void addX(double x) {this->data[0] += x;};
	void addY(double y) {this->data[1] += y;};
	void addZ(double z) {this->data[2] += z;};
	void addW(double w) {this->data[3] += w;};
	
	void subX(double x) {this->data[0] -= x;};
	void subY(double y) {this->data[1] -= y;};
	void subZ(double z) {this->data[2] -= z;};
	void subW(double w) {this->data[3] -= w;};
	
	void mulX(double scale) {this->data[0] *= scale;};
	void mulY(double scale) {this->data[1] *= scale;};
	void mulZ(double scale) {this->data[2] *= scale;};
	void mulW(double scale) {this->data[3] *= scale;};
	
	void addVec4d(STVec4d* v2);
	void subVec4d(STVec4d* v2);
	void mulScalar(double scale);
	STVec4d* sum(STVec4d* v2);
	STVec4d* diff(STVec4d* v2);
	double dotProduct(STVec4d* v2);
	double length() {return sqrt(this->dotProduct(this));};
	float distance(STVec4d* v2);
};

#endif //__ST_VECTOR_H__
