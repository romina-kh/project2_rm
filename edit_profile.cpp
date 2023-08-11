#include "edit_profile.h"
#include "ui_edit_profile.h"

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
