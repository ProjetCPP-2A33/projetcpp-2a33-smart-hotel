QT       += core gui sql
QT       += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += charts
QT += printsupport
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Employe.cpp \
    arduino.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcode.cpp

HEADERS += \
    Employe.h \
    arduino.h \
    connection.h \
    mainwindow.h \
    qrcode.h

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
    resource.qrc
