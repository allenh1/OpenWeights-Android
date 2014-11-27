#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>

#include "showStats.h"
#include "DateSelector.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief LogItem wrapper
 *
 * This struct contains a log item and its basic properties.
 * @see logComparator
 */
struct logItem
{
    int m_bicep;
    int m_tricep;
    int m_chest;
    QDate m_date;
};

/**
 * Allows for comparison of the objects in the array.
 * May not be completely necessary for anything ever,
 * but function objects are kinda neat. :P
 */
struct logComparator {
    bool operator () (const logItem & l1, const logItem & l2) const {
        return l1.m_date > l2.m_date;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Q_SLOT void updateLog();
    Q_SLOT void showLog();

private:
    Ui::MainWindow *ui;
    ShowStats * statsUi;
    DateSelector * dateUi;
};

#endif // MAINWINDOW_H
