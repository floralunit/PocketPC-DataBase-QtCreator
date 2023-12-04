#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include "addfieldwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_createButton_clicked();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupModel(DataBase data)
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    QStringList headers;
    headers.append(QString::fromUtf8("Тип"));
    headers.append(QString::fromUtf8("Наименование"));
    headers.append(QString::fromUtf8("Производитель"));
    headers.append(QString::fromUtf8("Страна-производитель"));
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    for (int i = 0; i < data.getData().size(); i++)
    {
        ui->tableWidget->insertRow(i);
        DataField dataf = data.getData()[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dataf.getType().c_str()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(dataf.getProductName().c_str()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(dataf.getCompanyName().c_str()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(dataf.getCountryName().c_str()));
    }
}

void MainWindow::on_saveButton_clicked()
{
    qDebug() << "SAVE";
    std::string str = QFileDialog::getSaveFileName(0,"Сохранить","C:\\MY\\UNI\3 semestr\\OOP\\CourseWork\\build-DataBase-Desktop_Qt_6_6_0_Mi","*.txt ;; *lmaikpi25").toStdString();
    myDatabase.saveData(str);
    if (str.length() != 0) ui->statusbar->showMessage("Сохранение в файл " + QFileInfo(QString::fromStdString(str)).fileName() + " произошло успешно", 5000);
    return;
}

void MainWindow::on_openButton_clicked()
{
    qDebug() << "OPEN";
    if (myDatabase.getData().size() > 0)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        QIcon icon;
        icon.addPixmap(QPixmap(":/resourses/Images/ICON.png"));
        msgBox.setWindowIcon(icon);
        msgBox.setText("Вы уверены, что хотите открыть новый файл?\nВсе изменения не будут сохранены.");
        msgBox.setIcon(QMessageBox::Question); msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No); msgBox.setDefaultButton(QMessageBox::Yes);
        if (msgBox.exec() == QMessageBox::No) {
            return;
        }
    }
    std::string str = QFileDialog::getOpenFileName(0,"Открыть","","*.lmaikpi25 *.txt").toStdString();
    myDatabase.readData(str);
    setupModel(myDatabase);
    ui->dataBaseName->setText(QFileInfo(QString::fromStdString(str)).fileName());
    this->setWindowTitle(QFileInfo(QString::fromStdString(str)).fileName());
    if (str.length() != 0) ui->statusbar->showMessage("Успешно открыт " + QFileInfo(QString::fromStdString(str)).fileName(), 5000);
}


void MainWindow::on_addDataButton_clicked()
{
    qDebug() << "ADD";
    AddFieldWindow addField;
    addField.setWindowTitle("Add new element");
    QIcon icon;
    icon.addPixmap(QPixmap(":/resourses/Images/ICON.png"));
    addField.setWindowIcon(icon);
    if (addField.exec() == QDialog::Accepted)
    {
        DataField temp = addField.getData();
        if (temp.isEmpty() == true)
        {
            qDebug() << "Empty";
            QMessageBox msgBox;
            msgBox.setWindowTitle("Внимание");
            QIcon icon;
            icon.addPixmap(QPixmap(":/resourses/Images/ICON.png"));
            msgBox.setWindowIcon(icon);
            msgBox.setText("Вы хотите добавить пустое поле!\nДанное действие не будет выполнено");
            msgBox.setIcon(QMessageBox::Warning); msgBox.setStandardButtons(QMessageBox::Close); msgBox.setDefaultButton(QMessageBox::Close);
            msgBox.exec();
            return;
        }
        else
        {
            myDatabase.AddData(temp);
            setupModel(myDatabase);
            ui->statusbar->showMessage("Добавлен новый элемент", 5000);
        }
    }
}

void MainWindow::on_mergeButton_clicked()
{
    qDebug() << "MERGE";
    std::string str = QFileDialog::getOpenFileName(0,"Открыть","","*.lmaikpi25 *.txt").toStdString();
    DataBase base2(str);
    myDatabase.MergeBase(&base2);
    setupModel(myDatabase);
    if (str.length() != 0) ui->statusbar->showMessage("Объединение с " + QFileInfo(QString::fromStdString(str)).fileName() + " произошло успешно", 5000);
}
void MainWindow::on_createButton_clicked()
{
    qDebug() << "CREATE";
    if (myDatabase.getData().size() > 0)
    {
        QMessageBox msgBox;
        QIcon icon;
        icon.addPixmap(QPixmap(":/resourses/Images/ICON.png"));
        msgBox.setWindowIcon(icon);
        msgBox.setWindowTitle("Внимание");
        msgBox.setText("Вы уверены, что хотите создать новый файл?\nВсе изменения не будут сохранены.");
        msgBox.setIcon(QMessageBox::Question); msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No); msgBox.setDefaultButton(QMessageBox::Yes);
        if (msgBox.exec() == QMessageBox::No) {
            return;
        }
    }
    DataBase newData;
    myDatabase = newData;
    setupModel(myDatabase);
    ui->dataBaseName->setText("NewDataBase.txt");
    ui->statusbar->showMessage("Создана новая база данных", 5000);
}

