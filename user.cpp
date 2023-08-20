#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "company.h"
#include "personal.h"
#include <fstream>
#include <QMessageBox>


using namespace std;

//---------------------------------------------------------------------------------
bool Common::ckeck_id(string &id) //This function ckeck the reserved word and @
{

    for (int i = 0 ; i < id.size() ; i++)
    {
        id[i] = tolower(id[i]);
    }

    if(id[0]=='@')
    {
        id.erase(0 , 1) ;
    }
    if(id=="exit"
    || id=="edit"
    || id=="login"
    || id=="signup"
    || id=="delete"
    || id=="username"
    || id=="password"
    || id=="tweet"
    || id=="retweet"
    || id=="tweet"
    || id=="like"
    || id=="dislike"
    || id=="mention"
    || id=="follow"
    || id== "help" )
    {

       return false;
    }

    return true;

}
//--------------------------------------------------------------------------------
int Common::Set_Name(string Name)//This function set the name
{
    this-> Name = Name;
}
//-------------------------------------------------------------------------------------------------------------
string Common::Get_Name()//This function get the name
{
    return Name;
}
//-------------------------------------------------------------------------------------------------------------
bool Common::User_val(string User_name)//This function check the username (validation)
{

     QMessageBox q;
    int counter = 0 , counter2 = 0 , counter3 = 0;

    string User = "" ;


    if(ckeck_id( User_name) == true)
    {
        if(User_name.size()>=5)
        {
            for (char c : User_name)
            {
            int num = c - '0'; // convert character to integer
            char ascii = static_cast<char>(num + '0'); // convert integer to ASCII
            User += ascii;
            }
            for( int i=0 ;i<User.size() ;i++)
            {
                if(User[0]>=65 && User[0]<=90 || User[0]>=97 && User[0]<=122 || User[0])// the first char should not be numbers
                {

                    if(User[i]>=65 && User[i]<=90 || User[i]>=97 && User[i]<=122 || User[i]>=48 && User[i]<=57)
                    {
                        counter++ ;
                    }
                    else
                    {

                        q.setText("! Your Username should only contains characters and numbers .");
                        q.exec();
                        return false;
                    }
                }
                else
                {

                    q.setText("! your Username should not start with numbers.");
                    q.exec();
                    return false;
                }
            }
        }
        else
        {

            q.setText("!Your Username should be more than 5 characters.");
            q.exec();
            return false;


        }
    }
    else
    {
        q.setText("! This is a reserved keyword. you can not choose it as your username." );
        q.exec();
        return false;
    }



return true;
}

//-------------------------------------------------------------------------------------------------------------

int Common::Set_User(string User)
{
    User_Name = User;
    return 0;

}

//-------------------------------------------------------------------------------------------------------------

int Common::Set_Phone(string Phone_Number)
{
     this->Phone_Number = Phone_Number;
    return 0;
}

//-------------------------------------------------------------------------------------------------------------

string Common::Get_User()
{
    return User_Name;
}

//-------------------------------------------------------------------------------------------------------------
bool Common::Pas_val(string password) //This function check the password (validation)
{
    QMessageBox q;// QMessageBox for showing message
    bool ch = false; //character
    bool num = false; //numbers
    string pass = "" ;
    if(password.size()> 4 ) //check size
    {
         for (char c : password )
        {
        int num = c - '0'; // convert character to integer
        char ascii = static_cast<char>(num + '0'); // convert integer to ASCII
        pass += ascii;
        }

        for( int i=0 ;i<pass.size() ;i++) //This function checks that all letters are characters
        {
            if(pass[i]>=65 && pass[i]<=90 || pass[i]>=97 && pass[i]<=122 )
            {
                ch = true;
            }
            else if(pass[i]>=48 && pass[i]<=57 )//This function checks that all letters are numbers
            {
                num = true;
            }
        }
    }
    else
    {
        q.setText( "! Your password must be more than 4 characters.");
        q.exec();
         return false;
    }

    if (ch == false || num == false)
    {

        q.setText( "! Password should contain both character and number.");
        q.exec();


         return false;
    }
    else if ( ch == false && num == true || ch== true && num==false) //Checking
    {
        q.setText( "! Password should contain both character and number.");
        q.exec();

        return false;
    }

    else
    {
        return true;
    }

}
//-------------------------------------------------------------------------------------------------------------

