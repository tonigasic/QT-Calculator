#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(numberPressed()));
    connect(ui->pushButton_comma,SIGNAL(released()),this,SLOT(commaPressed()));
    connect(ui->pushButton_predznak,SIGNAL(released()),this,SLOT(predznakPressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::predznakPressed(){
    double number;
    QString label;

    number= ui->label->text().toDouble();
    number=number * -1;
    label= QString::number(number,'g',15);
    ui->label->setText(label);
}
void MainWindow::commaPressed(){
    // TODO check if comma already exist in label
    QString labelText=ui->label->text();
    ui->label->setText(labelText + ".");
}
void MainWindow::numberPressed(){
    QPushButton * pressedButton = (QPushButton*)sender();

    double number;
    QString labelNumber;

    number=(ui->label->text() + pressedButton->text()).toDouble();
    labelNumber = QString::number(number,'g',15);

    ui->label->setText(labelNumber);

}
