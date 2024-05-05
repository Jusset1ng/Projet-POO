#include <iostream>
#include "Helium.h"
#include "SupportADessin.h"

 std::ostream& Helium::affiche(std::ostream& sortie) const {
		sortie << "particule Helium : ";
        Particule::affiche(sortie);
        return sortie;
    }
    
    void Helium::dessine_sur(SupportADessin& support) {support.dessine(*this);}

std::ostream& operator<<(std::ostream& sortie, const Helium& p){
    return p.affiche(sortie);
}
