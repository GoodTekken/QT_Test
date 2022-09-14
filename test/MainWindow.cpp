#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(ClickButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ClickButton()            //manual connect the signal and slot
{
//    QApplication::exit(0);
}


void MainWindow::on_pushButton_clicked() //auto connnect the signal and slot
{
    QApplication::exit(0);
}
