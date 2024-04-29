
 #include <iostream>
#include "Vecteur3D.h"
#include <cmath>
using namespace std;

//--------METHODE--------//

double Vecteur3D::get_coord(int n){
	if (n==0) return x;
	if (n==1) return y;
	if (n==2) return z;
	return 0;
}

void Vecteur3D::set_coord(int n, double a ){
		if (n==0) x=a;
		if (n==1) y=a;
		if (n==2) z=a;
		}
	
ostream& Vecteur3D::affiche(ostream& sortie)const {
    sortie << x << " " << y << " " << z ;
    return sortie;
}



bool Vecteur3D::compare(Vecteur3D const& vect, double p = 1e-10) const{
    if(( abs(vect.x - x) < p) and ( abs(vect.y - y) < p) and ( abs(vect.z - z) < p)) return true;
	else return false;}	
		

			
Vecteur3D Vecteur3D::addition(const Vecteur3D& autre) const {
		
	return Vecteur3D(x+autre.x,y+autre.y,z+autre.z);
	}

	
Vecteur3D Vecteur3D::soustraction(const Vecteur3D& autre) const {
		
	return Vecteur3D(x-autre.x,y-autre.y,z-autre.z);
	}
	
void Vecteur3D::oppose_n(int n){
	if (n==0) x = -x;
	if (n==1) y= -y;
	if (n==2) z= -z;
}
		
Vecteur3D Vecteur3D::oppose() const {

	return Vecteur3D(-x,-y,-z);
    }
		
Vecteur3D Vecteur3D::mult(double a) const{
	return Vecteur3D(x*a,y*a,z*a);
    }
		
double Vecteur3D::prod_scal(const Vecteur3D& autre) const{ 
    return x*autre.x +y*autre.y +z*autre.z;
    }

Vecteur3D Vecteur3D::prod_vect(const Vecteur3D& autre) const{
    return Vecteur3D(y*autre.z - z*autre.y,z*autre.x - x*autre.z,x*autre.y - y*autre.x);
    }

double Vecteur3D::norme() const{
    return sqrt(x*x + y*y + z*z);
    }	

double Vecteur3D::norme2() const{
    return x*x + y*y + z*z;
    }

Vecteur3D Vecteur3D::unitaire() const{
   double n(norme());
    return Vecteur3D(x/n,y/n,z/n);
    }
 
 
//--------OPERATOR---------//

ostream& operator<<(ostream& sortie, Vecteur3D const& v) 
	{return v.affiche(sortie);}
	
bool operator==(Vecteur3D const& v1, Vecteur3D const& v2)
	{return v1.compare(v2);}

bool operator!=(Vecteur3D const& v1, Vecteur3D const& v2)
	{return !(v1.compare(v2));}

Vecteur3D Vecteur3D::operator+=(const Vecteur3D& autre){
	x += autre.x;
	y += autre.y;
	z += autre.z;

	return *this;
	}

Vecteur3D operator+(Vecteur3D v1, const Vecteur3D& v2)
	{return v1 += v2;}

Vecteur3D Vecteur3D::operator-=(const Vecteur3D& autre){
	x -= autre.x;
	y -= autre.y;
	z -= autre.z;

	return *this;
}
		
Vecteur3D operator-(Vecteur3D v1,const Vecteur3D& v2)
	{return v1 -= v2;}	

double operator^(const Vecteur3D& v1,const Vecteur3D& v2){
	return v1.prod_scal(v2);
}

Vecteur3D operator~(const Vecteur3D& v){
	return v.unitaire();
}

Vecteur3D Vecteur3D::operator*=(double d){
	x *= d;
	y *= d;
	z *= d;
	return *this;
}

Vecteur3D operator*(Vecteur3D v, double d){
	return v *= d;
}

Vecteur3D operator*(double d, Vecteur3D v){
	return v *= d;
}