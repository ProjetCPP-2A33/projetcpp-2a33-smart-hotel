/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *afficher;
    QGroupBox *groupBox_2;
    QTableView *tableView;
    QPushButton *pushButton_afficher;
    QGraphicsView *graphicsView_chart;
    QLabel *label_23;
    QLabel *label_22;
    QPushButton *pushButton_trierParNom;
    QPushButton *pushButton_trierParNom_3;
    QPushButton *pushButton_export_pdf;
    QLabel *label_28;
    QPushButton *pushButton_client_fidele;
    QLabel *label_29;
    QLineEdit *lineEdit_critereRecherche;
    QPushButton *pushButtonRechercher_met;
    QPushButton *pushButton_tri_desc;
    QComboBox *comboBox_critereRecherche;
    QComboBox *comboBox_ordre;
    QComboBox *comboBoxCritere;
    QLabel *label_21;
    QWidget *Ajouter;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineedit_nom;
    QLineEdit *lineedit_prenom;
    QLineEdit *lineedit_adresse;
    QLineEdit *lineedit_tel;
    QRadioButton *radiobutton_homme;
    QRadioButton *radiobutton_femme;
    QPushButton *pushButton_ajouter;
    QLineEdit *lineedit_cin;
    QLabel *label_13;
    QLineEdit *lineedit_nationalite;
    QWidget *Modifier;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineedit_nom_modif;
    QLineEdit *lineedit_prenom_modif;
    QLineEdit *lineedit_adresse_modif;
    QLineEdit *lineedit_tel_modif;
    QRadioButton *radiobutton_homme_modif;
    QRadioButton *radiobutton_femme_modif;
    QPushButton *pushButton_modifier;
    QLineEdit *lineedit_id_modif;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *pushButton_rechercher2;
    QLineEdit *lineedit_nationalite_modif;
    QLabel *label_26;
    QLineEdit *lineedit_cin_modif;
    QWidget *supprimer;
    QGroupBox *groupBox_7;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_45;
    QLineEdit *lineedit_nom_supp;
    QLineEdit *lineedit_prenom_supp;
    QPushButton *pushButton_supprimer;
    QLineEdit *lineedit_id_rech;
    QLabel *label_48;
    QLabel *label_49;
    QPushButton *pushButton_rechercher;
    QLineEdit *lineedit_nationalite_supp;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *lineedit_adresse_supp;
    QLineEdit *lineedit_tel_supp;
    QRadioButton *radioButton_homme_supp;
    QRadioButton *radioButton_femme_supp;
    QLineEdit *lineedit_cin_supp;
    QLabel *label_27;
    QWidget *Mailing;
    QGroupBox *groupBox_4;
    QLineEdit *lineEditRecipient;
    QLineEdit *lineEditSubject;
    QPushButton *pushButtonSend;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *pushButton_4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_menu;
    QLabel *label_14;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgba(228, 234, 242, 255); /* Gris tr\303\250s clair */\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(280, 20, 1675, 861));
        tabWidget->setMinimumSize(QSize(1675, 0));
        tabWidget->setMaximumSize(QSize(1674, 935));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(20);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("/* Fond du QTabWidget */\n"
"QTabWidget {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(30, 144, 255, 255), stop:1 rgba(0, 70, 128, 255));\n"
"}\n"
"\n"
"/* Style des onglets */\n"
"QTabBar::tab {\n"
"    background-color: #3049D9; /* Remplac\303\251 par la couleur #3049D9 */\n"
"    color: #FFF9C4; /* Texte blanc */\n"
"   border: 3px solid #2A2DAC;\n"
"   border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 12px 20px; /* Espacement interne - ajustez selon vos besoins */\n"
"    text-align: center; /* Centrer le texte */\n"
"}\n"
"\n"
"/* Style des onglets lorsqu'ils sont survol\303\251s */\n"
"QTabBar::tab:hover {\n"
"    background-color: #435AD9; /* Changer la couleur au survol */\n"
"}\n"
"\n"
"/* Style des onglets actifs */\n"
"QTabBar::tab:pressed {\n"
"    background-color: #353FF2; /* Conserver la m\303\252me couleur que pour l'onglet actif */\n"
"}\n"
"\n"
"\n"
"/* Style du contenu des onglets */\n"
"QTabWidget::pane {\n"
"    border: 2px solid #0000"
                        "00; /* Bordure bleu fonc\303\251 pour le contenu des onglets */\n"
"    border-top: 0; /* Supprimer la bordure sup\303\251rieure */\n"
"}\n"
"\n"
"/* Style des boutons de fermeture des onglets */\n"
"QTabBar::close-button {\n"
"    image: url(close.png); /* Remplacez par le chemin de votre ic\303\264ne de fermeture */\n"
"    subcontrol-position: right; /* Position \303\240 droite du texte de l'onglet */\n"
"}\n"
"\n"
"QTabBar::close-button:hover {\n"
"    image: url(close-hover.png); /* Ic\303\264ne de fermeture au survol */\n"
"}\n"
"\n"
"/* Ajustement de la police */\n"
"QTabBar {\n"
"    font-size: 16px; /* Taille de la police pour les onglets */\n"
"    qproperty-drawBase: 0; /* D\303\251sactiver le dessin de la base (fond) de l'onglet */\n"
"}\n"
"\n"
""));
        tabWidget->setIconSize(QSize(16, 16));
        afficher = new QWidget();
        afficher->setObjectName("afficher");
        groupBox_2 = new QGroupBox(afficher);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 10, 1221, 691));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Trebuchet MS")});
        font1.setPointSize(24);
        font1.setBold(true);
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QString::fromUtf8("/* Style de base pour la QGroupBox */\n"
"QGroupBox {\n"
"    border: 4px solid #999DF2; /* Bordure de la m\303\252me couleur que le fond du titre */\n"
"    border-radius: 25px; /* Coins arrondis */\n"
"    margin-top: 10px; /* Marge en haut */\n"
"}\n"
"\n"
"/* Style du titre de la QGroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: #999DF2; /* Fond remplac\303\251 par #999DF2 */\n"
"    color: #ffffff; /* Texte blanc pour le titre */\n"
"    border-radius: 10px; /* Coins arrondis du titre */\n"
"}\n"
"\n"
"/* Style des QLabel \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLabel {\n"
"    color: #000000; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QRadioButton \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QRadioButton {\n"
"    color: #333333; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QComboBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QComboBox {\n"
"    background"
                        "-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QLineEdit \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QSpinBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QSpinBox {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sacti"
                        "v\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0; /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0; /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}"));
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 50, 791, 481));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"image: url(:/c/cc.png);\n"
"image: url(:/c/cc.png);\n"
"image: url(:/c/cc.png);\n"
"image: url(:/c/cc.png);\n"
"QTableWidget {\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #cccccc;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    font-weight: bold;\n"
"    color: #333333;\n"
"    background-color: #f5f5f5;\n"
"    border-bottom: 1px solid #cccccc;\n"
"}\n"
"\n"
"\n"
""));
        pushButton_afficher = new QPushButton(groupBox_2);
        pushButton_afficher->setObjectName("pushButton_afficher");
        pushButton_afficher->setGeometry(QRect(310, 540, 201, 51));
        pushButton_afficher->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
