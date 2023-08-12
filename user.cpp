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
//common
int Common::Set_Name(string Name)//This function set the name
{
    this-> Name = Name;
}


string Common::Get_Name()//This function set the name
{
    return Name;
}


int Common::Set_User(string User_name)//This function set the username (validation)
{

    int counter = 0 , counter2 = 0;

    string User = "" ;

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
                    cout << "! Your Username should only contains characters and numbers .\n" ;
                    return ++counter2;
                }
            }
            else
            {
                cout << "! your Username should not start with numbers.\n" ;
                return ++counter2;
            }
        }
    }
    else
    {
        cout << "! Your Username should be more than 5 characters.\n" ;
        return ++counter2;


    }
    if(counter == User.size())
    {
        User_Name = User;
        return 0;
    }

}


string Common::Get_User()
{
    return User_Name;
}


int Common::Set_Password(string password)
{
    hash<string> mystdhash;
    int counter = 0;
    bool ch = false; //character
    bool num = false; //numbers
    string pass = "" ;
    if(password.size()> 4 )
    {
         for (char c : password )
        {
        int num = c - '0'; // convert character to integer
        char ascii = static_cast<char>(num + '0'); // convert integer to ASCII
        pass += ascii;
        }

        for( int i=0 ;i<pass.size() ;i++)
        {
            if(pass[i]>=65 && pass[i]<=90 || pass[i]>=97 && pass[i]<=122 )
            {
                ch = true;
            }
            else if(pass[i]>=48 && pass[i]<=57 )
            {
                num = true;
            }
        }
    }
    else
    {
        cout << "! Your password must be more than 4 characters.\n";
        return ++counter ;
    }

    if (ch == false || num == false)
    {
        cout << "! Password should contain both character and number.\n" ;
        return ++counter;
    }
    else if ( ch == false && num == true || ch== true && num==false)
    {
         cout << "! Password should contain both character and number.\n" ;
        return ++counter;
    }

    // else
    // {
    //     Password = mystdhash(pass);
    //     return 0;
    // }
    else
    {
        Password = pass;
        return 0;
    }

}
//-------------------------------------------------------------------------------------------------------------
int Common::Set_Password_nohash(string password)
{
    hash<string> mystdhash;
    int counter = 0;
    bool ch = false; //character
    bool num = false; //numbers
    string pass = "" ;
    if(password.size()> 4 )
    {
         for (char c : password )
        {
        int num = c - '0'; // convert character to integer
        char ascii = static_cast<char>(num + '0'); // convert integer to ASCII
        pass += ascii;
        }

        for( int i=0 ;i<pass.size() ;i++)
        {
            if(pass[i]>=65 && pass[i]<=90 || pass[i]>=97 && pass[i]<=122 )
            {
                ch = true;
            }
            else if(pass[i]>=48 && pass[i]<=57 )
            {
                num = true;
            }
        }
    }
    else
    {
        cout << "! Your password must be more than 4 characters.\n";
        return ++counter ;
    }

    if (ch == false || num == false)
    {
        cout << "! Password should contain both character and number.\n" ;
        return ++counter;
    }
    else if ( ch == false && num == true || ch== true && num==false)
    {
         cout << "! Password should contain both character and number.\n" ;
        return ++counter;
    }

    else
    {
        Password_nohash = pass;
        return 0;
    }
        // Password_nohash = passwordd;
        // return 0;


}
//-------------------------------------------------------------------------------------------------------------
string Common::Get_Password_nonhash()//size
{
    return Password_nohash;
}

string Common::Get_Password()
{
    return Password;
}


void Common::Set_Header(string Header)
{
    this -> Header = Header;
}


string Common::Get_Header()
{
    return Header;
}


void Common::push_tweet(Tweet t)
{
    QMessageBox q;
    q.setText("* Your tweet has been successfully registered.");
    mtweet[this->index] = t;
    q.exec();

}


void Common::push_tweet2(Tweet t)
{

    mtweet[this->index] = t;

}


void Common::get_tweet()
{
    if(mtweet.size()==0)
    {
        cout << "! No tweet has been created.\n" ;
    }
    else
    {
        for(auto i: mtweet)
        {
            cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
            cout << i.first << ": " << i.second.get_classtweet() << endl << "likes : " <<  i.second.liker_size() <<endl ;
            cout << i.second.get_Date();

        }
            cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";

    }
}


void Common::get_tweet1(int index)
{
    if(mtweet.count(index)==1)
    {
        cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
        cout << mtweet[index].get_number() << ":" << mtweet[index].get_classtweet()<< endl << mtweet[index].get_Date() << endl;
    }
    else
    {
        cout << "! this Tweet does not exist.\n" ;
    }
}




string Common::get_tweet_hash()
{
    string twt;
    for(auto i: mtweet)
    {
        twt = i.second.get_classtweet() + " ";
    }
    return twt;

}


void Common::set_index()
{
    index++;
}

void Common::delete_tweet(int Number)
{
    QMessageBox q;
    q.setText("We can not find this tweet.");
    if(mtweet.find(Number)!=mtweet.end())
    {
        mtweet.erase(Number) ;
    }
    else
    {
        q.exec();
    }
}


