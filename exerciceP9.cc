#include <iostream>
#include "Systeme.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
using namespace std;


	

int main(){
	
Systeme S(20, 20, 20, 1); // Enceinte de dim 20 de cote et de pas d'espace 1.
Textviewer T(cout);
 
Neon N1(1, 18.5, 1 ,0 ,0.2, 0 ,20.1797);
Argon A1(1, 1, 3.1 ,0, 0, -0.5,39.948);
Helium H1(1 ,1, 1,0, 0, 0,4.002602);
 
Helium* ptr0(&H1);
Neon* ptr1(&N1);
Argon* ptr2(&A1);

S.ajouter_particule(ptr0);
S.ajouter_particule(ptr1);
S.ajouter_particule(ptr2);

S.dessine_sur(T);
unsigned int k(0);
cout << "Nombre d'evolutions :"; cin >> k;
std::cout << "Lancement de la simulation" << endl;
std::cout << "==========----------" << endl;
for(int i(0); i <= k ; ++i){
    S.evolue(0.1);
}
cout << "etc.";
return 0;
}
