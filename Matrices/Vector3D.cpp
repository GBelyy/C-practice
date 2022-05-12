#include "Vector3D.h"





Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Vector3D::Vector3D()
{
    x = 0;
    y = 0;
    z = 0;
}
double Vector3D::getX() const {
    return x;
}
double Vector3D::getY()  const {
    return y;
}
double Vector3D::getZ()  const {
    return z;
}
double Vector3D::get(int i)  const
{
    switch (i) {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    }
    return 0;
}
void Vector3D::setX(double x) {
    this->x = x;
}
void Vector3D::setY(double y) {
    this->y = y;
}
void Vector3D::setZ(double z) {
    this->z = z;
}
void Vector3D::set(double value, int i)
{
    switch (i) {
    case 0:
        x = value;
    case 1:
        y = value;
    case 2:
        z = value;
    }
}





bool Vector3D::operator== (const Vector3D& v) const
{
    return x == v.x && y == v.y && z == v.z;
};
bool Vector3D::operator!= (const Vector3D& v) const
{
    return x != v.x || y != v.y || z != v.z;
};
Vector3D Vector3D::operator+ (const Vector3D& v) const
{
    return Vector3D(x + v.x, y + v.y, z + v.z);
};

Vector3D Vector3D::operator- (const Vector3D& v) const
{
    return Vector3D(x - v.x, y - v.y, z - v.z);
};
double Vector3D::operator*(const Vector3D& v) const
{
    return v.x * x + v.y * y + v.z * z;
}
Vector3D Vector3D::operator* (const double& a) const
{
    return Vector3D(a * x, a * y, a * z);
};



std::istream& operator>>(std::istream& mean, Vector3D& v)
{
    double x;
    double y;
    double z;

    mean >> x >> y >> z;
    v = Vector3D(x, y, z);
    return mean;
};


std::ostream& operator<<(std::ostream& wh,const  Vector3D& v)
{
    wh << "(" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")";
    return wh;
};

Vector3D operator*(const Matrix3D& matrix,const  Vector3D& vector) {
    Vector3D s;
    for (int i = 0; i < 3; i++) {
        double p = 0;
        for (int j = 0; j < 3; j++) {
            p += matrix.get(i, j) * vector.get(j);
        }
        s.set(p, i);
    }
    return s;
}

Vector3D operator* (const double a,const  Vector3D& v)
{
    return Vector3D(a * v.getX(), a * v.getY(), a * v.getZ());
}
