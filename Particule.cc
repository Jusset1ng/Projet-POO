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
    pos += v*dt;
}

void Particule::choc_paroie(double largeur, double hauteur, double profondeur){
    choc_paroie_n(0, largeur);
    choc_paroie_n(1, hauteur);
    choc_paroie_n(2, profondeur);
}
void Particule::choc_paroie_n(int n, double taille){
    if(pos.get_coord(n) < 0 or pos.get_coord(n) > taille){//pour eviter la copie et n'écrire qu'une fois l'inversion de la direction de la vitesse
        if(pos.get_coord(n) < 0){
            pos.set_coord(n, -pos.get_coord(n)); //le symetrique par rapport a l'axe d'origine de la paroi
        }
        else if(pos.get_coord(n) > taille){
            pos.set_coord(n, 2*taille - pos.get_coord(n));  
        }
        v.set_coord(n, -v.get_coord(n));
    }
}

bool Particule::test_position(const std::unique_ptr<Particule>& autre, double Epsilon) const{
    return pos.compare(autre->pos, Epsilon);
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
    std::cout << " part. " << i+1 << " : : " << *this << std::endl;
    std::cout << "autre   : : " << autre << std::endl;
    return std::cout;
}



//--------OPERATOR--------

std::ostream& operator<<(std::ostream& sortie, const Particule& p){
    return p.affiche(sortie);
}

