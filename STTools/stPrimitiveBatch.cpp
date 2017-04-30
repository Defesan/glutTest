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
	std::vector<GLdouble>::iterator iterD = this->verts.end();	//We're appending any incoming vertices.
	
	for(iterV; iterV < verts.end(); iterV++)
	{
		//For each vertex in the verts vector, we need another iterator...
		iterD = this->verts.end();
		std::vector<GLdouble>::iterS = *iterV->getData.begin();
		this->verts.insert(iterD, iterS.begin(), iterS.end());
	}
	//That...should work. Sadly, it IS basically extra work, which means it WILL be slower, but it's probably the best the setup I made can offer.
	//Okay, maybe not probably. I'm sure there's an optimization SOMEWHERE.
	
	if(this->vertID == 0)
	{
		//We've never bound a buffer before. So, we need a new Buffer ID.
		glGenBuffers(1, &vertID);
		glBindBuffer(GL_ARRAY_BUFFER, vertID);
		//Oh, Hey-o, guess what I get to do that GLTools couldn't? Vectors can report their size! That's why I started using them in the first place!
		glBindData(GL_ARRAY_BUFFER, sizeof(GLdouble) * this->verts.size(), this->verts.data(), GL_DYNAMIC_DRAW);
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, vertID);
		glBindSubData(GL_ARRAY_BUFFER, sizeof(GLdouble) * this->verts.size(), this->verts.data());
	}
}


