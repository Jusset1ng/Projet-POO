#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include "glwidgetdeux.h"

// ======================================================================
void GLWidgetdeux::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
  vue.init();
  timerId = startTimer(20);
}

GLWidgetdeux::GLWidgetdeux(QWidget* parent)
    : QOpenGLWidget(parent)
  {
    chronometre.restart();
c.set_enceinte(Enceinte(20,20,20));
c.set_epsilon(1.0);
      c.ajouter_particule(new Helium(1 ,1, 1,0, 0, 0,4.002602));
      c.ajouter_particule(new Neon(1, 18.5, 1 ,0 ,0.2, 0 ,20.1797));
      c .ajouter_particule(new Argon(1, 1, 3.1 ,0, 0, -0.5,39.948));
      c.set_forcage(true);
       }
// ======================================================================
void GLWidgetdeux::resizeGL(int width, int height)
{
  /* On commance par dire sur quelle partie de la
   * fenêtre OpenGL doit dessiner.
   * Ici on lui demande de dessiner sur toute la fenêtre.
   */
  glViewport(0, 0, width, height);

  /* Puis on modifie la matrice de projection du shader.
   * Pour ce faire on crée une matrice identité (constructeur
   * par défaut), on la multiplie par la droite par une matrice
   * de perspective.
   * Plus de détail sur cette matrice
   *     http://www.songho.ca/opengl/gl_projectionmatrix.html
   * Puis on upload la matrice sur le shader à l'aide de la
   * méthode de la classe VueOpenGL
   */
  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);
}

// ======================================================================
void GLWidgetdeux::paintGL()
{
    // Désactiver OpenGL pour utiliser QPainter
        glDisable(GL_DEPTH_TEST); // Désactiver le test de profondeur
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width(), height(), 0, -1, 1); // Définir une projection orthographique
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Configurer QPainter
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Effacer l'arrière-plan
        glClear(GL_COLOR_BUFFER_BIT);

        // Définir la couleur du texte en blanc
        painter.setPen(Qt::white);

        // Dessiner avec QPainter
        QFont font("Arial", 12);
        painter.setFont(font);
        QString text = " L'energie cinetique moyenne est : " + QString::number(c.calculer_Ecin());
        QString text1 = " Le nombre actuel de chocs avec les parois est " + QString::number(c.get_comptechocparois());

        painter.drawText(20, 40, text);
        painter.drawText(20, 80, text1);
        // Réactiver OpenGL
        glEnable(GL_DEPTH_TEST); // Réactiver le test de profondeur
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        // Configurez ici votre matrice de projection OpenGL
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        // Configurez ici votre matrice de modèle-vue OpenGL

}


// ======================================================================
void GLWidgetdeux::keyPressEvent(QKeyEvent* event)
{
  constexpr double petit_angle(5.0); // en degrés
  constexpr double petit_pas(1.0);
    switch (event->key()) {
            // Existing cases...

  case Qt::Key_G:  // Use F1 to switch window
      emit switchWindow();
         break;


  case Qt::Key_Left:
    vue.rotate(petit_angle, 0.0, -1.0, 0.0);
    break;

  case Qt::Key_Right:
    vue.rotate(petit_angle, 0.0, +1.0, 0.0);
    break;

  case Qt::Key_Up:
    vue.rotate(petit_angle, -1.0, 0.0, 0.0);
    break;

  case Qt::Key_Down:
    vue.rotate(petit_angle, +1.0, 0.0, 0.0);
    break;

  case Qt::Key_PageUp:
  case Qt::Key_W:
    vue.translate(0.0, 0.0,  petit_pas);
    break;

  case Qt::Key_PageDown:
  case Qt::Key_S:
    vue.translate(0.0, 0.0, -petit_pas);
    break;

  case Qt::Key_A:
    vue.translate( petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_D:
    vue.translate(-petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_R:
    vue.translate(0.0, -petit_pas, 0.0);
    break;

  case Qt::Key_F:
    vue.translate(0.0,  petit_pas, 0.0);
    break;

  case Qt::Key_Q:
    vue.rotate(petit_angle, 0.0, 0.0, -1.0);
    break;

  case Qt::Key_E:
    vue.rotate(petit_angle, 0.0, 0.0, +1.0);
    break;

  case Qt::Key_Home:
    vue.initializePosition();
    break;

  case Qt::Key_Space:
    pause();
    break;
  };

  update(); // redessine
}

// ======================================================================
void GLWidgetdeux::timerEvent(QTimerEvent* event)
{
  Q_UNUSED(event);

  const double dt = chronometre.elapsed() / 1000.0;
  chronometre.restart();

  c.evolue(c.pas);
  update();
}

// ======================================================================
void GLWidgetdeux::pause()
{
  if (timerId == 0) {
    // dans ce cas le timer ne tourne pas alors on le lance
    timerId = startTimer(20);
    chronometre.restart();
  } else {
    // le timer tourne alors on l'arrête
    killTimer(timerId);
    timerId = 0;
  }
}

