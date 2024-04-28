#pragma once
#include "vector"
#include "Dessinable.h"
#include "Machin.h"
class Contenu:public Dessinable{
	
	std::vector<Machin*> Collection;
	public :
	virtual ~Contenu() = default;
  //Contenu(Contenu const&)            = default;
 //Contenu& operator=(Contenu const&) = default;
  //Contenu(Contenu&&)                 = default;
  //Contenu& operator=(Contenu&&)      = default;

  virtual void dessine_sur(SupportADessin& support) override
  { for(std::size_t i(0);i<Collection.size();++i)
	  {Collection[i]->dessine_sur(support); }}

  void evolue(double dt){ 
	  for(std::size_t i(0);i<Collection.size();++i)
	  {Collection[i]->evolue(dt); }}
 
 void ajoute (Machin* M)
 {Collection.push_back(M);}
	
	};
