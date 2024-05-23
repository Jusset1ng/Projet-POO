#include <iostream>
#include "Particule.h"


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
    if(trace){
        memoire.push_front(pos);
        if(memoire.size() == 20)
            memoire.pop_back();
    }
    pos += v*dt;
    
}

void Particule::evolue(double dt, size_t i, Enceinte& E){//surcharge de evolue: methode avec decoupage de l'enceinte (P14)

    size_t X = floor(this->pos.get_coord(0) * A_to_cm);
    size_t Y = floor(this->pos.get_coord(1) * A_to_cm);
    size_t Z = floor(this->pos.get_coord(2) * A_to_cm);

    E.efface_particule(i, X, Y, Z);//on supprime l'index de la particule dans la case courante

    if(trace){
        memoire.push_front(pos);
        if(memoire.size() == 20)
            memoire.pop_back();
    }

    pos += v*dt*10;

    this->choc_paroi(i, E.get_largeur(), E.get_profondeur(), E.get_hauteur()); //je reteste les chocs contre les parois pour ne pas ajouter de mauvais indices dans le tableau.

    X = floor(this->pos.get_coord(0) * A_to_cm);
    Y = floor(this->pos.get_coord(1) * A_to_cm);
    Z = floor(this->pos.get_coord(2) * A_to_cm);
    std::cout << "J'ajoute la nouvelle position : " << X << " " << Y << " " << Z << std::endl;
    E.ajoute_index(i, X, Y, Z); //on ajoute l'index de la particule dans sa nouvelle case
    
}
void Particule::choc_paroi(size_t i, double largeur, double hauteur, double profondeur){
    while(pos.get_coord(0) < 0 or pos.get_coord(0) > largeur or pos.get_coord(1) < 0 or pos.get_coord(1) > hauteur 
            or pos.get_coord(2) < 0 or pos.get_coord(2) > profondeur){


    choc_paroi_n(i, 0, largeur);
    choc_paroi_n(i, 1, hauteur);
    choc_paroi_n(i, 2, profondeur);
    }
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



//--------OPERATOR--------

std::ostream& operator<<(std::ostream& sortie, const Particule& p){
    return p.affiche(sortie);
}

