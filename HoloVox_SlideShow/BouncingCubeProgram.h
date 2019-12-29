#pragma once

#ifndef BOUNCING_CUBE_PROGRAM_H
#define BOUNCING_CUBE_PROGRAM_H

#include "BouncingShapeProgram.h"

// ##################################################################
// A Wireframe Cube bouncing around the screen
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################
class BouncingCubeProgram : public BouncingShapeProgram
{
public:
    // ############################### Constructor ###################################
    BouncingCubeProgram(float const maxSpeed, float const minScale, float const maxScale) : BouncingShapeProgram(maxSpeed, minScale, maxScale), m_cube(0, 0, 0, 7, 7, 7, 0, 0, 0) {}
    ~BouncingCubeProgram() = default;

    // ############################### Functionality ###################################
    void draw(HoloVox &rDisplay) override
    {
        m_cube.draw(rDisplay);
    }

    void move(const Vector3 &rMovementVector) override
    {
        m_cube.Position += rMovementVector;
    }

    // ############################### Setter ###################################
    void setScale(float const scale) override
    {
        m_cube.setScale(scale, scale, scale);
    }

    // ############################### Getter ###################################
    Vector3 &getPos() override
    {
        return m_cube.Position;
    }

    float getColliderRadius() const override
    {
        return m_cube.getDimensions().x * 0.5f * m_cube.getScale().x;
    }

private:
    WireCube m_cube;
};

#endif
