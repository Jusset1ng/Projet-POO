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
 
Neon n(0);
Argon a(0);
Helium h(0);

n.initialise_rd(10,10,S);//nb, masse, systeme
a.initialise_rd(10,10,S);
h.initialise_rd(10,10,S);

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