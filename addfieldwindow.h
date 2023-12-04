#ifndef ADDFIELDWINDOW_H
#define ADDFIELDWINDOW_H

#include <QDialog>
#include "datafield.h"
namespace Ui {
class AddFieldWindow;
}

class AddFieldWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddFieldWindow(QWidget *parent = nullptr);
    ~AddFieldWindow();
    DataField getData();
    void setTypeName(QString str);
    void setProductName(QString str);
    void setCompanyName(QString str);
    void setCountryName(QString str);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddFieldWindow *ui;
};

#endif // ADDFIELDWINDOW_H
