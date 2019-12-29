#pragma once

#ifndef HOURGLASS_H
#define HOURGLASS_H

#include "WireShape.h"

class HourGlass : public WireShape {
    public:
    // ############################### Constructor ###################################
    HourGlass(float const xPos, float const yPos, float const zPos, float const xSize, float const ySize, float const zSize, float const xRot, float const yRot, float const zRot);
    ~HourGlass() = default;

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
    Vector3 points[8];

    // the rotated vertices in model space
    Vector3 transformedPoints[8];
};

#endif