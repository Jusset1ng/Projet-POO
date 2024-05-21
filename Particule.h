#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <deque>
#include "Vecteur3D.h"
#include "Dessinable.h"


class Particule : public Dessinable {

    protected:
    Vecteur3D pos;
    Vecteur3D v;
    double masse;
    bool trace;
    std::deque<Vecteur3D> memoire;//ou faire une queue pour avoir une ligne qui s'efface au fur et a mesure

    static constexpr double R = 8.314472;

    public:
    Particule(double x, double y, double z, double vx, double vy, double vz, double masse, bool trace = false)
    : pos(x, y, z), v(vx, vy, vz), masse(masse), trace(trace) {}
    Particule(double masse, bool trace = false)
    : pos(), v(), masse(masse), trace(trace) {}

    virtual ~Particule(){};

    virtual std::ostream& affiche(std::ostream& sortie) const;

    void dessine_sur(SupportADessin& support) override;

    void evolue(double dt);

    void choc_paroi(size_t i, double largeur, double hauteur, double profondeur);

    void choc_paroi_n(size_t i, int n, double taille);

    bool test_position(const std::unique_ptr<Particule>& autre, double Epsilon) const;
    
    Vecteur3D calcule_vg(const std::unique_ptr<Particule>& autre) const;

    double calcule_L(const Vecteur3D& vg) const;

    void choc_particule(std::unique_ptr<Particule>& autre, const Vecteur3D& vg, const Vecteur3D& v0);

    std::ostream& afficher_choc(size_t i, const std::unique_ptr<Particule>& autre) const;
    
};




std::ostream& operator<<(std::ostream& sortie, const Particule& p);




	
