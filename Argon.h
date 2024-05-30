#pragma once 
#include "Particule.h"
#include "Systeme.h"


class Argon : public Particule {
public:
    Argon(double x, double y, double z, double vx, double vy, double vz, double masse, bool trace = false) :
        Particule(x, y, z, vx, vy, vz, masse, trace) {}

    Argon(double masse, bool trace = false) :
        Particule(masse, trace) {}

    std::ostream& affiche(std::ostream& sortie) const override;
    
    void dessine_sur(SupportADessin& support) override ;

    void initialise_rd(unsigned int nb_part, double masse, Systeme& s);

private: 
    static constexpr double M = 39.948;

};

std::ostream& operator<<(std::ostream& sortie, const Argon& p);