"QPushButton {\n"
"    background-color: #435AD9;  /* Bleu vif pour un look frais et moderne */\n"
"    color: #ffffff;              /* Texte blanc */\n"
"    border: 3px solid #435AD9;  /* Bordure de la m\303\252me couleur que le fond */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne */\n"
"    font: 75 18pt \"Times New Roman\"; /* Police en gras */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #5f7cd8;   /* Bleu plus clair au survol */\n"
"    border: 3px solid #5f7cd8;   /* Bordure de la m\303\252me couleur que le fond survol\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est press\303\251 (clic) */\n"
"QPushButton:pressed {\n"
"    background-color: #3b4fbf;   /* Bleu fonc\303\251 au clic */\n"
"    border: 3px solid #435AD9;   /* Garder la bordure de la couleur d'origine */\n"
"}\n"
"\n"
"/* Style du QPushButt"
                        "on lorsqu'il est en focus (tabulation) */\n"
"QPushButton:focus {\n"
"    outline: none;               /* Supprimer le contour par d\303\251faut */\n"
"    border: 2px solid #2e8a56;  /* Bordure plus fonc\303\251e lorsqu'en focus */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0;   /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070;              /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0;   /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sactiv\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0;   /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0;              /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}\n"
""));
        graphicsView_chart = new QGraphicsView(groupBox_2);
        graphicsView_chart->setObjectName("graphicsView_chart");
        graphicsView_chart->setGeometry(QRect(810, 310, 401, 341));
        graphicsView_chart->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(840, 230, 371, 31));
        label_23->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(860, 150, 271, 31));
        label_22->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        pushButton_trierParNom = new QPushButton(groupBox_2);
        pushButton_trierParNom->setObjectName("pushButton_trierParNom");
        pushButton_trierParNom->setGeometry(QRect(1110, 180, 41, 41));
        pushButton_trierParNom->setStyleSheet(QString::fromUtf8("background-color: #999DF2; /* Nouveau bleu pour l'arri\303\250re-plan */\n"
"color: #000000; /* Texte blanc */\n"
"border: 5px solid #999DF2; /* Bordure de la m\303\252me couleur que l'arri\303\250re-plan */\n"
"border-radius: 10px; /* Coins arrondis */\n"
"padding: 5px 10px; /* Espacement interne */\n"
"font: 15 8pt; /* Police avec un poids de 75 et taille de 15pt */\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/6fa8be47-cec4-4270-ae1f-b0962243668d-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_trierParNom->setIcon(icon);
        pushButton_trierParNom->setIconSize(QSize(25, 25));
        pushButton_trierParNom->setAutoRepeat(false);
        pushButton_trierParNom->setAutoExclusive(false);
        pushButton_trierParNom_3 = new QPushButton(groupBox_2);
        pushButton_trierParNom_3->setObjectName("pushButton_trierParNom_3");
        pushButton_trierParNom_3->setGeometry(QRect(1160, 180, 41, 41));
        pushButton_trierParNom_3->setStyleSheet(QString::fromUtf8("background-color: #999DF2; /* Nouveau bleu pour l'arri\303\250re-plan */\n"
"color: #000000; /* Texte blanc */\n"
"border: 5px solid #999DF2; /* Bordure de la m\303\252me couleur que l'arri\303\250re-plan */\n"
"border-radius: 10px; /* Coins arrondis */\n"
"padding: 5px 10px; /* Espacement interne */\n"
"font: 15 8pt; /* Police avec un poids de 75 et taille de 15pt */\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/29abf6e7-23c4-4564-b07f-5229067fda50-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_trierParNom_3->setIcon(icon1);
        pushButton_trierParNom_3->setIconSize(QSize(25, 25));
        pushButton_trierParNom_3->setAutoRepeat(false);
        pushButton_trierParNom_3->setAutoExclusive(false);
        pushButton_export_pdf = new QPushButton(groupBox_2);
        pushButton_export_pdf->setObjectName("pushButton_export_pdf");
        pushButton_export_pdf->setGeometry(QRect(720, 620, 41, 41));
        pushButton_export_pdf->setStyleSheet(QString::fromUtf8("background-color: #999DF2; /* Nouveau bleu pour l'arri\303\250re-plan */\n"
"color: #ffffff; /* Texte blanc */\n"
"border: 5px solid #999DF2; /* Bordure de la m\303\252me couleur que l'arri\303\250re-plan */\n"
"border-radius: 10px; /* Coins arrondis */\n"
"padding: 5px 10px; /* Espacement interne */\n"
"font: 75 15pt; /* Police avec un poids de 75 et taille de 15pt */\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/WhatsApp_Image_2024-11-10_at_23.19.58-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_export_pdf->setIcon(icon2);
        pushButton_export_pdf->setIconSize(QSize(90, 90));
        pushButton_export_pdf->setAutoRepeat(false);
        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(20, 620, 221, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(14);
        font2.setItalic(true);
        label_28->setFont(font2);
        pushButton_client_fidele = new QPushButton(groupBox_2);
        pushButton_client_fidele->setObjectName("pushButton_client_fidele");
        pushButton_client_fidele->setGeometry(QRect(240, 620, 41, 41));
        pushButton_client_fidele->setStyleSheet(QString::fromUtf8("background-color: #999DF2; /* Nouveau bleu pour l'arri\303\250re-plan */\n"
"color: #ffffff; /* Texte blanc */\n"
"border: 5px solid #999DF2; /* Bordure de la m\303\252me couleur que l'arri\303\250re-plan */\n"
"border-radius: 10px; /* Coins arrondis */\n"
"padding: 5px 10px; /* Espacement interne */\n"
"font: 75 15pt; /* Police avec un poids de 75 et taille de 15pt */\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/fidelite-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_client_fidele->setIcon(icon3);
        pushButton_client_fidele->setIconSize(QSize(40, 40));
        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(650, 630, 63, 20));
        label_29->setFont(font2);
        lineEdit_critereRecherche = new QLineEdit(afficher);
        lineEdit_critereRecherche->setObjectName("lineEdit_critereRecherche");
        lineEdit_critereRecherche->setGeometry(QRect(920, 120, 231, 41));
        QFont font3;
        font3.setPointSize(14);
        lineEdit_critereRecherche->setFont(font3);
        lineEdit_critereRecherche->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 20px; "));
        lineEdit_critereRecherche->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButtonRechercher_met = new QPushButton(afficher);
        pushButtonRechercher_met->setObjectName("pushButtonRechercher_met");
        pushButtonRechercher_met->setGeometry(QRect(1120, 60, 41, 41));
        pushButtonRechercher_met->setStyleSheet(QString::fromUtf8("background-color: #999DF2; /* Nouveau bleu pour l'arri\303\250re-plan */\n"
"color: #ffffff; /* Texte blanc */\n"
"border: 5px solid #999DF2; /* Bordure de la m\303\252me couleur que l'arri\303\250re-plan */\n"
"border-radius: 10px; /* Coins arrondis */\n"
"padding: 5px 10px; /* Espacement interne */\n"
"font: 75 15pt; /* Police avec un poids de 75 et taille de 15pt */\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/0b26b188-484e-4955-b620-a8405c76b74e-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRechercher_met->setIcon(icon4);
        pushButtonRechercher_met->setIconSize(QSize(25, 25));
        pushButtonRechercher_met->setCheckable(false);
        pushButtonRechercher_met->setChecked(false);
        pushButtonRechercher_met->setAutoRepeat(false);
        pushButtonRechercher_met->setAutoExclusive(false);
        pushButton_tri_desc = new QPushButton(afficher);
        pushButton_tri_desc->setObjectName("pushButton_tri_desc");
        pushButton_tri_desc->setGeometry(QRect(1140, 270, 41, 41));
        pushButton_tri_desc->setStyleSheet(QString::fromUtf8("background-color: #999DF2; /* Nouveau bleu pour l'arri\303\250re-plan */\n"
"color: #ffffff; /* Texte blanc */\n"
"border: 5px solid #999DF2; /* Bordure de la m\303\252me couleur que l'arri\303\250re-plan */\n"
"border-radius: 10px; /* Coins arrondis */\n"
"padding: 5px 10px; /* Espacement interne */\n"
"font: 75 15pt; /* Police avec un poids de 75 et taille de 15pt */\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/8051f3d1-c574-4c63-b54e-83dfdd52aa02-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_tri_desc->setIcon(icon5);
        pushButton_tri_desc->setIconSize(QSize(25, 25));
        comboBox_critereRecherche = new QComboBox(afficher);
        comboBox_critereRecherche->addItem(QString());
        comboBox_critereRecherche->addItem(QString());
        comboBox_critereRecherche->addItem(QString());
        comboBox_critereRecherche->addItem(QString());
        comboBox_critereRecherche->setObjectName("comboBox_critereRecherche");
        comboBox_critereRecherche->setGeometry(QRect(950, 70, 141, 31));
        comboBox_critereRecherche->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"QComboBox {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 3px;\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #ccc;\n"
"    border-radius: 0 5px 5px 0;\n"
"}"));
        comboBox_ordre = new QComboBox(afficher);
        comboBox_ordre->addItem(QString());
        comboBox_ordre->setObjectName("comboBox_ordre");
        comboBox_ordre->setGeometry(QRect(950, 200, 141, 31));
        comboBox_ordre->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBoxCritere = new QComboBox(afficher);
        comboBoxCritere->addItem(QString());
        comboBoxCritere->addItem(QString());
        comboBoxCritere->setObjectName("comboBoxCritere");
        comboBoxCritere->setGeometry(QRect(950, 280, 151, 31));
        comboBoxCritere->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_21 = new QLabel(afficher);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(890, 30, 241, 31));
        label_21->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        tabWidget->addTab(afficher, QString());
        groupBox_2->raise();
        lineEdit_critereRecherche->raise();
        pushButton_tri_desc->raise();
        pushButtonRechercher_met->raise();
        comboBox_critereRecherche->raise();
        comboBox_ordre->raise();
        comboBoxCritere->raise();
        label_21->raise();
        Ajouter = new QWidget();
        Ajouter->setObjectName("Ajouter");
        groupBox = new QGroupBox(Ajouter);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 1171, 671));
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("/* Style de base pour la QGroupBox */\n"
"QGroupBox {\n"
"    border: 4px solid #999DF2; /* Bordure de la m\303\252me couleur que le fond du titre */\n"
"    border-radius: 25px; /* Coins arrondis */\n"
"    margin-top: 10px; /* Marge en haut */\n"
"}\n"
"\n"
"/* Style du titre de la QGroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: #999DF2; /* Fond remplac\303\251 par #999DF2 */\n"
"    color: #ffffff; /* Texte blanc pour le titre */\n"
"    border-radius: 10px; /* Coins arrondis du titre */\n"
"\n"
"}\n"
"\n"
"/* Style des QLabel \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLabel {\n"
"    color: #000000; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QRadioButton \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QRadioButton {\n"
"    color: #333333; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QComboBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QComboBox {\n"
"    backg"
                        "round-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QLineEdit \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QSpinBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QSpinBox {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251"
                        "sactiv\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0; /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0; /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}"));
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 100, 131, 31));
        label->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 170, 131, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 240, 171, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(150, 310, 131, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(140, 380, 131, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(120, 440, 191, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_nom = new QLineEdit(groupBox);
        lineedit_nom->setObjectName("lineedit_nom");
        lineedit_nom->setGeometry(QRect(370, 90, 471, 51));
        lineedit_nom->setFont(font3);
        lineedit_nom->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_nom->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_prenom = new QLineEdit(groupBox);
        lineedit_prenom->setObjectName("lineedit_prenom");
        lineedit_prenom->setGeometry(QRect(370, 160, 471, 51));
        lineedit_prenom->setFont(font3);
        lineedit_prenom->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_prenom->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_adresse = new QLineEdit(groupBox);
        lineedit_adresse->setObjectName("lineedit_adresse");
        lineedit_adresse->setGeometry(QRect(370, 310, 471, 51));
        lineedit_adresse->setFont(font3);
        lineedit_adresse->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_adresse->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_tel = new QLineEdit(groupBox);
        lineedit_tel->setObjectName("lineedit_tel");
        lineedit_tel->setGeometry(QRect(370, 430, 471, 51));
        lineedit_tel->setFont(font3);
        lineedit_tel->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_tel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        radiobutton_homme = new QRadioButton(groupBox);
        radiobutton_homme->setObjectName("radiobutton_homme");
        radiobutton_homme->setGeometry(QRect(460, 380, 151, 31));
        radiobutton_homme->setFont(font3);
        radiobutton_homme->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        radiobutton_femme = new QRadioButton(groupBox);
        radiobutton_femme->setObjectName("radiobutton_femme");
        radiobutton_femme->setGeometry(QRect(670, 380, 151, 31));
        radiobutton_femme->setFont(font3);
        radiobutton_femme->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        pushButton_ajouter = new QPushButton(groupBox);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(450, 590, 221, 51));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
"QPushButton {\n"
"    background-color: #435AD9;  /* Bleu vif pour un look frais et moderne */\n"
"    color: #ffffff;              /* Texte blanc */\n"
"    border: 3px solid #435AD9;  /* Bordure de la m\303\252me couleur que le fond */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne */\n"
"    font: 75 18pt \"Times New Roman\"; /* Police en gras */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #5f7cd8;   /* Bleu plus clair au survol */\n"
"    border: 3px solid #5f7cd8;   /* Bordure de la m\303\252me couleur que le fond survol\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est press\303\251 (clic) */\n"
"QPushButton:pressed {\n"
"    background-color: #3b4fbf;   /* Bleu fonc\303\251 au clic */\n"
"    border: 3px solid #3b4fbf;   /* Bordure de la m\303\252me couleur que le fond press\303\251 */\n"
"}\n"
"\n"
"/* "
                        "Style du QPushButton lorsqu'il est en focus (tabulation) */\n"
"QPushButton:focus {\n"
"    outline: none;               /* Supprimer le contour par d\303\251faut */\n"
"    border: 2px solid #2e8a56;  /* Bordure plus fonc\303\251e lorsqu'en focus */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0;   /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070;              /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0;   /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sactiv\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0;   /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0;              /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}\n"
""));
        lineedit_cin = new QLineEdit(groupBox);
        lineedit_cin->setObjectName("lineedit_cin");
        lineedit_cin->setGeometry(QRect(370, 230, 471, 51));
        lineedit_cin->setFont(font3);
        lineedit_cin->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_cin->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(140, 520, 171, 31));
        label_13->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        lineedit_nationalite = new QLineEdit(groupBox);
        lineedit_nationalite->setObjectName("lineedit_nationalite");
        lineedit_nationalite->setGeometry(QRect(370, 510, 471, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(14);
        font4.setItalic(false);
        lineedit_nationalite->setFont(font4);
        lineedit_nationalite->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_nationalite->setMaxLength(32778);
        lineedit_nationalite->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tabWidget->addTab(Ajouter, QString());
        Modifier = new QWidget();
        Modifier->setObjectName("Modifier");
        groupBox_3 = new QGroupBox(Modifier);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 10, 1191, 671));
        groupBox_3->setFont(font1);
        groupBox_3->setStyleSheet(QString::fromUtf8("/* Style de base pour la QGroupBox */\n"
"QGroupBox {\n"
"    border: 4px solid #999DF2; /* Bordure de la m\303\252me couleur que le fond du titre */\n"
"    border-radius: 25px; /* Coins arrondis */\n"
"    margin-top: 10px; /* Marge en haut */\n"
"}\n"
"\n"
"/* Style du titre de la QGroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: #999DF2; /* Fond remplac\303\251 par #999DF2 */\n"
"    color: #ffffff; /* Texte blanc pour le titre */\n"
"    border-radius: 10px; /* Coins arrondis du titre */\n"
"}\n"
"\n"
"/* Style des QLabel \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLabel {\n"
"    color: #000000; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QRadioButton \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QRadioButton {\n"
"    color: #333333; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QComboBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QComboBox {\n"
"    background"
                        "-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QLineEdit \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QSpinBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QSpinBox {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sacti"
                        "v\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0; /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0; /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}"));
        groupBox_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 100, 131, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(70, 180, 131, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(50, 330, 181, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(70, 410, 141, 31));
        label_10->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(70, 470, 131, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 520, 191, 31));
        label_12->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_nom_modif = new QLineEdit(groupBox_3);
        lineedit_nom_modif->setObjectName("lineedit_nom_modif");
        lineedit_nom_modif->setGeometry(QRect(260, 90, 471, 51));
        lineedit_nom_modif->setFont(font3);
        lineedit_nom_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_nom_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_prenom_modif = new QLineEdit(groupBox_3);
        lineedit_prenom_modif->setObjectName("lineedit_prenom_modif");
        lineedit_prenom_modif->setGeometry(QRect(260, 180, 471, 51));
        lineedit_prenom_modif->setFont(font3);
        lineedit_prenom_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_prenom_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_adresse_modif = new QLineEdit(groupBox_3);
        lineedit_adresse_modif->setObjectName("lineedit_adresse_modif");
        lineedit_adresse_modif->setGeometry(QRect(260, 400, 471, 51));
        lineedit_adresse_modif->setFont(font3);
        lineedit_adresse_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_adresse_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_tel_modif = new QLineEdit(groupBox_3);
        lineedit_tel_modif->setObjectName("lineedit_tel_modif");
        lineedit_tel_modif->setGeometry(QRect(260, 520, 471, 51));
        lineedit_tel_modif->setFont(font3);
        lineedit_tel_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_tel_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        radiobutton_homme_modif = new QRadioButton(groupBox_3);
        radiobutton_homme_modif->setObjectName("radiobutton_homme_modif");
        radiobutton_homme_modif->setGeometry(QRect(270, 470, 151, 31));
        radiobutton_homme_modif->setFont(font3);
        radiobutton_homme_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        radiobutton_femme_modif = new QRadioButton(groupBox_3);
        radiobutton_femme_modif->setObjectName("radiobutton_femme_modif");
        radiobutton_femme_modif->setGeometry(QRect(510, 470, 151, 31));
        radiobutton_femme_modif->setFont(font3);
        radiobutton_femme_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        pushButton_modifier = new QPushButton(groupBox_3);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(420, 590, 221, 51));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
"QPushButton {\n"
"    background-color: #435AD9;  /* Bleu vif pour un look frais et moderne */\n"
"    color: #ffffff;              /* Texte blanc */\n"
"    border: 3px solid #435AD9;  /* Bordure de la m\303\252me couleur que le fond */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne */\n"
"    font: 75 18pt \"Times New Roman\"; /* Police en gras */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #5f7cd8;   /* Bleu plus clair au survol */\n"
"    border: 3px solid #5f7cd8;   /* Bordure de la m\303\252me couleur que le fond survol\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est press\303\251 (clic) */\n"
"QPushButton:pressed {\n"
"    background-color: #3b4fbf;   /* Bleu fonc\303\251 au clic */\n"
"    border: 3px solid #3b4fbf;   /* Bordure de la m\303\252me couleur que le fond press\303\251 */\n"
"}\n"
"\n"
"/* "
                        "Style du QPushButton lorsqu'il est en focus (tabulation) */\n"
"QPushButton:focus {\n"
"    outline: none;               /* Supprimer le contour par d\303\251faut */\n"
"    border: 2px solid #2e8a56;  /* Bordure plus fonc\303\251e lorsqu'en focus */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0;   /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070;              /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0;   /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sactiv\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0;   /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0;              /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}\n"
""));
        lineedit_id_modif = new QLineEdit(groupBox_3);
        lineedit_id_modif->setObjectName("lineedit_id_modif");
        lineedit_id_modif->setGeometry(QRect(940, 250, 221, 51));
        lineedit_id_modif->setFont(font3);
        lineedit_id_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_id_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(770, 250, 141, 31));
        label_15->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_15->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(760, 160, 371, 31));
        label_16->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_rechercher2 = new QPushButton(groupBox_3);
        pushButton_rechercher2->setObjectName("pushButton_rechercher2");
        pushButton_rechercher2->setGeometry(QRect(840, 360, 221, 51));
        pushButton_rechercher2->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
