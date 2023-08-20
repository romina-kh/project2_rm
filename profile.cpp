#include "profile.h"
#include "ui_profile.h"
#include "user.h"
#include "twitterak.h"
#include "tweet.h"
#include "setting.h"
#include <QMessageBox>
#include <fstream>
#include "show_profile.h"
#include <QPixmap>
#include <QImage>


profile::profile(map <string , vector<Tweet>>& hashtag,unordered_map<string , Common*>& users,Common* cuser,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);

    User = cuser;
    set_pro(User);
    musers = users;
    mhashtag = hashtag;

    //this is for adding picture on the profile.
    QPixmap pixmap(QString::fromStdString(User->Get_Pic()));
    ui->lbl_picture->setPixmap(pixmap);
    ui->lbl_picture->setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);
    ui->lbl_picture->setFixedSize(100,100);

    QRegion *region = new QRegion(0 , 0 , ui->lbl_picture->width(), ui->lbl_picture->height(),QRegion::Ellipse);
    ui->lbl_picture->setScaledContents(true);
    ui->lbl_picture->setMask(*region);

    //this is for adding header on the top of the profile.
    QString style = "background-color: " +QString::fromStdString(User->Get_Header()) + ';' ;
    ui->groupBox_pic->setStyleSheet(style);

  {

    string following ;// showing the name of the people on the following part.
    QString qstr = QString::fromStdString(following);

    for (int i = 0 ; i < User->Get_following() ; i++)
      {
         following = User->Get_indx_following(i);
         qstr = QString::fromStdString(following);
         ui->listWidget_following->addItem(qstr);

      }

    ui->lbl_follower_pro->setText(QString ::number(User->Get_followers()));

  }


 show_tweet();

}

//-----------------------------------------------------------

profile::~profile()
{
    delete ui;
}

//-----------------------------------------------------------

void profile :: pfollow()//for putting following in file
{
    ofstream myfollow;
    myfollow.open("follow.txt" , ios::out);

    for ( auto i : musers)
    {
        myfollow << i.second->Get_User() << ":" << endl;
        for(int j = 0 ; j < i.second->Get_following(); j++)
        {
            myfollow << i.second->Get_indx_following(j) << endl;
        }
        myfollow << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    }

    myfollow.close();
}

//-----------------------------------------------------------

void profile :: ptweet()//putt tweets in file
{
    remove("tweet.txt");
    for ( auto i : musers)
    {
        i.second->put_tweet();
    }
}

//-----------------------------------------------------------

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


void profile :: findhash(string str, Tweet tobj)//find # in tweets
{
    string key;

    size_t found = str.find('#');
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

//-----------------------------------------------------------

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
        //t.Set_date();

        t.Set_date();
        t.Set_Tweet(tweet);
        User->set_index();
        t.set_number(User->get_index());
        User->push_tweet(t);


        string str = t.get_classtweet();
        findhash(str,t);
        ui->list_tweet->clear();
        show_tweet();
        ptweet();

     }
}

//-----------------------------------------------------------

void profile::on_btn_setting_clicked()
{
   setting * setting_obj = new setting(mhashtag, musers,User);

   setting_obj->show();

   set_pro(User);
   this->close();

}

//-----------------------------------------------------------

void profile::on_btn_like_pro_clicked()
{
    bool flag = false;
    Tweet t;
    string username ;

    int index;
    username = ui->ln_like_pro->text().toStdString();
    index = ui->ln_likenum_pro->text().toInt();
    if(musers.count(username) == 1)
    {
        if (User->Get_Name() == "Anonymous User")
        {

            for (int i = 0 ; i<User->Get_following() ; i++)
            {
                if (musers[username]->Get_User() == User->Get_indx_following(i))
                {
                    musers[username]->indx(index).likes(User , musers[username] , index);
                    ui->list_tweet->clear();
                    show_tweet();
                     ptweet();
                    flag = true;
                }
            }
            if (!flag)
            {
                QMessageBox::warning(this,"","You must follow this account to like this tweet.");
            }
        }
        else
        {

        musers[username]->indx(index).likes(User , musers[username] , index);

        ui->list_tweet->clear();
        show_tweet();
         ptweet();

        }
    }
    else
    {
         QMessageBox::warning(this,"","! This member does not exist.");
    }


    ui->ln_like_pro->clear();
    ui->ln_likenum_pro->clear();

}

