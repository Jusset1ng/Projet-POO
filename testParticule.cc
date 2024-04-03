#include <iostream>
#include "Particule.h"
#include "Particule.cc"

int main() {
    Particule p1(1, 1, 1, 0, 0, 0, 4.002602);
    Particule p2(1, 18.5, 1, 0, 0.2, 0, 20.1797);
    Particule p3(1, 1, 3.1, 0, 0, -0.5, 39.948);
    Particule p4 = p2; // Copie de la particule p2
    Particule p5(2.0625); //Particule avec position 0,0,0 et vitesse nulle

    std::cout << "particule 1 : " << p1 ;
    std::cout << "particule 2 : " << p2 ;
    std::cout << "particule 3 : " << p3 ;
    std::cout << "particule 4 : " << p4 ;

    return 0;
}
