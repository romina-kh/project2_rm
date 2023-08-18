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
    this->close() ;


}


void MainWindow::on_btn_signup_m_clicked()
{
    signup* signup_obj = nullptr;
    signup_obj = new signup();

    signup_obj->show();
    this->close() ;

}


void MainWindow::on_btn_exit_m_clicked()
{
    exit(0);

}


void MainWindow::on_total_exit_clicked()
{
    QMessageBox q;
    q.setText("in help section you can know more about details and information of the twetterak.");
    q.setWindowTitle("Help");
    q.setDetailedText("first of all you should pay attention to the signup part!!"
                      "For <Phone_Number> enter your phone number with country code\n "
                      "~ You can have (maximum) 160 characters in your bio or no bio at all\n"
                      "~ For <birthday> do this to enter your date of birth:year/month/day\n"
                      "~ Do not forget, you must write your <Name>, <Username>, <Age> and <Password>, but other items are optional\n"
                      "for login part you only should enter your username and password correctly\n"
                      "~ If you want to see other profiles type their ID on the search part and for seeing more information just click on the username\n"
                      "edit profile : You can change your information by click on setting part and go to edit profile botton.\n"
                      "~ just dont forget to click on <save> for saving your changes\n");

    q.exec();
}

