#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT += core gui sql charts printsupport widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++17
CONFIG += lrelease
CONFIG += embed_translations

SOURCES += \
    connection.cpp \
    dialog.cpp \
    employe.cpp \
    equipe.cpp \
    joueur.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connection.h \
    dialog.h \
    employe.h \
    equipe.h \
    joueur.h \
    mainwindow.h

FORMS += \
    dialog.ui \
    mainwindow.ui

RESOURCES += \
    koura.qrc

DISTFILES += \
    assetes/logo/logo_app.png

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
