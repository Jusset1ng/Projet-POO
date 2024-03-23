#include <iostream>
#include "Particule.h"


//--------METHODES--------

std::ostream& Particule::affiche(std::ostream& sortie) const{
    sortie << "pos : ";
    pos.affiche(sortie);
    sortie << " ; v : ";
    v.affiche(sortie);
    sortie << " ; m : " << masse << std::endl;
    return sortie;
}

//--------OPERATOR--------

std::ostream& operator<<(std::ostream& sortie, const Particule& p){
    return p.affiche(sortie);
}