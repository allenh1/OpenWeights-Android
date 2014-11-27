#include "DateSelector.h"
#include "ui_dateSelector.h"

DateSelector::DateSelector(QWidget * parent) :
    QDialog(parent),
    ui(new Ui::DateSelector)
{
    ui->setupUi(this);
    connect(ui->doneButton, SIGNAL(pressed()), this, SLOT(prepareSend()));
}

DateSelector::~DateSelector()
{
    delete ui;
}

void DateSelector::prepareSend()
{
    QDate toSend = ui->calendarWidget->selectedDate();
    Q_EMIT sendDate(toSend);
    this->hide();
}
