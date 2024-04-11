#pragma once
#include <iostream>
#include "Dessinable.h"

class Enceinte:public Dessinable {
	
private:
    double hauteur;
    double largeur;
    double profondeur;
    
public:
    Enceinte(double a = 20.0, double b = 20.0, double c = 20.0) : hauteur(a), largeur(b), profondeur(c) {}

    std::ostream& affiche(std::ostream& sortie) const ;

void dessine_sur(SupportADessin& support) override ;


};

std::ostream& operator<<(std::ostream& sortie, const Enceinte& E);
