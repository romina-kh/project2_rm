#include "setting.h"
#include "ui_setting.h"
#include "mainwindow.h"
#include "profile.h"
#include "twitterak.h"
#include "user.h"
#include "edit_profile.h"


setting::setting(unordered_map<string , Common*>& users,Common* user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
   User = user;
   musers = users;
}

setting::~setting()
{
    delete ui;
}

void setting::on_btn_exit_setting_clicked()
{
    exit(0) ;
}


void setting::on_btn_logout_setting_clicked()
{
    MainWindow * log_btn = nullptr ;
    log_btn = new MainWindow ;
    log_btn->show() ;

}


void setting::on_btn_delete_setting_clicked()
{

    musers.erase(User->Get_User());

}


void setting::on_btn_edit_setting_clicked()
{
    edit_profile * edit_btn = nullptr ;
    edit_btn = new edit_profile(musers ,User) ;
    edit_btn->show() ;

}


void setting::on_btn_back_clicked()
{
    this->close();
}

