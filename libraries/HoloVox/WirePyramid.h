#pragma once

#ifndef WIRE_PYRAMID_H
#define WIRE_PYRAMID_H

#include "WireShape.h"

// ##################################################################
// A Wireframe Pyramid that can be moved and rotated
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################
class WirePyramid : public WireShape
{
public:
    // ############################### Constructor ###################################
    WirePyramid(float const xPos, float const yPos, float const zPos, float const xSize, float const ySize, float const zSize, float const xRot, float const yRot, float const zRot);
    ~WirePyramid() = default;

    // ############################### Functionality ###################################
    void draw(HoloVox &rDisplay) const override;

    // ############################### Getter ###################################
    Vector3 getDimensions() const
    {
        return m_dimensions;
    }

private:
    Vector3 m_dimensions;

    // the vertices in model space
    Vector3 points[5];

    // the rotated vertices in model space
    Vector3 transformedPoints[5];
};

#endif