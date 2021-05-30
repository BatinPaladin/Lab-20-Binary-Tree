#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    searchTree = new SearchTree<int>;
    widget = new Widget(searchTree);
    scroll = new QScrollArea;
    scroll->setWidget(widget);
    ui->verticalLayout->addWidget(scroll);
    ui->LE_Add->setValidator(new QIntValidator(1, 99, this));
    ui->LE_Del->setValidator(new QIntValidator(1, 99, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Btn_Add_Knot_clicked()
{
    QString value = ui->LE_Add->text();
    searchTree->insert(value.toInt());
    widget->rePaint();
    ui->LE_Add->setText("");
    ui->L_min->setText("");
}

void MainWindow::on_Btn_Find_Min_clicked()
{
    if (!searchTree->empty())
    {
        int value = searchTree->findMin();
        ui->L_min->setText(QString::number(value));
    }
    else
    {
        cout << "Empty binary search tree! " << endl;
    }
}

void MainWindow::on_Btn_Del_Knot_clicked()
{
    QString value = ui->LE_Del->text();
    searchTree->deleteKnot(value.toInt());
    widget->rePaint();
    ui->LE_Del->setText("");
    ui->L_min->setText("");
}
