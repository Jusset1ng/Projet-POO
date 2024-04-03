#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Vecteur3D.h"
#include "Vecteur3D.cc"

class Particule{

    private:
    Vecteur3D pos;
    Vecteur3D v;
    double masse;
    public:
    
    Particule(double x, double y, double z, double vx, double vy, double vz, double masse)
    : pos(x, y, z), v(vx, vy, vz), masse(masse){}
    Particule(double masse)
    : pos(), v(), masse(masse){}
   


    Particule(const Particule& autre): pos(autre.pos), v(autre.v), masse(autre.masse) {}

    ~Particule(){};

    std::ostream& affiche(std::ostream& sortie) const;

    friend std::ostream& operator<<(std::ostream& sortie, const Particule& p);

};

std::ostream& operator<<(std::ostream& sortie, const Particule& p);




	
