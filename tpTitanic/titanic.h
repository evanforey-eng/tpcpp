#ifndef TITANIC_H
#define TITANIC_H

#include <QMainWindow>
#include<QWidget>

#include "data.h"
#include "abstractchartview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Titanic; }
QT_END_NAMESPACE

class Titanic : public QMainWindow
{
    Q_OBJECT
    Data dataPassenger;
    AbstractChartView *view;

public:
    Titanic(QWidget *parent = nullptr);
    ~Titanic();
    void showView();

private:
    Ui::Titanic *ui;

private slots :
    void on_actionPie_triggered();
    void on_actionBar_triggered();
    void on_actionMulti_triggered();
    void on_actionVoir_triggered();
};
#endif // TITANIC_H
