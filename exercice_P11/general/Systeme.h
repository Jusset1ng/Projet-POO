#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include "Enceinte.h"
#include "Particule.h"
#include "GenerateurAleatoire.h"

class Systeme :public Dessinable{
	private:
    
    std::vector<std::unique_ptr<Particule>> particules;
        Enceinte E;

    GenerateurAleatoire tirage; //peut etre initialisé avec la meme graine pour debugger
    double Epsilon;

    bool forcer = false; //Premier choc avec zenith à pi/2 et azimut a pi/3

    public:

    const double pas=1;

    
    Systeme() :  E (){}
    
    Systeme(double Eps) : Epsilon(Eps) {}

    Systeme(double a, double b, double c, double Eps) :  E(a, b, c), Epsilon(Eps) {}

    void set_forcage(bool b){forcer = b;}

    virtual ~Systeme() {}

    void  ajouter_particule(Particule* p);
    
    void set_enceinte(Enceinte enc);
    
    void set_epsilon(double n);
    
    void supprimer_particules();
    
    std::ostream& affiche(std::ostream& sortie) const;

    void dessine_sur(SupportADessin& support) override;

    void evolue(double dt);
 
};

std::ostream& operator<<(std::ostream& sortie, const Systeme& S) ;
    
 


