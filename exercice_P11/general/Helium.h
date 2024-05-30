#pragma once 
#include "Particule.h"
#include "Systeme.h"

class Helium : public Particule {
public:
    Helium(double x, double y, double z, double vx, double vy, double vz, double masse, bool trace = false,bool couleur =false) :
            Particule(x, y, z, vx, vy, vz, masse, trace,couleur) {}
    Helium(double masse,  bool trace = false,bool couleur =false) :
       Particule(masse, trace,couleur) {}

    std::ostream& affiche(std::ostream& sortie) const override;
        
        
   void dessine_sur(SupportADessin& support) override ;

   void initialise_rd(unsigned int nb_part, double masse, Systeme& s);

private:
    static constexpr double M = 4.002602;
        };

std::ostream& operator<<(std::ostream& sortie, const Helium& p);
