#ifndef BASE_H
#define BASE_H

#include <numbers>
#include <cmath>
#include <cstdint>

namespace wavegen
{
  using float128_t = long double;

  class Base
  {
  public:
    constexpr Base(float128_t frequency,
                   float128_t amplitude,
                   uint32_t   samplesPerSecond)
      : m_frequency(frequency),
        m_amplitude(amplitude),
        m_samplesPerSecond(samplesPerSecond)
    {
    }

    virtual float128_t sample(void) = 0;

    virtual void setFrequency(float128_t frequency)
    {
      if(m_frequency != frequency)
      {
        m_frequency = frequency;
        recalculateStep();
      }
    }

    virtual constexpr void setAmplitude(float128_t amplitude)
      { m_amplitude = amplitude; }

    virtual void setSampleRate(uint32_t samplesPerSecond)
    {
      if(m_samplesPerSecond != samplesPerSecond)
      {
        m_samplesPerSecond = samplesPerSecond;
        recalculateStep();
      }
    }

    virtual void recalculateStep(void) = 0;

  protected:
    float128_t m_frequency;
    float128_t m_amplitude;
    float128_t m_samplesPerSecond; // Hz
  };
}

#endif // BASE_H
