#ifndef SAWTOOTH_H
#define SAWTOOTH_H

#include "base.h"

namespace wavegen
{
  class SawTooth : public Base
  {
  public:
    SawTooth(float128_t frequency, float128_t amplitude, float128_t samplesPerSecond);

    float128_t sample(void) override;

  private:
    void recalculateStep(void) override;
  private:
    float128_t m_currentX;
    float128_t m_increment;
  };
}

#endif // SAWTOOTH_H
