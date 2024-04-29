#pragma once
#include <iostream>

class Particule;
class Neon;
class Argon;
class Enceinte;
class Systeme;


class SupportADessin {
public:
    virtual ~SupportADessin() = default;
    virtual void dessine(Particule const&) = 0;
    virtual void dessine(Neon const&) = 0;
    virtual void dessine(Argon const&) = 0;
    virtual void dessine(Enceinte const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    // Autres éléments que vous souhaitez dessiner
};



