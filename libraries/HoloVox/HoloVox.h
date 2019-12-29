#pragma once

#ifndef HOLO_VOX_H
#define HOLO_VOX_H

#include <Arduino.h>

// define some pins
#define LAYER_CLEAR A0
#define LAYER_ADVANCE A1
#define LAYER_DATA A2

// define the dimensions of the Voxel Cube
#define LAYERS 8
#define ROWS 8
#define COLS 8

// ##################################################################
// Contains everything necessary to drive the HoloVox volumetric display
//
// v1.0 09/2019
// Written by Fabian Kober
// fabian-kober@gmx.net
// ##################################################################
class HoloVox
{
public:
  // ############################### Constructor ###################################
  HoloVox() = default;
  ~HoloVox() = default;


  // ############################### Init ###################################
  // initializes all needed pins
  void initialize() const;


  // ############################### Functionality ###################################
  // renders the current buffer
  void render() const;
  void clearBuffer();

  // sets the voxel at the provided position to be on in the buffer
  void setVoxel(int const x, int const y, int const z);
  // writes the provided state of the provided voxel to the buffer
  void writeVoxel(int const x, int const y, int const z, byte const state);

private:
  // ############################### Members ###################################
  // all row pins
  const char rows[ROWS] = {5, 6, 7, 8, 9, 10, 11, 12};
  // all colum pins
  const char cols[COLS] = {A3, A4, A5, 0, 1, 2, 3, 4};

  // this holds our image that should be rendered when render is called
  byte buffer[LAYERS][COLS];


  // ############################### Utility ###################################
  void renderRow(byte const data) const;
  inline void incrementLayer() const;
};

#endif