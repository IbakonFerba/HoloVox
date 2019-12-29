#pragma once

#ifndef SLIDESHOW_PROGRAM_H
#define SLIDESHOW_PROGRAM_H

#include "HoloVox.h"

// ##################################################################
// Base for the programs of the HoloVox slideshow
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################
class SlideshowProgram
{
public:
    // ############################### Constructor ###################################
    SlideshowProgram() = default;
    virtual ~SlideshowProgram() = default;

    // ############################### Functionality ###################################
    virtual void start(){};
    virtual void update(const float deltaTime){};
    virtual void draw(HoloVox &display){};
};

#endif