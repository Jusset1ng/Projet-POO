#pragma once
#include <QObject>
#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QElapsedTimer> // Classe pour gérer le temps
#include <QOpenGLFunctions>
#include <QPainter>
#include <QFont>
#include <cmath>
#include "glwidget.h"



class GLWidgetdeux:public GLWidget{

public:
    GLWidgetdeux(QWidget* parent = nullptr,GLWidget& w= defaut);
  virtual ~GLWidgetdeux() = default;
private:
 virtual void paintGL()                       override;

 GLWidget& ref;
 static GLWidget defaut;

};
