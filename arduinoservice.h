#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QObject>

class Arduino : public QObject {
    Q_OBJECT

public:
    explicit Arduino(QObject *parent = nullptr);
    ~Arduino();

    bool connectToArduino(const QString &portName);
    void disconnectFromArduino();
    bool ouvrirPort(const QString &portName);
    void fermerPort();
    bool envoyerCommande(const QByteArray &commande);
    bool estPortOuvert() const;


signals:
    void idReceived(const QString &id); // Signal pour transmettre l'ID reçu

private slots:
    void readSerialData(); // Lecture des données série

private:
    QSerialPort *serialPort;
};

#endif // ARDUINO_H
