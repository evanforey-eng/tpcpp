#include "barchartview.h"

BarChartView::BarChartView()
{
}

QWidget *BarChartView::getChartView(const Data &d)
{
    auto setMort = new QBarSet("Mort");
    auto setVivant = new QBarSet("Vivant");

    *setVivant << d.getPassengerClasse(0,1) << d.getPassengerClasse(1,1) << d.getPassengerClasse(2,1) << d.getPassengerClasse(3,1) ;
    *setMort << d.getPassengerClasse(0,0) << d.getPassengerClasse(1,0) << d.getPassengerClasse(2,0) << d.getPassengerClasse(3,0);

    QBarSeries *series = new QBarSeries;
    series->append(setMort);
    series->append(setVivant);


    auto chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Simple Bar Chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories {"Equipage", "1er", "2nd", "3eme"};
    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto axisY = new QValueAxis;
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;

}
