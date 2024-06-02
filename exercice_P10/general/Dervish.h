#pragma once 
#include "quitourne.h"
#include "support_a_dessin.h"

class Dervish:public QuiTourne{
public:
Dervish (double a=0.0):
QuiTourne(a){}
virtual void dessine_sur(SupportADessin& support) override
  { support.dessine(*this); }


};
