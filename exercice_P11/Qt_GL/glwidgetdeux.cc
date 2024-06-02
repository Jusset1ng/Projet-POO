#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include "glwidgetdeux.h"



GLWidgetdeux::GLWidgetdeux(QWidget* parent,GLWidget& w):
    GLWidget(parent),ref(w){resize(1500, 300);
                    }
// ======================================================================
void GLWidgetdeux::paintGL()//redefinissions de PaintGL
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
        QString text = " L'energie cinetique moyenne estimatrice de la température T  est de: " + QString::number(ref.info(0))+"[J]";
        QString text1 = " Le nombre actuel de chocs avec les parois est " + QString::number(ref.info(1));
        QString text2 = " La pression actuelle P est de " + QString::number(ref.info(2))+" [Pa]";
       QString text3 = "  Selon La loi des gaz parfait P/T est égal à:  " + QString::number(ref.info(2)/ref.info(0));
        QString text4 = "  le pas est actuellement de  " + QString::number(ref.info(3))+"[ps]";

        painter.drawText(20, 40, text);
        painter.drawText(20, 80, text1);
        painter.drawText(20, 120, text2);
        painter.drawText(20, 160, text3);
         painter.drawText(20, 200, text4);
        // Réactiver OpenGL
        glEnable(GL_DEPTH_TEST); // Réactiver le test de profondeur
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        // Configurez ici votre matrice de projection OpenGL
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        // Configurez ici votre matrice de modèle-vue OpenGL

}






