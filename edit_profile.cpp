#include "edit_profile.h"
#include "ui_edit_profile.h"
#include "setting.h"

edit_profile::edit_profile(Common* user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_profile)
{
    ui->setupUi(this);
    User = user;
}

edit_profile::~edit_profile()
{
    delete ui;
}

void edit_profile::on_editprofile_dateEdit_userDateChanged(const QDate &date)
{

}


void edit_profile::on_btn_back_editpro_clicked()
{
    this->close();
}


void edit_profile::on_btn_save_edit_clicked()
{

}