"QPushButton {\n"
"    background-color: #435AD9;  /* Bleu vif pour un look frais et moderne */\n"
"    color: #ffffff;              /* Texte blanc */\n"
"    border: 3px solid #435AD9;  /* Bordure de la m\303\252me couleur que le fond */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne */\n"
"    font: 75 18pt \"Times New Roman\"; /* Police en gras */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #5f7cd8;   /* Bleu plus clair au survol */\n"
"    border: 3px solid #5f7cd8;   /* Bordure de la m\303\252me couleur que le fond survol\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est press\303\251 (clic) */\n"
"QPushButton:pressed {\n"
"    background-color: #3b4fbf;   /* Bleu fonc\303\251 au clic */\n"
"    border: 3px solid #3b4fbf;   /* Bordure de la m\303\252me couleur que le fond press\303\251 */\n"
"}\n"
"\n"
"/* "
                        "Style du QPushButton lorsqu'il est en focus (tabulation) */\n"
"QPushButton:focus {\n"
"    outline: none;               /* Supprimer le contour par d\303\251faut */\n"
"    border: 2px solid #2e8a56;  /* Bordure plus fonc\303\251e lorsqu'en focus */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0;   /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070;              /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0;   /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sactiv\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0;   /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0;              /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}\n"
""));
        lineedit_nationalite_modif = new QLineEdit(groupBox_3);
        lineedit_nationalite_modif->setObjectName("lineedit_nationalite_modif");
        lineedit_nationalite_modif->setGeometry(QRect(260, 320, 471, 51));
        lineedit_nationalite_modif->setFont(font3);
        lineedit_nationalite_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_nationalite_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(90, 270, 63, 20));
        label_26->setFont(font2);
        lineedit_cin_modif = new QLineEdit(groupBox_3);
        lineedit_cin_modif->setObjectName("lineedit_cin_modif");
        lineedit_cin_modif->setGeometry(QRect(260, 250, 471, 51));
        lineedit_cin_modif->setFont(font3);
        lineedit_cin_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_cin_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tabWidget->addTab(Modifier, QString());
        supprimer = new QWidget();
        supprimer->setObjectName("supprimer");
        groupBox_7 = new QGroupBox(supprimer);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(10, 10, 1191, 671));
        groupBox_7->setFont(font1);
        groupBox_7->setStyleSheet(QString::fromUtf8("/* Style de base pour la QGroupBox */\n"
"QGroupBox {\n"
"    border: 4px solid #999DF2; /* Bordure de la m\303\252me couleur que le fond du titre */\n"
"    border-radius: 25px; /* Coins arrondis */\n"
"    margin-top: 10px; /* Marge en haut */\n"
"}\n"
"\n"
"/* Style du titre de la QGroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: #999DF2; /* Fond remplac\303\251 par #999DF2 */\n"
"    color: #ffffff; /* Texte blanc pour le titre */\n"
"    border-radius: 10px; /* Coins arrondis du titre */\n"
"}\n"
"\n"
"/* Style des QLabel \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLabel {\n"
"    color: #000000; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QRadioButton \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QRadioButton {\n"
"    color: #333333; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QComboBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QComboBox {\n"
"    background"
                        "-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QLineEdit \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QSpinBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QSpinBox {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sacti"
                        "v\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0; /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0; /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}"));
        groupBox_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_41 = new QLabel(groupBox_7);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(70, 110, 131, 31));
        label_41->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_41->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_42 = new QLabel(groupBox_7);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(70, 180, 131, 31));
        label_42->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_42->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_43 = new QLabel(groupBox_7);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(30, 320, 201, 31));
        label_43->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_43->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_45 = new QLabel(groupBox_7);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(60, 380, 131, 31));
        label_45->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_45->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_nom_supp = new QLineEdit(groupBox_7);
        lineedit_nom_supp->setObjectName("lineedit_nom_supp");
        lineedit_nom_supp->setGeometry(QRect(260, 100, 471, 51));
        lineedit_nom_supp->setFont(font3);
        lineedit_nom_supp->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_nom_supp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_nom_supp->setReadOnly(false);
        lineedit_prenom_supp = new QLineEdit(groupBox_7);
        lineedit_prenom_supp->setObjectName("lineedit_prenom_supp");
        lineedit_prenom_supp->setGeometry(QRect(260, 170, 471, 51));
        lineedit_prenom_supp->setFont(font3);
        lineedit_prenom_supp->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_prenom_supp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_prenom_supp->setReadOnly(false);
        pushButton_supprimer = new QPushButton(groupBox_7);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(400, 570, 221, 51));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
