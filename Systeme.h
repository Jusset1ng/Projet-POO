#pragma once
#include <iostream>
#include <vector>
#include <memory>//pour les unique ptr
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

    bool forcer = false; //Si true: Premier choc avec zenith à pi/2 et azimut a pi/3

    public:
    
    Systeme(double Eps = 1) : Epsilon(Eps) {}

    Systeme(double a, double b, double c, double Eps = 	1) :  E(a, b, c), Epsilon(Eps) {}

    void set_tirage(double graine){tirage = graine;} // initialise une graine

    void set_forcage(bool b){forcer = b;} //determine si le premier choc est aléatoire ou forcé

    virtual ~Systeme() {}

    void  ajouter_particule(Particule* p);
    
    void supprimer_particules();
    
    std::ostream& affiche(std::ostream& sortie) const;

    void dessine_sur(SupportADessin& support) override;

    void evolue_choc(size_t p1, size_t p2); //idem

    void evolue(double dt);//pavage cubique et test d'égalité

    void evolue2(double dt);//découpage du systeme en case et test si sont dans la meme case
    
    void affiche_systeme() const;
    
    void set_temperature(double t){if(t>0) temperature = t;}
    
    double position_rd(unsigned int coord);//position selon un tirage uniforme

    double vitesse_rd(double constante);//vitesse selon un tirage qui suit une loi gaussienne

    void initialise_rd_neon(unsigned int nb_part, double masse);

    void initialise_rd_helium(unsigned int nb_part, double masse);

    void initialise_rd_argon(unsigned int nb_part, double masse);

};

std::ostream& operator<<(std::ostream& sortie, const Systeme& S) ;
    



