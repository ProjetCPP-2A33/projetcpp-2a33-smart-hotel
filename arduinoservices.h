#ifndef ARDUINOSERVICES_H
#define ARDUINOSERVICES_H
#include <QSerialPort>
#include <QString>
#include <QObject>

class arduinoServices : public QObject {
        Q_OBJECT

    public:
        explicit arduinoServices(QObject *parent = nullptr);
        ~arduinoServices();

        bool ouvrirPort(const QString &portName);
        void fermerPort();
        bool envoyerCommande(const QByteArray &commande);
        bool estPortOuvert() const;

    private:
        QSerialPort *serialPort;
    };


#endif // ARDUINOSERVICES_H
