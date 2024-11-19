#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Client
{

public:

    //constructeurs
    Client();
    Client(QString,int,QString,QString,QString,QString,QString);
    //getters
    QString getNom(){return nomC;}
    QString getPrenom(){return prenomC;}
    QString getNationalite(){return nationalite;}
    QString getEmail(){return emailC;}
    QString getGenre(){return genre;}
    //int getID(){return idC;}
    QString getCIN(){return CIN;}
    int getNum_tel(){return num_telC;}


    //setters
    void setNom(QString n){nomC=n;}
    void setPrenom(QString p){prenomC=p;}
    void setNationalite(QString nationalite){nationalite=nationalite;}
    void setEmail(QString e){emailC=e;}
    void setGenre(QString g){genre=g;}
    //void setID(int idC){this->idC=idC;}
    void setCIN(QString c){CIN=c;}
    void setNum_tel(int num_telC){this->num_telC=num_telC;}


    //fonctionnaltés de base
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    Client rechercher(int idC);
    bool modifier(int idC);
    QSqlQueryModel* trierParNom(const QString& ordre = "ASC");
    QSqlQueryModel* trierParNom_desc(const QString& order="DESC");
    QSqlQueryModel* rechercher(const QString& critere, const QString& typeRecherche);

    //QSqlQueryModel* rechercherClients(const QString& champ, const QString& valeur);
    QSqlQueryModel* obtenirReservationsParClient();
   // QString clientLePlusFidele();  // Déclaration de la fonction
 // QString afficherNbReservationsParClient();  // Déclaration de la fonction
 //  QString clientLePlusFidele();
     Client clientLePlusFidele();
    QString CIN,nomC, prenomC, nationalite, emailC, genre;
    int num_telC;
   //  QString clientLePlusFidele();



};

#endif // CLIENT_H
