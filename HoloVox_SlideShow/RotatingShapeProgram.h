#pragma once

#ifndef ROTATING_SHAPE_PROGRAM_H
#define ROTATING_SHAPE_PROGRAM_H

#include "SlideshowProgram.h"
#include "HoloVoxUtils.h"

// ##################################################################
// A program that rotates and can also scale a wireframe shape
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################
class RotatingShapeProgram : public SlideshowProgram
{
public:
    // ############################### Constructor ###################################
    RotatingShapeProgram(float const speed, float const minScale, float const maxScale, float const maxScaleSpeed);
    ~RotatingShapeProgram();

    // ############################### SlideshowProgram ###################################
    void start() override;
    void update(const float deltaTime) override;
    void draw(HoloVox &display) override;

private:
#define NUM_OF_SHAPES 2
    // the shapes at our disposal
    WireShape *m_shapes[NUM_OF_SHAPES];

    // index of the currently active shape
    int m_currentShape;

    // the time this program is already running for
    float m_runTime;

    Vector3 m_angularVelocity;
    float m_speed;

    float m_minScale;
    float m_maxScale;
    float m_scale;
    byte m_changeScale;
    float m_maxScaleSpeed;
    float m_scalingSpeed;
};

#endif