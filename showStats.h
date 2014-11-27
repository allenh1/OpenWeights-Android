#ifndef SHOWSTATS_H
#define SHOWSTATS_H

#include <QWidget>
#include <QList>
#include "LogStruct.h"

namespace Ui {
class ShowStats;
}

class ShowStats : public QWidget
{
    Q_OBJECT

public:
    explicit ShowStats(QWidget *parent = 0);
    ~ShowStats();
    Q_SLOT void displayInfo();
    Q_SLOT void backPressed();
    Q_SLOT void saveList(QList<logItem>);

private:
    Ui::ShowStats *ui;

    QList<logItem> myList;
};

#endif // SHOWSTATS_H
