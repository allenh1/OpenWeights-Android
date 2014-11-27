#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

void MainWindow::showLog()
{
    //TODO: stuff here
}
