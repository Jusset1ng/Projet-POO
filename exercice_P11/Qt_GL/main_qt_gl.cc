#include <QApplication>
#include<QObject>
#include "glwidget.h"
#include "glwidgetdeux.h"
int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w1;
  GLWidgetdeux w2;

  w1.show();
  w2.hide();  // Start with the second window hidden

  QObject::connect(&w1, &GLWidget::switchWindow, [&]() {
          w1.hide();
          w2.show();
      });

      // Connecter le signal switchWindow de w2 au slot switchWindow de w1
      QObject::connect(&w2, &GLWidgetdeux::switchWindow, [&]() {
          w2.hide();
          w1.show();
      });

  return a.exec();
}
