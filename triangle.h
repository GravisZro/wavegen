#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "base.h"

namespace wavegen
{
  class Triangle : public Base
  {
  public:
    Triangle(float128_t frequency, float128_t amplitude, uint32_t samplesPerSecond);

    float128_t sample(void) override;

    void recalculateStep(void) override;
  private:
    float128_t m_currentX;
    float128_t m_increment;
  };
}

#endif // TRIANGLE_H
