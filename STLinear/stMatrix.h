#ifndef __ST_MATRIX_H__
#define __ST_MATRIX_H__

#include "stVector.h"

//Four types of matrices, as classes: Two 3x3 and tw 4x4

class STMatrix33f {
private:
	std::vector<float> data;
public:
	//How do I want to initialize this?
	//Obviously, this is going to be mostly done behind the scenes -- nobody wants to initialize a matrix inline in a program that's getting edited.
	//That means the stGLTools library will be doing most of the work. Nothing for it, then...
	STMatrix33f(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	STMatrix33f() : STMatrix33f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) {};	//In case you want to make an empty matrix easily.
	
	//Ugh...I imagine these will be rarely used.
	//Have to figure out the column-major format eventually. At least now I know why they're used!
	void set(int col,int row, float val);
	void set11(float val) {this->data[0] = val;};
	void set12(float val) {this->data[3] = val;};
	void set13(float val) {this->data[6] = val;};
	void set21(float val) {this->data[1] = val;};
	void set22(float val) {this->data[4] = val;};
	void set23(float val) {this->data[7] = val;};
	void set31(float val) {this->data[2] = val;};
	void set32(float val) {this->data[5] = val;};
	void set33(float val) {this->data[8] = val;};
	
	float get(int col, int row);
	float get11() {return this->data[0];};
	float get12() {return this->data[3];};
	float get13() {return this->data[6];};
	float get21() {return this->data[1];};
	float get22() {return this->data[4];};
	float get23() {return this->data[7];};
	float get31() {return this->data[2];};
	float get32() {return this->data[5];};
	float get33() {return this->data[8];};
	
	STMatrix33f* mul(STMatrix33f* m2);
	
	//Actually, these will probably do a lot of the work in creating a usable matrix.
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
	//How do I want to initialize this?
	//Obviously, this is going to be mostly done behind the scenes -- nobody wants to initialize a matrix inline in a program that's getting edited.
	//That means the stGLTools library will be doing most of the work. Nothing for it, then...
	STMatrix44f(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2, float x3, float y3, float z3, float w3, float x4, float y4, float z4, float w4);
	STMatrix44f() : STMatrix44f(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) {};	//In case you want to make an empty matrix easily.
	
	//Ugh...I imagine these will be rarely used.
	//Have to figure out the column-major format eventually. At least now I know why they're used!
	//Also, I NEED to figure out a better way of doing this. Maybe macros after all? Or operator overloading.
	//Or maybe just a set(int index, float val) function? Yeah, that'll do for now.
	void set(int col, int row, float val);
	void set11(float val) {this->data[0] = val;};
	void set12(float val) {this->data[4] = val;};
	void set13(float val) {this->data[8] = val;};
	void set14(float val) {this->data[12] = val;};
	void set21(float val) {this->data[1] = val;};
	void set22(float val) {this->data[5] = val;};
	void set23(float val) {this->data[9] = val;};
	void set24(float val) {this->data[13] = val;};
	void set31(float val) {this->data[2] = val;};
	void set32(float val) {this->data[6] = val;};
	void set33(float val) {this->data[10] = val;};
	void set34(float val) {this->data[14] = val;};
	void set41(float val) {this->data[3] = val;};
	void set42(float val) {this->data[7] = val;};
	void set43(float val) {this->data[11] = val;};
	void set44(float val) {this->data[15] = val;};
	
	float get(int col, int row);
	float get11() {return this->data[0];};
	float get12() {return this->data[4];};
	float get13() {return this->data[8];};
	float get14() {return this->data[12];};
	float get21() {return this->data[1];};
	float get22() {return this->data[5];};
	float get23() {return this->data[9];};
	float get24() {return this->data[13];};
	float get31() {return this->data[2];};
	float get32() {return this->data[6];};
	float get33() {return this->data[10];};
	float get34() {return this->data[14];};
	float get41() {return this->data[3];};
	float get42() {return this->data[7];};
	float get43() {return this->data[11];};
	float get44() {return this->data[15];};
	
	
	STMatrix44f* mul(STMatrix44f* m2);
	