"QPushButton {\n"
"    background-color: #435AD9;  /* Bleu vif pour un look frais et moderne */\n"
"    color: #ffffff;              /* Texte blanc */\n"
"    border: 3px solid #435AD9;  /* Bordure de la m\303\252me couleur que le fond */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne */\n"
"    font: 75 18pt \"Times New Roman\"; /* Police en gras */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #5f7cd8;   /* Bleu plus clair au survol */\n"
"    border: 3px solid #5f7cd8;   /* Bordure de la m\303\252me couleur que le fond survol\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est press\303\251 (clic) */\n"
"QPushButton:pressed {\n"
"    background-color: #3b4fbf;   /* Bleu fonc\303\251 au clic */\n"
"    border: 3px solid #3b4fbf;   /* Bordure de la m\303\252me couleur que le fond press\303\251 */\n"
"}\n"
"\n"
"/* "
                        "Style du QPushButton lorsqu'il est en focus (tabulation) */\n"
"QPushButton:focus {\n"
"    outline: none;               /* Supprimer le contour par d\303\251faut */\n"
"    border: 2px solid #2e8a56;  /* Bordure plus fonc\303\251e lorsqu'en focus */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0;   /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070;              /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0;   /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sactiv\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0;   /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0;              /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}\n"
""));
        lineedit_id_rech = new QLineEdit(groupBox_7);
        lineedit_id_rech->setObjectName("lineedit_id_rech");
        lineedit_id_rech->setGeometry(QRect(900, 250, 221, 51));
        lineedit_id_rech->setFont(font3);
        lineedit_id_rech->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_id_rech->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_48 = new QLabel(groupBox_7);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(770, 260, 111, 31));
        label_48->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_48->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_49 = new QLabel(groupBox_7);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(740, 190, 391, 31));
        label_49->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_49->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_rechercher = new QPushButton(groupBox_7);
        pushButton_rechercher->setObjectName("pushButton_rechercher");
        pushButton_rechercher->setGeometry(QRect(850, 340, 221, 51));
        pushButton_rechercher->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
