#ifndef PULSE_H
#define PULSE_H

#include "base.h"

namespace wavegen
{
  class Pulse : public Base
  {
  public:
    Pulse(float128_t frequency, float128_t amplitude, uint32_t samplesPerSecond, float128_t duty_cycle = 0.5);

    float128_t sample(void) override;

    void setDutyCycle(float128_t duty_cycle);
    void recalculateStep(void) override;
  private:
    float128_t m_duty_cycle;
    uint32_t m_sample_num;
    uint32_t m_cutoff_cycle;
    uint32_t m_last_cycle;
  };
}

#endif // PULSE_H
