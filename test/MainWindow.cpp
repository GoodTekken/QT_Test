#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QDebug>

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
//    QApplication::exit(0);,
    QString path = QFileDialog::getOpenFileName(this,"open image",".","Image File(*.jpg *.png *.jpeg)");
    if(path!="") QMessageBox::information(this,"caption",path);
}

void MainWindow::on_colorBtn_clicked()
{
    QColorDialog dlg(this);
    dlg.setWindowTitle("my color dialog");
    if(dlg.exec()==QColorDialog::Accepted)
    {
        qDebug()<<dlg.selectedColor();
    }
}
