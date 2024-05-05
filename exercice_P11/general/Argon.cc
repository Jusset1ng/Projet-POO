#include <iostream>
#include "Argon.h"
#include "SupportADessin.h"

 std::ostream& Argon::affiche(std::ostream& sortie) const {
		sortie << "particule Argon : ";
        Particule::affiche(sortie);
        return sortie;
    }
    
    void Argon::dessine_sur(SupportADessin& support) {support.dessine(*this);}
    
    std::ostream& operator<<(std::ostream& sortie, const Argon& p){
    return p.affiche(sortie);
}


