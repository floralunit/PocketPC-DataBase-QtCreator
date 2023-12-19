#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include "DataBase.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_saveButton_clicked();
    void on_SearchButton_clicked();
    void on_openButton_clicked();
    void on_addDataButton_clicked();
    void on_mergeButton_clicked();
    void on_createButton_clicked();
    void on_action_create_triggered();
    void on_action_developer_triggered();
    void on_action_add_triggered();
    void on_action_save_triggered();
    void on_action_delete_triggered();
    void on_action_merge_triggered();
    void on_action_open_triggered();
    void on_deleteDataButton_clicked();
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_action_edit_triggered();

    void on_SearchLine_textChanged(const QString &arg1);

    void on_SearchLine_textEdited(const QString &arg1);

    void on_toolButton_triggered(QAction *arg1);

    void on_createToolButton_triggered(QAction *arg1);

    void on_createToolButton_clicked();

    void on_openToolButton_clicked();

    void on_mergeToolButton_clicked();

    void on_saveToolButton_clicked();

    void on_addToolButton_clicked();

    void on_editToolButton_clicked();

    void on_deleteToolButton_clicked();

private:
    Ui::MainWindow *ui;
    DataBase myDatabase;
    QTableView *tableView;
    QStandardItemModel *model;
    void setupModel(DataBase data);
};
#endif // MAINWINDOW_H
