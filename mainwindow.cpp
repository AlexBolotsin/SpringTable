#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "mylistwidget.h"
#include "showtaskdialog.h"
#include <QDebug>
#include <QFile>

#define DATA_FILE "data.bin"

QDataStream &operator>>(QDataStream &in, MyListWidget *list) {
    QAbstractItemModel* model = list->model();
    int i = 1;
    while(!in.atEnd())
    {
        QString string;
        in >> string;
        model->insertRow(i);
        model->setData(model->index(i, 0), string);
        i++;
    }
    return in;
}

QDataStream &operator<<(QDataStream &out, const MyListWidget *list) {
    QAbstractItemModel* model = list->model();
    for (int n = 1; n < model->rowCount(); n++) {
        out << model->index(n, 0).data().toString();
    }
    return out;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file(DATA_FILE);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> ui->listWidget;
}

MainWindow::~MainWindow()
{
    QFile file(DATA_FILE);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << ui->listWidget;
    delete ui;
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    if (index.isValid() && index.data().toString() == "New") {
        Dialog* dialog = new Dialog(this);
        dialog->setModal(true);
        dialog->addWidget(ui->listWidget);
        dialog->show();
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ShowTaskDialog* dialog = new ShowTaskDialog(this);
    dialog->setModal(true);
    dialog->SetItem(item);
    dialog->show();
}
