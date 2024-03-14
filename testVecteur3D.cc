

#include <iostream>
#include "Vecteur3D.h"
using namespace std;


int main()
{
Vecteur3D vect1;
Vecteur3D vect2(1.1,2.2,3.3);
Vecteur3D vect3(vect2);

if(vect2==vect3){
cout<<vect1<<endl;}
return 0;
}
