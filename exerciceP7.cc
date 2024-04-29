#include <iostream>
#include "Systeme.h"
#include "Neon.h"
#include "Argon.h"
using namespace std;



	

int main() {
Systeme S;
Textviewer T(cout);
 
 Neon N1(1, 18.5, 1 ,0 ,0.2, 0 ,20.1797);
 Argon A1(1, 1, 3.1 ,0, 0, -0.5,39.948);
 Neon* ptr1(&N1);
 Argon* ptr2(&A1);

S.ajouter_particule(ptr1);
S.ajouter_particule(ptr2);

S.dessine_sur(T);

    return 0;
}
