#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Vecteur3D.h"
#include "Dessinable.h"


class Particule : public Dessinable {

    protected:
    Vecteur3D pos;
    Vecteur3D v;
    double masse;
    public:
    
    Particule(double x, double y, double z, double vx, double vy, double vz, double masse)
    : pos(x, y, z), v(vx, vy, vz), masse(masse){}
    Particule(double masse)
    : pos(), v(), masse(masse){}
    

    Particule(const Particule& autre): pos(autre.pos), v(autre.v), masse(autre.masse) {}

    virtual ~Particule(){};

    virtual std::ostream& affiche(std::ostream& sortie) const;

    void dessine_sur(SupportADessin& support) override;

    void evolue(double dt);

    void choc_paroie(double largeur, double hauteur, double profondeur);

    void choc_paroie_n(int n, double taille);

    bool test_position(const std::unique_ptr<Particule>& autre, double Epsilon) const;
    
    Vecteur3D calcule_vg(const std::unique_ptr<Particule>& autre) const;

    double calcule_L(const Vecteur3D& vg) const;

    void choc_particule(std::unique_ptr<Particule>& autre, const Vecteur3D& vg, const Vecteur3D& v0);

    std::ostream& afficher_choc(size_t i, const std::unique_ptr<Particule>& autre) const;
};




std::ostream& operator<<(std::ostream& sortie, const Particule& p);




	
