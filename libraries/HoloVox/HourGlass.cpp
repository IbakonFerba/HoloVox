#include "HourGlass.h"
#include "HoloVoxUtils.h"

// ############################### Constructor ###################################
HourGlass::HourGlass(float const xPos, float const yPos, float const zPos, float const xSize, float const ySize, float const zSize, float const xRot, float const yRot, float const zRot) : m_dimensions(xSize, ySize, zSize)
{
    Position = Vector3(xPos, yPos, zPos);
    setRotation(xRot, yRot, zRot);

    Vector3 halfDim = m_dimensions * 0.5f;
    points[0] = Vector3(-halfDim.x, -halfDim.y, -halfDim.z);
    points[1] = Vector3(halfDim.x, -halfDim.y, -halfDim.z);
    points[2] = Vector3(halfDim.x, -halfDim.y, halfDim.z);
    points[3] = Vector3(-halfDim.x, -halfDim.y, halfDim.z);
    points[4] = Vector3(-halfDim.x, halfDim.y, -halfDim.z);
    points[5] = Vector3(halfDim.x, halfDim.y, -halfDim.z);
    points[6] = Vector3(halfDim.x, halfDim.y, halfDim.z);
    points[7] = Vector3(-halfDim.x, halfDim.y, halfDim.z);
}

// ############################### Functionality ###################################
void HourGlass::draw(HoloVox &rDisplay) const
{
    transformPoints(points, transformedPoints, 8);

    drawLine(transformedPoints[0], transformedPoints[1], rDisplay);
    drawLine(transformedPoints[1], transformedPoints[2], rDisplay);
    drawLine(transformedPoints[2], transformedPoints[3], rDisplay);
    drawLine(transformedPoints[3], transformedPoints[0], rDisplay);

    drawLine(transformedPoints[4], transformedPoints[5], rDisplay);
    drawLine(transformedPoints[5], transformedPoints[6], rDisplay);
    drawLine(transformedPoints[6], transformedPoints[7], rDisplay);
    drawLine(transformedPoints[7], transformedPoints[4], rDisplay);

    drawLine(transformedPoints[0], transformedPoints[6], rDisplay);
    drawLine(transformedPoints[1], transformedPoints[7], rDisplay);
    drawLine(transformedPoints[2], transformedPoints[4], rDisplay);
    drawLine(transformedPoints[3], transformedPoints[5], rDisplay);
}