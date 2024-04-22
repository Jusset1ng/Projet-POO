#include <iostream>
#include <vector>
#include <memory>
#include "Systeme.h"

using namespace std;

//----------METHODES----------
    
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

void Systeme::evolue(double dt){//deplacement choc, rebond...
                                //on regarde toutes les particules dans le meme ordre (deterministe) et choc parois puis choc particules:
    //deplacement infinitésimal du a la vitesse:
    for(auto& particule : particules){
        particule->evolue(dt);
        particule->choc_paroie(E.get_largeur(), E.get_profondeur(), E.get_hauteur());
    }
    
    for(size_t i(0); i < particules.size(); ++i){//pour pouvoir afficher l'index i conformément au main attendu (voir affichage)
        vector<unsigned int> candidats;

        for(size_t j(0); j < particules.size(); ++j){//test de choc entre toutes les pairs de particules, pavage sphérique, epsilon par defaut dans l'operateur ==
            if((particules[i]->test_position(particules[j], Epsilon)) and (&particules[i] != &particules[j])){ //il faut qu'elles aient la meme position mais pas que ce soit la meme particule
                candidats.push_back(j);
            }
        }
        if(!candidats.empty()){
            unsigned int index_particule = tirage.uniforme(0, candidats.size()-1);

            std::cout << "La particule " << i+1 << " entre en collision avec une autre particule." << endl;
            std::cout << "   avant le choc :" << endl;
            particules[i]->afficher_choc(i, particules[index_particule]);

            Vecteur3D vg = particules[i]->calcule_vg(particules[index_particule]);
            double L = particules[i]->calcule_L(vg);
            double z = tirage.uniforme(-L, L);
            double phi;
            do{
                phi = tirage.uniforme(0, 2*M_PI);
            }while(phi == 2*M_PI);
            double r = sqrt(L*L - z*z);
            Vecteur3D v0(r*(std::cos(phi)), r*(std::sin(phi)), z);
            particules[i]->choc_particule(particules[index_particule], vg, v0);

            std::cout << "apres le choc :" << endl;
            particules[i]->afficher_choc(i, particules[index_particule]);
        }
    }
    for(const auto& particule : particules){
        particule->affiche(std::cout) ; 
        std::cout << "==========----------" << endl;
    }
}

//----------FONCTION----------

Vecteur3D tirage_v0(double L, GenerateurAleatoire tirage){

    double z = tirage.uniforme(-L, L);
    double phi;
    do{
        phi = tirage.uniforme(0, 2*M_PI);
    }while(phi == 2*M_PI);
    double r = sqrt(L*L-z*z);
    return Vecteur3D(r*std::cos(phi), r*std::sin(phi), z);
}

//----------OPERATOR------------
    
    std::ostream& operator<<(std::ostream& sortie, const Systeme& S) {
    return S.affiche(sortie);}
