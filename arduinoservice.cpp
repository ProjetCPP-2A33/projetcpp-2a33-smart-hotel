#include "arduinoservice.h"
#include <QDebug>

Arduino::Arduino(QObject *parent) : QObject(parent) {
    serialPort = new QSerialPort(this);
}

Arduino::~Arduino() {
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
}

bool Arduino::connectToArduino(const QString &portName) {
    if (serialPort->isOpen()) {
        serialPort->close(); // Ferme le port s'il est déjà ouvert
    }

    serialPort->setPortName(portName);
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Ouvrir le port en mode lecture et écriture
    if (serialPort->open(QIODevice::ReadWrite)) {
        connect(serialPort, &QSerialPort::readyRead, this, &Arduino::readSerialData);
        qDebug() << "Port série connecté et ouvert en lecture/écriture sur :" << portName;
        return true;
    } else {
        qDebug() << "Erreur de connexion au port série :" << serialPort->errorString();
        return false;
    }
}


void Arduino::disconnectFromArduino() {
    if (serialPort->isOpen()) {
        serialPort->close();
    }
}

void Arduino::readSerialData() {
    while (serialPort->canReadLine()) {
        QByteArray data = serialPort->readLine().trimmed();
        emit idReceived(QString::fromUtf8(data)); // Émettre l'ID reçu
    }
}
bool Arduino::ouvrirPort(const QString &portName) {
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    serialPort->setPortName(portName);
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::WriteOnly)) {
        qDebug() << "Port série ouvert : " << portName;
        return true;
    } else {
        qDebug() << "Échec d'ouverture du port série : " << serialPort->errorString();
        return false;
    }
}

void Arduino::fermerPort() {
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Port série fermé.";
    }
}

bool Arduino::envoyerCommande(const QByteArray &commande) {
    if (serialPort->isOpen()) {
        serialPort->write(commande);
        qDebug() << "Commande envoyée : " << commande;
        return true;
    } else {
        qDebug() << "Impossible d'envoyer la commande, le port série est fermé.";
        return false;
    }
}

bool Arduino::estPortOuvert() const {
    return serialPort->isOpen();
}
