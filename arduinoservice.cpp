#include "arduinoservice.h"
#include <QDebug>

arduinoServices::arduinoServices(QObject *parent)
    : QObject(parent),
    serialPort(new QSerialPort(this)) {
}

arduinoServices::~arduinoServices() {
    fermerPort();
}

bool arduinoServices::ouvrirPort(const QString &portName1) {
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    serialPort->setPortName(portName1);
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::WriteOnly)) {
        qDebug() << "Port série ouvert : " << portName1;
        return true;
    } else {
        qDebug() << "Échec d'ouverture du port série : " << serialPort->errorString();
        return false;
    }
}

void arduinoServices::fermerPort() {
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Port série fermé.";
    }
}

bool arduinoServices::envoyerCommande(const QByteArray &commande) {
    if (serialPort->isOpen()) {
        serialPort->write(commande);
        qDebug() << "Commande envoyée : " << commande;
        return true;
    } else {
        qDebug() << "Impossible d'envoyer la commande, le port série est fermé.";
        return false;
    }
}

bool arduinoServices::estPortOuvert() const {
    return serialPort->isOpen();
}
