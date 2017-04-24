#ifndef __ST_MATRIX_STACK_H__
#define __ST_MATRIX_STACK_H__

#include "../STLinear/stMatrix.h"

enum ST_STACK_ERROR {ST_NO_ERROR = 0, ST_STACK_UNDERFLOW, ST_STACK_OVERFLOW};

//The matrix stack in the GLTools library is too useful to ignore, but I'll be making some changes.
//Aside from not optimizing so heavily that the header/code distinction is basically erased,
//I'll also be using a vector(which lately doesn't have much overhead at all over C arrays)
//And I'm swtiching up to a double precision matrix, since the distances involved in Phase 4 are...
//Well, let's say they're large. I have no intention of baiting the Kraken.
class STMatrixStack
{
private:
	vector<STMatrix44d*> matrices;
	int stackPointer;
	int stackDepth; 			//Normally, I wouldn't use it, but it serves as a handy braking mechanism in case of things going terribly wrong.
	ST_STACK_ERROR lastError;	//Without this, of course, there's nothing stopping a program from just asking for negative elements or trying to put elements over the limit.
public:
	STMatrixStack(int stackDepth);
	~STMatrixStack();
	
	void setDepth(int newDepth)	{this->stackDepth = newDepth};							//Changes the stack depth
	
	void loadIdentity() {this->matrices[stackPointer]->loadIdentity();};				//Loads an identity matrix to the current top of the stack
	void loadMatrix(STMatrix44d* matrix) { this->matrices[stackPointer] = matrix;};		//Loads a *specific* matrix to the current top of the stack
	void mulMatrix(STMatrix44d* matrix) {this->matrices[stackPointer]->mul(matrix);}; 	//Multiplies the matrix at the top of the stack by a given matrix
	int pushMatrix(STMatrix44d* matrix);												//Pushes a matrix onto the stack, leaving the previous top matrix unchanged
	int pushMatrix();																	//Copies the current top matrix into the new top position. This was the normal way to do this?
	int popMatrix();																	//Obviously, causes a matrix to explode into a mess of vectors and loose doubles. Very messy.
	void scale(double x, double y, double z);											//Scales the current top matrix
	void translate(double x, double y, double z);										//Shifts the current top matrix in whatever space it exists in(projection, model, view, etc.)
	void rotate(double angle, double x, double y, double z);							//Rotates the current top matrix.
	
	STMatrix44d* getMatrix() {return this->matrices[stackPointer];};					//Returns the matrix at the current top of the stack.
	ST_STACK_ERROR getLastError() {return this->lastError;};							//Returns the value of the last error.
	int getDepth() {return this->stackDepth;};											//Gets the current maximum stack depth											
};


#endif //__ST_MATRIX_STACK_H__
