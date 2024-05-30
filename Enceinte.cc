#include <iostream>
#include "Enceinte.h"



void Enceinte::redimensionne(unsigned int a, unsigned int b, unsigned int c) {// Redimensionner les vecteurs en fonction de la taille de l'enceinte
        a/= A_to_cm;
        b/= A_to_cm;
        c/= A_to_cm;
        kase.resize(a);  
        for (unsigned int i = 0; i < a; ++i) {
            kase[i].resize(b);  
            for (unsigned int j = 0; j < b; ++j) {
                kase[i][j].resize(c);  
            }
        }
    }

std::ostream& Enceinte::affiche(std::ostream& sortie) const {
        sortie << "hauteur : " << hauteur << ", largeur : " << largeur << ", profondeur : " << profondeur << std::endl;
        return sortie;
    }

void Enceinte::dessine_sur(SupportADessin& support)  {support.dessine(*this);}

void Enceinte::ajoute_index(size_t i, unsigned int a, unsigned int b, unsigned int c){
    kase[a][b][c].push_back(i);
}

void Enceinte::efface_particule(size_t i, unsigned int a, unsigned int b, unsigned int c){

    auto index = std::find(kase[a][b][c].begin(), kase[a][b][c].end(), i);
    if(index != kase[a][b][c].end()){
        if (a < kase.size() && b < kase[a].size() && c < kase[a][b].size()) {
            kase[a][b][c].erase(index);
        } else {
            std::cout << "Erreur : les indices sont hors limites !" << std::endl;
        }
    }
}



std::ostream& operator<<(std::ostream& sortie, const Enceinte& E) {
    return E.affiche(sortie);};
