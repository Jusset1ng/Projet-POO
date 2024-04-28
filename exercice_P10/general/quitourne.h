#pragma once
#include "Machin.h"

class QuiTourne : public Machin {
public:
  QuiTourne(double a=0.0)
    : angle(a)
  {}
  virtual ~QuiTourne() = default;
  //QuiTourne(QuiTourne const&)            = default;
  //QuiTourne& operator=(QuiTourne const&) = default;
  //QuiTourne(QuiTourne&&)                 = default;
  //QuiTourne& operator=(QuiTourne&&)      = default;


  void evolue(double dt);

  // accesseur
  double infos() const { return angle; }

private:
  double angle; /* pour le mouvement ;
                   dans cet exemple, juste une rotation
                   au cours du temps                    */
};
