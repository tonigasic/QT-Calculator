#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void numberPressed();
    void commaPressed();
    void predznakPressed();
    void percentagePressed();
    void removePressed();
    void plusPressed();
    void minusPressed();
    void multiplyPressed();
    void divisionPressed();
    void resultPressed();

};




#endif // MAINWINDOW_H