	//Actually, these will probably do a lot of the work in creating a usable matrix. Also, pretty sure not all of these make sense for every matrix...
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
	//How do I want to initialize this?
	//Obviously, this is going to be mostly done behind the scenes -- nobody wants to initialize a matrix inline in a program that's getting edited.
	//That means the stGLTools library will be doing most of the work. Nothing for it, then...
	STMatrix33d(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
	STMatrix33d() : STMatrix33d(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {};	//In case you want to make an empty matrix easily.
	
	//Ugh...I imagine these will be rarely used.
	//Have to figure out the column-major format eventually. At least now I know why they're used!
	void set(int col, int row, double val);
	void set11(double val) {this->data[0] = val;};
	void set12(double val) {this->data[3] = val;};
	void set13(double val) {this->data[6] = val;};
	void set21(double val) {this->data[1] = val;};
	void set22(double val) {this->data[4] = val;};
	void set23(double val) {this->data[7] = val;};
	void set31(double val) {this->data[2] = val;};
	void set32(double val) {this->data[5] = val;};
	void set33(double val) {this->data[8] = val;};
	
	double get(int col, int row);
	double get11() {return this->data[0];};
	double get12() {return this->data[3];};
	double get13() {return this->data[6];};
	double get21() {return this->data[1];};
	double get22() {return this->data[4];};
	double get23() {return this->data[7];};
	double get31() {return this->data[2];};
	double get32() {return this->data[5];};
	double get33() {return this->data[8];};
	
	STMatrix33d* mul(STMatrix33d* m2);
	
	//Actually, these will probably do a lot of the work in creating a usable matrix.
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
	//How do I want to initialize this?
	//Obviously, this is going to be mostly done behind the scenes -- nobody wants to initialize a matrix inline in a program that's getting edited.
	//That means the stGLTools library will be doing most of the work. Nothing for it, then...
	STMatrix44f(double x1, double y1, double z1, double w1, double x2, double y2, double z2, double w2, double x3, double y3, double z3, double w3, double x4, double y4, double z4, double w4);
	STMatrix44f() : STMatrix44f(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) {};	//In case you want to make an empty matrix easily.
	
	//Ugh...I imagine these will be rarely used.
	//Have to figure out the column-major format eventually. At least now I know why they're used!
	//Also, I NEED to figure out a better way of doing this. Maybe macros after all? Or operator overloading.
	//Or maybe just a set(int index, float val) function? Yeah, that'll do for now.
	void set(int col, int row, double val);
	void set11(double val) {this->data[0] = val;};
	void set12(double val) {this->data[4] = val;};
	void set13(double val) {this->data[8] = val;};
	void set14(double val) {this->data[12] = val;};
	void set21(double val) {this->data[1] = val;};
	void set22(double val) {this->data[5] = val;};
	void set23(double val) {this->data[9] = val;};
	void set24(double val) {this->data[13] = val;};
	void set31(double val) {this->data[2] = val;};
	void set32(double val) {this->data[6] = val;};
	void set33(double val) {this->data[10] = val;};
	void set34(double val) {this->data[14] = val;};
	void set41(double val) {this->data[3] = val;};
	void set42(double val) {this->data[7] = val;};
	void set43(double val) {this->data[11] = val;};
	void set44(double val) {this->data[15] = val;};
	
	double get(int col, int row);
	double get11() {return this->data[0];};
	double get12() {return this->data[4];};
	double get13() {return this->data[8];};
	double get14() {return this->data[12];};
	double get21() {return this->data[1];};
	double get22() {return this->data[5];};
	double get23() {return this->data[9];};
	double get24() {return this->data[13];};
	double get31() {return this->data[2];};
	double get32() {return this->data[6];};
	double get33() {return this->data[10];};
	double get34() {return this->data[14];};
	double get41() {return this->data[3];};
	double get42() {return this->data[7];};
	double get43() {return this->data[11];};
	double get44() {return this->data[15];};
	
	
	STMatrix44f* mul(STMatrix44f* m2);
	
	//Actually, these will probably do a lot of the work in creating a usable matrix. Also, pretty sure not all of these make sense for every matrix...
	void loadIdentity();
	void loadRotationMatrix(double angle, double x, double y, double z);
	void loadTranslationMatrix(double x, double y, double z);
	void loadScaleMatrix(double x, double y, double z);
	void loadPerspectiveMatrix(double fov, double aspect, double zMin, double zMax);
	void loadOrthoMatrix(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax);

};

#endif //__ST_MATRIX_H__
