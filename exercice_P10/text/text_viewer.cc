#include <iostream> // pour endl
#include "text_viewer.h"
#include "quitourne.h"
#include "Moucheron.h"
#include "Dervish.h"
#include "Bloc.h"

void TextViewer::dessine(Moucheron const& a_dessiner)
{
flot << "Moucheron : " << a_dessiner.infos() << std::endl;
}
void TextViewer::dessine(Dervish const& a_dessiner)
{
flot << "Devish : " << a_dessiner.infos() << std::endl;
}
void TextViewer::dessine(Bloc const& a_dessiner __attribute__((unused)))
{
flot << "Bloc : immobile" << std::endl;
}