void Common::edit_tweet(int nUmber)
{

    if(mtweet.find(nUmber)!= mtweet.end())
    {

        int totall=stoi(Age.substr(0 ,4)) ;
        if(totall>2005)
        {
            cout << "! cant edit tweet because You are under 18.\n"  ;
        }
        else
        {
            cout << "* Enter new text for tweet" << nUmber << ": " ;
            string newtwe ; //new tweet
            getline(cin , newtwe) ;
            mtweet[nUmber].Set_Tweet(newtwe) ;
            cout << "* Your tweet has been edited successfully.\n" ;
        }
    }
    else
    {
        cout << "! We can not find this tweet.\n" ;
    }
}

string Common::backstring(int number)
 {
    if(mtweet.count(number)==1)
    {
        return mtweet[number].get_classtweet();
    }
 }

    int Common::Get_following()//
{
    return vecfollowing.size();//
}



void Common::Set_followers(int followers)//
{
    this -> followers = followers;//
}


int Common::Get_followers()//
{
    return followers;//
}

void Common::add_following(string addfollow)
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
        q.exec();

        vecfollowing.push_back(addfollow) ;
        cout << "* followed.\n" ;
    }
    else
    {
        q2.exec();
        cout << "! You have already follow this account.\n" ;
    }

}



void Common::add_following2(string addfollow)
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





void Common::show_following()
{
    cout << Get_following() << endl ;
    cout << "name"<<endl;
    for(auto i : vecfollowing )
    {
        cout << i << endl ;
    }

}

void Common::increase_follower()
{
   this->followers++ ;
}

void Common::create_mention(int number ,string USER)//%%%%
{
    if(mtweet.count(number)==1)
    {
        Tweet mention ;
        mention.Set_User(USER) ;
        string MENTION ;
        cout << "* Enter your mention:\n" ;

        getline(cin , MENTION) ;
        mention.set_number(mtweet[number].Get_mention().size()+1) ;
        mention.Set_Tweet(MENTION) ;
        mention.Set_date() ;
        mtweet[number].push_mention(mention) ;

        cout << "* Mentioned successfully.\n" ;
    }
    else
    {
        cout << "! This tweet does not exist.\n" ;
    }

}

void Common::show_mention(int numtweet)
{
    unsigned int size =mtweet[numtweet].Get_mention().size() ;

    for ( size_t i = 0 ; i<size ; i++ )
    {
        cout << i+1 << ":" << mtweet[numtweet].Get_mention()[i].get_classtweet() << endl ;
        cout << mtweet[numtweet].Get_mention()[i].get_Date() << endl ;
        mtweet[numtweet].Get_mention()[i].show_numberlike_m(this ,numtweet , i) ;

    }
}

void Common::like_mention(Common* mmtn ,int NUMt , int NUMM)
{
    if(mtweet.count(NUMt) == 1)
    {
        if(NUMM > 0 && NUMM < mtweet[NUMt].Get_mention().size() + 1)
        {
            int check_flag = mtweet[NUMt].like_mntn(mmtn, NUMM-1);

            if(check_flag== 1)

             {
                cout << "* Liked.\n";
             }
        }
        else
        {
            cout << "! Can not find the mention with this number.\n";
        }
    }
    else
    {
        cout << "! Can not find the tweet with this number.\n";
    }
}


//============================================================================================================

void Common :: put_tweet()
{
    ofstream mytweet;
    mytweet.open("tweet.txt" , ios::app);
    if(mtweet.size() != 0)
    {
        mytweet << User_Name << endl;
        for(auto i : mtweet)
        {
            mytweet << i.first << ": " << i.second.get_classtweet() << endl  <<i.second.get_Date()
            << "likes: " ;
            for (int j = 0 ; j < i.second.liker_size() ; j++)
            {
                mytweet << i.second.show_likers(j) << " ";
            }
            mytweet << endl << "------------------------------------------\n";

            for(auto j: i.second.Get_mention())
            {
                mytweet <<j.get_number()<< ": " << j.get_classtweet() << endl << j.get_Date() << endl << "likes: " ;

                for(int k = 0 ; k < j.liker_size() ; k++)
                {
                   mytweet << j.show_likers(k) << " ";
                }
               mytweet << "^^^^^" << endl ;
            }
            mytweet << endl << "&&&" << endl ;
        }
        mytweet << "****************************************\n";

    }



    mytweet.close();
}

//==============================================================================================================

void Common :: put_follow()
{
    ofstream myfollow;
    myfollow.open("follow.txt" , ios::app);

    myfollow << User_Name << endl;

    for(int i = 0 ; i< vecfollowing.size(); i++)
    {
        myfollow << vecfollowing[i] << endl;
    }
    myfollow << "***************************************\n";
    myfollow.close();
}

//---------------------------------------------------------------------------------------------------------------
void Common :: flike(Common* purpose , int index)
{
    mtweet[index].likes(purpose);
}

void Common :: follow_f(string purpose)
{
    vecfollowing.push_back(purpose);
}
