#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include "QtCharts"

QChartView* CreateBarChart(QBarSeries *series, QStringList categories, QString title);

StatisticsWindow::StatisticsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);


    // Creating bar
    QBarSet *textDataSetRLE = new QBarSet("Text");
    QBarSet *pngDataSetRLE = new QBarSet("Png");
    QBarSet *bmpDataSetRLE = new QBarSet("Bmp");

    *textDataSetRLE << 1 << 0.55 << 0.5;
    *pngDataSetRLE << 1 << 1 << 1;
    *bmpDataSetRLE << 0.37 << 0.56 << 0.17;

    QBarSeries *seriesRLE = new QBarSeries();
    seriesRLE->append(textDataSetRLE);
    seriesRLE->append(pngDataSetRLE);
    seriesRLE->append(bmpDataSetRLE);

    QStringList categoriesRLE;
    categoriesRLE << "RLE" << "LZ77" << "Huffman";


    QChartView *chartView = CreateBarChart(seriesRLE, categoriesRLE, "Сompression analytics");

    // Adding chart to layout
    ui->graphLayout->addWidget(chartView);
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

// Creating bar chart with data from QBarSeries and QStringList
QChartView* CreateBarChart(QBarSeries *series, QStringList categories, QString title) {
    // Creating chart and adding title and series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Creating x axes of bar
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Сompression algorithm");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Creating y axes of bar
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,1.2);
    axisY->setTitleText("Compression ratio");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    // bottom text (describe each color)
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Creating chart view of chart and set the theme of the chart
    QChartView *chartView = new QChartView(chart);
    chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);

    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;

}

