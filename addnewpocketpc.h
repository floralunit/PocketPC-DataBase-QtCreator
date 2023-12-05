#ifndef ADDNEWPOCKETPC_H
#define ADDNEWPOCKETPC_H

#include <QDialog>
#include "PocketPC.h"

namespace Ui {
class AddNewPocketPC;
}

class AddNewPocketPC : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewPocketPC(QWidget *parent = nullptr);
    ~AddNewPocketPC();
    PocketPC getData();
    void setModel(QString str);
    void setCompany(QString str);
    void setProcessor(QString str);
    void setRAM_ROM(QString str);
    void setScreenResolution(QString str);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddNewPocketPC *ui;
};

#endif // ADDNEWPOCKETPC_H
