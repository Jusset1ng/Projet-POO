#include <iostream>
#include <vector>
#include <memory>
#include "Systeme.h"

using namespace std;

    
     void Systeme:: ajouter_particule(Particule* p) {
        particules.push_back(std::unique_ptr<Particule>(p));
    }

void Systeme::supprimer_particules() {
        particules.clear();
    }
  
   void Systeme::dessine_sur(SupportADessin& support) {
		support.dessine(*this);
	}
    
    std::ostream& Systeme:: affiche(std::ostream& sortie) const {
        sortie << "Dimension de l'enceinte : ";
        E.affiche(sortie);
        sortie << "Le systeme est compose des "<<particules.size()<<" particules suivantes : " << std::endl;
        for (size_t i(0);i<particules.size();++i) {
            particules[i]->affiche(sortie);
        }
        return sortie;
    }
    
    std::ostream& operator<<(std::ostream& sortie, const Systeme& S) {
    return S.affiche(sortie);}
