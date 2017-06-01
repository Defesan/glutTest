#include "stPrimitiveBatch.h"

STPrimitiveBatch::STPrimitiveBatch(GLuint numTexLayers)
{
	this->type = PRIMITIVE;
	if(numTexLayers > 4)
	{
		numTexLayers = 4;	//Have to experiment with this. Someday.
	}
	for(GLuint i = 0; i < numTexLayers; i++)
	{
		this->texCoordData.push_back(std::vector<GLfloat>());
		this->texIDs.push_back(0);
	}
	this->vertID = 0;
	this->normID = 0;
	this->indexID = 0;
	this->colorID = 0;
	this->vertexBufferArrayID = 0;
	
	glGenVertexArrays(1, &this->vertexBufferArrayID);
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
	
	for(iter = this->texIDs.begin(); iter != this->texIDs.end(); iter++)
	{
		if((*iter) != 0)
		{
			glDeleteBuffers(1, &(*iter));
		}
	}

}

void STPrimitiveBatch::begin()
{
	glBindVertexArray(this->vertexBufferArrayID);
}

void STPrimitiveBatch::finalize()
{
	//Basically, given that data has been copied in and buffered, it takes the buffers and sets vertex attribute pointers to them so that GL can utilize them.
	//Since I'm not doing 'immediate mode' for the moment, and I'm not supporting ES, that's... That's basically it.
	
	std::vector<GLuint>::iterator iter;
	
	glBindVertexArray(this->vertexBufferArrayID);
	
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
	glBindVertexArray(0);
	
}

//Alright... Let's see if we can make this as fast and painless as possible. Time for VECTOR::INSERT!!!

void STPrimitiveBatch::copyVertexData(std::vector<STVec3f*> verts)
{
	//The objective is to get the data from the vector of Vec3d's into this object's vector of GLdoubles with minimum fuss.
	//Also, hopefully, minimum memory thrashing.
	
	std::vector<STVec3f*>::iterator iterV = verts.begin();
	std::vector<GLfloat>::iterator iterD = this->vertData.end();	//We're appending any incoming vertices.
	
	for(; iterV != verts.end(); iterV++)
	{
		this->vertData.insert(iterD, (*iterV)->getData().begin(), (*iterV)->getData().end());
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
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * this->vertData.size(), this->vertData.data(), GL_DYNAMIC_DRAW);
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->vertID);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * this->vertData.size(), this->vertData.data());
	}
}

void STPrimitiveBatch::copyNormalData(std::vector<STVec3f*> norms)
{
	std::vector<STVec3f*>::iterator iterN = norms.begin();
	std::vector<GLfloat>::iterator iterD = this->normData.begin();
	
	for(; iterN != norms.end(); iterN++)
	{
		this->normData.insert(iterD, (*iterN)->getData().begin(), (*iterN)->getData().end());
		iterD = this->normData.end();
	}
	
	if(this->normID == 0)
	{
		glGenBuffers(1, &(this->normID));
		glBindBuffer(GL_ARRAY_BUFFER, this->normID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * this->normData.size(), this->normData.data(), GL_DYNAMIC_DRAW);	
	}	
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->normID);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * this->normData.size(), this->normData.data());
	}
	
}

void STPrimitiveBatch::copyColorData(std::vector<STVec4f*> colors)
{
	std::vector<STVec4f*>::iterator iterC = colors.begin();
	std::vector<GLfloat>::iterator iterD = this->colorData.begin();

	for(; iterC != colors.end(); iterC++)
	{
		this->colorData.insert(iterD, (*iterC)->getData().begin(), (*iterC)->getData().end());
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
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * this->colorData.size(), this->colorData.data());
	}
}	

void STPrimitiveBatch::copyTexCoordData(std::vector<STVec2f*> texCoords, GLuint textureLayer)
{
	if(textureLayer >= 4)
	{
		std::cerr << "Invalid texture layer" << std::endl;
		return;
	}
	std::vector<STVec2f*>::iterator iterT = texCoords.begin();
	std::vector<GLfloat>::iterator iterD = this->texCoordData[textureLayer].begin();

	for(; iterT != texCoords.end(); iterT++)
	{
		this->texCoordData[textureLayer].insert(iterD, (*iterT)->getData().begin(), (*iterT)->getData().end());
		iterD = this->texCoordData[textureLayer].end();
	}
	
	if(this->texIDs[textureLayer] == 0)
	{	
		glGenBuffers(1, &(this->texIDs[textureLayer]));
		glBindBuffer(GL_ARRAY_BUFFER, this->texIDs[textureLayer]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * this->texCoordData[textureLayer].size(), this->texCoordData[textureLayer].data(), GL_DYNAMIC_DRAW);
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->texIDs[textureLayer]);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * this->texCoordData[textureLayer].size(), this->texCoordData[textureLayer].data());
	}
}


void STPrimitiveBatch::draw()
{
	//For some reason I was putting this off. Then I looked more closely at what *OpenGL* needs, as opposed to cross-platform OpenGL and OpenGL ES.
	//I mean... I'm impressed. VBOs make this ridiculously simple.
	glBindVertexArray(this->vertexBufferArrayID);
	
	glDrawArrays(GL_TRIANGLES, 0, (this->vertData.size() / 3));
	
	glBindVertexArray(0);
	
}
