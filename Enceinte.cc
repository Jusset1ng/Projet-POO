#include <iostream>
#include "Enceinte.h"

std::ostream& Enceinte::affiche(std::ostream& sortie) const {
        sortie << "hauteur : " << hauteur << ", largeur : " << largeur << ", profondeur : " << profondeur << std::endl;
        return sortie;
    }

void Enceinte::dessine_sur(SupportADessin& support)  {support.dessine(*this);}


std::ostream& operator<<(std::ostream& sortie, const Enceinte& E) {
    return E.affiche(sortie);};
