#ifndef __ST_PRIMITIVE_BATCH_H__
#define __ST_PRIMITIVE_BATCH_H__

#include "stBatch.h"

class STPrimitiveBatch : public STBatch
{
private:
public:
	STPrimitiveBatch(GLuint numTexLayers = 4);
	~STPrimitiveBatch();
	
	void begin();
	void end();
	
	void copyVertexData(std::vector<STVec3d*> verts);
	void copyNormalData(std::vector<STVec3d*> norms);
	void copyColorData(std::vector<STVec4f*> colors);
	void copyTexCoordData(std::vector<STVec2d*> texCoords, GLuint textureLayer);
	
	void draw() override;
}


#endif //__ST_PRIMITIVE_BATCH_H__
