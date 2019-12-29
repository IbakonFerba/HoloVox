#include "HoloVox.h"

// ############################### Init ###################################
void HoloVox::initialize() const
{
    // set pinmodes of layer control pins
    pinMode(LAYER_ADVANCE, OUTPUT);
    pinMode(LAYER_DATA, OUTPUT);
    pinMode(LAYER_CLEAR, OUTPUT);

    // initialize the layer shift register to be empty
    digitalWrite(LAYER_ADVANCE, LOW);
    digitalWrite(LAYER_DATA, LOW);
    digitalWrite(LAYER_CLEAR, LOW); // clear is active low, so we pulse it low
    digitalWrite(LAYER_CLEAR, HIGH);

    // initialize the row pins
    for (int i = 0; i < 8; ++i)
    {
        pinMode(rows[i], OUTPUT);
        digitalWrite(rows[i], HIGH);
    }

    // initialize the colum pins
    for (int i = 0; i < 8; ++i)
    {
        pinMode(cols[i], OUTPUT);
        digitalWrite(cols[i], LOW);
    }
}

// ############################### Functionality ###################################
void HoloVox::render() const
{
    // set lowest bit of layer shift register to HIGH (the register is empty at this point, assuming initialize was called before render is called the first time)
    digitalWrite(LAYER_DATA, HIGH);
    incrementLayer();
    digitalWrite(LAYER_DATA, LOW);

    // now go trhough all voxels and set them to the state saved in the buffer
    for (byte l = 0; l < LAYERS; ++l)
    {
        for (byte c = 0; c < COLS; ++c)
        {
            // enable the current colum
            digitalWrite(cols[c], HIGH);

            // render the contents of the buffer at this row. We need to wait a litte so the LEDs glow brighter
            renderRow(buffer[l][c]);
            delayMicroseconds(100);

            // disable the row and the colum again
            renderRow(0);
            digitalWrite(cols[c], LOW);
        }

        incrementLayer();
    }
}

void HoloVox::clearBuffer()
{
    for (byte l = 0; l < LAYERS; ++l)
    {
        for (byte c = 0; c < COLS; ++c)
        {
            buffer[l][c] = 0;
        }
    }
}

void HoloVox::setVoxel(int const x, int const y, int const z)
{
    if (x < 0 || x >= COLS || y < 0 || y >= ROWS || z < 0 || z >= LAYERS)
        return;
    buffer[z][x] |= 1 << y;
}

void HoloVox::writeVoxel(int const x, int const y, int const z, byte const state)
{
    if (x < 0 || x >= COLS || y < 0 || y >= ROWS || z < 0 || z >= LAYERS)
        return;
    if (state == 0)
        buffer[z][x] &= ~(1 << y);
    else
        buffer[z][x] |= 1 << y;
}

// ############################### Utility ###################################
void HoloVox::renderRow(byte data) const
{
    for (byte r = 0; r < ROWS; ++r)
    {
        digitalWrite(rows[r], (data >> r) & 1 == 1 ? 0 : 1);
    }
}

inline void HoloVox::incrementLayer() const
{
    // pulse the clock of the Layer Shift register to get to the next layer
    digitalWrite(LAYER_ADVANCE, HIGH);
    digitalWrite(LAYER_ADVANCE, LOW);
}