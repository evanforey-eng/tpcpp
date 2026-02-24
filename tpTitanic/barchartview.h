#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include "abstractchartview.h"
#include "QtCharts"

class BarChartView : public AbstractChartView
{
public:
    BarChartView();
    QWidget *getChartView(const Data &d)override;
};

#endif // BARCHARTVIEW_H
