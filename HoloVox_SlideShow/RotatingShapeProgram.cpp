#include "RotatingShapeProgram.h"

// ############################### Constructor ###################################
RotatingShapeProgram::RotatingShapeProgram(float const speed, float const minScale, float const maxScale, float const maxScaleSpeed) : m_speed(speed), m_runTime(0), m_minScale(minScale), m_maxScale(maxScale), m_maxScaleSpeed(maxScaleSpeed)
{
    m_shapes[0] = new HourGlass(3.5, 3.5, 3.5, 7, 7, 7, 0, 0, 0);
    m_shapes[1] = new WireCube(3.5, 3.5, 3.5, 7,7,7, 0,0,0);
}

RotatingShapeProgram::~RotatingShapeProgram() {
    for(int i = 0; i < NUM_OF_SHAPES; ++i) {
        delete m_shapes[i];
    }
}


    // ############################### SlideshowProgram ###################################
void RotatingShapeProgram::start() {
    m_scale = randomf(m_minScale, m_maxScale);

    // determine if we should animate our scale, if yes we need to determine a scaling speed
    m_changeScale = random(2);
    if(m_changeScale)
        m_scalingSpeed = randomf(m_maxScaleSpeed);

    m_currentShape = random(NUM_OF_SHAPES);

    m_shapes[m_currentShape]->setScale(m_scale, m_scale, m_scale);
    m_angularVelocity = Vector3(randomf(-m_speed, m_speed), randomf(-m_speed, m_speed), randomf(-m_speed, m_speed));
}

void RotatingShapeProgram::update(const float deltaTime)
{
    m_runTime += deltaTime;

    if(m_changeScale) {
        float scale = (sin(m_runTime*m_scalingSpeed)*0.5f+0.5f)*(m_scale+(1.0f-m_maxScale));
        m_shapes[m_currentShape]->setScale(scale, scale, scale);
    }

    m_shapes[m_currentShape]->setRotation(m_runTime*m_angularVelocity.x, m_runTime*m_angularVelocity.y, m_runTime*m_angularVelocity.z);
}

void RotatingShapeProgram::draw(HoloVox &display)
{
    m_shapes[m_currentShape]->draw(display);
}