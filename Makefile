CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall         # pour les purs et durs
# CXXFLAGS += -g                    # pour debugger
# CXXFLAGS += -O2                   # pour optimiser la vitesse

all: testVecteur3D testParticule testsysteme1 exerciceP7 exerciceP9 exerciceP12

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h

testVecteur3D: testVecteur3D.o Vecteur3D.o

SupportADessin.o: SupportADessin.h

TextViewer.o : TextViewer.h SupportADessin.h

Dessinable.o: Dessinable.h TextViewer.h

Particule.o: Particule.cc Particule.h Vecteur3D.h Dessinable.h

testParticule.o: testParticule.cc Particule.h  

testParticule: testParticule.o Particule.o Vecteur3D.o 

Neon.o :Neon.cc Neon.h Particule.h 

Argon.o :Argon.cc Argon.h Particule.h

Helium.o :Helium.cc Helium.h Particule.h

Enceinte.o:Enceinte.cc Enceinte.h Dessinable.h

GenerateurAleatoire.o: GenerateurAleatoire.h

Systeme.o: Systeme.cc Systeme.h Enceinte.h Particule.h GenerateurAleatoire.h

testsysteme1.o: testsysteme1.cc Systeme.h Neon.h Argon.h Helium.h

testsysteme1:testsysteme1.o Systeme.o Particule.o Enceinte.o Neon.o Argon.o Helium.o Vecteur3D.o

exerciceP7.o: exerciceP7.cc  Systeme.h Argon.h Neon.h

exerciceP7: exerciceP7.o Systeme.o Particule.o Enceinte.o Neon.o Argon.o Helium.o Vecteur3D.o 

exerciceP9.o: exerciceP9.cc Systeme.h Neon.h Argon.h Helium.h 

exerciceP9: exerciceP9.o Systeme.o Particule.o Enceinte.o Neon.o Argon.o Helium.o Vecteur3D.o

exerciceP12.o: exerciceP12.cc Systeme.h Neon.h Argon.h Helium.h

exerciceP12: exerciceP12.o Systeme.o Particule.o Enceinte.o Neon.o Argon.o Helium.o Vecteur3D.o