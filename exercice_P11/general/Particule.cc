#include <iostream>
#include "Particule.h"
#include "Vecteur3D.h"
#include "SupportADessin.h"


//--------METHODES--------

std::ostream& Particule::affiche(std::ostream& sortie) const{
    sortie << "pos : ";
    pos.affiche(sortie);
    sortie << " ; v : ";
    v.affiche(sortie);
    sortie << " ; m : " << masse << std::endl;
    return sortie;
}

void Particule::dessine_sur(SupportADessin& support) {
    support.dessine(*this);
}

void Particule::evolue(double dt){
    //on deplace la particule de v dt:
    pos += v*dt;
}

void Particule::choc_paroi(size_t i, double largeur, double hauteur, double profondeur){
    choc_paroi_n(i, 0, largeur);
    choc_paroi_n(i, 1, hauteur);
    choc_paroi_n(i, 2, profondeur);
}
void Particule::choc_paroi_n(size_t i, int n, double taille){
    if(pos.get_coord(n) < 0 or pos.get_coord(n) > taille){//pour eviter la copie et n'écrire qu'une fois l'inversion de la direction de la vitesse
        std::cout << "La particule " << i+1 << " rebondit sur la face ";
        if(pos.get_coord(n) < 0){
            switch(n){
            case 0: std::cout << '3' << std::endl;
                break;
            case 1: std::cout << '2' << std::endl;
                break;
            case 2: std::cout << '6' << std::endl;
                break;
            default: std::cout << "face inconnue" << std::endl;
            }
            pos.oppose_n(n); //le symetrique par rapport a l'axe d'origine de la paroi
        }
        else if(pos.get_coord(n) > taille){
            switch(n){
            case 0: std::cout << '4' << std::endl;
                break;
            case 1: std::cout << '1' << std::endl;
                break;
            case 2: std::cout << '5' << std::endl;
                break;
            default: std::cout << "face inconnue" << std::endl;
            }
            pos.set_coord(n, 2*taille - pos.get_coord(n));
        }
        v.oppose_n(n);
    }
}

bool Particule::test_position(const std::unique_ptr<Particule>& autre, double Epsilon) const{
    return pos.compare2(autre->pos, Epsilon);
}

Vecteur3D Particule::calcule_vg(const std::unique_ptr<Particule>& autre) const{
    return masse/(masse + autre->masse)*v + (autre->masse)/(masse + autre->masse)*autre->v;
}

double Particule::calcule_L(const Vecteur3D& vg) const{
    return (v - vg).norme();
}


void Particule::choc_particule(std::unique_ptr<Particule>& autre, const Vecteur3D& vg, const Vecteur3D& v0){
    v = vg + v0;
    autre->v = vg - masse/autre->masse * v0;
}


std::ostream& Particule::afficher_choc(size_t i, const std::unique_ptr<Particule>& autre) const{
    std::cout << "   part. " << i+1 << " : : pos : " << pos << " ; v : " << v << std::endl;
    std::cout << "   autre   : : pos : " << autre->pos << " ; v : " << autre->v << std::endl;
    return std::cout;
}

double Particule::get_infos(int n)const{
    if (n==0) return pos.get_coord(0);
    if (n==1) return pos.get_coord(1);
    if (n==2) return pos.get_coord(2);
    return 0;}


//--------OPERATOR--------

std::ostream& operator<<(std::ostream& sortie, const Particule& p){
    return p.affiche(sortie);
}

