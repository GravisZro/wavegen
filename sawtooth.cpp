#include "sawtooth.h"

using namespace wavegen;

SawTooth::SawTooth(float128_t frequency,
                   float128_t amplitude,
                   float128_t samplesPerSecond)
  : Base(frequency, amplitude, samplesPerSecond),
    m_currentX(-1.0)
{
  SawTooth::recalculateStep();
}

float128_t SawTooth::sample(void)
{
  m_currentX += m_increment; // increment

  if (m_currentX > 1.0) // outside of upper bound
    m_currentX -= 2.0; // move just above lower bound

  return m_amplitude * m_currentX;
}

void SawTooth::recalculateStep(void)
{
  m_increment = 2.0 * m_frequency / m_samplesPerSecond;
}