void MainWindow::on_deleteDataButton_clicked()
{
    qDebug() << "Remove";
    auto selected = ui->tableWidget->selectionModel()->selectedRows();
    if (selected.length() > 0)
    {

        if (myDatabase.getData().size() > 0)
        {
            QMessageBox msgBox;
            QIcon icon;
            icon.addPixmap(QPixmap(":/resourses/Images/ICON.png"));
            msgBox.setWindowIcon(icon);
            msgBox.setWindowTitle("Внимание");
            msgBox.setText("Вы уверены, что хотите удалить выбранные элементы?\nОтменить это действие будет невозможно.");
            msgBox.setIcon(QMessageBox::Question); msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No); msgBox.setDefaultButton(QMessageBox::Yes);
            if (msgBox.exec() == QMessageBox::No) {
                return;
            }
        }
        for (auto begin = selected.rbegin(); begin != selected.rend(); begin++)
        {
            int indx = begin->row();
            myDatabase.RemoveData(indx);
        }
        setupModel(myDatabase);
        ui->statusbar->showMessage("Удалено " + QString::number(selected.size()) + " записей", 5000);
    }
}

void MainWindow::on_action_edit_triggered()
{
    qDebug() << "EDIT";
    auto selected = ui->tableWidget->selectedItems();
    if (selected.length() > 0)
    {
        AddFieldWindow editdata;
        editdata.setWindowTitle("Edit Element");
        QIcon icon;
        icon.addPixmap(QPixmap(":/resourses/Images/ICON.png"));
        editdata.setWindowIcon(icon);
        editdata.setTypeName(selected.at(0)->text());
        editdata.setProductName(selected.at(1)->text());
        editdata.setCompanyName(selected.at(2)->text());
        editdata.setCountryName(selected.at(3)->text());
        if (editdata.exec() == QDialog::Accepted)
        {
            DataField dataf = editdata.getData();
            myDatabase.EditData(dataf, selected.at(0)->row());
            setupModel(myDatabase);
            ui->statusbar->showMessage("Изменение произошло успешно", 5000);
        }
    }
}

void MainWindow::on_action_create_triggered()
{
    on_createButton_clicked();
}


void MainWindow::on_action_developer_triggered()
{
    qDebug() << "DEVELOPER";
    QMessageBox::about(this,"О программе","Разработчик: Ларин М.А.\n"
                            "Тема: Класс, характеризующий детали (комплектующие) для компьютера "
                            "(наименование [например, HDD], тип, марка, фирма - изготовитель и т.д.).\n"
                            "2023 год");
}


void MainWindow::on_action_add_triggered()
{
    on_addDataButton_clicked();
}


void MainWindow::on_action_save_triggered()
{
    on_saveButton_clicked();
}


void MainWindow::on_action_delete_triggered()
{
    on_deleteDataButton_clicked();
}


void MainWindow::on_action_merge_triggered()
{
    on_mergeButton_clicked();
}

void MainWindow::on_action_open_triggered()
{
    on_openButton_clicked();
}



void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    on_action_edit_triggered();
}

void MainWindow::on_SearchLine_textEdited(const QString &arg1)
{
}


void MainWindow::on_SearchLine_textChanged(const QString &arg1)
{
    qDebug() << "SEARCH";
    DataBase search;
    std::string str = arg1.toStdString();
    if (str.length() == 0) {setupModel(myDatabase); return;}
    for (int i = 0; i < this->myDatabase.getData().size()+1;i++)
    {
        if (myDatabase.getData()[i].getProductName().find(str) != std::string::npos || myDatabase.getData()[i].getType().find(str) != std::string::npos || myDatabase.getData()[i].getCompanyName().find(str) != std::string::npos || myDatabase.getData()[i].getCountryName().find(str) != std::string::npos)
        {
            search.AddData(myDatabase.getData()[i]);
        }
    }
    setupModel(search);
    ui->statusbar->showMessage("Нашлось " + QString::number(search.getData().size()) + " записей", 5000);
}

