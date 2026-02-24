#include "viewHistogram.h"

/**
 * @brief Constructeur de ViewHistogram qui crée un layout ajoute un observer sur promo pour modifier les données en cas de changement
 * @param p un pointeur sur la promotion
 * @param layout un poiteur sur le layout
 */
ViewHistogram::ViewHistogram(Promotion *p, QLayout *layout)
{
    promo = p;
    parentLayout = layout;
    promo->addObserver(this);

    histogramme = createHistogramme();
    parentLayout->addWidget(histogramme);

    bacData = promo->getBac();

}

ViewHistogram::~ViewHistogram()
{
    qDebug()<< "[-]viewHistogram";
}

/**
 * @brief ViewHistogram::update la promo va être mise à jour,la serie du diagramme est supprimé puis remplie avec les nouvelles données et le layout sera redessiné.
 */
void ViewHistogram::update()
{
    bacData = promo->getBac();

    if(series !=nullptr)
    {
        series->clear();
    }

    auto setBacS = new QBarSet("S");
    auto setBacES = new QBarSet("ES");
    auto setBacL = new QBarSet("L");
    auto setBacSTI = new QBarSet("STI");
    *setBacS << bacData[0];
    *setBacES << bacData[1];
    *setBacL << bacData[2];
    *setBacSTI << bacData[3];


    series->append(setBacS);
    series->append(setBacES);
    series->append(setBacL);
    series->append(setBacSTI);


    histogramme->repaint();


}
/**
 * @brief ViewHistogram::createHistogramme création du diagramme
 * @return chartView
 */
QWidget *ViewHistogram::createHistogramme()
{
    bacData = promo->getBac();


    auto setBacS = new QBarSet("S");
    auto setBacES = new QBarSet("ES");
    auto setBacL = new QBarSet("L");
    auto setBacSTI = new QBarSet("STI");
    *setBacS << bacData[0];
    *setBacES << bacData[1];
    *setBacL << bacData[2];
    *setBacSTI << bacData[3];

    series = new QBarSeries;
    series->append(setBacS);
    series->append(setBacES);
    series->append(setBacL);
    series->append(setBacSTI);

    auto chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Répartition des étudiants par Bac");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories {"BAC"};
    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto axisY = new QValueAxis;
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

