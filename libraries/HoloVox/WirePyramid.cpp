#include "WirePyramid.h"
#include "HoloVoxUtils.h"

// ############################### Constructor ###################################
WirePyramid::WirePyramid(float const xPos, float const yPos, float const zPos, float const xSize, float const ySize, float const zSize, float const xRot, float const yRot, float const zRot) : m_dimensions(xSize, ySize, zSize)
{
    Position = Vector3(xPos, yPos, zPos);
    setRotation(xRot, yRot, zRot);

    Vector3 halfDim = m_dimensions * 0.5f;
    points[0] = Vector3(-halfDim.x, 0, -halfDim.z);
    points[1] = Vector3(halfDim.x, 0, -halfDim.z);
    points[2] = Vector3(halfDim.x, 0, halfDim.z);
    points[3] = Vector3(-halfDim.x, 0, halfDim.z);
    points[4] = Vector3(0, m_dimensions.y, 0);
}

// ############################### Functionality ###################################
void WirePyramid::draw(HoloVox &rDisplay) const
{
    transformPoints(points, transformedPoints, 8);

    drawLine(transformedPoints[0], transformedPoints[1], rDisplay);
    drawLine(transformedPoints[1], transformedPoints[2], rDisplay);
    drawLine(transformedPoints[2], transformedPoints[3], rDisplay);
    drawLine(transformedPoints[3], transformedPoints[0], rDisplay);

    drawLine(transformedPoints[0], transformedPoints[4], rDisplay);
    drawLine(transformedPoints[1], transformedPoints[4], rDisplay);
    drawLine(transformedPoints[2], transformedPoints[4], rDisplay);
    drawLine(transformedPoints[3], transformedPoints[4], rDisplay);
}