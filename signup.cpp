#include "signup.h"
#include "ui_signup.h"
#include "twitterak.h"
#include "QLineEdit"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}



void signup::on_btn_done_signup_clicked()
{

    Twitterak app;
    app.in_user();
    app.in_tweet();
//    app.in_follow();
//    app.in_hashtag();

    string username , password , name , phone , country , link , bio , age;
    username = ui->ln_username_s->text().toStdString();
    password = ui->ln_password_s->text().toStdString();
    age = ui->dateEdit_age_s->text().toStdString();
    name = ui->ln_name_s->text().toStdString();
    phone = ui->ln_phone_s->text().toStdString();
    country = ui->ln_country_s->text().toStdString();
    link = ui->ln_link_s->text().toStdString();
    bio = ui->plainTxt_bio_s->toPlainText().toStdString();

    if (ui->rbtn_personal_s->isChecked())
    {
        app.signup(username ,name ,age ,phone, country, link , bio , password);
    }

    if (ui->rbtn_organ_s->isChecked())
    {
         app.signup_org(username ,name ,phone , country, link , bio , password);
    }

    if(ui->rbtn_ano_s->isChecked())
    {
        app.signup_ano(username , password);
    }





}




void signup::on_dateEdit_age_s_userDateChanged(const QDate &date)
{

}


void signup::on_rbtn_organ_s_clicked()
{
    ui->dateEdit_age_s->setEnabled(false);
    ui->ln_name_s->setEnabled(true);
    ui->ln_country_s->setEnabled(true);
    ui->ln_link_s->setEnabled(true);
    ui->ln_phone_s->setEnabled(true);
    ui->plainTxt_bio_s->setEnabled(true);

}


void signup::on_rbtn_personal_s_clicked()
{
    ui->ln_name_s->setEnabled(true);
    ui->ln_country_s->setEnabled(true);
    ui->ln_link_s->setEnabled(true);
    ui->ln_phone_s->setEnabled(true);
    ui->dateEdit_age_s->setEnabled(true);
    ui->plainTxt_bio_s->setEnabled(true);
}



void signup::on_rbtn_ano_s_clicked()
{
    ui->ln_name_s->setEnabled(false);
    ui->ln_country_s->setEnabled(false);
    ui->ln_link_s->setEnabled(false);
    ui->ln_phone_s->setEnabled(false);
    ui->dateEdit_age_s->setEnabled(false);
    ui->plainTxt_bio_s->setEnabled(false);

}


void signup::on_pushButton_clicked()
{
    Twitterak t;
    t.in_user();
    t.in_tweet();
    t.in_follow();
    string username , pass;
    username = ui->ln_username_s->text().toStdString();
    pass = ui->ln_password_s->text().toStdString();
    t.login(username , pass);
}

