#include "showStats.h"
#include "ui_ShowStats.h"

ShowStats::ShowStats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowStats)
{
    ui->setupUi(this);

    connect(ui->backButton, SIGNAL(pressed()), this, SLOT(backPressed()));
}

ShowStats::~ShowStats()
{
    delete ui;
}

void ShowStats::backPressed(){ this->hide(); }

void ShowStats::saveList(QList<logItem> sentList){ myList = sentList; }

void ShowStats::displayInfo()
{
    ui->logEditor->clear();
    QString toDisplay = "";

    for (int x = 0; x < myList.size(); ++x)
    {
        toDisplay += myList.at(x).asString;
        toDisplay += "\n";
    }//end for

    ui->logEditor->setText(toDisplay);
}
