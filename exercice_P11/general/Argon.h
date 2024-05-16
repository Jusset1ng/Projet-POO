#pragma once 
#include "Particule.h"


class Argon : public Particule {
public:
    Argon(double a=0.0, double b=0.0, double c=0.0, double d=0.0, double e=0.0, double f=0.0, double g=0.0) :
        Particule(a, b, c, d, e, f, g) {}

    std::ostream& affiche(std::ostream& sortie) const override;
    
    void dessine_sur(SupportADessin& support) override ;

};

std::ostream& operator<<(std::ostream& sortie, const Argon& p);
