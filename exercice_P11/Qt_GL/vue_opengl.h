#pragma once

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "SupportADessin.h"
#include "Systeme.h"
#include "Particule.h"
#include "Enceinte.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
#include "glsphere.h"

class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
  void dessine(Enceinte const& a_dessiner) override;
void dessine(Neon const& a_dessiner) override;
void dessine(Argon const& a_dessiner) override;
void dessine(Helium const& a_dessiner) override;
void dessine(Particule const& a_dessiner) override;
void dessine(Systeme const& a_dessiner) override;

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessinePyramide(QMatrix4x4 const& point_de_vue = QMatrix4x4());
  void dessineSphere(QMatrix4x4 const& point_de_vue,
                       double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  void dessineEnceinte(QMatrix4x4 const& point_de_vue = QMatrix4x4(),Enceinte const& E=Enceinte());
 void dessinetrace(Particule const& a_dessiner,QMatrix4x4 const& point_de_vue=QMatrix4x4());
 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;
  GLSphere sphere;

  // Caméra
  QMatrix4x4 matrice_vue;
};
