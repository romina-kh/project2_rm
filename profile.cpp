#include "profile.h"
#include "ui_profile.h"
#include "user.h"
#include "twitterak.h"
#include "tweet.h"
#include "setting.h"
#include <QMessageBox>

profile::profile(unordered_map<string , Common*>& users,Common* cuser,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    User = cuser;
    musers = users;
}

profile::~profile()
{
    delete ui;
}


void profile :: pfollow()
{
    remove("follow.txt");
    for ( auto i : musers)
    {
        i.second->put_follow();
    }
}


void profile :: ptweet()
{
    remove("tweet.txt");
    for ( auto i : musers)
    {
        i.second->put_tweet();
    }
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
    QMessageBox q;
    Tweet t;
    string tweet , date;
    if (User->Get_Name() == "Anonymous User")
    {
       q.setText( "! This account is not allowed to tweet.");
       q.exec();
    }
    else
    {
        tweet = ui->ln_tweet_pro->text().toStdString();
        t.Set_date();
        t.Set_Tweet(tweet);
        t.Set_date();
        User->set_index();
        User->push_tweet(t);
        ptweet();
     }

}

void profile::on_btn_setting_clicked()
{
    setting * setting_obj = nullptr;
    setting_obj = new setting;
    setting_obj->show();

}


void profile::on_btn_like_pro_clicked()
{
    QMessageBox q;
    Tweet t;
    string username ;

    int index;
    username = ui->ln_like_pro->text().toStdString();
    index = ui->ln_likenum_pro->text().toInt();


    musers[username]->indx(index).likes(User , musers[username] , index);

    ptweet();
    ui->ln_like_pro->clear();
    ui->ln_likenum_pro->clear();

}


void profile::on_btn_follow_pro_clicked()
{
    QMessageBox q;
    string username ;
    username = ui->ln_follow_pro->text().toStdString();
    if (User == musers[username])
    {
        q.setText("! You can not follow yourself.");
        q.exec();
    }
    else
    {
        User->add_following(username) ;
        musers[username]->increase_follower() ;
    }

    pfollow();
}

