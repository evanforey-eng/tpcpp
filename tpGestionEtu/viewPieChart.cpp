#include "viewPieChart.h"
#include <QDebug>
#include <QVBoxLayout>

ViewPieChart::ViewPieChart(Promotion* p, QLayout* layout)
{
    promo = p;
    parentLayout = layout;
    promo->addObserver(this);

    list = promo->getDep();

    pieChart = createChart();
    parentLayout->addWidget(pieChart);


}

ViewPieChart::~ViewPieChart()
{
    qDebug()<< "[-]viewPieChart";
}

QWidget* ViewPieChart::createChart()
{
    if (list.isEmpty())
        return nullptr;

    series = new QPieSeries();
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] > 0)
            series->append(QString::number(i + 1), list[i]);
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition géographique");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignTop);
    chart->legend()->setFont(QFont("Arial", 10));
    chart->legend()->setMarkerShape(QLegend::MarkerShapeRectangle);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

void ViewPieChart::update()
{
    list = promo->getDep();

    if (series != nullptr) {
        series->clear();
    }

    for (int i = 0; i < list.size(); ++i) {
        if (list[i] > 0)
            series->append(QString::number(i + 1), list[i]);
    }


    pieChart->repaint();

}
