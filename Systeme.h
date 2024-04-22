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
    std::vector<std::unique_ptr<Particule> > particules;
    Enceinte E;
    GenerateurAleatoire tirage; //peut etre initialisé avec la meme graine pour debugger
    double Epsilon;

    public:
    Systeme() :  E (){}
    
    Systeme(double Eps) : Epsilon(Eps) {}

    Systeme(double a, double b, double c, double Eps) :  E(a, b, c), Epsilon(Eps) {}

    virtual ~Systeme() {}

    void  ajouter_particule(Particule* p);
    
    void supprimer_particules();
    
    std::ostream& affiche(std::ostream& sortie) const;

    void dessine_sur(SupportADessin& support) override;

    void evolue(double dt);

};

std::ostream& operator<<(std::ostream& sortie, const Systeme& S) ;
    
 


