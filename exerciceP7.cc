#include <iostream>
#include "Systeme.h"
#include "Neon.h"
#include "Argon.h"
using namespace std;
	

int main() {
Systeme S(1);
Textviewer T(cout);

S.ajouter_particule(new Helium (1 ,1, 1, 0, 0, 0,4.002602));
S.ajouter_particule(new Neon(1, 18.5, 1 ,0 ,0.2, 0 ,20.1797));
S.ajouter_particule(new Argon (1, 1, 3.1 ,0, 0, -0.5,39.948));

S.dessine_sur(T);

    return 0;
}
