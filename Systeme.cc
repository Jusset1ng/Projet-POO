#include <iostream>
#include <vector>
#include <memory>
#include "Systeme.h"
#include "particule.h"
using namespace std;


std::ostream& Enceinte::affiche(std::ostream& sortie) const {
        sortie << "hauteur : " << hauteur << ", largeur : " << largeur << ", profondeur : " << profondeur << std::endl;
        return sortie;
    }
    
     void Systeme:: ajouter_particule(Particule* p) {
        particules.push_back(std::unique_ptr<Particule>(p));
    }

void Systeme::supprimer_particules() {
        particules.clear();
    }
    
    
    std::ostream& Systeme:: affiche(std::ostream& sortie) const {
        sortie << "Dimension de l'enceinte : ";
        E.affiche(sortie);
        sortie << "Liste des particules :" << std::endl;
        for (size_t i(0);i<particules.size();++i) {
            particules[i]->affiche(sortie);
        }
        return sortie;
    }
