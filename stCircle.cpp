#include "stCircle.h"

Circle::Circle(GLfloat originX, GLfloat originY, GLfloat originZ, GLfloat radius, GLushort numVerts)
{

	this->originX = originX;
	this->originY = originY;
	this->originZ = originZ;
	this->radius = radius;
	this->numSlices = numVerts;
	
	this->verts.reserve(3 * (this->numSlices + 1));
	this->colors.reserve(4 * (this->numSlices + 1));
	this->indices.reserve(3 * this->numSlices);

	this->genVerts();
	
	this->genIndices();

	
	GLubyte red = 0;
	GLubyte green = 0;
	GLubyte blue = 0;
	GLubyte alpha = 255;
	
	int delta = 765 / (this->numSlices + 1);
	
	if(!delta)
	{
		delta = 1;
	
	}
	
	for(int i = 0; i < (this->numSlices + 1); i++)
	{
		this->colors.push_back(red);
		this->colors.push_back(green);
		this->colors.push_back(blue);
		this->colors.push_back(alpha);
		
		//Generate the colors for the next vertex.
		//If red hasn't been maxed out...
		if(red < 255)
		{
			//and there's room for a full delta...
			if((255 - red) > delta)
			{
				//Add the full delta.
				red += delta;
			}
			else	//There's still room, but not ENOUGH room
			{
				int overflow = delta - (255 - red);
				red = 255;
				green += overflow;
			}
		
		}
		else if(green < 255)
		{
			if((255 - green) > delta)
			{
				green += delta;
			}
			else	
			{
				int overflow = delta - (255 - green);
				green = 255;
				blue += overflow;
			}
		}
		else if(blue < 255)
		{
			if((255 - blue) > delta)
			{
				blue += delta;
			}
			else	
			{
				blue = 255;
			}
		}
		else
		{
			std::cout << "Edge case... But this shouldn't happen. All the colors got filled up." << std::endl;
		}
	}

}

Circle::~Circle()
{

}

void Circle::genVerts()
{
	GLfloat sliceAngle = (2 * PI) / (GLfloat)this->numSlices; 

	this->verts.push_back(0.0f);
	this->verts.push_back(0.0f);
	this->verts.push_back(0.0f);
	
	
	for(int i = 1; i < (this->numSlices + 1); i++)
	{
		GLfloat currentAngle = sliceAngle * (i - 1);
		
		this->verts.push_back(sin(currentAngle) * this->radius);
		this->verts.push_back(cos(currentAngle) * this->radius);
		this->verts.push_back(0.0f);
	}
	this->translate(this->originX, this->originY, this->originZ);
}

void Circle::genIndices()
{
	
	for(int i = 0; i < (this->numSlices - 1); i++)
	{
		this->indices.push_back(0);
		this->indices.push_back(i + 1);
		this->indices.push_back(i + 2);
	}
	
	this->indices.push_back(0);
	this->indices.push_back(this->numSlices);
	this->indices.push_back(1);
}

bool Circle::setColors(GLubyte** colors)
{
	return false;
}

void Circle::setColorToGLColor()
{
	GLfloat colors[4] = {0.0f, 0.0f, 0.0f, 0.0f};
	GLubyte ubColors[4] = {0, 0, 0, 0};
	glGetFloatv(GL_CURRENT_COLOR, colors);
	
	//Convert from float to ubyte
	for(int i = 0; i < 4; i++)
	{
		ubColors[i] = (GLubyte)(colors[i] * 255);		
	}
	this->colors.clear();
	for(unsigned int i = 0; i < this->verts.size(); i++)
	{
		this->colors.push_back(ubColors[i % 4]);
	}
}

void Circle::render()
{
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, this->colors.data());
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, this->verts.data());
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_SHORT, this->indices.data());

}

void Circle::update()
{
	//Still wondering if this will come in handy...
	this->render();
}

void Circle::translate(GLfloat x, GLfloat y, GLfloat z)
{
	//Update the origin
	this->originX += x;
	this->originY += y;
	this->originZ += z;
	
	//...and the verts
	for(unsigned int i = 0; i < (this->verts.size() / 3); i++)
	{
		int startPos = i * 3;
		this->verts[startPos] += x;
		this->verts[startPos + 1] += y;
		this->verts[startPos + 2] += z;
	}
	
}
