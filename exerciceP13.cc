#include <iostream>
#include "Systeme.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
using namespace std;

int main(){

double Epsilon(1.0);

Systeme S(20, 20, 20, Epsilon); // Enceinte de dim 20 de cote et de pas d'espace 1.
Textviewer T(cout);


S.initialise_rd_neon(10,4.002602);//nb, masse

S.ajouter_particule(new Neon(1 ,1, 1, 0, 0, 0,4.002602, true));

S.set_forcage(true);

S.dessine_sur(T);
unsigned int k(10);

std::cout << "Lancement de la simulation" << endl;
std::cout << "==========----------" << endl;
for(int i(1); i <= k ; ++i){
    S.evolue(0.1);
}
cout << "etc.";
return 0;
}