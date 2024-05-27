TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++17

SOURCES =Particule.cc \
Enceinte.cc\
Neon.cc\
Argon.cc\
Helium.cc\
 Vecteur3D.cc\

HEADERS += \
    Particule.h \
    Dessinable.h \
    SupportADessin.h\
    Enceinte.h\
    Neon.h\
    Argon.h\
    Helium.h\
   Vecteur3D.h\
