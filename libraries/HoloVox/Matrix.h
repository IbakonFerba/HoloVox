#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include "Vector3.h"
#include <Arduino.h>

// ##################################################################
// A 3x3 Matrix with basic multiplication functionality and factory for rotation matrices
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################
class Matrix33
{
public:
    // ############################### Public Fields ###################################
    float Values[3][3];

    // ############################### Constructor ###################################
    Matrix33();
    Matrix33(const float r0c0, const float r0c1, const float r0c2, const float r1c0, const float r1c1, const float r1c2, const float r2c0, const float r2c1, const float r2c2);

    // ############################### Destructor ###################################
    ~Matrix33() = default;

    // ############################### Functionality ###################################
    Matrix33 mul(const Matrix33 &other) const;
    Vector3 mul(const Vector3 &rVec) const;

    // ############################### DestFactoriesructor ###################################
    static Matrix33 createAngleAxisRotation(const float angle, const Vector3 &rAxis);
    static Matrix33 createEulerAngleRotation(const float x, const float y, const float z);
};

#endif