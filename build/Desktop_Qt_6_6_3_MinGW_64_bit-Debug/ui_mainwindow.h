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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *pdf;
    QWidget *afficher;
    QGroupBox *TAB_E;
    QTableView *tab_affich_E;
    QLineEdit *lineEdit_critereRecherche;
    QComboBox *comboBox_critereRecherche;
    QPushButton *pushButton_afficher;
    QComboBox *comboBox_critereRech_2;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *pushButton_afficher_2;
    QWidget *Ajouter;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *numero;
    QPushButton *ajouter;
    QLineEdit *ide;
    QLabel *label_5;
    QLabel *label_27;
    QLineEdit *salaire;
    QDateEdit *datenaissance;
    QWidget *Modifier;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_12;
    QLineEdit *nom_modif;
    QLineEdit *prenom_modif;
    QLineEdit *numero_modif;
    QPushButton *modifier;
    QLabel *label_67;
    QDateEdit *datenaissance_modif;
    QLabel *label_61;
    QLineEdit *salaire_modif;
    QLabel *label_4;
    QLineEdit *ide_modif;
    QWidget *supprimer;
    QGroupBox *groupBox_7;
    QPushButton *supprimer_2;
    QLineEdit *id_supprimer;
    QLabel *label_48;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *stats;
    QWidget *tab_2;
    QPushButton *QrCode;
    QLabel *qrcodecommande_2;
    QLineEdit *qr_code_bar;
    QWidget *tab_3;
    QLabel *label_nome;
    QLabel *label_prenom;
    QPushButton *pushButton_4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_menu;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1477, 758);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgba(228, 234, 242, 255); /* Gris tr\303\250s clair */\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pdf = new QTabWidget(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setEnabled(true);
        pdf->setGeometry(QRect(290, 10, 1675, 935));
        pdf->setMinimumSize(QSize(1675, 0));
        pdf->setMaximumSize(QSize(1674, 935));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(20);
        pdf->setFont(font);
        pdf->setStyleSheet(QString::fromUtf8("/* Fond du QTabWidget */\n"
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
        pdf->setIconSize(QSize(16, 16));
        afficher = new QWidget();
        afficher->setObjectName("afficher");
        TAB_E = new QGroupBox(afficher);
        TAB_E->setObjectName("TAB_E");
        TAB_E->setGeometry(QRect(10, 20, 791, 461));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Trebuchet MS")});
        font1.setPointSize(24);
        font1.setBold(true);
        TAB_E->setFont(font1);
        TAB_E->setStyleSheet(QString::fromUtf8("/* Style de base pour la QGroupBox */\n"
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
        TAB_E->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tab_affich_E = new QTableView(TAB_E);
        tab_affich_E->setObjectName("tab_affich_E");
        tab_affich_E->setGeometry(QRect(20, 60, 741, 391));
        tab_affich_E->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
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
        lineEdit_critereRecherche = new QLineEdit(afficher);
        lineEdit_critereRecherche->setObjectName("lineEdit_critereRecherche");
        lineEdit_critereRecherche->setGeometry(QRect(820, 130, 231, 41));
        QFont font2;
        font2.setPointSize(14);
        lineEdit_critereRecherche->setFont(font2);
        lineEdit_critereRecherche->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 20px; "));
        lineEdit_critereRecherche->setAlignment(Qt::AlignmentFlag::AlignCenter);
        comboBox_critereRecherche = new QComboBox(afficher);
        comboBox_critereRecherche->addItem(QString());
        comboBox_critereRecherche->addItem(QString());
        comboBox_critereRecherche->addItem(QString());
        comboBox_critereRecherche->setObjectName("comboBox_critereRecherche");
        comboBox_critereRecherche->setGeometry(QRect(820, 80, 141, 31));
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
        pushButton_afficher = new QPushButton(afficher);
        pushButton_afficher->setObjectName("pushButton_afficher");
        pushButton_afficher->setGeometry(QRect(20, 490, 201, 51));
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
        comboBox_critereRech_2 = new QComboBox(afficher);
        comboBox_critereRech_2->addItem(QString());
        comboBox_critereRech_2->addItem(QString());
        comboBox_critereRech_2->setObjectName("comboBox_critereRech_2");
        comboBox_critereRech_2->setGeometry(QRect(820, 220, 141, 31));
        comboBox_critereRech_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_21 = new QLabel(afficher);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(820, 30, 241, 31));
        label_21->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_22 = new QLabel(afficher);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(820, 180, 281, 31));
        label_22->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        pushButton_afficher_2 = new QPushButton(afficher);
        pushButton_afficher_2->setObjectName("pushButton_afficher_2");
        pushButton_afficher_2->setGeometry(QRect(230, 490, 201, 51));
        pushButton_afficher_2->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
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
        pdf->addTab(afficher, QString());
        Ajouter = new QWidget();
        Ajouter->setObjectName("Ajouter");
        groupBox = new QGroupBox(Ajouter);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 991, 621));
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
        label->setGeometry(QRect(40, 60, 101, 31));
        label->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(480, 60, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 140, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 230, 141, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        nom = new QLineEdit(groupBox);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(150, 50, 331, 51));
        nom->setFont(font2);
        nom->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        nom->setAlignment(Qt::AlignmentFlag::AlignCenter);
        prenom = new QLineEdit(groupBox);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(570, 50, 301, 51));
        prenom->setFont(font2);
        prenom->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        prenom->setAlignment(Qt::AlignmentFlag::AlignCenter);
        numero = new QLineEdit(groupBox);
        numero->setObjectName("numero");
        numero->setGeometry(QRect(150, 220, 321, 51));
        numero->setFont(font2);
        numero->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        numero->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ajouter = new QPushButton(groupBox);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(370, 410, 221, 51));
        ajouter->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
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
        ide = new QLineEdit(groupBox);
        ide->setObjectName("ide");
        ide->setGeometry(QRect(150, 130, 331, 51));
        ide->setFont(font2);
        ide->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        ide->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(480, 140, 171, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_27 = new QLabel(groupBox);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(50, 300, 91, 31));
        label_27->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        salaire = new QLineEdit(groupBox);
        salaire->setObjectName("salaire");
        salaire->setGeometry(QRect(150, 290, 321, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(14);
        font3.setItalic(false);
        salaire->setFont(font3);
        salaire->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        salaire->setMaxLength(32778);
        salaire->setAlignment(Qt::AlignmentFlag::AlignCenter);
        datenaissance = new QDateEdit(groupBox);
        datenaissance->setObjectName("datenaissance");
        datenaissance->setGeometry(QRect(670, 130, 191, 41));
        pdf->addTab(Ajouter, QString());
        Modifier = new QWidget();
        Modifier->setObjectName("Modifier");
        groupBox_3 = new QGroupBox(Modifier);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 0, 911, 451));
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
        label_7->setGeometry(QRect(20, 60, 131, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(430, 60, 131, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 140, 191, 31));
        label_12->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        nom_modif = new QLineEdit(groupBox_3);
        nom_modif->setObjectName("nom_modif");
        nom_modif->setGeometry(QRect(130, 50, 301, 51));
        nom_modif->setFont(font2);
        nom_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        nom_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        prenom_modif = new QLineEdit(groupBox_3);
        prenom_modif->setObjectName("prenom_modif");
        prenom_modif->setGeometry(QRect(530, 50, 351, 51));
        prenom_modif->setFont(font2);
        prenom_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        prenom_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        numero_modif = new QLineEdit(groupBox_3);
        numero_modif->setObjectName("numero_modif");
        numero_modif->setGeometry(QRect(180, 130, 301, 51));
        numero_modif->setFont(font2);
        numero_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        numero_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        modifier = new QPushButton(groupBox_3);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(570, 220, 221, 51));
        modifier->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
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
        label_67 = new QLabel(groupBox_3);
        label_67->setObjectName("label_67");
        label_67->setGeometry(QRect(20, 230, 171, 31));
        label_67->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_67->setAlignment(Qt::AlignmentFlag::AlignCenter);
        datenaissance_modif = new QDateEdit(groupBox_3);
        datenaissance_modif->setObjectName("datenaissance_modif");
        datenaissance_modif->setGeometry(QRect(190, 220, 221, 41));
        datenaissance_modif->setStyleSheet(QString::fromUtf8("\n"
"                                                    QDateEdit{\n"
"                                                    background-color: #ffffff; /* Fond blanc */\n"
"                                                    color: #333333; /* Couleur du texte */\n"
"                                                    border: 1px solid #3498db; /* Bordure bleue */\n"
"                                                    border-radius: 3px; /* Coins arrondis */\n"
"                                                     padding: 2px; /* Espacement interne */\n"
"                                                     border-radius :15px\n"
"                                                    }\n"
"                                                  "));
        label_61 = new QLabel(groupBox_3);
        label_61->setObjectName("label_61");
        label_61->setGeometry(QRect(50, 310, 111, 31));
        label_61->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        salaire_modif = new QLineEdit(groupBox_3);
        salaire_modif->setObjectName("salaire_modif");
        salaire_modif->setGeometry(QRect(160, 300, 331, 51));
        salaire_modif->setFont(font3);
        salaire_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        salaire_modif->setMaxLength(32778);
        salaire_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(480, 140, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ide_modif = new QLineEdit(groupBox_3);
        ide_modif->setObjectName("ide_modif");
        ide_modif->setGeometry(QRect(560, 130, 331, 51));
        ide_modif->setFont(font2);
        ide_modif->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        ide_modif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pdf->addTab(Modifier, QString());
        supprimer = new QWidget();
        supprimer->setObjectName("supprimer");
        groupBox_7 = new QGroupBox(supprimer);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(10, 10, 751, 381));
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
        supprimer_2 = new QPushButton(groupBox_7);
        supprimer_2->setObjectName("supprimer_2");
        supprimer_2->setGeometry(QRect(230, 230, 221, 51));
        supprimer_2->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
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
        id_supprimer = new QLineEdit(groupBox_7);
        id_supprimer->setObjectName("id_supprimer");
        id_supprimer->setGeometry(QRect(230, 130, 221, 51));
        id_supprimer->setFont(font2);
        id_supprimer->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        id_supprimer->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_48 = new QLabel(groupBox_7);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(80, 140, 151, 31));
        label_48->setStyleSheet(QString::fromUtf8("font: italic 14pt \"Times New Roman\";\n"
"border-radius :15px"));
        label_48->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pdf->addTab(supprimer, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 50, 701, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stats = new QPushButton(tab);
        stats->setObjectName("stats");
        stats->setGeometry(QRect(340, 340, 161, 51));
        stats->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
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
        pdf->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        QrCode = new QPushButton(tab_2);
        QrCode->setObjectName("QrCode");
        QrCode->setGeometry(QRect(270, 530, 161, 51));
        QrCode->setStyleSheet(QString::fromUtf8("/* Style de base pour le QPushButton */\n"
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
        qrcodecommande_2 = new QLabel(tab_2);
        qrcodecommande_2->setObjectName("qrcodecommande_2");
        qrcodecommande_2->setGeometry(QRect(200, 60, 531, 441));
        qr_code_bar = new QLineEdit(tab_2);
        qr_code_bar->setObjectName("qr_code_bar");
        qr_code_bar->setGeometry(QRect(450, 530, 331, 51));
        qr_code_bar->setFont(font2);
        qr_code_bar->setStyleSheet(QString::fromUtf8("border-radius :15px"));
        qr_code_bar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pdf->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label_nome = new QLabel(tab_3);
        label_nome->setObjectName("label_nome");
        label_nome->setGeometry(QRect(240, 125, 111, 31));
        label_prenom = new QLabel(tab_3);
        label_prenom->setObjectName("label_prenom");
        label_prenom->setGeometry(QRect(480, 120, 111, 31));
        pdf->addTab(tab_3, QString());
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 320, 261, 51));
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
        pushButton_11->setGeometry(QRect(10, 440, 261, 51));
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
        pushButton_9->setGeometry(QRect(10, 380, 261, 51));
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
        pushButton_6->setGeometry(QRect(10, 260, 261, 51));
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
        pushButton_menu->setGeometry(QRect(10, 190, 261, 51));
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
        label_14->setGeometry(QRect(20, -30, 241, 211));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/res/y.png)"));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(80, 500, 101, 41));
        label_17->setStyleSheet(QString::fromUtf8("image: url(:/res/vv-removebg-preview.png)\n"
""));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(90, 550, 81, 41));
        label_18->setStyleSheet(QString::fromUtf8("image: url(:/res/pp-removebg-preview.png)"));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(90, 590, 81, 51));
        label_19->setStyleSheet(QString::fromUtf8("image: url(:/res/n-removebg-preview.png)"));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(90, 640, 81, 51));
        label_20->setStyleSheet(QString::fromUtf8("image: url(:/res/www-removebg-preview.png)"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1477, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        pdf->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        TAB_E->setTitle(QCoreApplication::translate("MainWindow", "liste des Employ\303\251s", nullptr));
        lineEdit_critereRecherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        comboBox_critereRecherche->setItemText(0, QCoreApplication::translate("MainWindow", "id", nullptr));
        comboBox_critereRecherche->setItemText(1, QCoreApplication::translate("MainWindow", "numero", nullptr));
        comboBox_critereRecherche->setItemText(2, QCoreApplication::translate("MainWindow", "nom", nullptr));

        pushButton_afficher->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        comboBox_critereRech_2->setItemText(0, QCoreApplication::translate("MainWindow", "id", nullptr));
        comboBox_critereRech_2->setItemText(1, QCoreApplication::translate("MainWindow", "nom", nullptr));

        label_21->setText(QCoreApplication::translate("MainWindow", "Rechercher un Employe par:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Trier la liste des clients par:", nullptr));
        pushButton_afficher_2->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pdf->setTabText(pdf->indexOf(afficher), QCoreApplication::translate("MainWindow", "Liste", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom : ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Prenom : ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Id_e:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Num t\303\251l\303\251phone  : ", nullptr));
        nom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre nom ", nullptr));
        prenom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre prenom ", nullptr));
        numero->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre numero de t\303\251l\303\251phone ", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter ", nullptr));
        ide->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre idantifiant", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Date de naissance:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Salaire:", nullptr));
        salaire->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre Salaire", nullptr));
        pdf->setTabText(pdf->indexOf(Ajouter), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nom : ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Prenom : ", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Num_t\303\251l\303\251phone  : ", nullptr));
        nom_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Modifier le nom ", nullptr));
        prenom_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Modifier le Prenom", nullptr));
        numero_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Modifier le numero de t\303\251l\303\251phone ", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_67->setText(QCoreApplication::translate("MainWindow", "Date de naissance:", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "Salaire:", nullptr));
        salaire_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Modifier le Salaire", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Id_e:", nullptr));
        ide_modif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre idantifiant", nullptr));
        pdf->setTabText(pdf->indexOf(Modifier), QCoreApplication::translate("MainWindow", "Modifier ", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        supprimer_2->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        id_supprimer->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par ID", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "ID_e :", nullptr));
        pdf->setTabText(pdf->indexOf(supprimer), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        stats->setText(QCoreApplication::translate("MainWindow", "Stats", nullptr));
        pdf->setTabText(pdf->indexOf(tab), QCoreApplication::translate("MainWindow", "statistiques ", nullptr));
        QrCode->setText(QCoreApplication::translate("MainWindow", "QrCode", nullptr));
        qrcodecommande_2->setText(QString());
        qr_code_bar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez votre idantifiant", nullptr));
        pdf->setTabText(pdf->indexOf(tab_2), QCoreApplication::translate("MainWindow", "QrCode", nullptr));
        label_nome->setText(QCoreApplication::translate("MainWindow", "afficher nom", nullptr));
        label_prenom->setText(QCoreApplication::translate("MainWindow", "afficher prenom", nullptr));
        pdf->setTabText(pdf->indexOf(tab_3), QCoreApplication::translate("MainWindow", "ardui", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Gestion Clients", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Gestion Services", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Gestion R\303\251servations", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Gestion Emply\303\251es", nullptr));
        pushButton_menu->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        label_14->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
        label_20->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
