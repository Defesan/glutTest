#include "stMatrixStack.h"

STMatrixStack::STMatrixStack(int stackDepth)
{
	this->lastError = 0;
	this->stackPointer = 0;
	this->stackDepth = stackDepth;

	STMatrix44d* top = new STMatrix44d();
	top->loadIdentity();
	this->matrices.push_back(top);
}

int STMatrixStack::pushMatrix(STMatrix44d* matrix)
{
	if(this->stackPointer < this->stackDepth)
	{
		this->matrices.push_back(matrix);
		this->stackPointer += 1;
	}
	else
	{
		this->lastError = ST_STACK_OVERFLOW;
	}
	return (int)this->lastError();
}

int STMatrixStack::pushMatrix()
{
	if(this->stackPointer < this->stackDepth)
	{
		this->matrices.push_back(this->matrices[stackPointer]->copyMatrix());
		this->stackPointer += 1;
	}
	else
	{
		this->lastError = ST_STACK_OVERFLOW;
	}
	return (int)this->lastError();
}

int STMatrixStack::popMatrix()
{
	if(this->stackPointer > 0)
	{
		this->matrices.pop_back();
		this->stackPointer -= 1;
	}
	else
	{
		this->lastError = ST_STACK_UNDERFLOW;
	}
	return (int)this->lastError;
}

void STMatrixStack::scale(double x, double y, double z)
{
	STMatrix44d* scaleMatrix = new STMatrix44d();
	scaleMatrix->loadScaleMatrix(x,y,z);
	this->mulMatrix(scaleMatrix);
}

void STMatrixStack::translate(double x, double y, double z)
{
	STMatrix44d* translationMatrix = new STMatrix44d();
	translationMatrix->loadTranslationMatrix(x,y,z);
	this->mulMatrix(translationMatrix);
}

void STMatrixStack::rotate(double angle, double x, double y, double z);
{
	STMatrix44d* rotationMatrix = new STMatrix44d();
	rotationMatrix->loadRotationMatrix(angle, x, y, z);
	this->mulMatrix(rotationMatrix);
}
