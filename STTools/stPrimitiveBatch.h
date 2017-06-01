#ifndef __ST_PRIMITIVE_BATCH_H__
#define __ST_PRIMITIVE_BATCH_H__

#include "stBatch.h"

class STPrimitiveBatch : public STBatch
{
public:
	STPrimitiveBatch(GLuint numTexLayers);
	~STPrimitiveBatch();
	
	void begin();
	void finalize();
	
	void copyVertexData(std::vector<STVec3f*> verts);
	void copyNormalData(std::vector<STVec3f*> norms);
	void copyColorData(std::vector<STVec4f*> colors);
	void copyTexCoordData(std::vector<STVec2f*> texCoords, GLuint textureLayer);
	
	void draw() override;
};


#endif //__ST_PRIMITIVE_BATCH_H__
