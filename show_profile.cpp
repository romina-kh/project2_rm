#include "show_profile.h"
#include "ui_show_profile.h"
#include "user.h"
#include "profile.h"

show_profile::show_profile(Common* User ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::show_profile)
{
    user = User ;
    ui->setupUi(this);
    show_tweet();
    show_follow();
}

show_profile::~show_profile()
{
    delete ui;
}

void show_profile :: set_pro2(Common* user)
{
    ui->lbl_name_pro->setText(QString ::fromStdString(user->Get_Name()));
    ui->lbl_link_pro->setText(QString ::fromStdString(user->Get_Link()));
    ui->lbl_contry_pro->setText(QString ::fromStdString(user->Get_Country()));
    ui->lbl_phone_pro->setText(QString ::fromStdString(user->Get_Phone()));
    ui->lbl_user_pro->setText(QString ::fromStdString(user->Get_User()));
    ui->lbl_age_pro->setText(QString ::fromStdString(user->Get_Age()));
    ui->txtb_bio->setText(QString ::fromStdString(user->Get_Bio()));
}


void show_profile ::show_tweet()
{
    QString qtweet;
    QString total;
    string tweet;
    Tweet t;
    for(int i = 1 ; i <= user->get_size_mtweet(); i++)
    {
       tweet = user->indx(i).get_classtweet()  ;
       total = QString::fromStdString(tweet) + '\n' + QString::fromStdString(user->indx(i).get_Date()) + "like : "
               +QString::number(t.show_numberlikes(user , i));

       ui->list_tweet_show->addItem(total);

    }
}




void show_profile ::show_follow()
{

     ui->lbl_following_show->setText(QString ::number(user->Get_following()));
    ui->lbl_follower_show->setText(QString ::number(user->Get_followers()));

}

void show_profile::on_pushButton_clicked()
{

    this->close() ;
}

