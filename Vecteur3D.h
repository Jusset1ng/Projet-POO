#pragma once

class Vecteur3D {
	private:
	double x;
	double y; 
	double z;

	public:
	
	void set_coord(int n, double a );
	
	void affiche();

    bool compare(Vecteur3D& vect, double p );
			
	Vecteur3D addition(Vecteur3D& autre) const;
		
	Vecteur3D soustraction(Vecteur3D& autre) const;
		
	Vecteur3D oppose() const;
		
	Vecteur3D mult(double a) const;
		
	double prod_scal(Vecteur3D autre) const;

    Vecteur3D prod_vect(Vecteur3D autre) const;

	double norme() const;

    double norme2() const;

    Vecteur3D unitaire() const;
};
 
