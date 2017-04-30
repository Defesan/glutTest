#include "stPrimitiveBatch.h"

STPrimitiveBatch::STPrimitiveBatch(GLuint numTexLayers = 4)
{
	this->type = PRIMITIVE;
	for(GLuint i = 0; i < numTexLayers; i++)
	{
		this->texCoords.push_back(std::vector<STVec2d*>());
	}
}

//Alright... Let's see if we can make this as fast and painless as possible. Time for VECTOR::INSERT!!!

void STPrimitiveBatch::copyVertexData(std::vector<STVec3d*> verts)
{
	//The objective is to get the data from the vector of Vec3d's into this object's vector of GLdoubles with minimum fuss.
	//Also, hopefully, minimum memory thrashing.
	
	std::vector<STVec3d*>::iterator iterV = verts.begin();
	std::vector<GLdouble>::iterator iterD = this->vertData.begin();	//We're appending any incoming vertices.
	
	for(iterV; iterV < verts.end(); iterV++)
	{
		//For each vertex in the verts vector, we need another iterator...
		std::vector<GLdouble>::iterator iterS = *iterV->getData().begin();
		this->vertData.insert(iterD, iterS.begin(), iterS.end());
		iterD = this->vertData.end();
	}
	//That...should work. Sadly, it IS basically extra work, which means it WILL be slower, but it's probably the best the setup I made can offer.
	//Okay, maybe not probably. I'm sure there's an optimization SOMEWHERE.
	
	if(this->vertID == 0)
	{
		//We've never bound a buffer before. So, we need a new Buffer ID.
		glGenBuffers(1, &(this->vertID));
		glBindBuffer(GL_ARRAY_BUFFER, this->vertID);
		//Oh, Hey-o, guess what I get to do that GLTools couldn't? Vectors can report their size! That's why I started using them in the first place!
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLdouble) * this->vertData.size(), this->vertData.data(), GL_DYNAMIC_DRAW);
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->vertID);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLdouble) * this->vertData.size(), this->vertData.data());
	}
}

void STPrimitiveBatch::copyNormalData(std::vector<STVec3d*> norms)
{
	std::vector<STVec3d*>::iterator iterN = norms.begin();
	std::vector<GLdouble>::iterator iterD = this->normData.begin();
	
	for(iterN; iterN < norms.end(); iterN++)
	{
		//For each vertex in the verts vector, we need another iterator...
		std::vector<GLdouble>::iterator iterS = *iterN->getData().begin();
		this->normData.insert(iterD, iterS.begin(), iterS.end());
		iterD = this->normData.end();
	}
	
	if(this->normID == 0)
	{
		glGenBuffers(1, &(this->normID));
		glBindBuffer(GL_ARRAY_BUFFER, this->normID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLdouble) * this->normData.size(), this->normData.data(), GL_DYNAMIC_DRAW);	
	}	
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->normID);
		GLBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLdouble) * this->normData.size(), this->normData.data());
	}
	
}

void STPrimitiveBatch::copyColorData(std::vector<STVec4f*> colors)
{
	std::vector<STVec4f*>::iterator iterC = colors.begin();
	std::vector<GLfloat>::iterator iterD = this->colorData.begin();

	for(iterC; iterC < colors.end(); iterC++)
	{
		std::vector<GLdouble>::iterator iterS = *iterC->getData().begin();
		this->colorData.insert(iterD, iterS.begin(), iterS.end());
		iterD = this->colorData.end();
	}
	
	if(this->colorID == 0)
	{	
		glGenBuffers(1, &(this->colorID));
		glBindBuffer(GL_ARRAY_BUFFER, this->colorID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * this->colorData.size(), this->colorData.data(), GL_DYNAMIC_DRAW);
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->colorID);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * this->colorData.size(), this->colorData.data();
	}
}	
