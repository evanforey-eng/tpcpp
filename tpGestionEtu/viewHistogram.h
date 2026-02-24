#pragma once

#include <QWidget>
#include <QObject>
#include <QtCharts>
#include <QBarSeries>
#include"promotion.h"

/**
 * @brief The ViewHistogram class
 */
class ViewHistogram : public QObject,Observer
{
    Q_OBJECT

private:
    Promotion* promo;  /// promo est un poiteur sur la promo d'étudiants
    QList<int> bacData; ///bacData est un tableau qui stock les donées sur les bacs des étudiants
    QWidget* histogramme; ///histogramme est le widget de l'histogramme
    QLayout* parentLayout; ///parentLayout est le layout ou l'on va placé histogramme

    QBarSeries* series; /// series sont les informations sur les bacs dans l'histogramme
    QChartView* chartView;

    QWidget* createHistogramme();


public:
    ViewHistogram(Promotion* p,QLayout* layout);
    ~ViewHistogram();
    void update() override;
};