"QPushButton {\n"
"    background-color: #435AD9;  /* Bleu vif pour un look frais et moderne */\n"
"    color: #ffffff;              /* Texte blanc */\n"
"    border: 3px solid #435AD9;  /* Bordure de la m\303\252me couleur que le fond */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne */\n"
"    font: 75 18pt \"Times New Roman\"; /* Police en gras */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #5f7cd8;   /* Bleu plus clair au survol */\n"
"    border: 3px solid #5f7cd8;   /* Bordure de la m\303\252me couleur que le fond survol\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est press\303\251 (clic) */\n"
"QPushButton:pressed {\n"
"    background-color: #3b4fbf;   /* Bleu fonc\303\251 au clic */\n"
"    border: 3px solid #3b4fbf;   /* Bordure de la m\303\252me couleur que le fond press\303\251 */\n"
"}\n"
"\n"
"/* "
                        "Style du QPushButton lorsqu'il est en focus (tabulation) */\n"
"QPushButton:focus {\n"
"    outline: none;               /* Supprimer le contour par d\303\251faut */\n"
"    border: 2px solid #2e8a56;  /* Bordure plus fonc\303\251e lorsqu'en focus */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0;   /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070;              /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0;   /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sactiv\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0;   /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0;              /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}\n"
""));
        lineedit_nationalite_supp = new QLineEdit(groupBox_7);
        lineedit_nationalite_supp->setObjectName("lineedit_nationalite_supp");
        lineedit_nationalite_supp->setGeometry(QRect(260, 310, 471, 51));
        lineedit_nationalite_supp->setFont(font3);
        lineedit_nationalite_supp->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_nationalite_supp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_nationalite_supp->setReadOnly(false);
        label_24 = new QLabel(groupBox_7);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(60, 440, 151, 41));
        label_24->setFont(font2);
        label_25 = new QLabel(groupBox_7);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(50, 510, 171, 31));
        label_25->setFont(font2);
        lineedit_adresse_supp = new QLineEdit(groupBox_7);
        lineedit_adresse_supp->setObjectName("lineedit_adresse_supp");
        lineedit_adresse_supp->setGeometry(QRect(260, 440, 471, 51));
        lineedit_adresse_supp->setFont(font3);
        lineedit_adresse_supp->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_adresse_supp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineedit_tel_supp = new QLineEdit(groupBox_7);
        lineedit_tel_supp->setObjectName("lineedit_tel_supp");
        lineedit_tel_supp->setGeometry(QRect(260, 510, 471, 51));
        lineedit_tel_supp->setFont(font3);
        lineedit_tel_supp->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_tel_supp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        radioButton_homme_supp = new QRadioButton(groupBox_7);
        radioButton_homme_supp->setObjectName("radioButton_homme_supp");
        radioButton_homme_supp->setGeometry(QRect(320, 380, 110, 24));
        radioButton_homme_supp->setFont(font3);
        radioButton_femme_supp = new QRadioButton(groupBox_7);
        radioButton_femme_supp->setObjectName("radioButton_femme_supp");
        radioButton_femme_supp->setGeometry(QRect(570, 380, 110, 24));
        radioButton_femme_supp->setFont(font3);
        lineedit_cin_supp = new QLineEdit(groupBox_7);
        lineedit_cin_supp->setObjectName("lineedit_cin_supp");
        lineedit_cin_supp->setGeometry(QRect(260, 240, 471, 51));
        lineedit_cin_supp->setFont(font3);
        lineedit_cin_supp->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineedit_cin_supp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_27 = new QLabel(groupBox_7);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(100, 260, 141, 31));
        label_27->setFont(font2);
        tabWidget->addTab(supprimer, QString());
        Mailing = new QWidget();
        Mailing->setObjectName("Mailing");
        groupBox_4 = new QGroupBox(Mailing);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 10, 1191, 671));
        groupBox_4->setFont(font1);
        groupBox_4->setStyleSheet(QString::fromUtf8("/* Style de base pour la QGroupBox */\n"
"QGroupBox {\n"
"    border: 4px solid #999DF2; /* Bordure de la m\303\252me couleur que le fond du titre */\n"
"    border-radius: 25px; /* Coins arrondis */\n"
"    margin-top: 10px; /* Marge en haut */\n"
"}\n"
"\n"
"/* Style du titre de la QGroupBox */\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: #999DF2; /* Fond remplac\303\251 par #999DF2 */\n"
"    color: #ffffff; /* Texte blanc pour le titre */\n"
"    border-radius: 10px; /* Coins arrondis du titre */\n"
"}\n"
"\n"
"/* Style des QLabel \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLabel {\n"
"    color: #000000; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QRadioButton \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QRadioButton {\n"
"    color: #333333; /* Couleur du texte */\n"
"}\n"
"\n"
"/* Style des QComboBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QComboBox {\n"
"    background"
                        "-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QLineEdit \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style des QSpinBox \303\240 l'int\303\251rieur de la QGroupBox */\n"
"QSpinBox {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    color: #333333; /* Couleur du texte */\n"
"    border: 1px solid #3498db; /* Bordure bleue */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    padding: 2px; /* Espacement interne */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sacti"
                        "v\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0; /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0; /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}"));
        groupBox_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEditRecipient = new QLineEdit(groupBox_4);
        lineEditRecipient->setObjectName("lineEditRecipient");
        lineEditRecipient->setGeometry(QRect(440, 200, 311, 31));
        lineEditRecipient->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        lineEditSubject = new QLineEdit(groupBox_4);
        lineEditSubject->setObjectName("lineEditSubject");
        lineEditSubject->setGeometry(QRect(440, 300, 311, 31));
        lineEditSubject->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        pushButtonSend = new QPushButton(groupBox_4);
        pushButtonSend->setObjectName("pushButtonSend");
        pushButtonSend->setGeometry(QRect(530, 440, 141, 51));
        pushButtonSend->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
