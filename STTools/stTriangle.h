#ifndef __ST_TRIANGLE_H__
#define __ST_TRIANGLE_H__

#include <vector>

#include "stVector.h"


class STTriangle
{
private:
	std::vector<STVec3f*> verts;
	std::vector<STVec3f*> norms;
	std::vector<STVec2f*> texCoords;

};

#endif //__ST_TRIANGLE_H__
