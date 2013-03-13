#include "dialog.h"
#include "ui_dialog.h"
#include <QTextEdit>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addWidget(QListWidget* model) {
    this->model = model;
}

void Dialog::on_pushButton_clicked()
{
    QTextEdit* text = ui->textEdit;
    if (text)
        model->addItem(new QListWidgetItem(text->toPlainText()));
}
