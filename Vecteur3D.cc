#include <iostream>
#include "Vecteur3D.h"
using namespace std;

    void Vecteur3D::set_coord(int n, double a ){
		if (n==0) x=a;
		if (n==1) y=a;
		if (n==2) z=a;}
	
	void Vecteur3D::affiche (){
		cout<< x <<"  "<< y << "  " << z <<endl;}
		
	bool Vecteur3D::compare(Vecteur3D& vect, double p = 1e-10){
        if(( abs(vect.x - x) < p) and ( abs(vect.y - y) < p) and ( abs(vect.z - z) < p)) return true;
		else return false;}		
			
	Vecteur3D Vecteur3D::addition(Vecteur3D& autre) const {
		
		Vecteur3D nouveau;
		nouveau.set_coord(0, x+autre.x );
		nouveau.set_coord(1, y+autre.y );
		nouveau.set_coord(2, z+autre.z );

	return nouveau;
	}
		
	Vecteur3D Vecteur3D::soustraction(Vecteur3D& autre) const {
		
		Vecteur3D nouveau;
		nouveau.set_coord( 0,  x-autre.x );
		nouveau.set_coord(1,  y-autre.y );
		nouveau.set_coord(2, z-autre.z );
	return nouveau;
	}
		
	Vecteur3D Vecteur3D::oppose() const {

		Vecteur3D nouveau;
		nouveau.set_coord(0, -x );
		nouveau.set_coord(1, -y );
		nouveau.set_coord(2, -z );
	return nouveau; 
    }
		
	Vecteur3D Vecteur3D::mult(double a) const{
		Vecteur3D nouveau;
		nouveau.set_coord(0,  a*x );
		nouveau.set_coord(1,  a*y );
		nouveau.set_coord(2, a*z );
	return nouveau;
    }
		
	double Vecteur3D::prod_scal(Vecteur3D autre) const{ 
        return x*autre.x +y*autre.y +z*autre.z;
    }

    Vecteur3D Vecteur3D::prod_vect(Vecteur3D autre) const{
        Vecteur3D nouveau;
        nouveau.set_coord(0, y*autre.z - z*autre.y);
        nouveau.set_coord(1, z*autre.x - x*autre.z);
        nouveau.set_coord(2, x*autre.y - y*autre.x);
    return nouveau;
    }

    double Vecteur3D::norme() const{
        return sqrt(x*x + y*y + z*z);
    }	

    double Vecteur3D::norme2() const{
        return x*x + y*y + z*z;
    }

    Vecteur3D Vecteur3D::unitaire() const{
        Vecteur3D nouveau;
        double n(norme());
        nouveau.set_coord(0, x/n);
        nouveau.set_coord(1, y/n);
        nouveau.set_coord(2, z/n);
    return nouveau;
    }
 
 
 

