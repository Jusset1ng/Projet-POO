#pragma once
#include <iostream>
#include "Dessinable.h"

class Enceinte:public Dessinable {
	
private:

    double largeur;     //x
    double profondeur;  //y
    double hauteur;     //z

public:
    Enceinte(double a = 20.0, double b = 20.0, double c = 20.0) : largeur(a), profondeur(b), hauteur(c) {}

    std::ostream& affiche(std::ostream& sortie) const ;

    void dessine_sur(SupportADessin& support) override ;
    
    double get_largeur(){ return largeur;}
    double get_profondeur(){ return profondeur;}
    double get_hauteur(){ return hauteur;}
};

std::ostream& operator<<(std::ostream& sortie, const Enceinte& E);
