#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QTextStream"
#include "QVBoxLayout"
#include "QLabel"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString filename = QFileDialog::getOpenFileName();
    if(filename.length())
    {
        QFile file(filename);
        if(file.open(QFile::ReadOnly | QFile::ExistingOnly))
        {
            QTextStream stream(&file);
            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
        }
    }
}


void MainWindow::on_action_2_triggered()
{
    QString filename = QFileDialog::getSaveFileName();
    if(filename.length())
    {
        QFile file(filename);
        if(file.open(QFile::WriteOnly | QFile::NewOnly))
        {
            QTextStream stream(&file);
            stream << ui->plainTextEdit->toPlainText();
            file.close();
        }
    }
}


void MainWindow::on_action_4_triggered()
{
    QWidget* pWindow = new QWidget();

    QDialog* childDialog = new QDialog(pWindow);
    childDialog->setMinimumWidth(200);
    childDialog->setMinimumHeight(100);
    childDialog->setWindowTitle("Справка");
    QVBoxLayout *vlayout = new QVBoxLayout;
    QLabel *label = new QLabel("Ver 0.01 \nby Renkeles");
    vlayout->addWidget(label);
    childDialog->setLayout(vlayout);
    childDialog->show();



}

