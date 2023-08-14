#include "edit_profile.h"
#include "ui_edit_profile.h"
#include "setting.h"
#include "twitterak.h"
#include "user.h"
#include "personal.h"
#include "company.h"
#include "anonymous.h"
#include "QMessageBox"
#include <fstream>
#include "profile.h"
edit_profile::edit_profile(unordered_map<string , Common*>& users ,Common* user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_profile)
{
    ui->setupUi(this);
    User = user;
    musers = users ;
}



void edit_profile :: put_user()
{
    ofstream outuser;
    outuser.open("user.txt", ios::out);

    Personal* per;
    Anonymous* ano;
    Company* org;

    for (auto i : musers)
    {
        per = dynamic_cast<Personal*>(i.second);
        ano = dynamic_cast<Anonymous*>(i.second);
        org = dynamic_cast<Company*>(i.second);

        if (per != NULL)
        {
            outuser << i.second->Get_User() << "p" ;
        }
        if (ano != NULL)
        {
            outuser << i.second->Get_User() << "a" ;
        }
        if (org != NULL)
        {
            outuser << i.second->Get_User() << "o" ;
        }
        outuser << endl << i.second->Get_Name() << endl << i.second->Get_Age() << endl
        << i.second->Get_Phone() << endl << i.second->Get_Country() << endl << i.second->Get_Link() << endl <<
        i.second->Get_Bio() << endl << i.second->Get_Password() << endl
        << "************************************************\n";
        //header
    }

    outuser.close();
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
    QMessageBox q;

    put_user();


    q.setText("!save succsessfully.") ;
    q.exec();
    this->close();

    //parentWidget()->hide();


}



void edit_profile::on_box_total_edit_clicked()
{
    if(User->Get_Name()== "Anonymous User")
    {
        ui->editprofile_dateEdit->setEnabled(false);
        ui->ln_edit_name->setEnabled(false);
        ui->ln_edit_country->setEnabled(false);
        ui->ln_edit_link->setEnabled(false);
        ui->ln_edit_phone->setEnabled(false);
        ui->txt_edit_bio->setEnabled(false);

    }
    else if (User->Get_Age()=="")
    {

         ui->editprofile_dateEdit->setEnabled(false);
         ui->ln_edit_name->setEnabled(true);
         ui->ln_edit_country->setEnabled(true);
         ui->ln_edit_link->setEnabled(true);
         ui->ln_edit_phone->setEnabled(true);
         ui->txt_edit_bio->setEnabled(true);
    }
    else
    {
        ui->editprofile_dateEdit->setEnabled(true);
        ui->ln_edit_name->setEnabled(true);
        ui->ln_edit_country->setEnabled(true);
        ui->ln_edit_link->setEnabled(true);
        ui->ln_edit_phone->setEnabled(true);
        ui->txt_edit_bio->setEnabled(true);

    }


}


void edit_profile::on_btn_edit_name_clicked()
{
    string name ;
    name = ui->ln_edit_name->text().toStdString();
    User->Set_Name(name) ;
    QMessageBox qu ;
    qu.setText("*editted.") ;
    qu.exec();


}


void edit_profile::on_btn_edit_user_clicked()
{
    string username ;
    username = ui->ln_edit_user->text().toStdString();
    User->Set_User(username) ;
    QMessageBox qu ;
    qu.setText("*editted.") ;
    qu.exec();

}


void edit_profile::on_btn_edit_pass_clicked()
{
    string password ;
    password = ui->ln_edit_pass->text().toStdString();
    User->Set_Password(password) ;
    QMessageBox qu ;
    qu.setText("*editted.") ;
    qu.exec();

}


void edit_profile::on_btn_edit_age_clicked()
{
    string age ;
    age = ui->editprofile_dateEdit->text().toStdString();
    User->Set_Age(age) ;
    QMessageBox qu ;
    qu.setText("*editted.") ;
    qu.exec();

}


void edit_profile::on_btn_edit_phone_clicked()
{
    string phone ;
    phone = ui->ln_edit_phone->text().toStdString();
    User->Set_Phone(phone) ;
    QMessageBox qu ;
    qu.setText("*editted.") ;
    qu.exec();
}


void edit_profile::on_btn_edit_country_clicked()
{
    string country ;
    country = ui->ln_edit_country->text().toStdString();
    User->Set_Country(country) ;
    QMessageBox qu ;
    qu.setText("*editted.") ;
    qu.exec();
}


void edit_profile::on_btn_edit_link_clicked()
{
    string link ;
    link = ui->ln_edit_link->text().toStdString();
    User->Set_Link(link) ;
    QMessageBox qu ;
    qu.setText("*editted.") ;
    qu.exec();

}


void edit_profile::on_btn_edit_bio_clicked()
{
    string bio ;
    bio = ui->txt_edit_bio->toPlainText().toStdString();
    User->Set_Bio(bio) ;
    QMessageBox qu ;
    qu.setText("*editted.") ;
    qu.exec();
}

