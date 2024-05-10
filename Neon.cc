#include <iostream>
#include "Neon.h"

 std::ostream& Neon::affiche(std::ostream& sortie) const {
		sortie << "particule Neon : ";
        Particule::affiche(sortie);
        return sortie;
    }
    
void Neon::dessine_sur(SupportADessin& support) {support.dessine(*this);}

   void Neon::initialise_rd(unsigned int nb_part, double masse, Systeme& s){
        double constante = pow(10,3) * R / M;
            for(size_t i(0); i < nb_part; ++i){
                double x = s.position_rd(0);
                double y = s.position_rd(1);
                double z = s.position_rd(2);
                double vx = s.vitesse_rd(constante);
                double vy = s.vitesse_rd(constante);
                double vz = s.vitesse_rd(constante);
                s.ajouter_particule(new Neon(x, y, z, vx, vy, vz, masse));
                }
        }

std::ostream& operator<<(std::ostream& sortie, const Neon& p){
    return p.affiche(sortie);
}
