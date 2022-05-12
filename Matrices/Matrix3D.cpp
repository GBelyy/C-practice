#include "Matrix3D.h"


using namespace std;


Matrix3D::Matrix3D(double a0, double a1, double a2,
    double a3, double a4, double a5,
    double a6, double a7, double a8) {
    data[0] = a0;
    data[1] = a1;
    data[2] = a2;
    data[3] = a3;
    data[4] = a4;
    data[5] = a5;
    data[6] = a6;
    data[7] = a7;
    data[8] = a8;
}

Matrix3D::Matrix3D(double* data) {
    for (int i = 0; i < 9; i++) {
        this->data[i] = data[i];
    }
    delete[] data;
}


double Matrix3D::get(int i, int j) const {
    if ((i < 0) || (j < 0) || (i > 2) || (j > 2)) {
        return 0;
    }
    return data[(i * 3) + j];
}

Matrix3D::Matrix3D() {
    for (int i = 0; i < 9; i++) {
        data[i] = 0;
    }
}

void Matrix3D::set(double value, int i, int j) {
    data[(i * 3) + j] = value;
}

double Matrix3D::determinant() const {
    return data[0] * (data[4] * data[8] - data[5] * data[7])
        - data[1] * (data[3] * data[8] - data[5] * data[6])
        + data[2] * (data[3] * data[7] - data[4] * data[6]);
}

Matrix3D Matrix3D::operator+(const Matrix3D& m1) const {
    double* s = new double[9];
    for (int i = 0; i < 9; i++) {
        s[i] = data[i] + m1.data[i];
    }
    return Matrix3D(s);
}

Matrix3D Matrix3D::operator-(const Matrix3D& m1) const {
    return Matrix3D(m1 * (-1.0) + *this);
}

Matrix3D Matrix3D::operator*(const double& scale) const {
    double* s = new double[9];
    for (int i = 0; i < 9; i++) {
        s[i] = scale * data[i];
    }
    return Matrix3D(s);
}

Matrix3D Matrix3D::operator*(const Matrix3D& m1) const {
    double* s = new double[9];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s[(i * 3) + j] = 0;
            for (int k = 0; k < 3; k++) {
                s[(i * 3) + j] += get(i, k) * m1.get(k, j);
            }
        }
    }
    return Matrix3D(s);
}

std:: ostream& operator<<(std::ostream& wh, const Matrix3D& m) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            wh << m.get(i, j) << ", ";
        }
        wh << std::endl;
    }
    return wh;
}

std::istream& operator>>(std::istream& hw, Matrix3D& matrix) {
    double* data = new double[9];
    for (int i = 0; i < 9; i++)
    {
        hw >> data[i];
    }
    matrix = Matrix3D(data);
    return hw;
}

Matrix3D operator*(const double& scale, const Matrix3D& matrix) {
    return matrix * scale;
}
