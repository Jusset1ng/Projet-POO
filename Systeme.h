#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include "Enceinte.h"
#include "Particule.h"
#include "GenerateurAleatoire.h"
#include "Neon.h"
#include "Helium.h"
#include "Argon.h"


class Systeme :public Dessinable{
	private:
    std::vector<std::unique_ptr<Particule> > particules;
    Enceinte E;
    GenerateurAleatoire tirage; //peut etre initialisé avec la meme graine pour debugger
    double Epsilon;
    double temperature = 290;
    static constexpr double R = 8.314472;

    bool forcer = false; //Si true: Premier choc avec zenith à pi/2 et azimut a pi/3

    public:
    Systeme() :  E (){}
    
    Systeme(double Eps) : Epsilon(Eps) {}

    Systeme(double a, double b, double c, double Eps) :  E(a, b, c), Epsilon(Eps) {}

    void set_tirage(double graine){tirage = graine;}

    void set_forcage(bool b){forcer = b;}

    virtual ~Systeme() {}

    void  ajouter_particule(Particule* p);
    
    void supprimer_particules();
    
    std::ostream& affiche(std::ostream& sortie) const;

    void dessine_sur(SupportADessin& support) override;

    void evolue(double dt);

    void set_temperature(double t){if(t>0) temperature = t;}
    
    double position_rd(unsigned int coord);

    double vitesse_rd(double constante);

    void initialise_rd_neon(unsigned int nb_part, double masse);

    void initialise_rd_helium(unsigned int nb_part, double masse);

    void initialise_rd_argon(unsigned int nb_part, double masse);

};

std::ostream& operator<<(std::ostream& sortie, const Systeme& S) ;
    
 


