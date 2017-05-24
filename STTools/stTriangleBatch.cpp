#include "stTriangleBatch.h"

STTriangleBatch::STTriangleBatch()
{
	this->type = TRIANGLE;
	this->vertID = 0;
	this->normID = 0;
	this->colorID = 0;
	this->indexID = 0;
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
	//Check to see if any of the verts are already in the list
	//Here's the score:
	//There's a list of vertices, a list of normals, a list of texture coordinates.
	//For a vertex to be considered a match, to another vertex, all three must be 'close enough' to the elements at that vertex's index in the three vectors.
	//The author used a delta of 0.00001, which sounds reasonable.
	//...And I just realized that all of this is going to be low-level(in this architecture), because the point isn't to see if a vertex exists in a triangle, it's the other way around.
	//I may not need stTriangle after all.
	//I mean, I didn't need it in the first place, but it may not even be useful. Might just be an extra step.
	//Oh well, live and learn, and plan your designs better in the future.
	
	//Anyway, as I was saying, each of the three vertices in the triangle has to be checked against all other vertices in the array. Still painful, btw.
	//At least the if statement short-circuits pretty quickly in almost every case, unless you've got vertices piled on top of one another with different texture coords or normals, 
	//which just causes texture or z-fighting, and looks terrible. Basically, they won't be physically close enough to check the others.
	//If all of that falls through, the vertex at that position in the triangle just devolves to another instance of the index of that vertex(already in the vertex array)
	//being placed in the index array.  
	
	//As a final note, I was confused as to how he figured out which texture layer the vertex was on. He doesn't. GLTriangleBatch only supports a single layer.
	//Might be something to improve in the future. 
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
	
	
}
