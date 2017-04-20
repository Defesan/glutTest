#ifndef __ST_MATRIX_H__
#define __ST_MATRIX_H__

#include "stVector.h"

//Four types of matrices, as classes: Two 3x3 and tw 4x4

class STMatrix33f {
private:
	std::vector<float> data;
public:
	STMatrix33f(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	STMatrix33f() : STMatrix33f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) {};	//In case you want to make an empty matrix easily.
	
	void set(int col,int row, float val) {this->data[row + (col * 3)] = val;};	
	float get(int col, int row) {return this->data[row + (col * 3)];};
	
	STMatrix33f* mul(STMatrix33f* m2);
	STVec3f* mulVector(STVec3f* vec);
	
	void loadIdentity();
	void loadRotationMatrix(float angle, float x, float y, float z);
	void loadTranslationMatrix(float x, float y, float z);
	void loadScaleMatrix(float x, float y, float z);
	void loadPerspectiveMatrix(float fov, float aspect, float zMin, float zMax);
	void loadOrthoMatrix(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax);

};

class STMatrix44f {
private:
	std::vector<float> data;
public:
	STMatrix44f(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2, float x3, float y3, float z3, float w3, float x4, float y4, float z4, float w4);
	STMatrix44f() : STMatrix44f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) {};	//In case you want to make an empty matrix easily.
	
	void set(int col,int row, float val) {this->data[row + (col * 4)] = val;};	
	float get(int col, int row) {return this->data[row + (col * 4)];};

	STMatrix44f* mul(STMatrix44f* m2);
	STVec4f* mulVector(STVec4f* vec);
	
	void loadIdentity();
	void loadRotationMatrix(float angle, float x, float y, float z);
	void loadTranslationMatrix(float x, float y, float z);
	void loadScaleMatrix(float x, float y, float z);
	void loadPerspectiveMatrix(float fov, float aspect, float zMin, float zMax);
	void loadOrthoMatrix(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax);

};

class STMatrix33d {
private:
	std::vector<double> data;
public:
	STMatrix33d(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
	STMatrix33d() : STMatrix33d(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {};	//In case you want to make an empty matrix easily.
	
	void set(int col,int row, double val) {this->data[row + (col * 3)] = val;};	
	double get(int col, int row) {return this->data[row + (col * 3)];};
	
	STMatrix33d* mul(STMatrix33d* m2);
	STVec3d* mulVector(STVec3d* vec);
	
	void loadIdentity();
	void loadRotationMatrix(double angle, double x, double y, double z);
	void loadTranslationMatrix(double x, double y, double z);
	void loadScaleMatrix(double x, double y, double z);
	void loadPerspectiveMatrix(double fov, double aspect, double zMin, double zMax);
	void loadOrthoMatrix(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax);

};

class STMatrix44d {
private:
	std::vector<double> data;
public:
	STMatrix44d(double x1, double y1, double z1, double w1, double x2, double y2, double z2, double w2, double x3, double y3, double z3, double w3, double x4, double y4, double z4, double w4);
	STMatrix44d() : STMatrix44d(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {};	//In case you want to make an empty matrix easily.
	

	void set(int col,int row, double val) {this->data[row + (col * 4)] = val;};	
	double get(int col, int row) {return this->data[row + (col * 4)];};
	
	STMatrix44d* mul(STMatrix44d* m2);
	STVec4d* mulVector(STVec4d* vec);
	
	void loadIdentity();
	void loadRotationMatrix(double angle, double x, double y, double z);
	void loadTranslationMatrix(double x, double y, double z);
	void loadScaleMatrix(double x, double y, double z);
	void loadPerspectiveMatrix(double fov, double aspect, double zMin, double zMax);
	void loadOrthoMatrix(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax);

};

#endif //__ST_MATRIX_H__
