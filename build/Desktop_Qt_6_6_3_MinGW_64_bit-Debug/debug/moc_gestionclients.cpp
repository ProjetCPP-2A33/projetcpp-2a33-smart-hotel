/****************************************************************************
** Meta object code from reading C++ file 'gestionclients.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gestionclients.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestionclients.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_pushButton_trierParNom_clicked",
    "",
    "on_pushButton_trierParNom_3_clicked",
    "exportToPdf",
    "fileName",
    "on_pushButton_export_pdf_clicked",
    "createPieChart",
    "critere",
    "on_comboBoxCritere_currentIndexChanged",
    "on_pushButtonRechercher_met_clicked",
    "on_pushButton_afficher_clicked",
    "sendEmailWithPostmark",
    "verifyEmployeeID",
    "processEmployeeID",
    "employeeID",
    "on_pushButton_VerifyID_clicked",
    "on_ajouterButton_clicked",
    "on_supprimerButton_clicked",
    "on_modifierButton_clicked",
    "on_rechercherButton_clicked",
    "on_trierButton_clicked",
    "on_statistiqueButton_clicked",
    "on_statistiqueButton_2_clicked",
    "on_pb_pdf_clicked",
    "on_pb_historiqueService_clicked",
    "on_ButtonOuvrir_Clicked",
    "on_sendSMSButton_clicked",
    "envoyerSMS",
    "destinataire",
    "message",
    "on_pushButton_ajouter_clicked",
    "on_pushButton_supprimer_clicked",
    "on_pushButton_rechercher_clicked",
    "actualiserListeClients",
    "on_pushButton_modifier_clicked",
    "on_pushButton_rechercher2_clicked",
    "on_pushButtonSend_clicked",
    "on_pushButton_client_fidele_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[78];
    char stringdata0[11];
    char stringdata1[34];
    char stringdata2[1];
    char stringdata3[36];
    char stringdata4[12];
    char stringdata5[9];
    char stringdata6[33];
    char stringdata7[15];
    char stringdata8[8];
    char stringdata9[39];
    char stringdata10[36];
    char stringdata11[31];
    char stringdata12[22];
    char stringdata13[17];
    char stringdata14[18];
    char stringdata15[11];
    char stringdata16[31];
    char stringdata17[25];
    char stringdata18[27];
    char stringdata19[26];
    char stringdata20[28];
    char stringdata21[23];
    char stringdata22[29];
    char stringdata23[31];
    char stringdata24[18];
    char stringdata25[32];
    char stringdata26[24];
    char stringdata27[25];
    char stringdata28[11];
    char stringdata29[13];
    char stringdata30[8];
    char stringdata31[30];
    char stringdata32[32];
    char stringdata33[33];
    char stringdata34[23];
    char stringdata35[31];
    char stringdata36[34];
    char stringdata37[26];
    char stringdata38[36];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 33),  // "on_pushButton_trierParNom_cli..."
        QT_MOC_LITERAL(45, 0),  // ""
        QT_MOC_LITERAL(46, 35),  // "on_pushButton_trierParNom_3_c..."
        QT_MOC_LITERAL(82, 11),  // "exportToPdf"
        QT_MOC_LITERAL(94, 8),  // "fileName"
        QT_MOC_LITERAL(103, 32),  // "on_pushButton_export_pdf_clicked"
        QT_MOC_LITERAL(136, 14),  // "createPieChart"
        QT_MOC_LITERAL(151, 7),  // "critere"
        QT_MOC_LITERAL(159, 38),  // "on_comboBoxCritere_currentInd..."
        QT_MOC_LITERAL(198, 35),  // "on_pushButtonRechercher_met_c..."
        QT_MOC_LITERAL(234, 30),  // "on_pushButton_afficher_clicked"
        QT_MOC_LITERAL(265, 21),  // "sendEmailWithPostmark"
        QT_MOC_LITERAL(287, 16),  // "verifyEmployeeID"
        QT_MOC_LITERAL(304, 17),  // "processEmployeeID"
        QT_MOC_LITERAL(322, 10),  // "employeeID"
        QT_MOC_LITERAL(333, 30),  // "on_pushButton_VerifyID_clicked"
        QT_MOC_LITERAL(364, 24),  // "on_ajouterButton_clicked"
        QT_MOC_LITERAL(389, 26),  // "on_supprimerButton_clicked"
        QT_MOC_LITERAL(416, 25),  // "on_modifierButton_clicked"
        QT_MOC_LITERAL(442, 27),  // "on_rechercherButton_clicked"
        QT_MOC_LITERAL(470, 22),  // "on_trierButton_clicked"
        QT_MOC_LITERAL(493, 28),  // "on_statistiqueButton_clicked"
        QT_MOC_LITERAL(522, 30),  // "on_statistiqueButton_2_clicked"
        QT_MOC_LITERAL(553, 17),  // "on_pb_pdf_clicked"
        QT_MOC_LITERAL(571, 31),  // "on_pb_historiqueService_clicked"
        QT_MOC_LITERAL(603, 23),  // "on_ButtonOuvrir_Clicked"
        QT_MOC_LITERAL(627, 24),  // "on_sendSMSButton_clicked"
        QT_MOC_LITERAL(652, 10),  // "envoyerSMS"
        QT_MOC_LITERAL(663, 12),  // "destinataire"
        QT_MOC_LITERAL(676, 7),  // "message"
        QT_MOC_LITERAL(684, 29),  // "on_pushButton_ajouter_clicked"
        QT_MOC_LITERAL(714, 31),  // "on_pushButton_supprimer_clicked"
        QT_MOC_LITERAL(746, 32),  // "on_pushButton_rechercher_clicked"
        QT_MOC_LITERAL(779, 22),  // "actualiserListeClients"
        QT_MOC_LITERAL(802, 30),  // "on_pushButton_modifier_clicked"
        QT_MOC_LITERAL(833, 33),  // "on_pushButton_rechercher2_cli..."
        QT_MOC_LITERAL(867, 25),  // "on_pushButtonSend_clicked"
        QT_MOC_LITERAL(893, 35)   // "on_pushButton_client_fidele_c..."
    },
    "MainWindow",
    "on_pushButton_trierParNom_clicked",
    "",
    "on_pushButton_trierParNom_3_clicked",
    "exportToPdf",
    "fileName",
    "on_pushButton_export_pdf_clicked",
    "createPieChart",
    "critere",
    "on_comboBoxCritere_currentIndexChanged",
    "on_pushButtonRechercher_met_clicked",
    "on_pushButton_afficher_clicked",
    "sendEmailWithPostmark",
    "verifyEmployeeID",
    "processEmployeeID",
    "employeeID",
    "on_pushButton_VerifyID_clicked",
    "on_ajouterButton_clicked",
    "on_supprimerButton_clicked",
    "on_modifierButton_clicked",
    "on_rechercherButton_clicked",
    "on_trierButton_clicked",
    "on_statistiqueButton_clicked",
    "on_statistiqueButton_2_clicked",
    "on_pb_pdf_clicked",
    "on_pb_historiqueService_clicked",
    "on_ButtonOuvrir_Clicked",
    "on_sendSMSButton_clicked",
    "envoyerSMS",
    "destinataire",
    "message",
    "on_pushButton_ajouter_clicked",
    "on_pushButton_supprimer_clicked",
    "on_pushButton_rechercher_clicked",
    "actualiserListeClients",
    "on_pushButton_modifier_clicked",
    "on_pushButton_rechercher2_clicked",
    "on_pushButtonSend_clicked",
    "on_pushButton_client_fidele_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  206,    2, 0x0a,    1 /* Public */,
       3,    0,  207,    2, 0x0a,    2 /* Public */,
       4,    1,  208,    2, 0x0a,    3 /* Public */,
       6,    0,  211,    2, 0x0a,    5 /* Public */,
       7,    1,  212,    2, 0x0a,    6 /* Public */,
       9,    0,  215,    2, 0x0a,    8 /* Public */,
      10,    0,  216,    2, 0x0a,    9 /* Public */,
      11,    0,  217,    2, 0x0a,   10 /* Public */,
      12,    0,  218,    2, 0x0a,   11 /* Public */,
      13,    0,  219,    2, 0x0a,   12 /* Public */,
      14,    1,  220,    2, 0x0a,   13 /* Public */,
      16,    0,  223,    2, 0x0a,   15 /* Public */,
      17,    0,  224,    2, 0x0a,   16 /* Public */,
      18,    0,  225,    2, 0x0a,   17 /* Public */,
      19,    0,  226,    2, 0x0a,   18 /* Public */,
      20,    0,  227,    2, 0x0a,   19 /* Public */,
      21,    0,  228,    2, 0x0a,   20 /* Public */,
      22,    0,  229,    2, 0x0a,   21 /* Public */,
      23,    0,  230,    2, 0x0a,   22 /* Public */,
      24,    0,  231,    2, 0x0a,   23 /* Public */,
      25,    0,  232,    2, 0x0a,   24 /* Public */,
      26,    0,  233,    2, 0x0a,   25 /* Public */,
      27,    0,  234,    2, 0x0a,   26 /* Public */,
      28,    2,  235,    2, 0x0a,   27 /* Public */,
      31,    0,  240,    2, 0x08,   30 /* Private */,
      32,    0,  241,    2, 0x08,   31 /* Private */,
      33,    0,  242,    2, 0x08,   32 /* Private */,
      34,    0,  243,    2, 0x08,   33 /* Private */,
      35,    0,  244,    2, 0x08,   34 /* Private */,
      36,    0,  245,    2, 0x08,   35 /* Private */,
      37,    0,  246,    2, 0x08,   36 /* Private */,
      38,    0,  247,    2, 0x08,   37 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   29,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_pushButton_trierParNom_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_trierParNom_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exportToPdf'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_export_pdf_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createPieChart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_comboBoxCritere_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonRechercher_met_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_afficher_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendEmailWithPostmark'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'verifyEmployeeID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processEmployeeID'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_VerifyID_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ajouterButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_supprimerButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_modifierButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rechercherButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_trierButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_statistiqueButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_statistiqueButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_pdf_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_historiqueService_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ButtonOuvrir_Clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sendSMSButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'envoyerSMS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_ajouter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_supprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_rechercher_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'actualiserListeClients'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_modifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_rechercher2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSend_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_client_fidele_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_trierParNom_clicked(); break;
        case 1: _t->on_pushButton_trierParNom_3_clicked(); break;
        case 2: _t->exportToPdf((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_pushButton_export_pdf_clicked(); break;
        case 4: _t->createPieChart((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_comboBoxCritere_currentIndexChanged(); break;
        case 6: _t->on_pushButtonRechercher_met_clicked(); break;
        case 7: _t->on_pushButton_afficher_clicked(); break;
        case 8: _t->sendEmailWithPostmark(); break;
        case 9: _t->verifyEmployeeID(); break;
        case 10: { QString _r = _t->processEmployeeID((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->on_pushButton_VerifyID_clicked(); break;
        case 12: _t->on_ajouterButton_clicked(); break;
        case 13: _t->on_supprimerButton_clicked(); break;
        case 14: _t->on_modifierButton_clicked(); break;
        case 15: _t->on_rechercherButton_clicked(); break;
        case 16: _t->on_trierButton_clicked(); break;
        case 17: _t->on_statistiqueButton_clicked(); break;
        case 18: _t->on_statistiqueButton_2_clicked(); break;
        case 19: _t->on_pb_pdf_clicked(); break;
        case 20: _t->on_pb_historiqueService_clicked(); break;
        case 21: _t->on_ButtonOuvrir_Clicked(); break;
        case 22: _t->on_sendSMSButton_clicked(); break;
        case 23: _t->envoyerSMS((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 24: _t->on_pushButton_ajouter_clicked(); break;
        case 25: _t->on_pushButton_supprimer_clicked(); break;
        case 26: _t->on_pushButton_rechercher_clicked(); break;
        case 27: _t->actualiserListeClients(); break;
        case 28: _t->on_pushButton_modifier_clicked(); break;
        case 29: _t->on_pushButton_rechercher2_clicked(); break;
        case 30: _t->on_pushButtonSend_clicked(); break;
        case 31: _t->on_pushButton_client_fidele_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 32;
    }
    return _id;
}
QT_WARNING_POP
