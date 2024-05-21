#pragma once 
#include "Particule.h"

class Helium : public Particule {
public:
    Helium(double x, double y, double z, double vx, double vy, double vz, double masse, bool trace = false) :
            Particule(x, y, z, vx, vy, vz, masse, trace) {}

    std::ostream& affiche(std::ostream& sortie) const override;
        
        
   void dessine_sur(SupportADessin& support) override ;
     
        };

std::ostream& operator<<(std::ostream& sortie, const Helium& p);
