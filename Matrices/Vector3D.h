#ifndef LINAL_VECTOR3D_H
#define LINAL_VECTOR3D_H
#include "Matrix3D.h"

using namespace std;



class Vector3D
{
public:
    Vector3D(double x, double y, double z);
    Vector3D();
    double getX() const;
    double getY() const;
    double getZ()const;
    double get(int i) const;
    
    
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void set(double value, int i);


    bool operator== (const Vector3D& v) const;
    bool operator!= (const Vector3D& v) const;
    Vector3D operator+ (const Vector3D& v) const;
    double operator*(const Vector3D& v) const;
    Vector3D operator- (const Vector3D& v) const;
    Vector3D operator* (const double& a) const;
protected:
    double x;
    double y;
    double z;
};

std::ostream& operator<<(std::ostream& wh,const Vector3D& v);
Vector3D operator*(const Matrix3D& m, const Vector3D& v);
Vector3D operator* (const double a, const Vector3D& v);
std::istream& operator>>(std::istream& mean, Vector3D& v);



#endif //LINAL_VECTOR3D_H