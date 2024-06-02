#include "quitourne.h"

// ======================================================================
void QuiTourne::evolue(double dt)
{
  constexpr double omega(100.0);
  angle += omega * dt;
}
