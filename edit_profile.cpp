#include "edit_profile.h"
#include "ui_edit_profile.h"
#include "setting.h"

edit_profile::edit_profile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_profile)
{
    ui->setupUi(this);
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
    setting * back_btn_edit = nullptr ;
    back_btn_edit = new setting ;
    back_btn_edit->show();
}

