QMAKE_CXXFLAGS += -std=c++17

CONFIG += console

TARGET = ex_05_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc \
    text_viewer.cc\
  ../general/Systeme.cc\


HEADERS += \
    ../general/Systeme.h \
    text_viewer.h \
    ../general/Dessinable.h \
    ../general/SupportADessin.h

