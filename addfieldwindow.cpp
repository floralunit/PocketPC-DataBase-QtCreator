#include "addfieldwindow.h"
#include "ui_addfieldwindow.h"

AddFieldWindow::AddFieldWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFieldWindow)
{
    ui->setupUi(this);
}

AddFieldWindow::~AddFieldWindow()
{
    delete ui;
}

void AddFieldWindow::on_buttonBox_accepted()
{
}

DataField AddFieldWindow::getData()
{
    DataField newData;
    newData.setType(ui->TypeLineEdit->text().toStdString());
    newData.setProductName(ui->ProductLineEdit->text().toStdString());
    newData.setCompanyName(ui->CompanyLineEdit->text().toStdString());
    newData.setCountryName(ui->CountryLineEdit->text().toStdString());
    return newData;
}

void AddFieldWindow::setTypeName(QString str)
{
    ui->TypeLineEdit->setText(str);
}
void AddFieldWindow::setProductName(QString str)
{
    ui->ProductLineEdit->setText(str);
}
void AddFieldWindow::setCompanyName(QString str)
{
    ui->CompanyLineEdit->setText(str);
}
void AddFieldWindow::setCountryName(QString str)
{
    ui->CountryLineEdit->setText(str);
}

