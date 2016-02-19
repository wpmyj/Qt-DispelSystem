#include "hnupgradewidget.h"
#include "ui_hnupgradewidget.h"
#include "qtankdefine.h"
#include <QTimer>

HNUpgradeWidget::HNUpgradeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HNUpgradeWidget)
{
    ui->setupUi(this);
    //setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    ui->widgetProgressBar->setFixedWidth(240);
    ui->widgetProgressBar->setRange(0, 100);
    ui->widgetProgressBar->setValue(0);
    QTimer* timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeGoGo()));
    timer->start(100);
}

HNUpgradeWidget::~HNUpgradeWidget()
{
    delete ui;
}

void HNUpgradeWidget::timeGoGo()
{
    static int i = 0;
    ui->widgetProgressBar->setValue(i++%100);
}
