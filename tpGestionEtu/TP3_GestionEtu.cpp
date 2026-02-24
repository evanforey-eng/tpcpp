#include "TP3_GestionEtu.h"
#include <QDir>

TP3_GestionEtu::TP3_GestionEtu(QWidget *parent)
    : QMainWindow(parent), promo(nullptr)
{
    ui.setupUi(this);

    // Create Promotion
    promo = new Promotion( QDir::currentPath()+"/../data/promoDUT.csv");


    // Create Views and add connectors
    listView = new ViewList(promo,ui.listWidget);
    listFormAdd = new ViewForms(ui.lineEdit_add_number,ui.lineEdit_add_lastname,ui.lineEdit_add_firstname,ui.lineEdit_add_BAC,ui.lineEdit_add_department,promo);
    listFormDelete = new ViewForms(ui.lineEdit_remove_number,promo);
    connect(ui.pushButton_delete_list,SIGNAL(pressed()),listView,SLOT(remove()));
    connect(ui.pushButton_delete_number,SIGNAL(pressed()),listFormDelete,SLOT(removeId()));
    connect(ui.pushButton_addStudent,SIGNAL(pressed()),listFormAdd,SLOT(addEtu()));
    connect(ui.pushButton_darkMode,SIGNAL(pressed()),this,SLOT(darkMode()));


    if (!ui.groupBox_department->layout())
        ui.groupBox_department->setLayout(new QVBoxLayout());

    pieChartView = new ViewPieChart(promo, ui.groupBox_department->layout());

    if (!ui.groupBox_bacs->layout())
        ui.groupBox_bacs->setLayout(new QVBoxLayout());

    histogramView = new ViewHistogram(promo, ui.groupBox_bacs->layout());



    // Handle Observers
}

TP3_GestionEtu::~TP3_GestionEtu(){
    delete promo;
    delete listView;
    delete listFormDelete;
    delete listFormAdd;
    delete pieChartView;
}

void TP3_GestionEtu::darkMode()
{
    static bool dark = false;
    if(!dark) {
        qApp->setStyleSheet(
            "QWidget { background-color: #2d2d30; color: #ffffff; }"
            "QLineEdit, QTextEdit { background-color: #3c3c3c; color: #ffffff; }"
            "QPushButton { background-color: #444444; color: #ffffff; border: 1px solid #555555; }"
            "QPushButton:hover { background-color: #555555; }"
            "QComboBox { background-color: #3c3c3c; color: #ffffff; }"
            "QListWidget { background-color: #3c3c3c; color: #ffffff; }"
            );
        dark = true;
    } else {
        qApp->setStyleSheet("");
        dark = false;
    }
}


