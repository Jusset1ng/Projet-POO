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
 

S.initialise_rd_neon(5,10);//nb, masse
//S.initialise_rd_helium(10,10);
//S.initialise_rd_argon(10,10);

S.set_forcage(true);

S.dessine_sur(T);
unsigned int k(3);

std::cout << "Lancement de la simulation" << endl;
std::cout << "==========----------" << endl;
for(int i(1); i <= k ; ++i){
    S.evolue(0.1);
}
cout << "etc.";
return 0;
}