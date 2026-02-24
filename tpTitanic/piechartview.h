#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include "abstractchartview.h"
#include "QtCharts"

class PieChartView : public AbstractChartView
{
public:
    PieChartView();
    QWidget *getChartView(const Data &d)override;
};

#endif // PIECHARTVIEW_H
