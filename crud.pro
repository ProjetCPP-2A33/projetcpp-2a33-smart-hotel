QT       += core gui sql printsupport charts
QT += network
QT +=serialport
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Arduino.cpp \
    arduinoservice.cpp \
    client.cpp \
    connection.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcode.cpp \
    reservation.cpp \
    service.cpp

HEADERS += \
    Arduino.h \
    arduinoservice.h \
    client.h \
    connection.h \
    employee.h \
    mainwindow.h \
    qrcode.h \
    reservation.h \
    service.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    img/b.qrc \
    img/logo.qrc \
    img/n.qrc \
    img/t.qrc \
    resource.qrc \
    resource.qrc \
    ressource.qrc

DISTFILES += \
    img/0b26b188-484e-4955-b620-a8405c76b74e.jfif \
    img/29abf6e7-23c4-4564-b07f-5229067fda50.jfif \
    img/6fa8be47-cec4-4270-ae1f-b0962243668d.jfif \
    img/8051f3d1-c574-4c63-b54e-83dfdd52aa02.jfif \
    img/fidelite-removebg-preview.png
