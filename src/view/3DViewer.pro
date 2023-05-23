QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(../QtGifImage-master/src/gifimage/qtgifimage.pri)

CONFIG += c++17
QT += widgets opengl openglwidgets


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#DEFINES += GL_SILENCE_DEPRECATION

SOURCES += \
    ../controller/controller.cpp \
    ../model/edge.cpp \
    ../model/figure.cpp \
    ../model/parser.cpp \
    ../model/vertex.cpp \
    facade.cpp \
    geometry.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp \
    widget.cpp

HEADERS += \
    ../controller/controller.h \
    ../model/edge.h \
    ../model/figure.h \
    ../model/parser.h \
    ../model/vertex.h \
    facade.h \
    geometry.h \
    mainwindow.h \
    settings.h \
    widget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ashader.vsh \
    fshader.fsh \
    fshader.glsl \
    vshader.glsl \
    vshader.glsl \
    vshader.vsh

RESOURCES += \
    fshader.qrc \
    fshader.qrc \
    fshader.qrc \
    fshader.qrc \
    vshader.qrc \
    vshader.qrc \
    vshader.qrc