int Common :: Set_pass(string pass)
{
    Password = pass;
}

//-------------------------------------------------------------------------------------------------------------

string Common::Get_Password()
{
    return Password;
}

//-------------------------------------------------------------------------------------------------------------

void Common::Set_Header(string Header)
{
    this -> Header = Header;
}

//-------------------------------------------------------------------------------------------------------------

string Common::Get_Header()
{
    return Header;
}

//-------------------------------------------------------------------------------------------------------------

void Common::push_tweet(Tweet t)//For putting tweet in mtweet(map tweet) --with showing message
{
    QMessageBox q;
    q.setText("* Your tweet has been successfully registered.");
    mtweet[this->index] = t;
    q.exec();

}

//-------------------------------------------------------------------------------------------------------------

void Common::push_tweet2(Tweet t)//For putting tweet in mtweet(map tweet)--without showing message
{
    mtweet[this->index] = t;
}

//-------------------------------------------------------------------------------------------------------------

void Common::set_index()//This function increase tweet's number
{
    index++;
}

//-------------------------------------------------------------------------------------------------------------

void Common::delete_tweet(int Number)
{
    QMessageBox q;
    QMessageBox x;

    if(mtweet.find(Number)!=mtweet.end())
    {
        x.setText("* Your tweet has successfully deleted.");
        mtweet.erase(Number) ;
        x.exec();
    }
    else
    {
        q.setText("! We can not find this tweet.");
        q.exec();
    }
}

//-------------------------------------------------------------------------------------------------------------

string Common::backstring(int number)//This function checks that there is a tweet or not (in mtweet)
{
    if(mtweet.count(number)==1)
    {
        return mtweet[number].get_classtweet();
    }
    else
    {
        QMessageBox q ;
        q.setText(" this tweet does not exist.") ;
        q.exec() ;
    }
}

//-------------------------------------------------------------------------------------------------------------

void Common::Set_followers(int followers)//This function sets follower(number)
{
    this -> followers = followers;
}

//-------------------------------------------------------------------------------------------------------------

int Common::Get_followers()//This function return number of follower
{
    return followers;
}

//-------------------------------------------------------------------------------------------------------------

void Common::add_following(string addfollow)//This function pushback following's name in vector --with showing message
{
    QMessageBox q , q2;
    q.setText("* followed.");
    q2.setText("! You have already follow this account.");

    bool flag = 0 ;
    for(auto i : vecfollowing)
    {
        if(i == addfollow)
        {
            flag = 1 ;
            break ;
        }
    }
    if(flag == 0)
    {
        vecfollowing.push_back(addfollow) ;
        q.exec();
    }
    else
    {
        q2.exec();
    }

}

//-------------------------------------------------------------------------------------------------------------

void Common::add_following2(string addfollow)//This function pushback following's name in vector --without showing message
{
    bool flag = 0 ;
    for(auto i : vecfollowing)
    {
        if(i == addfollow)
        {
            flag = 1 ;
            break ;
        }
    }
    if(flag == 0)
    {
        vecfollowing.push_back(addfollow) ;
    }

}

//-------------------------------------------------------------------------------------------------------------

int Common::get_follow_person(string str)//check we have this person in our following or not
{

    for(auto i : vecfollowing )
    {
        if( i == str )
        {
            return 1 ;
        }
    }
    return 0 ;
}

//-------------------------------------------------------------------------------------------------------------

void Common::increase_follower()
{
   this->followers++ ;
}

//-------------------------------------------------------------------------------------------------------------

void Common::create_mention(string MENTION , int number ,string USER)//This function make mention
{
    if(mtweet.count(number)== 1)
    {

        Tweet mention ;
        mention.Set_User(USER) ;
        mention.set_number(mtweet[number].Get_mention().size()+1) ;
        mention.Set_Tweet(MENTION) ;
        mention.Set_date() ;
        mtweet[number].push_mention(mention) ;
        QMessageBox p ;
        p.setText("* Mentioned successfully.") ;
        p.exec() ;
   }

    else
    {
        QMessageBox p ;
        p.setText("! This tweet does not exist.") ;
        p.exec() ;

    }

}

