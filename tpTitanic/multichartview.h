#ifndef MULTICHARTVIEW_H
#define MULTICHARTVIEW_H

#include "abstractchartview.h"
#include "QtCharts"

class MultiChartView : public AbstractChartView
{
public:
    MultiChartView();
    QWidget *getChartView(const Data &d)override;
    QChartView *getPopuCate(const Data &d);
    QChartView *getPopuAge(const Data &d);

};

#endif // MULTICHARTVIEW_H
