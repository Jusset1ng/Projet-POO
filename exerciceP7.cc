#include <iostream>
#include "Systeme.h"
#include "systeme.cc"
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
//class Dessinable{
//virtual void dessine_sur(SupportADessin& support) override
//{ support.dessine(*this); }};

class Textviewer : public SupportADessin{
	
	string& texte();
	
	void dessine(Neon const& N) override{cout<<N<<endl;};
    void dessine(Argon const& A) override  {cout<<A<<endl;};
    void dessine(Enceinte const& E) override {cout<<E<<endl;};
     void dessine(Systeme const& S) override{cout<<S<<endl;};
	
	};

int main() {
    Neon N1(1, 18.5, 1 ,0 ,0.2, 0 ,20.1797);
    Argon A1(1, 1, 3.1 ,0, 0, -0.5,39.948);

  Particule& ref1(N1);
Particule& ref2(A1);
cout<<ref1<<ref2<<endl;
    return 0;
}
