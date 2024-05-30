QT += core gui opengl widgets
contains(QT_VERSION, ^6\\..*) {
    QT += openglwidgets
}
QMAKE_CXXFLAGS += -std=c++17

win32:LIBS += -lopengl32


TARGET = ex_p11_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    glwidgetdeux.cc\
    glsphere.cc\
    vue_opengl.cc\
    ../general/Systeme.cc

HEADERS += \
    glwidget.h \
    glwidgetdeux.h\
    vertex_shader.h \
    vue_opengl.h \
    glsphere.h\
    ../general/Dessinable.h \
    ../general/SupportADessin.h \
    ../general/Systeme.h

RESOURCES += \
    resource.qrc
