#include "pulse.h"

using namespace wavegen;

Pulse::Pulse(float128_t frequency,
             float128_t amplitude,
             uint32_t samplesPerSecond,
             float128_t duty_cycle)
  : Base(frequency, amplitude, samplesPerSecond),
    m_duty_cycle(duty_cycle),
    m_sample_num(0),
    m_cutoff_cycle(0),
    m_last_cycle(samplesPerSecond)
{
  Pulse::recalculateStep();
}

float128_t Pulse::sample(void)
{
  if(m_sample_num < m_last_cycle)
    ++m_sample_num;
  else
    m_sample_num = 0;

  if(m_sample_num < m_cutoff_cycle)
    return m_amplitude * m_frequency;

  return 0;
}

void Pulse::recalculateStep(void)
{
  m_last_cycle = std::floor(m_samplesPerSecond);
  m_cutoff_cycle = std::ceil(m_duty_cycle * m_samplesPerSecond);
}

void Pulse::setDutyCycle(float128_t duty_cycle)
{
  if(m_duty_cycle != duty_cycle)
  {
    m_duty_cycle = duty_cycle;
    recalculateStep();
  }
}
