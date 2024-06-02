#pragma once

#include <iostream>
#include "support_a_dessin.h"
//#include "Bloc.h"
//#include "Moucheron.h"
//#include "Dervish.h"
 // ou class Bloc 
//class Moucheron
// class Dervish
// declarer mais pas initialiser attention methode infos a declarer dans le .cc





class TextViewer : public SupportADessin {
public:
 TextViewer(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~TextViewer() = default;
  // on ne copie pas les TextViewer
  //TextViewer(TextViewer const&)            = delete;
  //TextViewer& operator=(TextViewer const&) = delete;
   // mais on peut les déplacer
  //TextViewer(TextViewer&&)            = default;
  //TextViewer& operator=(TextViewer&&) = default;

  void dessine(Bloc const& a_dessiner) override;
void dessine(Moucheron const& a_dessiner) override;
void dessine(Dervish const& a_dessiner) override;

private:
  std::ostream& flot;
};
