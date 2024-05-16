#include <iostream>
#include <vector>
#include "text_viewer.h"
#include "Systeme.h"
#include "Enceinte.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
using namespace std;

int main()
{

    Systeme S(20.0, 20.0, 20.0, 1.0); // Enceinte de dim 20 de cote et de pas d'espace 1.
    TextViewer T(cout);


   S.ajouter_particule(new Helium(1 ,1, 1,0, 0, 0,4.002602));
    S.ajouter_particule(new Neon(1, 18.5, 1 ,0 ,0.2, 0 ,20.1797));
    S.ajouter_particule(new Argon(1, 1, 3.1 ,0, 0, -0.5,39.948));
S.set_forcage(true);

    S.dessine_sur(T);

    for(int i(0); i <= 10 ; ++i){
        S.evolue(1);
    }
    cout << "etc.";
    return 0;
}
