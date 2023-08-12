#include <iostream>
#include <fstream>
#include "tweet.h"
#include "user.h"
#include <ctime>
#include <qmessagebox.h>



void Tweet:: Set_Tweet(string tweet)
{
    this -> tweet = tweet;
}


string Tweet::get_classtweet()
{
    return tweet;
}


void Tweet::set_number(int num)
{
    number = num;
}


int Tweet::get_number()
{
    return number;
}

void Tweet::Set_User(string userName)
{
    this->userName = userName ;
}


void Tweet::likes(Common* user ,Common* purpose, int index) //liking tweet
{
   QMessageBox q;

    bool flag = false;
    cout << purpose->mtweet[index].likers.size() <<endl;
    if(purpose->mtweet[index].likers.size() != 0)
    {
        cout << "1234567890\n";
        for (auto i : purpose->mtweet[index].likers )
        {
            if (i == user)
            {
                flag = true;
            }
        }
        if (flag == false)
        {
            purpose->mtweet[index].likers.push_back(user);
            q.setText("* liked.");
            q.exec();
            cout << "* liked.\n" ;
        }
        else
        {
            cout << "! you can not like this tweet again.\n";
        }
    }

    else
    {
        purpose->mtweet[index].likers.push_back(user);
        cout << "* liked 3333.\n" ;
    }

}


void Tweet:: show_numberlikes( Common *purpose, int index) //number of likes
{
    cout << "Likes : " << purpose->mtweet[index].likers.size()<< endl ;
}


void Tweet:: show_likers(Common* purpose, int index) //showing users (likes tweet)
{
    for(auto i : purpose->mtweet[index].likers)
    {
        cout << i->Get_User()<<endl;
    }
}


void Tweet::dislike(Common* user ,Common* purpose, int index)
{
    QMessageBox q;
    for (int i = 0 ; i < purpose->mtweet[index].likers.size() ; i++ )
    {
        if (purpose->mtweet[index].likers.at(i) == user )
        {
            purpose->mtweet[index].likers.erase(purpose->mtweet[index].likers.begin() + i);
            q.setText("* disliked.");
            q.exec();
        }
    }
}


void Tweet:: Set_date()
{
    time_t now = time(0);
    string dt = ctime(&now);
    Date = dt;
}


string Tweet::get_Date()
{
    return Date ;
}


int Tweet::liker_size()
{
    return likers.size();
}

void Tweet::push_mention(Tweet mention)//%%%%
{
    mentions.push_back(mention) ;
}


vector<Tweet> Tweet:: Get_mention()
{
    return mentions ;
}

int Tweet::like_mntn(Common* Accountm , int index)
{
    bool flg = 0 ;
    for(auto i: mentions[index].likers)
    {
        if(i == Accountm)
        {
            flg = 1;
            break;
        }
    }
    if(flg == 0)
    {
        mentions[index].likers.push_back(Accountm) ;
        return 1 ;
    }
    else
    {
        cout << "! You have already liked this mention.\n" ;
        return 0;
    }

}

void Tweet::show_numberlike_m( Common *purpose, int index , int indexm)
{
    cout << "Likes : " << purpose->mtweet[index].Get_mention()[indexm].likers.size()<< endl << endl << endl ;
}


string Tweet :: show_likers(int index)
{
    return likers[index]->Get_User();
}

void Tweet :: Set_date(string Date)
{
    this->Date = Date;
}

void Tweet :: sett()
{

}

//-----------------------------------------------------------------------------------
void Tweet::likes(Common* purpose) //liking tweet
{

likers.push_back(purpose);

}
