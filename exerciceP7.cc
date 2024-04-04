#include <iostream>
#include "Systeme.h"
#include "systeme.cc"
using namespace std;

class Neon : public Particule {
public:
    Neon(double a, double b, double c, double d, double e, double f, double g) :
        Particule(a, b, c, d, e, f, g) {}

    std::ostream& affiche(std::ostream& sortie) const override {
        sortie << "Neon: pos : ";
        pos.affiche(sortie);
        sortie << " ; v : ";
        v.affiche(sortie);
        sortie << " ; m : " << masse << std::endl;
        return sortie;
    }
};

class Argon : public Particule {
public:
    Argon(double a, double b, double c, double d, double e, double f, double g) :
        Particule(a, b, c, d, e, f, g) {}

    std::ostream& affiche(std::ostream& sortie) const override {
        sortie << "Argon : pos : ";
        pos.affiche(sortie);
        sortie << " ; v : ";
        v.affiche(sortie);
        sortie << " ; m : " << masse << std::endl;
        return sortie;
    }
};
class SupportADessin {
public:
    virtual ~SupportADessin() = default;
    virtual void dessine(Neon const&) = 0;
    virtual void dessine(Argon const&) = 0;
    virtual void dessine(Enceinte const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    // Autres éléments que vous souhaitez dessiner
};


class Textviewer : public SupportADessin{
	private:
	ostream& flot;
	public:
	Textviewer(ostream& f):
	flot(f){}
	void dessine(Neon const& N) override{flot<<N<<endl;};
    void dessine(Argon const& A) override  {flot<<A<<endl;};
    void dessine(Enceinte const& E) override {flot<<E<<endl;};
     void dessine(Systeme const& S) override{flot<<S<<endl;};
	
	};
	
//class Dessinable{	
//virtual void dessine_sur(SupportADessin& support) 
//{ support.dessine(*this); }};

//class :Contenu {
	//virtual void dessine_sur(SupportADessin& support) override
//{ support.dessine(*this); }};

int main() {
	Systeme S;
	Textviewer T(cout);
    Neon N1(1, 18.5, 1 ,0 ,0.2, 0 ,20.1797);
    Argon A1(1, 1, 3.1 ,0, 0, -0.5,39.948);
  Neon* ptr1(&N1);
  Argon* ptr2(&A1);

S.ajouter_particule(ptr1);
S.ajouter_particule(ptr2);

T.dessine(S);//devrait être S.dessine_sur(T); une fois la méthode dessine_sur mise dans les classes dessinables

    return 0;
}
