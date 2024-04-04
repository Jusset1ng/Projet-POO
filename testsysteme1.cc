#include <iostream>
#include <vector>
#include <memory>
#include "Systeme.h"
#include "Systeme.cc"

using namespace std;

int main(){
	
Systeme S1;
Particule P(1,2,3,4,5,6,7);
Particule* ptr(&P);

S1.ajouter_particule(ptr);	
	
cout<<S1<<endl;
	return 0;}
