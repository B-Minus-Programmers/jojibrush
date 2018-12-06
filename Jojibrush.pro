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
        utils/exceptions.cpp \
        utils/FileHandler.cpp \
        Canvas.cpp \
        loginwindow.cpp \
        shapes/Shape.cpp \
        shapes/GeometricShape.cpp \
        shapes/FilledShape.cpp \
        shapes/Rectangle.cpp \
        shapes/Circle.cpp \
        shapes/Ellipse.cpp \
        shapes/Polygon.cpp \
        shapes/Line.cpp \
        shapes/Polyline.cpp \
        shapes/Text.cpp \
        AboutUs.cpp \
        menus/FilledPropertiesMenu.cpp \
        menus/GeometricPropertiesMenu.cpp \
        menus/shapeselectmenu.cpp \
        menus/TextPropertiesMenu.cpp \
        menus/AllPropertiesMenu.cpp

HEADERS += \
        mainwindow.hpp \
        utils/vector.hpp \
        utils/algorithms.hpp \
        utils/exceptions.hpp \
        utils/FileHandler.hpp \
        Canvas.hpp \
        loginwindow.hpp \
        shapes/Shapes.hpp \
        shapes/Shape.hpp \
        shapes/Properties.hpp \
        shapes/GeometricShape.hpp \
        shapes/FilledShape.hpp \
        shapes/Rectangle.hpp \
        shapes/Circle.hpp \
        shapes/Ellipse.hpp \
        shapes/Polygon.hpp \
        shapes/Line.hpp \
        shapes/Polyline.hpp \
        shapes/Shapes.hpp \
        shapes/Polygon.hpp \
        shapes/Shape.hpp \
        shapes/Text.hpp \
        utils/exceptions.hpp \
        loginwindow.hpp \
        utils/FileHandler.hpp \
        utils/algorithms.hpp \
        AccountType.hpp \
        AboutUs.hpp \
        menus/FilledPropertiesMenu.hpp \
        menus/GeometricPropertiesMenu.hpp \
        menus/shapeselectmenu.hpp \
        menus/TextPropertiesMenu.hpp \
    menus/AllPropertiesMenu.hpp

FORMS += \
        mainwindow.ui \
        loginwindow.ui \
        aboutus.ui \
        filledpropsmenu.ui \
        geopropsmenu.ui \
        shapeselectmenu.ui \
        textpropsmenu.ui \
        allpropsmenu.ui

RESOURCES += \
        login.qrc \
        global.qrc
