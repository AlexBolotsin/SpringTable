#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    if (index.isValid() && index.data().toString() == "New") {
        Dialog* dialog = new Dialog(this);
        dialog->show();
    }
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    qDebug() << index;
}