//-------------------------------------------------------------------------------------------------------------

void Common::like_mention(Common* mmtn ,int NUMt , int NUMM)
{
    if(mtweet.count(NUMt) == 1)
    {
        if(NUMM > 0 && NUMM < mtweet[NUMt].Get_mention().size() + 1)
        {
            int check_flag = mtweet[NUMt].like_mntn(mmtn, NUMM-1);

            if(check_flag== 1)
             {
                QMessageBox p ;
                p.setText( "* Liked.");
                p.exec();
             }
        }
        else
        {
            QMessageBox p ;
            p.setText( "! Can not find the mention with this number.");
            p.exec();
        }
    }
    else
    {
        QMessageBox p ;
        p.setText( "! Can not find the tweet with this number.");
        p.exec();
    }
}


//-------------------------------------------------------------------------------------------------------------

void Common :: put_tweet()//We are putting our tweet in a text file with this function
{
    ofstream mytweet;
    mytweet.open("tweet.txt" , ios::app);
    if(mtweet.size() != 0)
    {
        mytweet << User_Name << endl;
        for(auto i : mtweet)
        {
            mytweet << i.first << ": " << i.second.get_classtweet() << endl  <<i.second.get_Date()
            << "likes:\n" ;
            for (int j = 0 ; j < i.second.liker_size() ; j++)
            {
                mytweet << i.second.show_likers(j) << endl;
            }
            mytweet << "------------------------------------------\n";

            for(auto j: i.second.Get_mention())
            {
                mytweet <<j.get_number()<< ": " << j.get_classtweet() << endl << j.get_Date() << endl << "likes:\n" ;

                for(int k = 0 ; k < j.liker_size() ; k++)
                {
                   mytweet << j.show_likers(k) << endl;
                }
               mytweet << "^^^^^" << endl ;
            }
            mytweet << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl ;
        }
        mytweet << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    }



    mytweet.close();
}

//-------------------------------------------------------------------------------------------------------------

void Common :: flike(Common* purpose , int index)//This function is used for liking tweets in file
{
     mtweet[index].likes(purpose);

}

//-------------------------------------------------------------------------------------------------------------

void Common :: follow_f(string purpose)//This function is used in file for add following
{
    vecfollowing.push_back(purpose);
}

//------------------------------------------------------------------------------------------

Tweet& Common  ::indx(int x)//This function check if we have one specific tweet or not
{
    if(mtweet.count(x) == 1)
    {
        return this->mtweet[x];
    }
}

//------------------------------------------------------------------------------------------

bool Common :: check_indx(int x , int y)//This function check if we have one specific tweet (and mention) or not
{
    if(mtweet.count(x) == 1 && mtweet[x].size_mention() >= y)
    {
        return true;
    }
    else
    {
        return false;
    }

}

//------------------------------------------------------------------------------------------

int Common :: get_size_mtweet()//This function return size of mtweet(map tweet)
{
     return mtweet.size();
}

//------------------------------------------------------------------------------------------

string Common :: get_mention( int numtweet  , int i)
{
     return mtweet[numtweet].Get_mention()[i].get_classtweet();
}

//------------------------------------------------------------------------------------------

int Common ::size_mention(int numbtweet)
{
     return mtweet[numbtweet].Get_mention().size() ;
}

//------------------------------------------------------------------------------------------

string Common :: getdate_mention(int numtweet  , int i)
{
     return  mtweet[numtweet].Get_mention()[i].get_Date();
}

//------------------------------------------------------------------------------------------

int Common :: get_mention_likes( Common *purpose, int index , int indexm)
{
    return purpose->mtweet[index].Get_mention()[indexm].likers.size();
}

//------------------------------------------------------------------------------------------

void Common :: set_mention(Tweet t ,int index)
{
    this->mtweet[index].push_mention(t) ;
}

//---------------------------------------------------------------------------------------------------------------

int Common::Get_following()//This function return size of vector(following)
{
    return vecfollowing.size();
}

//-------------------------------------------------------------------------------------------------------------

string Common::Get_indx_following(int i)//This function return index(following)
{
     return vecfollowing[i];
}

//-------------------------------------------------------------------------------------------------------------
