#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Particule.h"
#include "Particule.cc"


class Enceinte {
	
private:
    double hauteur;
    double largeur;
    double profondeur;
    
public:
    Enceinte(double a = 20.0, double b = 20.0, double c = 20.0) : hauteur(a), largeur(b), profondeur(c) {}

    std::ostream& affiche(std::ostream& sortie) const ;


};

class Systeme {
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

};


std::ostream& operator<<(std::ostream& sortie, const Systeme& S) {
    return S.affiche(sortie);}
    
    std::ostream& operator<<(std::ostream& sortie, const Enceinte& E) {
    return E.affiche(sortie);}


