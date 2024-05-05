#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include "Systeme.h"

const double M_PI = 3.14159265358979323846;
//----------METHODES----------
    
void Systeme:: ajouter_particule(Particule* p) {
    particules.push_back(std::unique_ptr<Particule>(p));
    Collection.push_back(p);
}
 void Systeme::set_enceinte(Enceinte* enc){
	 E=*enc;
	 Collection.push_back(enc);
	 }
void Systeme::supprimer_particules() {
        particules.clear();
        
    }
  
void Systeme::dessine_sur(SupportADessin& support) {

 for(std::size_t i(0);i<Collection.size();++i)
      {Collection[i]->dessine_sur(support); }

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
    for(size_t i(0); i < particules.size(); ++i){
        particules[i]->evolue(dt);
        particules[i]->choc_paroi(i, E.get_largeur(), E.get_profondeur(), E.get_hauteur());
    }
    
    for(size_t i(0); i < particules.size(); ++i){//pour pouvoir afficher l'index i conformément au main attendu (voir affichage)
        std::vector<unsigned int> candidats;

        for(size_t j(0); j < particules.size() && j!=i ; ++j){//test de choc entre toutes les pairs de particules, pavage sphérique, epsilon par defaut dans l'operateur ==
            if(particules[i]->test_position(particules[j], Epsilon)){ //il faut qu'elles aient la meme position mais pas que ce soit la meme particule
                candidats.push_back(j);
            }
        }
        if(!candidats.empty()){
            unsigned int index_particule;
            do{
            index_particule = tirage.uniforme(0, candidats.size());//La conversion de double a int arrondie a l'inferieur donc on prend un indice de plus en l'excluant
            }while(index_particule == candidats.size());

            std::cout << "La particule " << i+1 << " entre en collision avec une autre particule." << std::endl;
            std::cout << " avant le choc :" << std::endl;
            particules[i]->afficher_choc(i, particules[index_particule]);

            Vecteur3D vg = particules[i]->calcule_vg(particules[index_particule]);
            Vecteur3D v0;
            double L = particules[i]->calcule_L(vg);
            if(forcer){
                v0 = Vecteur3D(0.5*L, 0.8663*L, 0);
                forcer = false;
            }
            else{
                
                double z = tirage.uniforme(-L, L);
                double phi;
                do{
                    phi = tirage.uniforme(0, 2*(M_PI));
                }while(phi == 2*(M_PI));
                double r = sqrt(L*L - z*z);
                v0 = Vecteur3D(r*(std::cos(phi)), r*(std::sin(phi)), z);
                
            }
            particules[i]->choc_particule(particules[index_particule], vg, v0);

                std::cout << " apres le choc :" << std::endl;
                particules[i]->afficher_choc(i, particules[index_particule]);

        }
        candidats.clear();
    }
    for(const auto& particule : particules){
        particule->affiche(std::cout) ; 
    }
    std::cout << "==========----------" << std::endl;
}

//----------FONCTION----------

Vecteur3D tirage_v0(double L, GenerateurAleatoire tirage){

    double z = tirage.uniforme(-L, L);
    double phi;
    do{
        phi = tirage.uniforme(0, 2*(M_PI));
    }while(phi == 2*(M_PI));
    double r = sqrt(L*L-z*z);
    return Vecteur3D(r*std::cos(phi), r*std::sin(phi), z);
}

//----------OPERATOR------------
    
    std::ostream& operator<<(std::ostream& sortie, const Systeme& S) {
    return S.affiche(sortie);}
