#-------------------------------------------------
#
# Project created by QtCreator 2018-10-25T22:17:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jojibrush
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        utils/algorithms.cpp \
        Canvas.cpp \
        loginwindow.cpp \
        shapes/Rect.cpp \
        shapes/Ellipse.cpp \
        shapes/Circle.cpp \
        shapes/Line.cpp \
        shapes/Polyline.cpp \
        shapes/Polygon.cpp \
        shapes/Shape.cpp \
        shapes/Text.cpp

HEADERS += \
        mainwindow.hpp \
        utils/vector.hpp \
        utils/algorithms.hpp \
        Canvas.hpp \
        loginwindow.hpp \
        shapes/Rect.hpp \
        shapes/Ellipse.hpp \
        shapes/Circle.hpp \
        shapes/Line.hpp \
        shapes/Polyline.hpp \
        shapes/Shapes.hpp \
        shapes/Polygon.hpp \
        shapes/Shape.hpp \
        shapes/Text.hpp

FORMS += \
        mainwindow.ui \
        loginwindow.ui

RESOURCES += \
    login.qrc \
    resources.qrc