//-----------------------------------------------------------

void profile::on_btn_follow_pro_clicked()
{
    string following ;
    QString qstr = QString::fromStdString(following);

    string username ;
    username = ui->ln_follow_pro->text().toStdString();

    if(musers.count(username) == 1 )
    {
        if (User == musers[username])
        {
            QMessageBox::warning(this,"", "You can not follow yourself.");
        }
        else if(musers[username]->Get_Name() == "Anonymous User")
        {
            QMessageBox::warning(this,"", "You can not follow this account.");
        }
        else
        {
            User->add_following(username) ;
            musers[username]->increase_follower() ;
            ui->listWidget_following->clear();
            for (int i = 0 ; i < User->Get_following() ; i++)
            {
                following = User->Get_indx_following(i);
                qstr = QString::fromStdString(following);
                ui->listWidget_following->addItem(qstr);

            }
            ui->lbl_follower_pro->setText(QString ::number(User->Get_followers()));

        }
    }
    else
    {
         QMessageBox::warning(this,"", "This user does not exist.");

    }

    pfollow();
    ui->ln_follow_pro->clear();

}

//-----------------------------------------------------------

void profile::on_btn_dislike_pro_clicked()
{
    bool flag = false;
    QMessageBox q;
    Tweet t;
    string username ;

    int index;
    username = ui->ln_like_pro->text().toStdString();
    index = ui->ln_likenum_pro->text().toInt();
    if(musers[username]->indx(index).check_like(User) == true)
    {
        if (User->Get_Name() == "Anonymous User")
        {

            for (int i = 0 ; i<User->Get_following() ; i++)
            {
                if (musers[username]->Get_User() == User->Get_indx_following(i))
                {
                    musers[username]->indx(index).dislike(User , musers[username] , index);
                     QMessageBox::information(this,tr(""), tr("Disliked."));
                    flag = true;
                }
                else
                {
                     QMessageBox::warning(this,"","you can not dislike before like.");
                }
            }
            if (!flag)
            {
                QMessageBox::warning(this,"","You must follow this account to like this tweet.");
            }
        }
        else
        {

            musers[username]->indx(index).dislike(User , musers[username] , index);
            QMessageBox::information(this,tr(""), tr("Disliked."));
        }
    }
    else
    {
         QMessageBox::warning(this,"","You must like this tweet first.");
    }


    ui->list_tweet->clear();
    show_tweet();


    ptweet();
    ui->ln_like_pro->clear();
    ui->ln_likenum_pro->clear();
}


//-----------------------------------------------------------

void profile::on_btn_deletetw_pro_clicked()
{
    int index;
    index = ui->ln_delete_pro->text().toInt();

    if (User->Get_Name() == "Anonymous User")
    {
        QMessageBox::warning(this,"","This account is not allowed to delete tweet.");
    }
    else
    {
        User->delete_tweet(index) ;
        ptweet();
        ui->ln_delete_pro->clear();
    }
     ui->list_tweet->clear();
    // ui->list_pro->clear();
    show_tweet();

}

//-----------------------------------------------------------

void profile::on_btn_mention_pro_2_clicked()
{

    Twitterak obj;
    string person , mention ;
    int number;
    int check1 ;
    person = ui->ln_mention_pro_3->text().toStdString();
    check1=User->get_follow_person(person) ;
    if(musers.count(person) == 1 )
    {
        if ( check1== 0  && User->Get_Name() == "Anonymous User" )
        {
            QMessageBox::warning(this,"","This account can not mention before follow.");
        }
        else
        {
            person = ui->ln_mention_pro_3->text().toStdString();
            number = ui->ln_mention_num_pro->text().toInt();
            mention = ui->ln_mention_final->text().toStdString();
            musers[person]->create_mention(mention ,number ,User->Get_User()) ;
            ptweet();
            ui->ln_mention_pro_3->clear();
            ui->ln_mention_num_pro->clear();
            ui->ln_mention_final->clear();

        }
    }
    else
    {
        QMessageBox::warning(this,"", "This user does not exist.");
    }
}

//-----------------------------------------------------------

void profile::show_tweet()
{
    QString qtweet;
    QString total;
    string tweet;
    Tweet t
            ;
    for(int i = 1 ; i <= User->get_size_mtweet(); i++)
    {
       tweet = User->indx(i).get_classtweet()  ;
       total = QString::fromStdString(tweet) + '\n' + QString::fromStdString(User->indx(i).get_Date()) + "like : "
               +QString::number(t.show_numberlikes(User , i));

       ui->list_tweet->addItem(total);

    }
}

