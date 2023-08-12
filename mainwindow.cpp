#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "twitterak.h"
#include "login.h"
#include "signup.h"
#include "QLineEdit"

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


void MainWindow::on_btn_login_m_clicked()
{
    login* log_obj = nullptr;
    log_obj = new login;
    log_obj->show();


}


void MainWindow::on_btn_signup_m_clicked()
{
    signup* signup_obj = nullptr;
    signup_obj = new signup();

    signup_obj->show();

}


void MainWindow::on_btn_exit_m_clicked()
{
    exit(0);

}

