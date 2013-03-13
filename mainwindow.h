#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QTableWidget* table;
};

#endif // MAINWINDOW_H
