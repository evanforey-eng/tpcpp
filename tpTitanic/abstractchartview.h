#ifndef ABSTRACTCHARTVIEW_H
#define ABSTRACTCHARTVIEW_H

#include <QWidget>
#include <QObject>
#include "data.h"

class AbstractChartView : public QObject
{
    Q_OBJECT
public:
    explicit AbstractChartView(QObject *parent = nullptr);
    virtual QWidget *getChartView(const Data &d) = 0 ;
    virtual ~AbstractChartView() = default;
};

#endif // ABSTRACTCHARTVIEW_H
