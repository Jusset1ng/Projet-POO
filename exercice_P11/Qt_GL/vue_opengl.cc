#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Enceinte.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
#include "Systeme.h"
#include "Particule.h"


// ======================================================================
void VueOpenGL::dessine(Enceinte const& a_dessiner)
{

  QMatrix4x4 matrice;
  //Dessine le 2e cube
  matrice.setToIdentity();
 matrice.translate(10,10,10);
 matrice.scale(10);
 matrice.rotate(.0, 0.0, 0.0, 0.0);
  dessineEnceinte(matrice);
}

void VueOpenGL:: dessine(Neon const&  a_dessiner){
  // Dessine le 3e cube
QMatrix4x4 matrice;
  matrice.setToIdentity();
  matrice.translate(a_dessiner.get_infos(0), a_dessiner.get_infos(1), a_dessiner.get_infos(2));
  matrice.scale(0.5);
  matrice.rotate(0.0, 0.0, 0.0, 0.0);
  dessineCube(matrice);
if (a_dessiner.get_trace()==true){
  glBegin(GL_LINE_STRIP);
  for (auto const& point : a_dessiner.get_memoire()) {
  glVertex3f(point.get_coord(0), point.get_coord(1), point.get_coord(2));
  }
  glEnd();}
}

void VueOpenGL:: dessine(Argon const& a_dessiner){
  // Dessine le 4e cube
    QMatrix4x4 matrice;
  matrice.setToIdentity();
  matrice.rotate(0.0, 0.0, 0.0, 0.0);
  matrice.translate(a_dessiner.get_infos(0), a_dessiner.get_infos(1), a_dessiner.get_infos(2));
  matrice.scale(0.5);
  dessinePyramide(matrice);
  if (a_dessiner.get_trace()==true){
    glBegin(GL_LINE_STRIP);
    for (auto const& point : a_dessiner.get_memoire()) {
    glVertex3f(point.get_coord(0), point.get_coord(1), point.get_coord(2));
    }
    glEnd();}
}

void VueOpenGL:: dessine(Helium const& a_dessiner){
    // Dessine le 3e cube
    QMatrix4x4 matrice;
    matrice.setToIdentity();
    matrice.translate(a_dessiner.get_infos(0), a_dessiner.get_infos(1),a_dessiner.get_infos(2));
    matrice.scale(0.5);
    matrice.rotate(0.0, 0.0, 0.0, 0.0);
    dessineSphere(matrice);

    if (a_dessiner.get_trace()==true){
      glBegin(GL_LINE_STRIP);
      for (auto const& point : a_dessiner.get_memoire()) {
      glVertex3f(point.get_coord(0), point.get_coord(1), point.get_coord(2));
      }
      glEnd();}}

void VueOpenGL:: dessine(Particule const& a_dessiner) {}
void VueOpenGL:: dessine(Systeme const& a_dessiner) {}

// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */


  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0, 0, -12);
  matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
  matrice_vue.rotate(45.0, 0.0, 0.0, 1.0);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0,1); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0,1); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0,1); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0,1); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0,1); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}

void VueOpenGL::dessinePyramide(QMatrix4x4 const& point_de_vue)
{
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    glBegin(GL_TRIANGLES);

    prog.setAttributeValue(CouleurId, +1.0,+ 0.0,+ 0.0,1); // Rouge
    prog.setAttributeValue(SommetId,+ 0.0,+ 0.0,+ 0.0);   // Sommet 1
    prog.setAttributeValue(SommetId, -1.0, -1.0,+ 1.0); // Sommet 2
    prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);  // Sommet 3

    // Faces latérales de la pyramide
    // Face 1
    prog.setAttributeValue(CouleurId,+ 0.0, +1.0, +0.0,1); // Vert
    prog.setAttributeValue(SommetId, +0.0,+ 0.0,+ 0.0);   // Sommet 1 (sommet de la base)
    prog.setAttributeValue(SommetId, +1.0, -1.0,+ 1.0);  // Sommet 2 (coin de la base)
    prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0); // Sommet 3 (sommet du côté)

    // Face 2
    prog.setAttributeValue(CouleurId,+ 0.0,+ 0.0, +1.0,1); // Bleu
    prog.setAttributeValue(SommetId,+ 0.0,+ 0.0,+ 0.0);   // Sommet 1 (sommet de la base)
    prog.setAttributeValue(SommetId, +0.0, -1.0,+ 0.0);  // Sommet 2 (coin de la base)
    prog.setAttributeValue(SommetId,+ 1.0, -1.0,+ 1.0);  // Sommet 3 (sommet du côté)

    // Face 3
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0,1); // Jaune
    prog.setAttributeValue(SommetId, -1.0, -1.0, 1.0); // Sommet 1 (coin de la base)
    prog.setAttributeValue(SommetId, 1.0, -1.0, 1.0); // Sommet 2 (coin de la base)
    prog.setAttributeValue(SommetId, 0.0, -1.0, 0.0); // Sommet 3 (sommet du côté)

    glEnd();
}
void VueOpenGL::dessineSphere(QMatrix4x4 const& point_de_vue)
{
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    const float radius = 1.0f;
    const int numSegments = 32;

    glBegin(GL_TRIANGLES);

    for (int j = 0; j < numSegments; ++j)
    {
        for (int i = 0; i < numSegments; ++i)
        {
            float theta1 = (float)(j) / (float)(numSegments) * M_PI * 2;
            float theta2 = (float)(j + 1) / (float)(numSegments) * M_PI * 2;
            float phi1 = (float)(i) / (float)(numSegments) * M_PI;
            float phi2 = (float)(i + 1) / (float)(numSegments) * M_PI;

            QVector3D p1(radius * sin(phi1) * cos(theta1), radius * sin(phi1) * sin(theta1), radius * cos(phi1));
            QVector3D p2(radius * sin(phi1) * cos(theta2), radius * sin(phi1) * sin(theta2), radius * cos(phi1));
            QVector3D p3(radius * sin(phi2) * cos(theta1), radius * sin(phi2) * sin(theta1), radius * cos(phi2));
            QVector3D p4(radius * sin(phi2) * cos(theta2), radius * sin(phi2) * sin(theta2), radius * cos(phi2));

            // Triangle 1
            prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // Rouge
            prog.setAttributeValue(SommetId, p1.x(), p1.y(), p1.z());
            prog.setAttributeValue(SommetId, p2.x(), p2.y(), p2.z());
            prog.setAttributeValue(SommetId, p3.x(), p3.y(), p3.z());

            // Triangle 2
            prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // Vert
            prog.setAttributeValue(SommetId, p4.x(), p4.y(), p4.z());
            prog.setAttributeValue(SommetId, p3.x(), p3.y(), p3.z());
            prog.setAttributeValue(SommetId, p2.x(), p2.y(), p2.z());
        }
    }

    glEnd();
}


void VueOpenGL::dessineEnceinte(QMatrix4x4 const& point_de_vue)
{

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);


    glBegin(GL_QUADS);

    // face coté X = -1
    prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0,0.2); // vert
    prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
    prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
    prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
    prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

    // face coté Y = +1
    prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0,0.2); // bleu
    prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
    prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
    prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
    prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

    // face coté Y = -1
    prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0,0.2); // cyan
    prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
    prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
    prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
    prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

    // face coté Z = +1
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0,0.2); // jaune
    prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
    prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
    prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
    prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

    // face coté Z = -1
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0,0.2); // magenta
    prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
    prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
    prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
    prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

    // face coté X = +1
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0,0.2); // rouge
    prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
    prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
    prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
    prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

    glEnd();}


