#include "showtaskdialog.h"
#include "ui_showtaskdialog.h"

ShowTaskDialog::ShowTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTaskDialog)
{
    ui->setupUi(this);
}

ShowTaskDialog::~ShowTaskDialog()
{
    delete ui;
}

void ShowTaskDialog::SetItem(QListWidgetItem* item) {
    this->item = item;
    ui->textEdit->append(item->text());
}
