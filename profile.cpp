#include "profile.h"
#include "ui_profile.h"
#include "user.h"
#include "twitterak.h"
#include "tweet.h"
#include "setting.h"

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
   Tweet t;
    string tweet , date;
    tweet = ui->ln_tweet_pro->text().toStdString();
    t.Set_date();
    t.Set_Tweet(tweet);
    t.Set_date();
    User->set_index();
    User->push_tweet(t);
    ptweet();

}

void profile::on_btn_setting_clicked()
{
    setting * setting_obj = nullptr;
    setting_obj = new setting;
    setting_obj->show();

}


void profile::on_btn_like_pro_clicked()
{
    Tweet t;
    string username ;
    int index;
    username = ui->ln_like_pro->text().toStdString();
    index = ui->ln_likenum_pro->text().toInt();


    musers[username]->indx(index).likes(User , musers[username] , index);
//    musers[username]->indx(index).show_likers(musers[username], index);
//    musers[username]->indx(index).show_numberlikes( musers[username], index);
    musers[username]->flike(musers[username] , index);

}

