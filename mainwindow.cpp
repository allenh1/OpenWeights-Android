#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    ui->bicepCurl->clear(); ui->chestPress->clear(); ui->tricepCurl->clear();
    ui->chestLabel->setText("Reps"); ui->bicepLabel->setText("Reps"); ui->tricepLabel->setText("Reps");
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
    //TODO: stuff here
}
