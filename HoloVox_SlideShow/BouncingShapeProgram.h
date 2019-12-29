#pragma once

#ifndef BOUNCING_SHAPE_PROGRAM_H
#define BOUNCING_SHAPE_PROGRAM_H

#include "SlideshowProgram.h"
#include "HoloVoxUtils.h"

// ##################################################################
// Base Program for bouncing shapes
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################
class BouncingShapeProgram : public SlideshowProgram
{
public:
    // ############################### Constructor ###################################
    BouncingShapeProgram(float const maxSpeed, float const minScale, float const maxScale);
    ~BouncingShapeProgram() = default;

    // ############################### SlideshowProgram ###################################
    void start() override;
    void update(const float deltaTime) override;
    virtual void draw(HoloVox &display) {}

    // ############################### Functionality ###################################
    virtual void move(const Vector3 &rMovementVector) {}

    // ############################### Setter ###################################
    virtual void setScale(float const scale) {}

    // ############################### Getter ###################################
    virtual Vector3 &getPos() { return m_velocity; }
    virtual float getColliderRadius() const { return 1; }

private:
    Vector3 m_velocity;
    float m_maxSpeed;
    float m_minScale;
    float m_maxScale;
};

#endif