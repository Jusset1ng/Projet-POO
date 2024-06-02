#include <iostream>
#include <vector>
#include "text_viewer.h"
#include "contenu.h"
#include "bloc.h"
#include "Moucheron.h"
#include "Dervish.h"
using namespace std;

int main()
{ 
	
  TextViewer ecran(cout);
  Contenu C;
 C.ajoute(new Bloc);
 C.ajoute(new Moucheron);
 C.ajoute(new Dervish );
 
  cout << "Au départ :" << endl;
  C.dessine_sur(ecran);

  C.evolue(0.1);
  cout << "Après un pas de calcul :" << endl;
  C.dessine_sur(ecran);

  C.evolue(0.1);
  cout << "Après deux pas de calcul :" << endl;
  C.dessine_sur(ecran);

  return 0;
}
