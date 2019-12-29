#include "Matrix.h"

// ############################### Constructor ###################################
Matrix33::Matrix33() {
    Values[0][0] = 1;
    Values[0][1] = 0;
    Values[0][2] = 0;
    Values[1][0] = 0;
    Values[1][1] = 1;
    Values[1][2] = 0;
    Values[2][0] = 0;
    Values[2][1] = 0;
    Values[2][2] = 1;
}

Matrix33::Matrix33(const float r0c0, const float r0c1, const float r0c2, const float r1c0, const float r1c1, const float r1c2, const float r2c0, const float r2c1, const float r2c2)
{
    Values[0][0] = r0c0;
    Values[0][1] = r0c1;
    Values[0][2] = r0c2;
    Values[1][0] = r1c0;
    Values[1][1] = r1c1;
    Values[1][2] = r1c2;
    Values[2][0] = r2c0;
    Values[2][1] = r2c1;
    Values[2][2] = r2c2;
}

// ############################### Functionality ###################################
Matrix33 Matrix33::mul(const Matrix33 &rOther) const
{
    Matrix33 returnMatrix;

    for (byte r = 0; r < 3; ++r)
    {
        for (byte c = 0; c < 3; ++c)
        {
            returnMatrix.Values[r][c] = Values[r][0] * rOther.Values[0][c] + Values[r][1] * rOther.Values[1][c] + Values[r][2] * rOther.Values[2][c];
        }
    }

    return returnMatrix;
}

Vector3 Matrix33::mul(const Vector3 &rVec) const
{
    Vector3 returnVector;

    returnVector.x = Values[0][0] * rVec.x + Values[0][1] * rVec.y + Values[0][2] * rVec.z;
    returnVector.y = Values[1][0] * rVec.x + Values[1][1] * rVec.y + Values[1][2] * rVec.z;
    returnVector.z = Values[2][0] * rVec.x + Values[2][1] * rVec.y + Values[2][2] * rVec.z;

    return returnVector;
}

// ############################### Factories ###################################
Matrix33 Matrix33::createAngleAxisRotation(const float angle, const Vector3 &rAxis)
{
    float angleCos = cosf(angle);
    float angleSin = sinf(angle);
    return Matrix33(angleCos + rAxis.x * rAxis.x * (1 - angleCos), rAxis.x * rAxis.y * (1 - angleCos) - rAxis.z * angleSin, rAxis.x * rAxis.z * (1 - angleCos) + rAxis.y * angleSin,
                    rAxis.y * rAxis.x * (1 - angleCos) + rAxis.z * angleSin, angleCos + rAxis.y * rAxis.y * (1 - angleCos), rAxis.y * rAxis.z * (1 - angleCos) - rAxis.x * angleSin,
                    rAxis.z * rAxis.x * (1 - angleCos) - rAxis.y * angleSin, rAxis.z * rAxis.y * (1 - angleCos) + rAxis.x * angleSin, angleCos + rAxis.z * rAxis.z * (1 - angleCos));
}

Matrix33 Matrix33::createEulerAngleRotation(const float x, const float y, const float z)
{
    float xCos = cos(x);
    float xSin = sin(x);

    float yCos = cos(y);
    float ySin = sin(y);

    float zCos = cos(z);
    float zSin = sin(z);

    Matrix33 rotX(1, 0, 0,
                  0, xCos, -xSin,
                  0, xSin, xCos);

    Matrix33 rotY(yCos, 0, ySin,
                  0, 1, 0,
                  -ySin, 0, yCos);

    Matrix33 rotZ(zCos, -zSin, 0,
                  zSin, zCos, 0,
                  0, 0, 1);

    Matrix33 rotXY = rotX.mul(rotY);
    return rotXY.mul(rotZ);
}