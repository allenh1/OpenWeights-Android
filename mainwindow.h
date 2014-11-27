#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>

#include "showStats.h"
#include "DateSelector.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Q_SLOT void updateLog();
    Q_SLOT void showLog();
    Q_SLOT void setDate(QDate);
    Q_SLOT void getDate();

    Q_SIGNAL void sendList(QList<logItem>);

    const QList<logItem> & getLogged(){ return loggedStuff; }

private:
    Ui::MainWindow *ui;
    ShowStats * statsUi;
    DateSelector * dateUi;
    QDate mostRecent;
    QList<logItem> loggedStuff;
};

#endif // MAINWINDOW_H
