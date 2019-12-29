#include "BouncingShapeProgram.h"

// ############################### Constructor ###################################
BouncingShapeProgram::BouncingShapeProgram(float const maxSpeed, float const minScale, float const maxScale) : m_maxSpeed(maxSpeed), m_minScale(minScale), m_maxScale(maxScale)
{
}

// ############################### SlideshowProgram ###################################
void BouncingShapeProgram::start()
{
    float scale = randomf(m_minScale, m_maxScale);
    setScale(scale);

    // determine a starting position inside the cube
    float r = getColliderRadius();
    Vector3 &rPos = getPos();
    rPos.x = randomf(r, COLS - 1 - r);
    rPos.y = randomf(r, ROWS - 1 - r);
    rPos.z = randomf(r, LAYERS - 1 - r);

    // create a random clamped velocity
    m_velocity = Vector3(randomf(-m_maxSpeed, m_maxSpeed), randomf(-m_maxSpeed, m_maxSpeed), randomf(-m_maxSpeed, m_maxSpeed));
    if (m_velocity.magnitude() > m_maxSpeed)
    {
        m_velocity.normalize();
        m_velocity *= m_maxSpeed;
    }
}

void BouncingShapeProgram::update(const float deltaTime)
{
    move(m_velocity * deltaTime);

    Vector3 &rPos = getPos();
    float r = getColliderRadius();

    // make the shape bounce from the walls of the cube
    if (rPos.x - r < 0.0f)
    {
        rPos.x = r;
        m_velocity.x *= -1;
    }
    else if (rPos.x + r >= COLS - 0.5)
    {
        rPos.x = COLS - 1 - r - 0.5;
        m_velocity.x *= -1;
    }

    if (rPos.y - r < 0.0f)
    {
        rPos.y = r;
        m_velocity.y *= -1;
    }
    else if (rPos.y + r >= ROWS - 0.5)
    {
        rPos.y = ROWS - 1 - r - 0.5;
        m_velocity.y *= -1;
    }

    if (rPos.z - r < 0.0f)
    {
        rPos.z = r;
        m_velocity.z *= -1;
    }
    else if (rPos.z + r >= LAYERS - 0.5)
    {
        rPos.z = LAYERS - 1 - r - 0.5;
        m_velocity.z *= -1;
    }
}