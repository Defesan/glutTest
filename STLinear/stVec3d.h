#ifndef __ST_VEC3D_H__
#define __ST_VEC3D_H__

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
	
	void addVec3f(STVec3d* v2);
	void subVec3f(STVec3d* v2);
	void mulScalar(double scale);

};

#endif //__ST_VEC3D_H__
