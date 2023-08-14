#include "setting.h"
#include "ui_setting.h"
#include "mainwindow.h"
#include "profile.h"
#include "twitterak.h"
#include "user.h"
#include "personal.h"
#include "anonymous.h"
#include "company.h"
#include <fstream>
#include "edit_profile.h"


setting::setting(map <string , vector<Tweet>>& hashtag,unordered_map<string , Common*>& users,Common* user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
   User = user;
   musers = users;
   mhashtag= hashtag ;
}


void setting :: put_user()
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
    this->close();

}


void setting::on_btn_delete_setting_clicked()
{
    MainWindow * delete_btn = nullptr ;
    delete_btn = new MainWindow ;
    delete_btn->show() ;
    musers.erase(User->Get_User());
    put_user();


}


void setting::on_btn_edit_setting_clicked()
{
    edit_profile * edit_btn = nullptr ;
    edit_btn = new edit_profile(musers , User) ;
    edit_btn->show() ;

}


void setting::on_btn_back_clicked()
{

    profile* profile_obj = new profile(mhashtag, musers,User);
    // put_user();
    //Twitterak * tw= new Twitterak ;
    //tw = new Twitterak ;
    //cout << User->Get_User() ;
    //tw->login(User->Get_User(), User->Get_Password());
    profile_obj->show();
    //tw->show(User->Get_User()) ;
    this->close() ;


}

