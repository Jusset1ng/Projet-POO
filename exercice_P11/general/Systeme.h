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
    
    std::vector<std::unique_ptr<Particule>> particules;

    Enceinte E;

double comptechocsparois;

double comptevitessesnormalesxmasses;

double pression;

double Ecin;

    GenerateurAleatoire tirage; //peut etre initialisé avec la meme graine pour debugger

    double Epsilon;

    bool forcer = false; //Premier choc avec zenith à pi/2 et azimut a pi/3

    double temperature = 290;

        static constexpr double R = 8.314472;

        const double pas=0.001;

    public:


        double get_pas (){return pas;}
    
    Systeme() :  E () ,comptechocsparois(0){}
    
    Systeme(double Eps) : Epsilon(Eps) {}

    Systeme(double a, double b, double c, double Eps) :  E(a, b, c), Epsilon(Eps) {}

    void set_forcage(bool b){forcer = b;}

    virtual ~Systeme() {}

    double calculer_Ecin();

    double calculer_pression();

    void  ajouter_particule(Particule* p);
    
    void set_enceinte(Enceinte enc);
    
    void set_epsilon(double n);
    
    void supprimer_particules();
    
    std::ostream& affiche(std::ostream& sortie) const;

    void dessine_sur(SupportADessin& support) override;

    void evolue(double dt);

    void evolue2(double dt);

    void evolue_choc(size_t p1, size_t p2);

    void affiche_systeme() const;

    double get_comptechocparois(){return comptechocsparois;}

    void set_temperature(double t){if(t>0) temperature = t;}

       double position_rd(unsigned int coord);

       double vitesse_rd(double constante);

       void initialise_rd_neon(unsigned int nb_part, double masse);

       void initialise_rd_helium(unsigned int nb_part, double masse);

       void initialise_rd_argon(unsigned int nb_part, double masse);

       int get_nbparticules(){return particules.size();}

       double get_Ecin(){return Ecin;}

       double get_pression(){return pression;}

       void change_couleur();
};

std::ostream& operator<<(std::ostream& sortie, const Systeme& S) ;
    
 


