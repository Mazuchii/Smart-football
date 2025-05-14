#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT += core gui sql charts printsupport widgets serialport location

TARGET = Atelier_Connexion
TEMPLATE = app

# Emit warnings for deprecated Qt features
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++17
CONFIG += lrelease
CONFIG += embed_translations

SOURCES += \
    arduino.cpp \
    ball.cpp \
    connection.cpp \
    dialog.cpp \
    employe.cpp \
    equipe.cpp \
    gesmatch.cpp \
    joueur.cpp \
    main.cpp \
    mainwindow.cpp \
    match.cpp \
    player.cpp \
    simulation.cpp \

HEADERS += \
    arduino.h \
    ball.h \
    connection.h \
    dialog.h \
    employe.h \
    equipe.h \
    gesmatch.h \
    joueur.h \
    mainwindow.h \
    match.h \
    player.h \
    simulation.h \

FORMS += \
    dialog.ui \
    mainwindow.ui

# Resources: Choose one or merge koura.qrc, logo.qrc, and assetes.qrc
RESOURCES += \
    bg.qrc \
    koura.qrc \
    logo.qrc
# If you want to merge into a single resource file (e.g., resources.qrc), create it and replace the above with:
# RESOURCES += resources.qrc

DISTFILES += \
    assetes/logo/logo_app.png

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
