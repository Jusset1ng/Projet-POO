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
 matrice.translate(a_dessiner.get_largeur()/2,a_dessiner.get_profondeur()/2,a_dessiner.get_hauteur()/2);

 matrice.rotate(0.0, 0.0, 0.0, 0.0);
  dessineEnceinte(matrice,a_dessiner);
}

void VueOpenGL:: dessine(Neon const&  a_dessiner){
  // Dessine le 3e cube
QMatrix4x4 matrice;
  matrice.setToIdentity();
  matrice.translate(a_dessiner.get_infos(0), a_dessiner.get_infos(1), a_dessiner.get_infos(2));
  matrice.scale(0.3);
  matrice.rotate(0.0, 0.0, 0.0, 0.0);

if (a_dessiner.get_couleur()==true){dessineSphere(matrice,a_dessiner.get_infos(7)/800,1-(a_dessiner.get_infos(7)/800),0.0);}
else{dessineCube(matrice);}
  QMatrix4x4 matrice1;
  matrice1.setToIdentity();
if (a_dessiner.get_trace()==true){dessinetrace(a_dessiner,matrice1);}

}


void VueOpenGL::dessinetrace(Particule const& a_dessiner,QMatrix4x4 const& point_de_vue)
{prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    glBegin(GL_LINE_STRIP);
    for (auto const& point : a_dessiner.get_memoire()) {
    glVertex3f(point.get_coord(0), point.get_coord(1), point.get_coord(2));
    }
    glEnd();

}
void VueOpenGL:: dessine(Argon const& a_dessiner){
  // Dessine le 4e cube
    QMatrix4x4 matrice;
  matrice.setToIdentity();
  matrice.rotate(0.0, 0.0, 0.0, 0.0);
  matrice.translate(a_dessiner.get_infos(0), a_dessiner.get_infos(1), a_dessiner.get_infos(2));
  matrice.scale(0.3);
  if (a_dessiner.get_couleur()==true){dessineSphere(matrice,a_dessiner.get_infos(7)/800,1-(a_dessiner.get_infos(7)/800),0.0);}
  else{dessinePyramide(matrice);}
  QMatrix4x4 matrice1;
  matrice1.setToIdentity();
if (a_dessiner.get_trace()==true){dessinetrace(a_dessiner,matrice1);}
}

void VueOpenGL:: dessine(Helium const& a_dessiner){
    // Dessine le 3e cube
    QMatrix4x4 matrice;
    matrice.setToIdentity();
    matrice.translate(a_dessiner.get_infos(0), a_dessiner.get_infos(1),a_dessiner.get_infos(2));
    matrice.scale(0.3);
    matrice.rotate(0.0, 0.0, 0.0, 0.0);
    if (a_dessiner.get_couleur()==true){dessineSphere(matrice,a_dessiner.get_infos(7)/800,1-(a_dessiner.get_infos(7)/800),0.0);}
    else{dessineSphere(matrice);}
    QMatrix4x4 matrice1;
    matrice1.setToIdentity();
if (a_dessiner.get_trace()==true){dessinetrace(a_dessiner,matrice1);}
    }


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
  sphere.initialize();                                      // initialise la sphère

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
    prog.setAttributeValue(CouleurId,+ 0.0,+ 0.0, +1.0); // Bleu
    prog.setAttributeValue(SommetId,+ 0.0,+ 0.0,+ 0.0);   // Sommet 1 (sommet de la base)
    prog.setAttributeValue(SommetId, +0.0, -1.0,+ 0.0);  // Sommet 2 (coin de la base)
    prog.setAttributeValue(SommetId,+ 1.0, -1.0,+ 1.0);  // Sommet 3 (sommet du côté)

    // Face 3
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // Jaune
    prog.setAttributeValue(SommetId, -1.0, -1.0, 1.0); // Sommet 1 (coin de la base)
    prog.setAttributeValue(SommetId, 1.0, -1.0, 1.0); // Sommet 2 (coin de la base)
    prog.setAttributeValue(SommetId, 0.0, -1.0, 0.0); // Sommet 3 (sommet du côté)

    glEnd();
}
void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}


void VueOpenGL::dessineEnceinte(QMatrix4x4 const& point_de_vue,Enceinte const& E)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    glBegin(GL_LINES);

    // Set line color to white for visibility
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0, 1.0); // white

    double h = E.get_hauteur();
        double l = E.get_largeur();
        double p = E.get_profondeur();

        // Define vertices for the enclosure with specified dimensions
        GLdouble vertices[8][3] = {
            {-l / 2, -p / 2, -h / 2},
                    {-l / 2,  p / 2, -h / 2},
                    { l / 2, -p / 2, -h / 2},
                    { l / 2,  p / 2, -h / 2},
                    {-l / 2, -p / 2,  h / 2},
                    {-l / 2,  p / 2,  h / 2},
                    { l / 2, -p / 2,  h / 2},
                    { l / 2,  p / 2,  h / 2}
        };

    // Define the edges of the enclosure
    GLint edges[12][2] = {
        {0, 1}, {1, 3}, {3, 2}, {2, 0}, // edges around X = -1
        {4, 5}, {5, 7}, {7, 6}, {6, 4}, // edges around X = +1
        {0, 4}, {1, 5}, {2, 6}, {3, 7}  // connecting edges between X = -1 and X = +1
    };

    // Draw the edges
    for (int i = 0; i < 12; ++i) {
        prog.setAttributeValue(SommetId, vertices[edges[i][0]][0], vertices[edges[i][0]][1], vertices[edges[i][0]][2]);
        prog.setAttributeValue(SommetId, vertices[edges[i][1]][0], vertices[edges[i][1]][1], vertices[edges[i][1]][2]);
    }

    glEnd();
}
