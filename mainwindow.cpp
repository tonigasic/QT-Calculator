#include "mainwindow.h"
#include "ui_mainwindow.h"


double firstNumber;
bool secondNumberTyping=false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->width(),this->height()); //not allowing to resize window

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
    connect(ui->pushButton_percentage,SIGNAL(released()),this,SLOT(percentagePressed()));
    connect(ui->pushButton_remove,SIGNAL(released()),this,SLOT(removePressed()));
    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(plusPressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(minusPressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(multiplyPressed()));
    connect(ui->pushButton_division,SIGNAL(released()),this,SLOT(divisionPressed()));
    connect(ui->pushButton_result,SIGNAL(released()),this,SLOT(resultPressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_division->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resultPressed(){
    QString label;
    double number,secondNumber;

    secondNumber=ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked()){

        number=firstNumber+secondNumber;
        label= QString::number(number,'g',15);
        ui->label->setText(label);
        ui->pushButton_plus->setChecked(false);
        ui->pushButton_division->setChecked(false);
        ui->pushButton_multiply->setChecked(false);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()){

        number=firstNumber-secondNumber;
        label= QString::number(number,'g',15);
        ui->label->setText(label);
        ui->pushButton_minus->setChecked(false);
        ui->pushButton_division->setChecked(true);
        ui->pushButton_multiply->setChecked(false);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked()){

        number=firstNumber*secondNumber;
        label= QString::number(number,'g',15);
        ui->label->setText(label);
        ui->pushButton_multiply->setChecked(false);
        ui->pushButton_minus->setChecked(false);
        ui->pushButton_division->setChecked(true);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_division->isChecked()){

        number=firstNumber/secondNumber;
        label= QString::number(number,'g',15);
        ui->label->setText(label);
        ui->pushButton_division->setChecked(false);
        ui->pushButton_multiply->setChecked(false);
        ui->pushButton_minus->setChecked(false);
        ui->pushButton_plus->setChecked(false);
    }
    secondNumberTyping=false;
}
void MainWindow::divisionPressed(){
    ui->pushButton_division->setChecked(true);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);

    firstNumber=ui->label->text().toDouble();
}
void MainWindow::multiplyPressed(){
    ui->pushButton_multiply->setChecked(true);
    ui->pushButton_division->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    firstNumber=ui->label->text().toDouble();
}
void MainWindow::minusPressed(){
    ui->pushButton_minus->setChecked(true);
    ui->pushButton_division->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    firstNumber=ui->label->text().toDouble();
}
void MainWindow::plusPressed(){
    ui->pushButton_plus->setChecked(true);
    ui->pushButton_division->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    firstNumber=ui->label->text().toDouble();
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
    QString labelText=ui->label->text();
    if(!labelText.contains('.')){
        ui->label->setText(labelText + ".");
    }

}
void MainWindow::removePressed(){
    ui->pushButton_division->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    secondNumberTyping=false;
    ui->label->setText("0");

}
void MainWindow::percentagePressed(){
    double number;
    QString label;

    number= ui->label->text().toDouble();
    number=number * 0.01;
    label= QString::number(number,'g',15);
    ui->label->setText(label);
}
void MainWindow::numberPressed(){
    QPushButton * pressedButton = (QPushButton*)sender();

    double number;
    QString labelNumber;

    if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked() || ui->pushButton_division->isChecked()) && !secondNumberTyping){
        number=pressedButton->text().toDouble();
        secondNumberTyping=true;
        labelNumber = QString::number(number,'g',15);
    }else{
        if(ui->label->text().contains('.') && pressedButton->text()== "0"){
            labelNumber = ui->label->text() + pressedButton->text();
        }else{
            number=(ui->label->text() + pressedButton->text()).toDouble();
            labelNumber = QString::number(number,'g',15);
        }

    }

    ui->label->setText(labelNumber);

}
