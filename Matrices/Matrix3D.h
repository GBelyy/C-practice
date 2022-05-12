#ifndef LINAL_MATRIX3D_H
#define LINAL_MATRIX3D_H

#include "iostream"
using namespace std;

class Matrix3D {
public:
    Matrix3D(double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8);
    Matrix3D(double* data);
    Matrix3D();
    double get(int i, int j) const;
    void set(double value, int i, int j);
    double determinant() const;
    Matrix3D operator+(const Matrix3D& m1) const;
    Matrix3D operator-(const Matrix3D& m1) const;
    Matrix3D operator*(const Matrix3D& m1) const;
    Matrix3D operator*(const double& scale) const;
protected:
    double data[9];
};

ostream& operator<<(std::ostream& wh, const Matrix3D& m);
istream& operator>>(std::istream& hw, Matrix3D& matrix);
Matrix3D operator*(const double& scale, const Matrix3D& matrix);

#endif //LINAL_MATRIX3D_H
