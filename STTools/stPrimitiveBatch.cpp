#include "stPrimitiveBatch.h"

STPrimitiveBatch::STPrimitiveBatch(GLuint numTexLayers = 4)
{
	this->type = PRIMITIVE;
	if(numTexLayers > 4)
	{
		numTexLayers = 4;	//Have to experiment with this. Someday.
	}
	for(GLuint i = 0; i < numTexLayers; i++)
	{
		this->texCoords.push_back(std::vector<STVec2d*>());
		this->texIDs.push_back(0);
	}
}

STPrimitiveBatch::~STPrimitiveBatch()
{
	//Unlike most of my vector-based classes, since we're interfacing with OpenGL directly at this level, some cleanup is required.
	std::vector<GLuint>::iterator iter;
	
	if(this->vertID != 0)
	{
		glDeleteBuffers(1, &(this->vertID));		
	}
	
	if(this->colorID != 0)
	{
		glDeleteBuffers(1, &(this->colorID));
	}
	
	if(this->normID != 0)
	{
		glDeleteBuffers(1, &(this->normID));
	}
	
	if(this->indexID != 0)
	{
		glDeleteBuffers(1, &(this->indexID));
	}
	
	for(iter = this->texIDs.begin(); iter < this->texIDs.size(); iter++)
	{
		if(*iter != 0)
		{
			glDeleteBuffers(1, &(*iter));
		}
	}

}

void STPrimitiveBatch::begin()
{
	//Still not quite clear on how this fits. In GLBatch, it basically does the initialization.
	//It sets the number of vertices to input(necessary because of the limitations of C arrays)
	//it sets the number of texture layers(a maximum of 4), which I do in the initialization phase
	//It allocates enough arrays to hold the texture coordinate data based on that, which I also do in the initialization phase,
	//And...Well, it also binds a vertex array if the platform is OpenGL ES, which I'm not currently supporting.
	//...So...
	//I'm kinda done here.

}

void STPrimitiveBatch::finalize()
{
	//Basically, given that data has been copied in and buffered, it takes the buffers and sets vertex attribute pointers to them so that GL can utilize them.
	//Since I'm not doing 'immediate mode' for the moment, and I'm not supporting ES, that's... That's basically it.
	
	std::vector<GLuint>::iterator iter;
	
	if(vertID != 0)
	{
		//Bind the vertex array
		glEnableVertexAttribArray(ST_ATTRIBUTE_VERTEX);
		glBindBuffer(GL_ARRAY_BUFFER, vertID);
		glVertexAttribPointer(ST_ATTRIBUTE_VERTEX, 3, GL_FLOAT, GL_FALSE, 0, nullptr);	//Now, I'm still not 100% on why we're initializing the buffer with a null pointer here.
	}
	if(normID != 0)
	{
		//Bind the normal array
		glEnableVertexAttribArray(ST_ATTRIBUTE_NORMAL);
		glBindBuffer(GL_ARRAY_BUFFER, normID);
		glVertexAttribPointer(ST_ATTRIBUTE_NORMAL, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	}
	if(colorID != 0)
	{
		//Bind the color array
		glEnableVertexAttribArray(ST_ATTRIBUTE_COLOR);
		glBindBuffer(GL_ARRAY_BUFFER, colorID);
		glVertexAttribPointer(ST_ATTRIBUTE_COLOR, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	}
	int i = 0;
	for(iter = this->texIDs.begin(); iter < this->texIDs.end(); iter++)
	{
		//Bind the i'th texture coordinate array.
		glEnableVertexAttribArray(ST_ATTRIBUTE_TEXTURE0 + i);
		glBindBuffer(GL_ARRAY_BUFFER, *iter);
		glVertexAttribPointer(ST_ATTRIBUTE_TEXTURE0 + i, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	}

}

//Alright... Let's see if we can make this as fast and painless as possible. Time for VECTOR::INSERT!!!

void STPrimitiveBatch::copyVertexData(std::vector<STVec3d*> verts)
{
	//The objective is to get the data from the vector of Vec3d's into this object's vector of GLdoubles with minimum fuss.
	//Also, hopefully, minimum memory thrashing.
	
	std::vector<STVec3d*>::iterator iterV = verts.begin();
	std::vector<GLdouble>::iterator iterD = this->vertData.end();	//We're appending any incoming vertices.
	
	for(iterV; iterV < verts.end(); iterV++)
	{
		this->vertData.insert(iterD, *iterV->getData()->begin(), *iterV->getData()->end());
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
		this->normData.insert(iterD, *iterN->getData()->begin(), *iterN->getData()->end());
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
		this->colorData.insert(iterD, *iterC->getData()->begin(), *iterC->getData()->end());
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

void STPrimitiveBatch::copyTexCoordData(std::vector<STVec2d*> texCoords, GLuint textureLayer)
{
	if(textureLayer >= 4)
	{
		std::cerr << "Invalid texture layer" << std::endl;
		return;
	}
	std::vector<STVec2d*>::iterator iterT = texCoords.begin();
	std::vector<GLdouble>::iterator iterD = this->texCoordData[textureLayer].begin();

	for(iterT; iterT < texCoords.end(); iterT++)
	{
		this->texCoordData[textureLayer].insert(iterD, *iterT->getData()->begin(), *iterT->getData()->end());
		iterD = this->texCoordData.end();
	}
	
	if(this->texIDs[textureLayer] == 0)
	{	
		glGenBuffers(1, &(this->texIDs[textureLayer]));
		glBindBuffer(GL_ARRAY_BUFFER, this->texIDs[textureLayer]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLdouble) * this->texCoordData[textureLayer].size(), this->texCoordData[textureLayer].data(), GL_DYNAMIC_DRAW);
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->texIDs[textureLayer]);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLdouble) * this->texCoordData[textureLayer].size(), this->texCoordData[textureLayer].data();
	}
}

}

void STPrimitiveBatch::draw()
{

}
