#include "stPrimitiveBatch.h"

stPrimitiveBatch::stPrimitiveBatch(GLuint numTexLayers = 4)
{
	this->type = PRIMITIVE;
	for(GLuint i = 0; i < numTexLayers; i++)
	{
		this->texCoords.push_back(std::vector<STVec2d*>());
	}
}
