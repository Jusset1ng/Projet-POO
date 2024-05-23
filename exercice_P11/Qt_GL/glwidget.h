#pragma once
#include <QObject>
#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QElapsedTimer>        // Classe pour gérer le temps
#include "vue_opengl.h"
#include "Systeme.h"
#include "Enceinte.h"
#include "Particule.h"
#include "Argon.h"
#include "Neon.h"
#include "Helium.h"


class GLWidget : public QOpenGLWidget
/* La fenêtre hérite de QOpenGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
    Q_OBJECT
public:

    GLWidget(QWidget* parent = nullptr );
  virtual ~GLWidget() = default;

signals:
    void switchWindow();

private:
  // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QElapsedTimer chronometre;

  // objets à dessiner, faire évoluer
  Systeme c;
};
