#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QScrollArea>

#include "search.h"
#include "widget.h"

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
    void on_Btn_Add_Knot_clicked();
    void on_Btn_Find_Min_clicked();
    void on_Btn_Del_Knot_clicked();

private:
    Ui::MainWindow *ui;
    Widget* widget;
    QScrollArea *scroll;
    SearchTree<int>* searchTree;

};
#endif // MAINWINDOW_H
