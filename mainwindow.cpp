#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mostRecent(QDate::currentDate())
{
    ui->setupUi(this);
    ui->bicepCurl->show();
    ui->chestPress->show();
    ui->tricepCurl->show();
    ui->logButton->show();

    dateUi = new DateSelector(this);
    statsUi = new ShowStats(this);
    dateUi->hide();
    statsUi->hide();

    connect(ui->logButton, SIGNAL(released()), this, SLOT(updateLog()));
    connect(ui->viewLog, SIGNAL(released()), this, SLOT(showLog()));
    connect(ui->dateSetting, SIGNAL(released()), this, SLOT(getDate()));
    connect(dateUi, SIGNAL(sendDate(QDate)), this, SLOT(setDate(QDate)));
    connect(statsUi, SIGNAL(showMain()), this, SLOT(makeVisible()));

    connect(ui->viewLog, SIGNAL(pressed()), statsUi, SLOT(displayInfo()));
    connect(this, SIGNAL(sendList(QList<logItem>)), statsUi, SLOT(saveList(QList<logItem>)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLog()
{
    QString bicepCurl = ui->bicepCurl->text();
    QString chestPress = ui->chestPress->text();
    QString tricepCurl = ui->tricepCurl->text();

    bool ok1 = true; bool ok2 = true; bool ok3 = true;
    logItem * item1 = new logItem;
    item1->m_bicep = bicepCurl.toInt(&ok1);
    item1->m_chest = chestPress.toInt(&ok2);
    item1->m_tricep = tricepCurl.toInt(&ok3);
    item1->m_date = mostRecent;

    QString setString = "Bicep: "; setString += bicepCurl;
    setString += "\nChest Press: "; setString += chestPress;
    setString += "\nTricep Curl: "; setString += tricepCurl;
    setString += "\nLogged: "; setString += mostRecent.toString();
    setString += "\n";
    item1->asString = setString;

    if (ok1 && ok2 && ok3)
        loggedStuff.push_back(*item1);
    //else
    //  TODO: make this a statement.
    delete item1;

    ui->bicepCurl->clear(); ui->chestPress->clear(); ui->tricepCurl->clear();
    //ui->chestLabel->setText("Reps"); ui->bicepLabel->setText("Reps"); ui->tricepLabel->setText("Reps");

    std::sort(loggedStuff.begin(), loggedStuff.end(), Comparator());
    Q_EMIT sendList(loggedStuff);
}

void MainWindow::getDate()
{
    dateUi->show();
}

void MainWindow::setDate(QDate received)
{
    mostRecent = received;
    ui->dateSetting->setText(mostRecent.toString());
}

void MainWindow::showLog()
{
    statsUi->show();
}
