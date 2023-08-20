#include <iostream>
#include <fstream>
#include "tweet.h"
#include "user.h"
#include <ctime>
#include "QMessageBox"
#include <qmessagebox.h>




void Tweet:: Set_Tweet(string tweet)
{
    this -> tweet = tweet;
}

//-----------------------------------------------------------------------------------

string Tweet::get_classtweet()
{
    return tweet;
}

//-----------------------------------------------------------------------------------

void Tweet::set_number(int num)
{
    number = num;
}

//-----------------------------------------------------------------------------------

int Tweet::get_number()
{
    return number;
}

//-----------------------------------------------------------------------------------

void Tweet::Set_User(string userName)
{
    this->userName = userName ;
}

//-----------------------------------------------------------------------------------

void Tweet::likes(Common* user ,Common* purpose, int index) //it likes the tweet.
{
    if(purpose->mtweet.count(index) == 1)//check that username exist.
    {
        bool flag = false;

        if(purpose->mtweet[index].likers.size() != 0)
        {
            for (auto i : purpose->mtweet[index].likers )//check that username has liked.
            {
                if (i == user)
                {
                    flag = true;
                }
            }
            if (flag == false)
            {
                purpose->mtweet[index].likers.push_back(user);
                QMessageBox q;
                q.setText("* liked.");
                q.exec();

            }
            else
            {
                QMessageBox q;
                q.setText("! you can not like this tweet again.");
                q.exec();
            }
        }

        else
        {
            purpose->mtweet[index].likers.push_back(user);//it push the username in likers vector.
            QMessageBox q;
            q.setText("* liked.");
            q.exec();

        }
    }
    else
    {
        QMessageBox q;
        q.setText("! this tweet does not exist.");
        q.exec();
    }

}

//-----------------------------------------------------------------------------------

int Tweet:: show_numberlikes( Common *purpose, int index) //show the number of likes
{
    return  purpose->mtweet[index].likers.size();
}

//-----------------------------------------------------------------------------------

void Tweet::dislike(Common* user ,Common* purpose, int index)//dislike the tweet.
{

    for (int i = 0 ; i < purpose->mtweet[index].likers.size() ; i++ )
    {
        if(purpose->mtweet[index].likers.at(i) == user )
        {
             purpose->mtweet[index].likers.erase(purpose->mtweet[index].likers.begin() + i);
        }
    }
}

//-----------------------------------------------------------------------------------

void Tweet:: Set_date()//set the date for each tweet at the right time.
{
    time_t now = time(0);
    string dt = ctime(&now);
    Date = dt;
}

//-----------------------------------------------------------------------------------

void Tweet :: Set_date(string Date)
{
    this->Date = Date;
}

//-----------------------------------------------------------------------------------

string Tweet::get_Date()
{
    return Date ;
}

//-----------------------------------------------------------------------------------

int Tweet::liker_size()//get size of vector(liker)
{
    return likers.size();
}

//-----------------------------------------------------------------------------------

void Tweet::push_mention(Tweet mention)
{
    mentions.push_back(mention) ;
}

//-----------------------------------------------------------------------------------

vector<Tweet> Tweet:: Get_mention()//it returns the exact mention object.
{
    return mentions ;
}

//-----------------------------------------------------------------------------------

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
        QMessageBox q;
        q.setText("! you have already liked this mention.");
        q.exec();
        return 0;
    }

}

//-----------------------------------------------------------------------------------

string Tweet :: show_likers(int index)//it shows the name of the people who have liked.
{
    return likers[index]->Get_User();
}

//-----------------------------------------------------------------------------------

void Tweet::likes(Common* purpose) //push the name of the likers in likers vector.
{
    likers.push_back(purpose);
}

//-----------------------------------------------------------------------------------

int Tweet ::size_mention()//it returns the size of vector mention.
{
    return mentions.size();
}

//-----------------------------------------------------------------------------------

bool Tweet :: check_like(Common* purpose)//check this tweet is liked or not (for dislike)
{
    if(count(this->likers.begin(),this->likers.end() , purpose))
    {
        return true;
    }
    else
    {
        return false;
    }
}
