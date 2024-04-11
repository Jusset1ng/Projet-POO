#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Enceinte.h"
#include "Particule.h"






class Systeme :public Dessinable{
	private:
    std::vector<std::unique_ptr<Particule>> particules;
    Enceinte E;
public:
    Systeme() :  E (){}
   
    Systeme(double a, double b, double c) :  E(a, b, c) 
    {}
    
    void  ajouter_particule(Particule* p);
    
    void supprimer_particules();
    
    std::ostream&  affiche(std::ostream& sortie) const;

void dessine_sur(SupportADessin& support) override  ;
};


std::ostream& operator<<(std::ostream& sortie, const Systeme& S) ;
    
 


