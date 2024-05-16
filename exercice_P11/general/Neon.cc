#include <iostream>
#include "Neon.h"
#include "SupportADessin.h"

 std::ostream& Neon::affiche(std::ostream& sortie) const {
		sortie << "particule Neon : ";
        Particule::affiche(sortie);
        return sortie;
    }
    
    void Neon::dessine_sur(SupportADessin& support) {support.dessine(*this);}

std::ostream& operator<<(std::ostream& sortie, const Neon& p){
    return p.affiche(sortie);
}
