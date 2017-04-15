#ifndef __ST_VEC4F_H__
#define __ST_VEC4F_H__

class STVec4f
{
private:
	float x;
	float y;
	float z;
	float w;
	
public:
	STVec4f(float x, float y, float z, float w);
	STVec4f() : STVec4f(0.0f, 0.0f, 0.0f, 0.0f) {};
	
	float getX() {return this->x;};
	float getY() {return this->y;};
	float getZ() {return this->z;};
	float getW() {return this->w;};

	void setX(float x) {this->x = x;};
	void setY(float y) {this->y = y;};
	void setZ(float z) {this->z = z;};
	void setW(float w) {this->w = w;};
	
	void addX(float x) {this->x += x;};
	void addY(float y) {this->y += y;};
	void addZ(float z) {this->z += z;};
	void addW(float w) {this->w += w;};
	
	void subX(float x) {this->x -= x;};
	void subY(float y) {this->y -= y;};
	void subZ(float z) {this->z -= z;};
	void subW(float w) {this->w -= w;};
	
	void mulX(float scale) {this->x *= scale;};
	void mulY(float scale) {this->y *= scale;};
	void mulZ(float scale) {this->z *= scale;};
	void mulW(float scale) {this->w *= scale;};
	
	void addVec4f(STVec4f v2);
	void subVec4f(STVec4f v2);

};


#endif //__ST_VEC4F_H__
