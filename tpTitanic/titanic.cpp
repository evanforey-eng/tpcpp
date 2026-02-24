#include "titanic.h"
#include "ui_titanic.h"

#include "piechartview.h"
#include "barchartview.h"
#include "multichartview.h"

Titanic::Titanic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Titanic)
{
    ui->setupUi(this);
    dataPassenger.loadFile("../Titanic/titanic.dbf");
}

Titanic::~Titanic()
{
    delete ui;
}
void Titanic::showView()
{
    setCentralWidget(view->getChartView(dataPassenger));
}

void Titanic::on_actionPie_triggered()
{
    view = new PieChartView();
}

void Titanic::on_actionBar_triggered()
{
    view = new BarChartView();
}

void Titanic::on_actionMulti_triggered()
{
    view = new MultiChartView();
}

void Titanic::on_actionVoir_triggered()
{
    showView();
}




