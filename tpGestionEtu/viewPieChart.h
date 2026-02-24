#pragma once


#include <QWidget>
#include <QObject>
#include <QtCharts>

#include"promotion.h"
/**
 * @brief Class to manage the PieChart View
 * @author Adrien Peytavie
*/
class ViewPieChart : public QObject,Observer
{
    Q_OBJECT

private:
    Promotion* promo;
    QList<int> list;
    QWidget* pieChart;
    QLayout* parentLayout;
    QPieSeries* series;
    QChartView* chartView;
    QWidget* createChart();

public:
    explicit ViewPieChart(Promotion* p, QLayout* layout);
    ~ViewPieChart();
    void update() override;
};
