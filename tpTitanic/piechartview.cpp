#include "piechartview.h"

PieChartView::PieChartView()
{

}

QWidget *PieChartView::getChartView(const Data &d)
{
    //![1]
        int cptHomme=0;
        int cptFemme=0;
        for (Passenger p : d.getListPassenger()){
            if(p.getSex()==1){
                cptHomme++;
            }else {
                cptFemme++;
            }

        }
        QPieSeries *series = new QPieSeries();
        series->append("Homme",cptHomme);
        series->append("Femme",cptFemme);

    //![1]

    //![2]
//        QPieSlice *slice = series->slices().at(1);
//        slice->setExploded();
//        slice->setLabelVisible();
//        slice->setPen(QPen(Qt::darkGreen, 2));
//        slice->setBrush(Qt::green);
    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Proportion H/F");
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignTop);
        chart->legend()->setFont(QFont("Arial",10));
        chart->legend()->setMarkerShape(QLegend::MarkerShapeRectangle);
        //![3]

    //![4]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![4]
        return chartView;

}
