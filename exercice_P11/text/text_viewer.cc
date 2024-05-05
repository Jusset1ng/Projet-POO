#include <iostream> // pour endl
#include "text_viewer.h"
#include "Particule.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
#include "Enceinte.h"
#include "Systeme.h"

void TextViewer:: dessine(Particule const& P){ flot << P << std::endl;}
    void TextViewer:: dessine(Neon const& N) { flot << N << std::endl;}
    void TextViewer::dessine(Argon const& A) {flot <<A << std::endl;}
    void TextViewer:: dessine(Helium const& N) { flot << N << std::endl;}
    void TextViewer::dessine(Enceinte const& E) {flot <<E << std::endl;}
    void TextViewer::dessine(Systeme const& S) {flot << S<< std::endl;}
