#include "stSphere.h"

Sphere::Sphere(GLfloat originX, GLfloat originY, GLfloat originZ, GLfloat radius, GLushort numLayers, GLushort numSlices)
{
	this->origin = new STVec3f();
	this->velocity = new STVec3f();
	this->radius = radius;
	this->numLayers = numLayers;
	this->numSlices = numSlices;
	this->boundPos = new STVec3f(100.0f, 100.0f, 100.0f);
	this->boundNeg = new STVec3f(-100.0f, -100.0f, -100.0f);
	
	this->genVerts();
	this->genIndices();
	this->genColors();
	
	this->translate(originX, originY, originZ);
}

Sphere::~Sphere()
{
	//Using vectors, so no current references to delete.

}

void Sphere::genVerts()
{
	//Sphere construction begins at the top.
	GLfloat vertexYPos = this->radius;//this->originY + this->radius;
	GLfloat vertexXPos = 0.0f;//this->originX;
	GLfloat vertexZPos = 0.0f;//this->originZ;
	
	GLfloat layerAngle = PI/(this->numLayers + 1);  //The angle, in radians, between each layer of the sphere
	GLfloat sliceAngle = (2 * PI)/this->numSlices;  //The angle, in radians, between each meridian of the sphere.
	
	GLfloat currentSliceAngle = 0.0f;	//This is just the slice angle multiplied by the index of the slice currently being placed.
	GLfloat currentLayerAngle = 0.0f;	//Same as above, but for layers
	GLfloat layerRadius = 0.0f;			//The radius of the circle that defines the current layer

	//Top vertex coordinates
	this->verts.push_back(vertexXPos);
	this->verts.push_back(vertexYPos);
	this->verts.push_back(vertexZPos);
	
	//Generate layer i
	for(int i = 0; i < this->numLayers; i++)
	{
		//Calculate the angle of the current layer
		currentLayerAngle = layerAngle * (i + 1);	
		
		//Define the dimensions and position of the current layer
		layerRadius = sin(currentLayerAngle) * this->radius;
		vertexYPos = cos(currentLayerAngle) * this->radius;
		
		//Generate vertex j of layer i
		for(int j = 0; j < this->numSlices; j++)
		{
			//Calculate the angle of the current slice
			currentSliceAngle = j * sliceAngle;
			
			//Determine the coordinates of the current vertex
			vertexXPos = sin(currentSliceAngle) * layerRadius;
			vertexZPos = cos(currentSliceAngle) * layerRadius;

			//Place vertex j of layer i
			this->verts.push_back(vertexXPos);
			this->verts.push_back(vertexYPos);
			this->verts.push_back(vertexZPos);
		}
	}
	
	//Bottom vertex coordinates
	vertexYPos = -1 * this->radius;
	vertexXPos = 0.0f;
	vertexZPos = 0.0f;
	
	this->verts.push_back(vertexXPos);
	this->verts.push_back(vertexYPos);
	this->verts.push_back(vertexZPos);
}

void Sphere::genIndices()
{
	/*
		Index generation is done in three parts:
		1) 'Upper cap' -- the triangles that are centered on the top vertex
		2) 'Strips' -- the areas between the layers, created with pairs of triangles forming quads
		3) 'Bottom cap' -- the triangles centered on the bottom vertex
	
	*/
	
	//1 -- Upper cap generation
	for(int i = 0; i < this->numSlices; i++)
	{
		this->indices.push_back(0);			//Each triangle starts with the top vertex...
		this->indices.push_back(i + 1);		//and extends to the i + 1th slice vertex
		
		//Then, it has to check to make sure the next vertex is actually in the current layer
		if(i != (this->numSlices - 1))
		{
			this->indices.push_back(i + 2);	//If it is, the third index is just the next vertex.
		}
		else
		{
			this->indices.push_back(1);		//Otherwise, it has to loop back to the start.
		}
	}

	
	//2 -- Strip generation
	//For N layers, this is done N - 1 times. This is because the strips are defined in terms of both the ith layer and the (i + 1)th layer.
	for(int i = 0; i < (this->numLayers - 1); i++)
	{
		int firstVert = (this->numSlices * i) + 1;			//The index of the first vertex in the current layer
		int belowFirst = (this->numSlices * (i + 1)) + 1; 	//The index of the first vertex on the layer below the current layer.
		
		//For each j, there are two triangles to generate.
		//Given vertex v(j) and v(j + M), with slice count M, the triangles are defined as follows:
		//Tri 1: {v(j), v(j + M), v(j + M + 1)}
		//Tri 2: {v(j), v(j + 1), v(j + M + 1)}
		for(int j = 0; j < this->numSlices; j++)
		{
			//The first two indices in each group of six are always the jth vertex after firstVert and belowFirst, respectively.
			this->indices.push_back(firstVert + j);
			
			//Again, the circular nature of the strips requires a branch.
			if(j != (this->numSlices - 1))		//For all but the last vertex in the strip,
			{
				this->indices.push_back(belowFirst + j);
				this->indices.push_back(belowFirst + (j + 1));	//v(j + M + 1)
				this->indices.push_back(firstVert + j);			//v(j)
				this->indices.push_back(belowFirst + (j + 1));  //v(j + M + 1)
				this->indices.push_back(firstVert + (j + 1));	//v(j + 1)
			}
			else	//Otherwise, we have to substitute the starting vertices of both layers for the 'next' vertices.
			{
				this->indices.push_back(belowFirst + j);
				this->indices.push_back(belowFirst);
				this->indices.push_back(firstVert + j);
				this->indices.push_back(belowFirst);
				this->indices.push_back(firstVert);
				
			}
		}
	}
		
		
	//3 -- Bottom cap generation
	//Here, the index of the central vertex, as well as the first vertex of the last layer, need to be calculated.
	int numVerts = this->numSlices * this->numLayers + 2;
	int lastVert = numVerts - 1;
	int startOfLastRing = lastVert - this->numSlices;

	//However, substituting lastVert for 0 and startOfLastRing for 1, the rest proceeds just like the upper cap.
	for(int i = 0; i < this->numSlices; i++)
	{
		this->indices.push_back(lastVert);
		
		if(i != (this->numSlices - 1))
		{
			this->indices.push_back(i + (startOfLastRing + 1));
		}
		else
		{
			this->indices.push_back(startOfLastRing);
		}
		
		this->indices.push_back(i + startOfLastRing);
	}
}

