#pragma once

#ifndef WIRE_SHAPE_H
#define WIRE_SHAPE_H

#include "Vector3.h"
#include "Matrix.h"
#include "HoloVox.h"

class HoloVox;

// ##################################################################
// Base for Wireframe models
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################
class WireShape
{
public:
    // ############################### Public Fields ###################################
    Vector3 Position;

    // ############################### Constructor ###################################
    WireShape() = default;
    virtual ~WireShape() = default;

    // ############################### Functionality ###################################
    virtual void draw(HoloVox &rDisplay) const = 0;

    // ############################### Setter ###################################
    void setRotation(const float x, const float y, const float z)
    {
        m_rot.x = x;
        m_rot.y = y;
        m_rot.z = z;

        RotationMatrix = Matrix33::createEulerAngleRotation(m_rot.x, m_rot.y, m_rot.z);
    }

    void setScale(const float x, const float y, const float z) 
    {
        m_scale.x = x;
        m_scale.y = y;
        m_scale.z = z;

        ScaleMatrix.Values[0][0] = x;
        ScaleMatrix.Values[1][1] = y;
        ScaleMatrix.Values[2][2] = z;
    }

    // ############################### Getter ###################################
    Vector3 getRotation() const
    {
        return m_rot;
    }

    Vector3 getScale() const
    {
        return m_scale;
    }

protected:
    Matrix33 RotationMatrix;
    Matrix33 ScaleMatrix;

    void transformPoints(Vector3* pPoints, Vector3* pTransformedPoints, const int numOfPoints) {
        for (int i = 0; i < numOfPoints; ++i)
        {
            *pTransformedPoints = Position + RotationMatrix.mul(ScaleMatrix.mul(*pPoints));
            ++pTransformedPoints;
            ++pPoints;
        }
    }
private:
    Vector3 m_rot;
    Vector3 m_scale;
};

#endif