"QPushButton {\n"
"    background-color: #435AD9;  /* Bleu vif pour un look frais et moderne */\n"
"    color: #ffffff;              /* Texte blanc */\n"
"    border: 3px solid #435AD9;  /* Bordure de la m\303\252me couleur que le fond */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne */\n"
"    font: 75 18pt \"Times New Roman\"; /* Police en gras */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #5f7cd8;   /* Bleu plus clair au survol */\n"
"    border: 3px solid #5f7cd8;   /* Bordure de la m\303\252me couleur que le fond survol\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est press\303\251 (clic) */\n"
"QPushButton:pressed {\n"
"    background-color: #3b4fbf;   /* Bleu fonc\303\251 au clic */\n"
"    border: 3px solid #3b4fbf;   /* Bordure de la m\303\252me couleur que le fond press\303\251 */\n"
"}\n"
"\n"
"/* "
                        "Style du QPushButton lorsqu'il est en focus (tabulation) */\n"
"QPushButton:focus {\n"
"    outline: none;               /* Supprimer le contour par d\303\251faut */\n"
"    border: 2px solid #2e8a56;  /* Bordure plus fonc\303\251e lorsqu'en focus */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0;   /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070;              /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0;   /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
"\n"
"/* Style g\303\251n\303\251ral pour les widgets lorsqu'ils sont d\303\251sactiv\303\251s */\n"
"QWidget:disabled {\n"
"    background-color: #f0f0f0;   /* Fond gris clair pour les widgets d\303\251sactiv\303\251s */\n"
"    color: #a0a0a0;              /* Couleur du texte grise pour les widgets d\303\251sactiv\303\251s */\n"
"}\n"
""));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(270, 190, 141, 31));
        label_17->setFont(font2);
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(310, 300, 101, 31));
        label_18->setFont(font2);
        tabWidget->addTab(Mailing, QString());
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 370, 261, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("/* Bouton non s\303\251lectionn\303\251 */\n"
"QPushButton {\n"
"    background-color: #353FF2;  /* Bleu vif pour un look attrayant */\n"
"    color: #FFFFFF;             /* Texte en blanc */\n"
"    border: 3px solid #2A2DAC;  /* Bordure bleu fonc\303\251 pour un bon contraste */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18pt \"Arial\";      /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Bouton s\303\251lectionn\303\251 */\n"
"QPushButton:checked {\n"
"    background-color: #2A2DAC;  /* Bleu plus fonc\303\251 pour bouton s\303\251lectionn\303\251 */\n"
"    color: #FFFFFF;              /* Texte en blanc */\n"
"    border: 3px solid #353FF2;   /* Bordure bleu vif */\n"
"    border-radius: 12px;         /* Coins arrondis */\n"
"    padding: 8px 12px;           /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18"
                        "pt \"Arial\";       /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #4A5BCC;   /* Bleu clair au survol */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0; /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070; /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0; /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
""));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(10, 510, 261, 51));
        pushButton_11->setStyleSheet(QString::fromUtf8("/* Bouton non s\303\251lectionn\303\251 */\n"
"QPushButton {\n"
"    background-color: #353FF2;  /* Bleu vif pour un look attrayant */\n"
"    color: #FFFFFF;             /* Texte en blanc */\n"
"    border: 3px solid #2A2DAC;  /* Bordure bleu fonc\303\251 pour un bon contraste */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18pt \"Arial\";      /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Bouton s\303\251lectionn\303\251 */\n"
"QPushButton:checked {\n"
"    background-color: #2A2DAC;  /* Bleu plus fonc\303\251 pour bouton s\303\251lectionn\303\251 */\n"
"    color: #FFFFFF;              /* Texte en blanc */\n"
"    border: 3px solid #353FF2;   /* Bordure bleu vif */\n"
"    border-radius: 12px;         /* Coins arrondis */\n"
"    padding: 8px 12px;           /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18"
                        "pt \"Arial\";       /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #4A5BCC;   /* Bleu clair au survol */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0; /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070; /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0; /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
""));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(10, 440, 261, 51));
        pushButton_9->setStyleSheet(QString::fromUtf8("/* Bouton non s\303\251lectionn\303\251 */\n"
"QPushButton {\n"
"    background-color: #353FF2;  /* Bleu vif pour un look attrayant */\n"
"    color: #FFFFFF;             /* Texte en blanc */\n"
"    border: 3px solid #2A2DAC;  /* Bordure bleu fonc\303\251 pour un bon contraste */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18pt \"Arial\";      /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Bouton s\303\251lectionn\303\251 */\n"
"QPushButton:checked {\n"
"    background-color: #2A2DAC;  /* Bleu plus fonc\303\251 pour bouton s\303\251lectionn\303\251 */\n"
"    color: #FFFFFF;              /* Texte en blanc */\n"
"    border: 3px solid #353FF2;   /* Bordure bleu vif */\n"
"    border-radius: 12px;         /* Coins arrondis */\n"
"    padding: 8px 12px;           /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18"
                        "pt \"Arial\";       /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #4A5BCC;   /* Bleu clair au survol */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0; /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070; /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0; /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
""));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(10, 300, 261, 51));
        pushButton_6->setStyleSheet(QString::fromUtf8("/* Bouton non s\303\251lectionn\303\251 */\n"
"QPushButton {\n"
"    background-color: #353FF2;  /* Bleu vif pour un look attrayant */\n"
"    color: #FFFFFF;             /* Texte en blanc */\n"
"    border: 3px solid #2A2DAC;  /* Bordure bleu fonc\303\251 pour un bon contraste */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18pt \"Arial\";      /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Bouton s\303\251lectionn\303\251 */\n"
"QPushButton:checked {\n"
"    background-color: #2A2DAC;  /* Bleu plus fonc\303\251 pour bouton s\303\251lectionn\303\251 */\n"
"    color: #FFFFFF;              /* Texte en blanc */\n"
"    border: 3px solid #353FF2;   /* Bordure bleu vif */\n"
"    border-radius: 12px;         /* Coins arrondis */\n"
"    padding: 8px 12px;           /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18"
                        "pt \"Arial\";       /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #4A5BCC;   /* Bleu clair au survol */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0; /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070; /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0; /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
""));
        pushButton_menu = new QPushButton(centralwidget);
        pushButton_menu->setObjectName("pushButton_menu");
        pushButton_menu->setGeometry(QRect(10, 230, 261, 51));
        pushButton_menu->setStyleSheet(QString::fromUtf8("/* Bouton non s\303\251lectionn\303\251 */\n"
"QPushButton {\n"
"    background-color: #353FF2;  /* Bleu vif pour un look attrayant */\n"
"    color: #FFFFFF;             /* Texte en blanc */\n"
"    border: 3px solid #2A2DAC;  /* Bordure bleu fonc\303\251 pour un bon contraste */\n"
"    border-radius: 12px;        /* Coins arrondis */\n"
"    padding: 8px 12px;          /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18pt \"Arial\";      /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Bouton s\303\251lectionn\303\251 */\n"
"QPushButton:checked {\n"
"    background-color: #2A2DAC;  /* Bleu plus fonc\303\251 pour bouton s\303\251lectionn\303\251 */\n"
"    color: #FFFFFF;              /* Texte en blanc */\n"
"    border: 3px solid #353FF2;   /* Bordure bleu vif */\n"
"    border-radius: 12px;         /* Coins arrondis */\n"
"    padding: 8px 12px;           /* Espacement interne, augment\303\251 pour plus de confort */\n"
"    font: 75 18"
                        "pt \"Arial\";       /* Police en gras, taille 18pt pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #4A5BCC;   /* Bleu clair au survol */\n"
"}\n"
"\n"
"/* Style du QPushButton lorsqu'il est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #b0b0b0; /* Fond gris clair pour les boutons d\303\251sactiv\303\251s */\n"
"    color: #707070; /* Couleur du texte grise pour les boutons d\303\251sactiv\303\251s */\n"
"    border: 2px solid #b0b0b0; /* Bordure grise pour les boutons d\303\251sactiv\303\251s */\n"
"}\n"
""));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 10, 241, 211));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/res/y.png)"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1920, 26));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "liste des clients", nullptr));
        pushButton_afficher->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Afficher les statistiques des clients par:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Trier la liste des clients par:", nullptr));
        pushButton_trierParNom->setText(QString());
        pushButton_export_pdf->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "Le client le plus fid\303\250le:", nullptr));
        pushButton_client_fidele->setText(QString());
        label_29->setText(QCoreApplication::translate("MainWindow", "PDF:", nullptr));
        lineEdit_critereRecherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        pushButtonRechercher_met->setText(QString());
        pushButton_tri_desc->setText(QString());
        comboBox_critereRecherche->setItemText(0, QCoreApplication::translate("MainWindow", "IdClient", nullptr));
        comboBox_critereRecherche->setItemText(1, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox_critereRecherche->setItemText(2, QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        comboBox_critereRecherche->setItemText(3, QCoreApplication::translate("MainWindow", "CIN", nullptr));

        comboBox_ordre->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));

        comboBoxCritere->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir un critere", nullptr));
        comboBoxCritere->setItemText(1, QCoreApplication::translate("MainWindow", "Genre", nullptr));

        label_21->setText(QCoreApplication::translate("MainWindow", "Rechercher un client par:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(afficher), QCoreApplication::translate("MainWindow", "Liste", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom : ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Prenom : ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "CIN:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Adresse-mail:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Genre : ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Num t\303\251l\303\251phone  : ", nullptr));
        lineedit_nom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre nom ", nullptr));
        lineedit_prenom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre prenom ", nullptr));
        lineedit_adresse->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre adresse ", nullptr));
        lineedit_tel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre numero de t\303\251l\303\251phone ", nullptr));
        radiobutton_homme->setText(QCoreApplication::translate("MainWindow", "Homme", nullptr));
        radiobutton_femme->setText(QCoreApplication::translate("MainWindow", "Femme", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        lineedit_cin->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre idantifiant", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Nationalit\303\251:", nullptr));
        lineedit_nationalite->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre nationalit\303\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Ajouter), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nom : ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Prenom : ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Nationalit\303\251:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Adresse-mail :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Genre : ", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Num_t\303\251l\303\251phone  : ", nullptr));
        lineedit_nom_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Modifier le nom ", nullptr));
        lineedit_prenom_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Modifier le Prenom", nullptr));
        lineedit_adresse_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Modifier l'Adresse", nullptr));
        lineedit_tel_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre numero de t\303\251l\303\251phone ", nullptr));
        radiobutton_homme_modif->setText(QCoreApplication::translate("MainWindow", "Homme", nullptr));
        radiobutton_femme_modif->setText(QCoreApplication::translate("MainWindow", "Femme", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        lineedit_id_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par ID", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "ID_client :", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Rechercher le client \303\240 modifier par ID", nullptr));
        pushButton_rechercher2->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        lineedit_nationalite_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Modifier la nationalit\303\251", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "CIN:", nullptr));
        lineedit_cin_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Modifier CIN", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Modifier), QCoreApplication::translate("MainWindow", "Modifier ", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "Nom : ", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Prenom : ", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "Nationalit\303\251:", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Genre : ", nullptr));
        lineedit_nom_supp->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom \303\240 supprimer", nullptr));
        lineedit_prenom_supp->setPlaceholderText(QCoreApplication::translate("MainWindow", "Prenom \303\240 supprimer", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        lineedit_id_rech->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par ID", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "ID_client :", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "Rechercher le client \303\240 supprimer par ID", nullptr));
        pushButton_rechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        lineedit_nationalite_supp->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nationalit\303\251 \303\240 supprimer", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Adresse_mail:", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Num_t\303\251l\303\251phone:", nullptr));
        lineedit_adresse_supp->setPlaceholderText(QCoreApplication::translate("MainWindow", "L'adresse \303\240 supprimer", nullptr));
        lineedit_tel_supp->setPlaceholderText(QCoreApplication::translate("MainWindow", "Num \303\240 supprimer", nullptr));
        radioButton_homme_supp->setText(QCoreApplication::translate("MainWindow", "Homme", nullptr));
        radioButton_femme_supp->setText(QCoreApplication::translate("MainWindow", "Femme", nullptr));
        lineedit_cin_supp->setPlaceholderText(QCoreApplication::translate("MainWindow", "CIN \303\240 supprimer", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "CIN:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(supprimer), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Mailing", nullptr));
        lineEditRecipient->setText(QString());
        lineEditSubject->setText(QString());
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "destinataire:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "objet:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Mailing), QCoreApplication::translate("MainWindow", "Mailing", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Gestion Clients", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Gestion Services", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Gestion R\303\251servations", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Gestion Emply\303\251es", nullptr));
        pushButton_menu->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        label_14->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
