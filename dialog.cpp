#include "dialog.h"
#include "ui_dialog.h"
#include <QTextEdit>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(Dialog_accepted()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addWidget(QListWidget* model) {
    this->model = model;
}

void Dialog::Dialog_accepted()
{
    QTextEdit* text = ui->textEdit;
    if (text)
        model->addItem(new QListWidgetItem(text->toPlainText()));
    Dialog::accept();
}
