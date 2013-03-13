#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListWidget>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void addWidget(QListWidget* list);

private slots:
    void Dialog_accepted();

private:
    Ui::Dialog *ui;
    QListWidget* model;
};

#endif // DIALOG_H