void Sphere::genColors()
{
	int numVerts = (this->numLayers * this->numSlices) + 2;

	GLubyte red = 0;
	GLubyte green = 0;
	GLubyte blue = 0;
	GLubyte alpha = 0;
	
	//Color generation, for the moment, is somewhat arbitrary.
	for(int i = 0; i < numVerts; i++)
	{
		this->colors.push_back(red);
		this->colors.push_back(green);
		this->colors.push_back(blue);
		this->colors.push_back(alpha);
		
		red += 1;
		green += 2;
		blue += 3;
		
	}

}

void Sphere::setColorToGLColor()
{
	//These colors are typically floats, which presents a problem....
	GLfloat colors[4] = {0.0f, 0.0f, 0.0f, 0.0f};
	GLubyte ubColors[4] = {0, 0, 0, 0};
	glGetFloatv(GL_CURRENT_COLOR, colors);
	int colorSize = this->colors.size();
	
	//Convert from float to ubyte
	for(int i = 0; i < 4; i++)
	{
		ubColors[i] = (GLubyte)(colors[i] * 255);		//should work?
	}
	this->colors.clear();
	for(int i = 0; i < colorSize; i++)
	{
		this->colors.push_back(ubColors[i % 4]);
	}
}

bool Sphere::setColors(GLubyte** colors)
{
	return false;
}

void Sphere::render()
{

	glColorPointer(4, GL_UNSIGNED_BYTE, 0, this->colors.data());
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, this->verts.data());
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_SHORT, this->indices.data());
}

void Sphere::update()
{
	//This acts as a sort of default behavior, really, but external calls can modify it considerably. Still only 'bout as smart as a Roomba...
	
	if(((this->origin->getX() + this->radius + this->velocity->getX()) > this->boundPos->getX()) || ((this->origin->getX() - this->radius + this->velocity->getX()) < this->boundNeg->getX()))
	{
		this->velocity->mulX(-1);
	}
	if(((this->origin->getY() + this->radius + this->velocity->getY()) > this->boundPos->getY()) || ((this->origin->getY() - this->radius + this->velocity->getY()) < this->boundNeg->getY()))
	{
		this->velocity->mulY(-1);
	}
	if(((this->origin->getZ() + this->radius + this->velocity->getZ()) > this->boundPos->getZ()) || ((this->origin->getZ() - this->radius + this->velocity->getZ()) < this->boundNeg->getZ()))
	{
		this->velocity->mulZ(-1);
	}
	
	this->translate(this->velocity->getX(), this->velocity->getY(), this->velocity->getZ());
	this->render();

}

void Sphere::setVelocity(GLfloat velX, GLfloat velY, GLfloat velZ)
{
	this->velocity->setX(velX);
	this->velocity->setY(velY);
	this->velocity->setZ(velZ);
}

void Sphere::accelerate(GLfloat accX, GLfloat accY, GLfloat accZ)
{
	this->velocity->addX(accX);
	this->velocity->addY(accY);
	this->velocity->addZ(accZ);
}


void Sphere::translate(GLfloat x, GLfloat y, GLfloat z)
{
	std::vector<GLfloat>::iterator iter;

	//Update the origin
	this->origin->addX(x);
	this->origin->addY(y);
	this->origin->addZ(z);
	
	//...and the verts
	for(iter = this->verts.begin(); iter != this->verts.end(); iter++)
	{
		*iter += x;
		iter++;
		*iter += y;
		iter++;
		*iter += z;
	}
	
}

void Sphere::setBounds(GLfloat xPos, GLfloat xNeg, GLfloat yPos, GLfloat yNeg, GLfloat zPos, GLfloat zNeg)
{
	this->boundPos->setX(xPos);
	this->boundPos->setY(yPos);
	this->boundPos->setZ(zPos);
	
	this->boundNeg->setX(xNeg);
	this->boundNeg->setY(yNeg);
	this->boundNeg->setZ(zNeg);

}
