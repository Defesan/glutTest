#include "stRect.h"

Rect::Rect(GLfloat originX, GLfloat originY, GLfloat originZ, GLfloat width, GLfloat height)
{
	//We need four vertices.
	//this->verts = new GLfloat[12];
	//this->colors = new GLubyte[12];
	//this->indices = new GLushort[6];
	
	//Let's just make sure there's no need for reallocation.
	this->verts.reserve(12);
	this->colors.reserve(16);
	this->indices.reserve(6);
	
	
	
	this->originX = originX;
	this->originY = originY;
	this->originZ = originZ;
	this->velX = 0.0f;
	this->velY = 0.0f;
	this->velZ = 0.0f;
	this->width = width;
	this->height = height;
	
	//Since I know what I'm working with, I can set some sane defaults. They do have to change with the aspect ratio, though.
	this->boundXPos = 100.0f;
	this->boundYPos = 100.0f;
	this->boundZPos = 100.0f;
	//That could lead to slowdowns, but then, this is a bit of a hack. Honestly, collision detection IS in the planning stages.
	this->boundXNeg = -100.0f;
	this->boundYNeg = -100.0f;
	this->boundZNeg = -100.0f;
	
	this->genVerts();
	this->genIndices();
	
	for(int i = 0; i < 4; i++)
	{
		this->colors.push_back(20 * i);
		this->colors.push_back(30 * i);
		this->colors.push_back(50 * i);
		this->colors.push_back(255);
	}
}

Rect::~Rect()
{

}

void Rect::genVerts()
{
	GLfloat offsetX = this->width / 2;
	GLfloat offsetY = this->height / 2; 
	this->verts.push_back(-offsetX);
	this->verts.push_back(offsetY);
	this->verts.push_back(0.0f);
	this->verts.push_back(offsetX);
	this->verts.push_back(offsetY);
	this->verts.push_back(0.0f);
	this->verts.push_back(-offsetX);
	this->verts.push_back(-offsetY);
	this->verts.push_back(0.0f);
	this->verts.push_back(offsetX);
	this->verts.push_back(-offsetY);
	this->verts.push_back(0.0f);
	
	this->translate(this->originX, this->originY, this->originZ);

}

void Rect::genIndices()
{
	this->indices.push_back(0);
	this->indices.push_back(1);
	this->indices.push_back(2);
	this->indices.push_back(2);
	this->indices.push_back(1);
	this->indices.push_back(3);
	
}

bool Rect::setColors(GLubyte** colors)
{
	if(colors)
	{
		this->colors.clear();
		//Yes, I know. Not good code. I need to pull in both the number of vertices and the size of the color array, but for now...
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				this->colors.push_back(colors[i][j]);
			}
		}
		return true;
	}
	return false;
}

void Rect::setColorToGLColor()
{
	//These colors are typically floats, which presents a problem....
	GLfloat colors[4] = {0.0f, 0.0f, 0.0f, 0.0f};
	GLubyte ubColors[4] = {0, 0, 0, 0};
	glGetFloatv(GL_CURRENT_COLOR, colors);
	
	//Convert from float to ubyte
	for(int i = 0; i < 4; i++)
	{
		ubColors[i] = (GLubyte)(colors[i] * 255);		//should work?
	}
	this->colors.clear();
	for(int i = 0; i < 16; i++)
	{
		this->colors.push_back(ubColors[i % 4]);
	}
}

void Rect::render()
{
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, this->colors.data());
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, this->verts.data());
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_SHORT, this->indices.data());
}


void Rect::update()
{
	GLfloat offsetX = this->width / 2;
	GLfloat offsetY = this->height / 2;
	
	if(((this->originX + offsetX + this->velX) > this->boundXPos) || ((this->originX - offsetX + this->velX) < this->boundXNeg))
	{
		this->velX *= -1;
	}
	if(((this->originY + offsetY + this->velY) > this->boundYPos) || ((this->originY - offsetY + this->velY) < this->boundYNeg))
	{
		this->velY *= -1;
	}
	if(((this->originZ + this->velZ) > this->boundZPos) || ((this->originZ + this->velZ) < this->boundZNeg))
	{
		this->velZ *= -1;
	}
	
	this->translate(this->velX, this->velY, this->velZ);
	this->render();

}

void Rect::setVelocity(GLfloat velX, GLfloat velY, GLfloat velZ)
{
	this->velX = velX;
	this->velY = velY;
	this->velZ = velZ;
}

void Rect::accelerate(GLfloat accX, GLfloat accY, GLfloat accZ)
{
	this->velX += accX;
	this->velY += accY;
	this->velZ += accZ;
}


void Rect::translate(GLfloat x, GLfloat y, GLfloat z)
{
	std::vector<GLfloat>::iterator iter;

	//Update the origin
	this->originX += x;
	this->originY += y;
	this->originZ += z;
	
	//...and the verts
	for(iter = this->verts.begin(); iter != this->verts.end(); iter++)
	{
		//I think this works?
		*iter += x;
		iter++;
		*iter += y;
		iter++;
		*iter += z;
	}
	
}

void Rect::setBounds(GLfloat xPos, GLfloat xNeg, GLfloat yPos, GLfloat yNeg, GLfloat zPos, GLfloat zNeg)
{
	this->boundXPos = xPos;
	this->boundXNeg = xNeg;
	this->boundYPos = yPos;
	this->boundYNeg = yNeg;
	this->boundZPos = zPos;
	this->boundZNeg = zNeg;

}
