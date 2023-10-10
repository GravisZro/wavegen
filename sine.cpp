#include "sine.h"

using namespace wavegen;

Sine::Sine(float128_t frequency,
           float128_t amplitude,
           uint32_t   samplesPerSecond)
  : Base(frequency, amplitude, samplesPerSecond),
    m_currentX(0.0),
    m_currentY(1.0)
{
  Sine::recalculateStep();
}

float128_t Sine::sample(void)
{
  /*
    f is frequency
    rad/s is radians per second (sample rate)
    ω is angular frequency

    ω = 2π * f * rad/s
    Xₜ = Yₜ₋₁ * sin(ω) + Xₜ₋₁ * cos(ω)
    Yₜ = Yₜ₋₁ * cos(ω) - Xₜ₋₁ * sin(ω)
  */
  float128_t new_X = m_currentY * m_sin_omega +
                     m_currentX * m_cos_omega;
  m_currentY       = m_currentY * m_cos_omega -
                     m_currentX * m_sin_omega; // update Y position
  m_currentX       = new_X; // update X position

  return m_amplitude * m_currentX;
}

void Sine::recalculateStep(void)
{
  // ω = 2π * f * rad/s
  float128_t omega = std::numbers::pi_v<float128_t> * 2.0 * m_frequency / m_samplesPerSecond;
  m_sin_omega = std::sin(omega);
  m_cos_omega = std::cos(omega);
}
