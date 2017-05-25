#include "stTriangleBatch.h"

STTriangleBatch::STTriangleBatch()
{
	this->type = TRIANGLE;
	this->vertID = 0;
	this->normID = 0;
	this->colorID = 0;
	this->indexID = 0;
	
	this->vertexBufferArrayID = 0;
	
	for(int i = 0; i < 4; i++)
	{
		this->texIDs[i] = 0;
	}
}

STTriangleBatch::~STTriangleBatch()
{
	glDeleteBuffers(1, &this->vertID);
	glDeleteBuffers(1, &this->normID);
	glDeleteBuffers(1, &this->colorID);
	glDeleteBuffers(1, &this->indexID);
	
	glDeleteBuffers(4, this->texIDs.data());
	
}

void STTriangleBatch::addTriangle(STTriangle* tri)
{
	for(int i = 0; i < 3; i++)
	{
		std::vector<GLfloat>::iterator iterV = this->vertData.begin();
		std::vector<GLfloat>::iterator iterN = this->normData.begin();
		std::vector<GLfloat>::iterator iterT = this->texCoordData[0].begin();
		
		bool match = false;
		
		for(; iterV < this->vertData.end(); iterV++, iterN++, iterT++)	//Probably the most complex, least intuitive for loop I've written in a while...
		{
			//And here we go...
			if(*iterV->closeEnough(tri->getVertex(i)) && *iterN->closeEnough(tri->getNormal(i)) && *iterT->closeEnough(tri->getTexCoord(i)))
			{
				//We've found a match! Now all we have to do is add the index(and where are we, exactly?) to the index array and end this run through the loop.
				GLuint index = iterV - this->vertData.begin();
				this->indexData.push_back(index);
				match = true;
				break;
			}
		}
		
		if(!match)
		{
			//We've got to add all the stuff.
			this->vertData.push_back(tri->getVertex(i));
			this->normData.push_back(tri->getNormal(i));
			this->texCoordData[0].push_back(tri->getTexCoord(i));
			this->indexData.push_back(this->vertData.size() - 1);
		}
		//And that's it! Once again, my way works out to be a bit easier than his. Time will tell how well it performs in other respects...
	}
}

void STTriangleBatch::finalize()
{
	//First, create an ID and bind the vertex buffer array to it. Still figuring this part out, since I don't think it was in the other one...
	glGenVertexArrays(1, &vertexBufferArrayID);
	glBindVertexArray(vertexBufferArrayID);
	
	//Now create the other IDs for the attribute arrays.
	glGenBuffers(1, &this->vertID);
	glGenBuffers(1, &this->normID);
	glGenBuffers(1, &this->indexID);
	glGenBuffers(1, &this->texIDs[0]);
	
	//..and bind them.
	glBindBuffer(GL_ARRAY_BUFFER, this->vertID);
	glEnableVertexAttribArray(ST_ATTRIBUTE_VERTEX);
	glBufferData
}
