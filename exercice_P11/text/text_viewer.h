#pragma once

#include <iostream>
#include "SupportADessin.h"






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

  void dessine(Particule const& a_dessiner) override;
void dessine(Neon const& a_dessiner) override;
void dessine(Argon const& a_dessiner) override;
void dessine(Helium const& a_dessiner) override;
void dessine(Enceinte const& E) override;
void dessine(Systeme const& S) override;
private:
  std::ostream& flot;
};
