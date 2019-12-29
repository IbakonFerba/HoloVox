// ##################################################################
// A Slideshow of different programs for the HoloVox cube
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################


#include <HoloVox.h>
#include <HoloVoxUtils.h>
#include <Vector3.h>

#include "RotatingShapeProgram.h"
#include "BouncingCubeProgram.h"
#include "BouncingHourglassProgram.h"

// the state of millis() when the last delta time calculation happened
float lastFrameTime;

HoloVox display;

// amount of time in seconds after which the current program should be switched out for a new one
float programChangeInterval = 300;
float programChangeTimer = 0;

#define NUM_PROGRAMS 3
// the place where the actual programs are stored
SlideshowProgram *programs[NUM_PROGRAMS] = {new RotatingShapeProgram(2.0f, 0.4, 0.8, 4.0f), new BouncingCubeProgram(4.0f, 0.2f, 0.8f), new BouncingHourglassProgram(4.0f, 0.4, 0.8)};

// in order to chose a program we create a pool from a number of probabilities. That way we can make some programs appear more often than others
#define PROGRAM_POOL_SIZE 10
float probabilities[NUM_PROGRAMS] = {3, 1, 1};
SlideshowProgram* programPool[PROGRAM_POOL_SIZE]; 
int programPoolLength = 0;

// currently active program
SlideshowProgram* currentProgram;

void selectNewProgram() {
    currentProgram = programPool[random(0, programPoolLength)];
}

void setup()
{
    display.initialize();

    // get a random seed for the random function by getting the contents of a random int pointer
    int *randAdress;
    randomSeed(*++randAdress);

    // create the program pool
    for(int i = 0; i < NUM_PROGRAMS; ++i) {
        for(int j = 0; j < probabilities[i]; ++j) {
            programPool[programPoolLength++] = programs[i];
        }
    }


    // start a random program
    selectNewProgram();
    currentProgram->start();

    lastFrameTime = millis();
}

void loop()
{
    // calculate the time in seconds since the last frame
    float dt = (millis() - lastFrameTime) * 0.001f;
    lastFrameTime = millis();

    // increase the program timer. Once it reaches the specified interval, start a new program
    programChangeTimer += dt;
    if (programChangeTimer >= programChangeInterval)
    {
        programChangeTimer = 0;
        selectNewProgram();

        currentProgram->start();
    }

    // update and draw the active program
    currentProgram->update(dt);
    currentProgram->draw(display);

    // manage rendering
    display.render();
    display.clearBuffer();
}
