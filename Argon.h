#pragma once 
#include "Particule.h"


class Argon : public Particule {
public:
    Argon(double a, double b, double c, double d, double e, double f, double g) :
        Particule(a, b, c, d, e, f, g) {}

    std::ostream& affiche(std::ostream& sortie) const override;
    
    void dessine_sur(SupportADessin& support) override ;

};

std::ostream& operator<<(std::ostream& sortie, const Argon& p);
