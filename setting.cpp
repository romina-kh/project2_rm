#include "setting.h"
#include "ui_setting.h"
#include "mainwindow.h"
#include "profile.h"
#include "twitterak.h"
#include "user.h"
#include "edit_profile.h"


setting::setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    //User = cuser;
    //musers = users;
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
    MainWindow * logout_btn = nullptr ;
    logout_btn  = new MainWindow ;
    logout_btn->show() ;

}


void setting::on_btn_delete_setting_clicked()
{
    Twitterak ti ;
    //ti.delete_account() ;
    MainWindow * logout_btn = nullptr ;
    logout_btn  = new MainWindow ;
    logout_btn->show() ;


}


void setting::on_btn_edit_setting_clicked()
{
    edit_profile * edit_btn = nullptr ;
    edit_btn = new edit_profile ;
    edit_btn->show() ;

}


void setting::on_btn_back_clicked()
{
    Twitterak back_btn ;
    back_btn.show();

}

