#include "profile.h"
#include "ui_profile.h"
#include "user.h"
#include "twitterak.h"

profile::profile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
}

profile::~profile()
{
    delete ui;
}

void profile :: set_pro(Common* user)
{
    ui->lbl_name_pro->setText(QString ::fromStdString(user->Get_Name()));
    ui->lbl_link_pro->setText(QString ::fromStdString(user->Get_Link()));
    ui->lbl_country_pro->setText(QString ::fromStdString(user->Get_Country()));
    ui->lbl_phone_pro->setText(QString ::fromStdString(user->Get_Phone()));
    ui->lbl_user_pro->setText(QString ::fromStdString(user->Get_User()));
    ui->lbl_age_pro->setText(QString ::fromStdString(user->Get_Age()));
    ui->textBrowser_bio_pro->setText(QString ::fromStdString(user->Get_Bio()));
}

void profile::on_btn_tweet_pro_clicked()
{
    cout << "4";
    Twitterak t;
    string tweet;
    tweet = ui->ln_tweet_pro->text().toStdString();
    cout << "1";
    t.qttweet(tweet);
    cout << "2";
    t.ptweet();
    cout << "3";


}

