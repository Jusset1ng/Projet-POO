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

    for(int i(0); i <= 5 ; ++i){
        S.evolue(0.1);
    }
    cout << "etc.";
    return 0;
}
