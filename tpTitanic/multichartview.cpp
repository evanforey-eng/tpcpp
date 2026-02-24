#include "multichartview.h"

MultiChartView::MultiChartView()
{

}

QWidget *MultiChartView::getChartView(const Data &d){
    // Pour la grille
    QGridLayout *gridlayout= new QGridLayout();
    gridlayout->addWidget(getPopuCate(d),0,0);
     gridlayout->addWidget(getPopuAge(d),1,0);

    QWidget *widget = new QWidget();
    widget->setLayout(gridlayout);

    return widget;
}

QChartView *MultiChartView::getPopuCate(const Data &d)
{
    // Population par cathegorie diag1
    auto set0 = new QBarSet("Population");

    *set0 << d.getPopulationClasse(0) << d.getPopulationClasse(1) << d.getPopulationClasse(2) << d.getPopulationClasse(3) ;


    auto series = new QHorizontalBarSeries;
    series->append(set0);

    auto chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Population/Cathegori");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories {"Equipage", "1er", "2nd", "3eme"};
    auto axisY = new QBarCategoryAxis;
    axisY->append(categories);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    auto axisX = new QValueAxis;
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisX->applyNiceNumbers();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![4]
    return chartView;

}

QChartView *MultiChartView::getPopuAge(const Data &d)
{
    // Population par cathegorie diag1
    auto set0 = new QBarSet("Population");

    *set0 << d.getPopulationAge(0) << d.getPopulationAge(1);


    auto series = new QHorizontalBarSeries;
    series->append(set0);

    auto chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Population/Age");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories {"Enfant", "Adulte"};
    auto axisY = new QBarCategoryAxis;
    axisY->append(categories);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    auto axisX = new QValueAxis;
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisX->applyNiceNumbers();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![4]
    return chartView;

}
