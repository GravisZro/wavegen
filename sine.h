#ifndef SINE_H
#define SINE_H

#include "base.h"

namespace wavegen
{
  class Sine : public Base
  {
  public:
    Sine(float128_t frequency, float128_t amplitude, uint32_t samplesPerSecond);

    float128_t sample(void) override;

  private:
    void recalculateStep(void) override;
  private:
    float128_t m_sin_omega;
    float128_t m_cos_omega;
    float128_t m_currentX;
    float128_t m_currentY;
  };
}

#endif // SINE_H
