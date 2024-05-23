#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include "Systeme.h"


//----------METHODES----------
double Systeme::calculer_Ecin()
{double Emoy(0);
    if (particules.empty()) {
            return Emoy;
        }

    for(size_t i(0);i<particules.size();++i)
{ double masse = particules[i]->get_infos(6);
        double vitesse = particules[i]->get_vitesse().norme();
        Emoy += 0.5 * masse * std::pow(vitesse, 2.0);}

Emoy=Emoy/particules.size();
return Emoy;
}
double Systeme::calculer_pression()
   {double pression(0);

    if (particules.empty()) {
            return pression;
        }
double masse(0);
double vitessenormale(0);

    for(size_t i(0);i<particules.size();++i)
{  masse += particules[i]->get_infos(6);
        vitessenormale += particules[i]->get_vitessenormalechocparoi();
        }
    vitessenormale=vitessenormale/particules.size();
    masse=masse/particules.size();
    pression +=comptechocparois*2  * masse * vitessenormale;
//pression=std::abs(pression);
return pression;
   }

void Systeme:: ajouter_particule(Particule* p) {
    particules.push_back(std::unique_ptr<Particule>(p));
   
}
 void Systeme::set_enceinte(Enceinte enc){
	 E=enc;
	 }
void Systeme ::set_epsilon(double n){
	Epsilon=n;}
void Systeme::supprimer_particules() {
        particules.clear();
        
    }

void Systeme::dessine_sur(SupportADessin& support) {
	
 for(std::size_t i(0);i<particules.size();++i)
      {
		  particules[i]->dessine_sur(support);
		   }
E.dessine_sur(support);
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


void Systeme::affiche_systeme() const{
        for(const auto& particule : particules){
        particule->affiche(std::cout) ;
    }
    std::cout << "==========----------" << std::endl;
}

void Systeme::evolue_choc(size_t p1, size_t p2){
std::cout << "La particule " << p1 << " entre en collision avec une autre particule." << std::endl;
    std::cout << " avant le choc :" << std::endl;
    particules[p1]->afficher_choc(p1, particules[p2]);

    Vecteur3D vg = particules[p1]->calcule_vg(particules[p2]);
    Vecteur3D v0;
    double L = particules[p1]->calcule_L(vg);
    if(forcer){
        v0 = Vecteur3D(0.5*L, std::sin((M_PI)/3)*L, 0);
        forcer = false;
    }
    else{

        double z = tirage.uniforme(-L, L);
        double phi;
        do{
            phi = tirage.uniforme(0, 2*M_PI);
        }while(phi == 2*M_PI);
        double r = sqrt(L*L - z*z);
        v0 = Vecteur3D(r*(std::cos(phi)), r*(std::sin(phi)), z);

    }
    particules[p1]->choc_particule(particules[p2], vg, v0);

        std::cout << " apres le choc :" << std::endl;
        particules[p1]->afficher_choc(p1, particules[p2]);
}
void Systeme::evolue(double dt){//deplacement choc, rebond...
                                //on regarde toutes les particules dans le meme ordre (deterministe) et choc parois puis choc particules:
    //deplacement infinitésimal du a la vitesse:
    comptechocparois=0;
    for(size_t p1(0); p1 < particules.size(); ++p1){
        particules[p1]->evolue(dt);
        particules[p1]->choc_paroi(p1, E.get_largeur(), E.get_profondeur(), E.get_hauteur());
        Ecin=calculer_Ecin();
        comptechocparois+=particules[p1]->get_comptechocparois();
        pression=calculer_pression();
                particules[p1]->reset_comptechocparois();

    }

    for(size_t p1(0); p1 < particules.size(); ++p1){//pour pouvoir afficher l'index i conformément au main attendu (voir affichage)
        std::vector<unsigned int> candidats;

        for(size_t j(0); j < particules.size() && j!=p1 ; ++j){//test de choc entre toutes les pairs de particules, pavage sphérique, epsilon par defaut dans l'operateur ==
            if(particules[p1]->test_position(particules[j], Epsilon)){ //il faut qu'elles aient la meme position mais pas que ce soit la meme particule
                candidats.push_back(j);
            }
        }
        if(!candidats.empty()){
            size_t p2;
            do{
            p2 = floor(tirage.uniforme(0, candidats.size()));//La conversion de double a int arrondie a l'inferieur donc on prend un indice de plus en l'excluant
            }while(p2 == candidats.size());

            evolue_choc(p1, p2);
        }
        candidats.clear();
    }
    affiche_systeme();
}

void Systeme::evolue2(double dt){
    for(size_t i(0); i < particules.size(); ++i){
        particules[i]->evolue(dt, i, E);
        particules[i]->choc_paroi(i, E.get_largeur(), E.get_profondeur(), E.get_hauteur());
    }

    for(auto surface : E.get_kase()){
        for(auto ligne : surface){
            for(auto kase : ligne){
                if( kase.size() > 1){
                unsigned int p1;
                unsigned int p2;
                    std::vector<size_t> candidats;
                    if(kase.size()==2){
                        p1 = kase[0];
                        p2 = kase[1];
                        candidats.push_back(p1);
                        candidats.push_back(p2);
                    }
                    else{
                        do{
                            p1 = floor(tirage.uniforme(0, kase.size()));
                            p2 = floor(tirage.uniforme(0, kase.size()));

                        }while(p1 == p2 or p1 == kase.size() or p2 == kase.size());//pour exclure la valeur egale a la taille du tableau et le fait que les deux indices soient les memes
                        candidats.push_back(p1);
                        candidats.push_back(p2);
                    }
                    evolue_choc(p1, p2);

                    }
                    }
                }
            }

    affiche_systeme();
}


    double Systeme::position_rd(unsigned int coord){
            switch(coord){
            case 0:
            return tirage.uniforme(0.0, E.get_largeur());//x
            break;
            case 1:
            return tirage.uniforme(0.0, E.get_profondeur());//y
            break;
            case 2:
            return tirage.uniforme(0.0, E.get_hauteur());//z
            break;
            default:
            std::cout << "Erreur d'indexation" << std::endl;
            return 0;
            }
        }


double Systeme::vitesse_rd(double constante){
    return tirage.gaussienne(0.0, sqrt(constante * temperature));
}

void Systeme::initialise_rd_neon(unsigned int nb_part, double masse){
        Neon n(0);
        n.initialise_rd(nb_part, masse, *this);
    }

void Systeme::initialise_rd_helium(unsigned int nb_part, double masse){
        Helium h(0);
        h.initialise_rd(nb_part, masse, *this);
    }

void Systeme::initialise_rd_argon(unsigned int nb_part, double masse){
        Argon a(0);
        a.initialise_rd(nb_part, masse, *this);
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
