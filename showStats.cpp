#include "showStats.h"
#include "ui_ShowStats.h"

ShowStats::ShowStats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowStats)
{
    ui->setupUi(this);
}

ShowStats::~ShowStats()
{
    delete ui;
}
