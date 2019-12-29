#pragma once

#ifndef BOUNCING_HOURGLASS_PROGRAM_H
#define BOUNCING_HOURGLASS_PROGRAM_H

#include "BouncingShapeProgram.h"

// ##################################################################
// A Wireframe Hourglass bouncing around the screen
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################
class BouncingHourglassProgram : public BouncingShapeProgram
{
public:
    // ############################### Constructor ###################################
    BouncingHourglassProgram(float const maxSpeed, float const minScale, float const maxScale) : BouncingShapeProgram(maxSpeed, minScale, maxScale), m_hourglass(0, 0, 0, 7, 7, 7, 0, 0, 0) {}
    ~BouncingHourglassProgram() = default;

    // ############################### Functionality ###################################
    void draw(HoloVox &rDisplay) override
    {
        m_hourglass.draw(rDisplay);
    }

    void move(const Vector3 &rMovementVector) override
    {
        m_hourglass.Position += rMovementVector;
    }

    // ############################### Setter ###################################
    void setScale(float const scale) override
    {
        m_hourglass.setScale(scale, scale, scale);
        m_hourglass.setRotation(random(4) * PI * 0.5f, random(4) * PI * 0.5f, random(4) * PI * 0.5f);
    }

    // ############################### Getter ###################################
    Vector3 &getPos() override
    {
        return m_hourglass.Position;
    }

    float getColliderRadius() const override
    {
        return m_hourglass.getDimensions().x * 0.5f * m_hourglass.getScale().x;
    }

private:
    HourGlass m_hourglass;
};

#endif
