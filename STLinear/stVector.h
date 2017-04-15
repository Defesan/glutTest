#ifndef __ST_VECTOR_H__
#define __ST_VECTOR_H__

class STVec3f
{
private:
	float x;
	float y;
	float z;
public:
	STVec3f(float x, float y, float z);
	STVec3f() : STVec3f(0.0f, 0.0f, 0.0f) {};
	
	float getX() {return this->x;};
	float getY() {return this->y;};
	float getZ() {return this->z;};

	void setX(float x) {this->x = x;};
	void setY(float y) {this->y = y;};
	void setZ(float z) {this->z = z;};
	
	void addX(float x) {this->x += x;};
	void addY(float y) {this->y += y;};
	void addZ(float z) {this->z += z;};
	
	void subX(float x) {this->x -= x;};
	void subY(float y) {this->y -= y;};
	void subZ(float z) {this->z -= z;};
	
	void mulX(float scale) {this->x *= scale;};
	void mulY(float scale) {this->y *= scale;};
	void mulZ(float scale) {this->z *= scale;};
	
	void addVec3f(STVec3f* v2);
	void subVec3f(STVec3f* v2);
	void mulScalar(float scale);

};

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
	void mulScalar(float scale);

};

class STVec3d
{
private:
	double x;
	double y;
	double z;
public:
	STVec3d(double x, double y, double z);
	STVec3d() : STVec3d(0.0, 0.0, 0.0) {};
	
	double getX() {return this->x;};
	double getY() {return this->y;};
	double getZ() {return this->z;};

	void setX(double x) {this->x = x;};
	void setY(double y) {this->y = y;};
	void setZ(double z) {this->z = z;};
	
	void addX(double x) {this->x += x;};
	void addY(double y) {this->y += y;};
	void addZ(double z) {this->z += z;};
	
	void subX(double x) {this->x -= x;};
	void subY(double y) {this->y -= y;};
	void subZ(double z) {this->z -= z;};
	
	void mulX(double scale) {this->x *= scale;};
	void mulY(double scale) {this->y *= scale;};
	void mulZ(double scale) {this->z *= scale;};
	
	void addVec3d(STVec3d* v2);
	void subVec3d(STVec3d* v2);
	void mulScalar(double scale);

};

class STVec4d
{
private:
	double x;
	double y;
	double z;
	double w;
	
public:
	STVec4d(double x, double y, double z, double w);
	STVec4d() : STVec4d(0.0, 0.0, 0.0, 0.0) {};
	
	double getX() {return this->x;};
	double getY() {return this->y;};
	double getZ() {return this->z;};
	double getW() {return this->w;};

	void setX(double x) {this->x = x;};
	void setY(double y) {this->y = y;};
	void setZ(double z) {this->z = z;};
	void setW(double w) {this->w = w;};
	
	void addX(double x) {this->x += x;};
	void addY(double y) {this->y += y;};
	void addZ(double z) {this->z += z;};
	void addW(double w) {this->w += w;};
	
	void subX(double x) {this->x -= x;};
	void subY(double y) {this->y -= y;};
	void subZ(double z) {this->z -= z;};
	void subW(double w) {this->w -= w;};
	
	void mulX(double scale) {this->x *= scale;};
	void mulY(double scale) {this->y *= scale;};
	void mulZ(double scale) {this->z *= scale;};
	void mulW(double scale) {this->w *= scale;};
	
	void addVec4f(STVec4f v2);
	void subVec4f(STVec4f v2);
	void mulScalar(double scale);

};

#endif //__ST_VECTOR_H__
