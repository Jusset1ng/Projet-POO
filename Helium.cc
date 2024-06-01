#include "Helium.h"

 std::ostream& Helium::affiche(std::ostream& sortie) const {
		sortie << "particule Helium : ";
        Particule::affiche(sortie);
        return sortie;
    }
    
    void Helium::dessine_sur(SupportADessin& support) {support.dessine(*this);}

   void Helium::initialise_rd(unsigned int nb_part, double masse, Systeme& s){
        double constante = pow(10,3) * R / M;
            for(size_t i(0); i < nb_part; ++i){
                double x = s.position_rd(0);
                double y = s.position_rd(1);
                double z = s.position_rd(2);
                double vx = s.vitesse_rd(constante);
                double vy = s.vitesse_rd(constante);
                double vz = s.vitesse_rd(constante);
                s.ajouter_particule(new Helium(x, y, z, vx, vy, vz, masse));
                }
        }
std::ostream& operator<<(std::ostream& sortie, const Helium& p){
    return p.affiche(sortie);
}
