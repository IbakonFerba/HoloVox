#pragma once

#ifndef HOLO_VOX_UTILS
#define HOLO_VOX_UTILS

#include "Vector3.h"
#include "HoloVox.h"
#include "Matrix.h"
#include "WireCube.h"
#include "WirePyramid.h"
#include "HourGlass.h"

// draws an axis aligned, filled box
static void drawAABox(const Vector3 &center, const Vector3 &dimensions, HoloVox &dp)
{
    Vector3 halfDim = dimensions * 0.5f;

    for (int x = round(center.x - halfDim.x); x < round(center.x + halfDim.x); ++x)
    {
        for (int y = round(center.y - halfDim.y); y < round(center.y + halfDim.y); ++y)
        {
            for (int z = round(center.z - halfDim.z); z < round(center.z + halfDim.z); ++z)
            {
                dp.setVoxel(x, y, z);
            }
        }
    }
}

static void drawSphere(const Vector3 &center, const float radius, HoloVox &dp)
{
    float sqrRad = radius * radius;
    for (int x = round(center.x - radius); x < round(center.x + radius); ++x)
    {
        for (int y = round(center.y - radius); y < round(center.y + radius); ++y)
        {
            for (int z = round(center.z - radius); z < round(center.z + radius); ++z)
            {
                Vector3 point(x, y, z);
                if ((point - center).sqrMag() <= sqrRad)
                    dp.setVoxel(x, y, z);
            }
        }
    }
}

// plots a line on the display using a 3D version of the DDA algorythm
static void drawLine(const Vector3 &rPos1, const Vector3 &rPos2, HoloVox &rDp)
{
    float dx = rPos2.x - rPos1.x;
    float dy = rPos2.y - rPos1.y;
    float dz = rPos2.z - rPos1.z;
    float absDx = abs(dx);
    float absDy = abs(dy);
    float absDz = abs(dz);
    float step = 0;
    if (absDx >= absDy && absDx >= absDz)
        step = absDx;
    else if (absDy >= absDx && absDy >= absDz)
        step = absDy;
    else
        step = absDz;

    dx = dx / step;
    dy = dy / step;
    dz = dz / step;
    float x = rPos1.x;
    float y = rPos1.y;
    float z = rPos1.z;
    for (int i = 0; i <= step; ++i)
    {
        rDp.setVoxel(round(x), round(y), round(z));
        x += dx;
        y += dy;
        z += dz;
    }
}

static float randomf()
{
    return (random(0, 101) / 100.0f);
}

static float randomf(float const max)
{
    return (random(0, 101) / 100.0f) * max;
}

static float randomf(float const min, float const max)
{
    return (random(0, 101)/100.0f)*(max-min)+min;
}

#endif