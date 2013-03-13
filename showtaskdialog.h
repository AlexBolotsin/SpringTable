#ifndef SHOWTASKDIALOG_H
#define SHOWTASKDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class ShowTaskDialog;
}

class ShowTaskDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ShowTaskDialog(QWidget *parent = 0);
    ~ShowTaskDialog();
    
    void SetItem(QListWidgetItem* item);
private:
    Ui::ShowTaskDialog *ui;
    QListWidgetItem* item;
};

#endif // SHOWTASKDIALOG_H