//-----------------------------------------------------------

void profile::on_btn_mentionlike_pro_3_clicked()
{
    string username ;
    int indexmention ,indextweet ;

    username = ui->ln_like_pro->text().toStdString();
    indexmention = ui->ln_nummention_likee->text().toInt();
    indextweet = ui->ln_likenum_pro->text().toInt();

    if(musers.count(username) == 1 && musers[username]->check_indx(indextweet , indexmention) == true )//checking this character exist
    {
        musers[username]->like_mention(musers[User->Get_User()] , indextweet , indexmention) ;
    }
    else if(musers.count(username) != 1)
    {
        QMessageBox::warning(this,"","! This member does not exist.");
    }
    else
    {
        QMessageBox::warning(this,"","! This mention does not exist.");
    }

    ptweet();
    ui->ln_like_pro->clear();
    ui->ln_likenum_pro->clear();
}

//-----------------------------------------------------------

void profile::on_list_pro_itemClicked(QListWidgetItem *item)
{
    string str = ui->ln_search_pro->text().toStdString();
    show_profile * sh_p = new show_profile(musers[str]) ;

    sh_p->set_pro2(musers[str]) ;
    sh_p->show();
}

//-----------------------------------------------------------

void profile::show_mention()
{
    QMessageBox q;
    QString total;
    string men , date;
    int numtwt , like;
    string username;

    username = ui->ln_mention_list_pro->text().toStdString();
    numtwt = ui->ln_men_twt_num_list_pro->text().toInt();

    if(musers.count(username) == 1)
    {
        for(int i = 0 ; i < musers[username]->size_mention(numtwt); i++)
        {
            men = musers[username]->get_mention(numtwt , i)  ;
            date = musers[username]->getdate_mention(numtwt,i);

            total = QString::fromStdString(men) + '\n' +  QString::fromStdString(date) + "like : "
                    +QString::number(musers[username]->get_mention_likes(musers[username], numtwt , i));

            ui->list_mention->addItem(total);
        }
    }
    else
    {
        QMessageBox::warning(this,"","! This member does not exist.");
    }


    ui->ln_mention_list_pro->clear();
    ui->ln_men_twt_num_list_pro->clear();
}

//-----------------------------------------------------------

void profile::on_btn_showmention_clicked()
{
    ui->list_mention->clear();
    show_mention();

}

//-----------------------------------------------------------

void profile::on_btn_retweet_pro_2_clicked()
{
   string username = ui->ln_retweetname_pro_2->text().toStdString();
   int numtw = ui->ln_retweetnum_pro_3->text().toInt();

    if(musers.count(username) == 1)
    {
        string temp2 = musers[username]->backstring(numtw) ;
        if(temp2 == "null")
        {
            QMessageBox q ;
            q.setText(" this tweet does not exist.") ;
            q.exec() ;
        }
        else
        {
            Tweet new2;
            new2.Set_date();
            new2.Set_Tweet(temp2);
            musers[User->Get_User()]->set_index();
            new2.set_number(musers[User->Get_User()]->get_index());
            musers[User->Get_User()]->push_tweet(new2);
            QMessageBox::information(this,tr(""), tr("retweeted."));
            ui->list_tweet->clear();
            show_tweet();
        }

    }
    else
    {
        QMessageBox::warning(this,"","! this member does not exist.");
    }

   ui->ln_retweetname_pro_2->clear();
   ui->ln_retweetnum_pro_3->clear();
}

//-----------------------------------------------------------

void profile::on_btn_search_p_clicked()
{

    string str , key , tweet , date;
    QString qtweet;
    str = ui->ln_search_pro->text().toStdString();
    if (str[0] == '#')
    {
        key = str.erase(0,1);
    }

    if (mhashtag.count(key) == 1)
    {
        for (auto i : mhashtag[str])
        {
            tweet = i.get_classtweet();
            QString qstr = QString::fromStdString(tweet);
            ui->list_pro->addItem(qstr);
        }
    }
    else
    {
        if( musers.count(str)== 1 )
        {
            QString q =QString::fromStdString(str);
            ui->list_pro->addItem(q);
        }
    }
    //ui->list_pro->clear();
}

