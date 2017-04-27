#ifndef __ST_BATCH_H__
#define __ST_BATCH_H__

/*
	I can certainly understand the virtue of having a base class for these batches...but calling it BatchBase is a bit much.
	Also, a trick I recall from my compilers class, sometimes you want to know the type of subclass you're working with.
 */

enum BATCH_TYPE {TRIANGLE, PRIMITIVE};

class STBatch
{
private:
	BATCH_TYPE type;
public:
	virtual void draw() = 0;
}; 


#endif //__ST_BATCH_H__
