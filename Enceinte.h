#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Dessinable.h"

typedef std::vector<std::vector<std::vector<std::vector<size_t>>>> Tab_Cases;

class Enceinte: public Dessinable {
	
private:

    double largeur;     //x
    double profondeur;  //y
    double hauteur;     //z

    Tab_Cases kase;

    static constexpr double A_to_cm = 1;


    void redimensionne(unsigned int a, unsigned int b, unsigned int c);

public:

    Enceinte(double a = 20.0, double b = 20.0, double c = 20.0) : largeur(a), profondeur(b), hauteur(c){     // Redimensionner le vecteur kase pour correspondre aux dimensions a, b, c
	if(a <= 0) {
	  a = 20;
	  std::cout << "Largeur invalide, largeur = 20." << std::endl;}
	if(b <= 0) {
	  b = 20;
	  std::cout << "Profondeur invalide, profondeur = 20." << std::endl;}
	if(c <= 0) {
	  a = 20;
	  std::cout << "Hauteur invalide, hauteur = 20." << std::endl;}
        redimensionne(static_cast<unsigned int>(largeur), static_cast<unsigned int>(profondeur), static_cast<unsigned int>(hauteur));
    }

    std::ostream& affiche(std::ostream& sortie) const ;

    void dessine_sur(SupportADessin& support) override ;
    
    double get_largeur() const{ return largeur;}
    double get_profondeur() const{ return profondeur;}
    double get_hauteur() const{ return hauteur;}

    Tab_Cases get_kase() const{ return kase;}

    void ajoute_index(size_t i, unsigned int a, unsigned int b, unsigned int c);

    void efface_particule(size_t i, unsigned int a, unsigned int b, unsigned int c);

};

std::ostream& operator<<(std::ostream& sortie, const Enceinte& E);
