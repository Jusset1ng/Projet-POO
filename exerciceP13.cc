#include <iostream>
#include "Systeme.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
using namespace std;

int main(){

double Epsilon(1.0);

Systeme S(20, 20, 20, Epsilon); // Enceinte de dim 20 de cote et de pas d'espace 1 découpé en cases
Textviewer T(cout);


S.ajouter_particule(new Helium (1 ,1, 1, 0, 0, 0,4.002602));
S.ajouter_particule(new Neon(1, 18.5, 1 ,0 ,0.2, 0 ,20.1797, true));
S.ajouter_particule(new Argon (1, 1, 3.1 ,0, 0, -0.5,39.948));

S.set_forcage(true);

S.dessine_sur(T);

unsigned int k(10);

std::cout << "Lancement de la simulation" << endl;
std::cout << "==========----------" << endl;
for(unsigned int i(1); i <= k ; ++i){
    S.evolue2(1);
}

cout << "etc.";
return 0;
}
