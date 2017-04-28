#ifndef __ST_PRIMITIVE_BATCH_H__
#define __ST_PRIMITIVE_BATCH_H__

#include "stBatch.h"

class STPrimitiveBatch : public STBatch
{
private:
public:
	STPrimitiveBatch();
	~STPrimitiveBatch();
	
	void begin();
	void end();
	
	void copyVertexData(std::vector<STVec3d*>);
	void copyNormalData(std::vector<STVec3d*>);
	
}


#endif //__ST_PRIMITIVE_BATCH_H__
