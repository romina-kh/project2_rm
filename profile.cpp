#include "profile.h"
#include "ui_profile.h"
#include "user.h"
#include "twitterak.h"
#include "tweet.h"
#include "setting.h"
#include <QMessageBox>
#include <fstream>


profile::profile(map <string , vector<Tweet>>& hashtag,unordered_map<string , Common*>& users,Common* cuser,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
    User = cuser;
    musers = users;
    mhashtag = hashtag;
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


void profile :: put_hashtag()
{
    ofstream myhashtag;
    myhashtag.open("hashtag.txt", ios::out);
        for (auto i : mhashtag)
        {
            if(i.second.size() != 0)
            {
                myhashtag << i.first <<endl;

                for (auto j : i.second)
                {
                    myhashtag << j.get_number() << ": " << j.get_classtweet() << endl << j.get_Date();
                    myhashtag << "----------------------------------------\n";
                }
                myhashtag << "****************************************\n";
            }
        }
    myhashtag.close();
}


void profile :: in_hashtag()
{
    ifstream in_hash;
    in_hash.open("hashtag.txt" , ios::in);

    if (!in_hash)
    {
        cout << "Error !\n";
    }
    else
    {
        while(!in_hash.eof())
        {
            string hashtag;

            in_hash >> hashtag;

            if(hashtag == "")
            {
                break;
            }

            while(1)
            {
                Tweet tt;
                string num;
                string twt;
                string date;

                in_hash >> num;
                if (num == "****************************************")
                {
                    in_hash.ignore(1);
                    break;
                }

                num.pop_back();
                int index = stoi(num);
                tt.set_number(index);

                getline(in_hash , twt);
                twt = twt.substr(1 , twt.size()) ;
                tt.Set_Tweet(twt);


                mhashtag[hashtag].push_back(tt);

                while(1)
                {
                    in_hash >> date;

                    if (date == "----------------------------------------")
                    {
                        break;
                    }


                }
            }

        }

    }

    in_hash.close();



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


void profile :: findhash(string str, Tweet tobj)
{
    string key;

    size_t found = str.find('#');
   // int index = User->get_index();
    if (found != string::npos)
    {
       for (int i = 0; i < str.size() ; i++)
       {
            if(str[i] == '#')
            {
                for(int j = i + 1 ; j < str.size() ; j++)
                {

                    if(str[j] != ' ')
                    {
                        key += str[j];
                    }
                    else
                    {
                        i = j + 1;
                        break;
                    }
                }
                for ( int i = 0 ; i < key.size() ; i++)
                {
                    key[i] = tolower(key[i]);
                }
                mhashtag[key].push_back(tobj);

                key = "";
            }
       }

   }
}

void profile::on_btn_tweet_pro_clicked()
{

    Tweet t;
    Twitterak obj;
    string tweet , date;
    if (User->Get_Name() == "Anonymous User")
    {
    QMessageBox::warning(this,"","This account is not allowed to tweet.");
    }
    else
    {
        tweet = ui->ln_tweet_pro->text().toStdString();
        t.Set_date();
        t.Set_Tweet(tweet);
        t.Set_date();
        User->set_index();
        User->push_tweet(t);
        string str = t.get_classtweet();
        findhash(str,t);
        ptweet();
     }

}

void profile::on_btn_setting_clicked()
{
   setting * setting_obj = new setting(mhashtag, musers,User);

   setting_obj->show();

   set_pro(User);

   this->close();


}


void profile::on_btn_like_pro_clicked()
{

    Tweet t;
    string username ;

    int index;
    username = ui->ln_like_pro->text().toStdString();
    index = ui->ln_likenum_pro->text().toInt();


    musers[username]->indx(index).likes(User , musers[username] , index);
    QMessageBox::information(this,tr(""), tr("Liked."));


    ptweet();
    ui->ln_like_pro->clear();
    ui->ln_likenum_pro->clear();

}


void profile::on_btn_follow_pro_clicked()
{

    string username ;
    username = ui->ln_follow_pro->text().toStdString();
    if (User == musers[username])
    {
        QMessageBox::warning(this,"", "You can not follow yourself.");
    }
    else
    {
        User->add_following(username) ;
        musers[username]->increase_follower() ;
    }

    pfollow();
}


void profile::on_btn_dislike_pro_clicked()
{
    QMessageBox q;
    Tweet t;
    string username ;

    int index;
    username = ui->ln_dislike_pro->text().toStdString();
    index = ui->ln_dislikenum_pro->text().toInt();


    musers[username]->indx(index).dislike(User , musers[username] , index);
     QMessageBox::information(this,tr(""), tr("Disliked."));

    ptweet();
    ui->ln_dislike_pro->clear();
    ui->ln_dislikenum_pro->clear();
}




void profile::on_btn_search_clicked()
{
    string str , key;
    str = ui->ln_search_pro->text().toStdString();
    if (str[0] == '#')
    {
       //ui->listWidget->addItem()

    }
    else
    {

    }


}


void profile::on_btn_dislike_pro_2_clicked()
{

}

