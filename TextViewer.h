#pragma once
#include "SupportADessin.h"

std::ostream& operator<<(std::ostream& , const Particule& );
std::ostream& operator<<(std::ostream& , const Neon& );
std::ostream& operator<<(std::ostream& , const Argon& );
std::ostream& operator<<(std::ostream& , const Enceinte& );
std::ostream& operator<<(std::ostream& , const Systeme& );

class Textviewer : public SupportADessin{
	private:
	std::ostream& flot;
	public:
	Textviewer(std::ostream& f):
	flot(f){}
	
	void dessine(Particule const& P) override{flot<<P<<std::endl;};
	void dessine(Neon const& N) override{flot<<N<<std::endl;};
    void dessine(Argon const& A) override {flot<<A<<std::endl;};
    void dessine(Enceinte const& E) override{flot<<E<<std::endl;};
    void dessine(Systeme const& S) override{flot<<S<<std::endl;};
	
	};
