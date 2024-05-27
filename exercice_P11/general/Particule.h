#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Vecteur3D.h"
#include "Dessinable.h"
#include "Enceinte.h"
#include <deque>


class Particule : public Dessinable {

    protected:
    Vecteur3D pos;
    Vecteur3D v;
    double masse;
    bool trace;
    bool couleur;
    double comptechocparois;
    int coordchocparoi;
    double vitessenormalechocparoi;
        std::deque<Vecteur3D> memoire;

          static constexpr double R = 8.314472;
          static constexpr double A_to_cm = 1;


    public:
    
        Particule(double x, double y, double z, double vx, double vy, double vz, double masse, bool trace = false,bool couleur=false)
            : pos(x, y, z), v(vx, vy, vz), masse(masse), trace(trace),couleur(couleur) {}
            Particule(double masse, bool trace = false,bool couleur=false)
            : pos(), v(), masse(masse), trace(trace),couleur(couleur) {}
    

    Particule(const Particule& autre): pos(autre.pos), v(autre.v), masse(autre.masse) {}

    virtual ~Particule(){};

    virtual std::ostream& affiche(std::ostream& sortie) const;

     std::deque<Vecteur3D> get_memoire()const {return memoire;}

     bool get_trace()const{return trace;}

    void dessine_sur(SupportADessin& support) override;

    void evolue(double dt);

    void evolue(double dt, size_t i, Enceinte& E);

    void choc_paroi(size_t i, double largeur, double hauteur, double profondeur);

    void choc_paroi_n(size_t i, int n, double taille);

    bool test_position(const std::unique_ptr<Particule>& autre, double Epsilon) const;
    
    Vecteur3D calcule_vg(const std::unique_ptr<Particule>& autre) const;

    double calcule_L(const Vecteur3D& vg) const;

    void choc_particule(std::unique_ptr<Particule>& autre, const Vecteur3D& vg, const Vecteur3D& v0);

    std::ostream& afficher_choc(size_t i, const std::unique_ptr<Particule>& autre) const;
    
    double get_infos(int n) const;

    Vecteur3D get_vitesse() const{return v;}

    double get_comptechocparois() {return comptechocparois;}

    void reset_comptechocparois(){comptechocparois=0;}

    void updatevitessenormalechocparoi(){if(coordchocparoi==0){vitessenormalechocparoi=v.get_coord(0);}
                                        if(coordchocparoi==1){vitessenormalechocparoi=v.get_coord(1);}
                                       if(coordchocparoi==2){vitessenormalechocparoi=v.get_coord(2);}
                                        if(coordchocparoi==3){vitessenormalechocparoi=0;}}

    double get_vitessenormalechocparoi(){return vitessenormalechocparoi;}

    void reset_vitessenormalechocparoi(){vitessenormalechocparoi=0;}

    bool get_couleur() const {return couleur;}

    void change_couleur(){if(couleur==false){couleur=true;}
                         else{couleur=false;}}
};




std::ostream& operator<<(std::ostream& sortie, const Particule& p);




	
