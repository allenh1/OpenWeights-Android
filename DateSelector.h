#ifndef DATESELECTOR_H
#define DATESELECTOR_H

#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
class DateSelector;
}

class DateSelector : public QDialog
{
    Q_OBJECT
public:
    explicit DateSelector(QWidget * parent = 0);
    ~DateSelector();
    Q_SIGNAL void sendDate(QDate);
    Q_SLOT void prepareSend();
private:
    Ui::DateSelector * ui;
};

#endif // DATESELECTOR_H
