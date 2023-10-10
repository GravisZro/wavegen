#include "triangle.h"

using namespace wavegen;

Triangle::Triangle(float128_t frequency,
                   float128_t amplitude,
                   uint32_t samplesPerSecond)
  : Base(frequency, amplitude, samplesPerSecond),
    m_currentX(0.0)
{
  Triangle::recalculateStep();
}

float128_t Triangle::sample(void)
{
  m_currentX += m_increment; // increment/decrement

  if(m_currentX > 1.0) // out of upper bound
  {
    m_currentX = 2.0 - m_currentX; // "bounce" down
    m_increment *= -1.0; // switch to decrement
  }
  else if(m_currentX < -1.0) // out of lower bound
  {
    m_currentX = 2.0 + m_currentX; // "bounce" up
    m_increment *= -1.0; // switch to increment
  }

  return m_amplitude * m_currentX;
}

void Triangle::recalculateStep(void)
{
  m_increment = 4.0 * m_frequency / m_samplesPerSecond;
}

