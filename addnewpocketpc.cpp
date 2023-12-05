#include "addnewpocketpc.h"
#include "ui_addnewpocketpc.h"

AddNewPocketPC::AddNewPocketPC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewPocketPC)
{
    ui->setupUi(this);
}

AddNewPocketPC::~AddNewPocketPC()
{
    delete ui;
}

void AddNewPocketPC::on_buttonBox_accepted()
{
}

PocketPC AddNewPocketPC::getData()
{
    PocketPC newData;
    newData.setModel(ui->ModelLineEdit->text().toStdString());
    newData.setCompany(ui->CompanyLineEdit->text().toStdString());
    newData.setProcessor(ui->ProcessorLineEdit->text().toStdString());
    newData.setRAM_ROM(ui->RAM_ROMLineEdit->text().toStdString());
    newData.setScreenResolution(ui->ScreenResolutionLineEdit->text().toStdString());
    return newData;
}

void AddNewPocketPC::setModel(QString str)
{
    ui->ModelLineEdit->setText(str);
}
void AddNewPocketPC::setCompany(QString str)
{
    ui->CompanyLineEdit->setText(str);
}
void AddNewPocketPC::setProcessor(QString str)
{
    ui->ProcessorLineEdit->setText(str);
}
void AddNewPocketPC::setRAM_ROM(QString str)
{
    ui->RAM_ROMLineEdit->setText(str);
}
void AddNewPocketPC::setScreenResolution(QString str)
{
    ui->ScreenResolutionLineEdit->setText(str);
}
