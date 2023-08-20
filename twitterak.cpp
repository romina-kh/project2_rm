#include <iostream>
#include <unordered_map>
#include <string>
#include "user.h"
#include "tweet.h"
#include "twitterak.h"
#include <bitset>
#include <functional>
#include <vector>
#include <sstream>
#include "company.h"
#include "personal.h"
#include "anonymous.h"
#include <fstream>
#include <qmessagebox.h>
#include "profile.h"

using namespace std ;

//objects of classe
//Common* user = nullptr;
Common* user = nullptr;
Tweet tweet_object;



//----------------------------------------------------------------------------------------------------------------
//personal signup
bool Twitterak::signup(string User , string Name, string Age ,string Phone_Number, string Country , string Link , string Bio , string Password , string img ,string header)
{
    //for checking validation
    bool fuser = false;
    bool fpass =false;
    bool fphone =false;
    bool fbio = false;
    bool fname = false;
    QMessageBox q;


    user = new Personal;

    if(!musers.count(User))
    {
        if(user->User_val(User) == true)
        {
            user->Set_User(User);
            fuser = true;
        }

    }
    else
    {
        q.setText("! There is a user with this username .");
        q.exec();


    }

    if(Name == "")
    {
        q.setText("! Please enter your name.");
        q.exec();
    }
    else
    {
         user->Set_Name(Name);
         fname = true;
    }

    user->Set_Age(Age);

    if(user->Phone_val(Phone_Number) ==  true)
    {
         user->Set_Phone(Phone_Number);
         fphone = true;
    }

    user->Set_Country(Country);
    user->Set_Link(Link);
    if(user->Bio_val(Bio)==true)
    {
         user->Set_Bio(Bio);
         fbio = true;
    }
    user->Set_Bio(Bio);
    if(user->Pas_val(Password)== true)
    {
        user->Set_pass(Password);
        fpass = true;
    }

    user->Set_Pic(img);
    user->Set_Header(header) ;

    if(fuser==true && fpass == true && fphone == true && fbio == true &&  fname == true)
    {
         musers[user->Get_User()] = user;
        put_user();
        q.setText("*signup");
        q.exec();
        return true;


    }
    else
    {
        return false;
    }

}
//----------------------------------------------------------------------------------------------------------------------------
//anonymous signup
bool Twitterak::signup_ano(string User, string Password ,string header)
{
    bool fuser = false;
    bool fpass =false;


    QMessageBox q;

    user = new Anonymous;



    if(!musers.count(User))
    {
        if(user->User_val(User) == true)
        {
            user->Set_User(User);
            fuser = true;
        }

    }
    else
    {
        q.setText("! There is a user with this username .");
        q.exec();


    }

    user->Set_Header(header) ;
    user->Set_Name("Anonymous User");
    if(user->Pas_val(Password)== true)
    {
        user->Set_pass(Password);
        fpass = true;
    }


    if(fuser==true && fpass == true)
    {
         musers[user->Get_User()] = user;
        put_user();
        q.setText("*signup");
        q.exec();
        return true;


    }
    else
    {
        return false;
    }



}
//---------------------------------------------------------------------------------------------------------------------------
//organisation signup
bool Twitterak::signup_org(string User , string Name ,string Phone_Number, string Country , string Link , string Bio , string Password , string manager , string img ,string header)
{
    bool fuser = false;
    bool fpass =false;
    bool fphone = false;
    bool fbio = false;
    bool fname = false;

    QMessageBox q;
    if(musers.count(manager) == 1 && musers[manager]->Get_Name() != "Anonymous User")
    {
        user = new Company;

        if(!musers.count(User))
        {
            if(user->User_val(User) == true)
            {
                user->Set_User(User);
                fuser = true;
            }

        }
        else
        {
            q.setText("! There is a user with this username .");
            q.exec();

        }

        if(Name == "")
        {
            q.setText("! Please enter your name.");
            q.exec();
        }
        else
        {
             user->Set_Name(Name);
             fname = true;
        }
        user->Set_Header(header) ;

        if(user->Phone_val(Phone_Number) ==  true)
        {
             user->Set_Phone(Phone_Number);
             fphone = true;
        }

        user->Set_Country(Country);
        user->Set_Link(Link);
        if(user->Bio_val(Bio)==true)
        {
             user->Set_Bio(Bio);
             fbio = true;
        }
        if(user->Pas_val(Password)== true)
        {
            user->Set_pass(Password);
            fpass = true;
        }
        user->Set_Pic(img);

        if(fuser==true && fpass == true && fphone == true && fbio == true &&  fname == true)
        {
             musers[user->Get_User()] = user;
            put_user();
            q.setText("*signup");
            q.exec();
            return true;


        }
        else
        {
            return false;
        }
    }
    else
    {
        q.setText("! There is no user with this username or it is an anonymous user. ");
        q.exec();
        return false;
    }


    //temp

}

//----------------------------------------------------------------------------------------------------------------

bool Twitterak::login(string usern , string pass)
{

    QMessageBox q;

        if(musers.count(usern) == 1)
        {
            if(musers[usern]->Get_Password() ==  pass)
            {
                user = musers[usern] ;
                temp = usern;

                q.setText("*login");

                q.exec();


                return true;


            }
            else
            {
                q.setText("! Your password is incorect.");
                q.exec();
                return false;

            }

        }
        else
        {
            q.setText("! This Username is not found.");
            q.exec();
           return false;

        }


}


//----------------------------------------------------------------------------------------------------------------

void Twitterak::show(string account)//for showing profile
    {

        profile* pro = new profile(mhashtag,musers , musers[account]);
        pro->set_pro(musers[account]);

        pro->show();

    }

//----------------------------------------------------------------------------------------------------------------

void Twitterak :: findhash(string str, Tweet tobj)//for find hashtag
{
    string key;
    size_t found = str.find('#');
//    int index = musers[temp]->get_index();
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

//----------------------------------------------------------------------------------------------------------------

void Twitterak :: put_user()//put users in file
{
    ofstream outuser;
    outuser.open("user.txt", ios::out);

    Personal* per;
    Anonymous* ano;
    Company* org;

    for (auto i : musers)
    {
        per = dynamic_cast<Personal*>(i.second);
        ano = dynamic_cast<Anonymous*>(i.second);
        org = dynamic_cast<Company*>(i.second);

        if (per != NULL)
        {
            outuser << i.second->Get_User() << "p" ;
        }
        if (ano != NULL)
        {
            outuser << i.second->Get_User() << "a" ;
        }
        if (org != NULL)
        {
            outuser << i.second->Get_User() << "o" ;
        }
        outuser << endl << i.second->Get_Name() << endl << i.second->Get_Age() << endl
               << i.second->Get_Phone() << endl << i.second->Get_Country() << endl << i.second->Get_Link() << endl <<
               i.second->Get_Bio() << endl << i.second->Get_Password() << endl << i.second->Get_Pic() <<endl << i.second->Get_Header() << endl
        << "************************************************\n";

    }

    outuser.close();
}

//----------------------------------------------------------------------------------------------------------------
void Twitterak :: ptweet() //put tweet in file
{
    remove("tweet.txt");//remove file first to avoid rewriting
    for ( auto i : musers)
    {
        i.second->put_tweet();
    }
}


//----------------------------------------------------------------------------------------------------------------
void Twitterak :: in_user()//reading (user) from file
{
    QMessageBox q;
    string username;
    string name;
    string age;
    string phone_number;
    string country;
    string link;
    string bio;
    string password;
    string picture;
    string Header ;

    ifstream in_user;
    in_user.open("user.txt" , ios::in);

    if(in_user.is_open())
    {
        while(!in_user.eof())
        {
            Common* file_user;

            getline (in_user, username);
            if (username[username.size()-1] == 'p')
            {
                file_user = new Personal;
            }
            else if (username[username.size()-1] == 'a')
            {
                file_user = new Anonymous;
            }
            else if (username[username.size()-1] == 'o')
            {
                file_user = new Company;
            }

            username.pop_back();
            file_user->Set_User(username);
            musers[username] = file_user;

            getline (in_user, name);
            musers[username]->Set_Name(name);

            getline (in_user, age);
            musers[username]->Set_Age(age);

            getline (in_user, phone_number);
            musers[username]->Set_Phone(phone_number);

            getline (in_user, country);
            musers[username]->Set_Country(country);

            getline (in_user, link);
            musers[username]->Set_Link(link);

            getline (in_user, bio);
            musers[username]->Set_Bio(bio);

            getline (in_user, password);
            musers[username]->Set_pass(password);

            getline(in_user , picture );
            musers[username]->Set_Pic(picture);

            getline(in_user ,Header);
            musers[username]->Set_Header(Header);

            in_user.ignore(49);
        }
    }
    in_user.close();
}

//----------------------------------------------------------------------------------------------------------------

void Twitterak :: in_tweet()//reading (tweet) from file
{

    ifstream in_tweet;
    in_tweet.open("tweet.txt" , ios::in);


    if(in_tweet.is_open())
    {
        while(!in_tweet.eof())
        {
            string username;
            in_tweet >> username;
            if(username == "")
            {
                break;
            }

            while(true)
            {
                Tweet t;
                string date;
                string like ;
                string liker;
                string tweet;
                string numb;
                string nummen ;
                string men ;
                string datemen ;
                string likemen ;
                string empty;

                in_tweet >> numb ;
                if (numb == "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
                {
                    in_tweet.ignore(1);
                    break;
                }
                //--------------------------
                numb.pop_back();
                int index = stoi(numb);
                t.set_number(index);
                //--------------------------
                getline(in_tweet , tweet);
                tweet = tweet.substr(1 , tweet.size()) ;
                t.Set_Tweet(tweet);
                findhash(tweet , t);
                //--------------------------
                getline (in_tweet , date);
                date.append("\n");
                t.Set_date(date);
                musers[username]->set_index();
                musers[username]->push_tweet2(t);

                //--------------------------
                getline(in_tweet , like);

                while(getline(in_tweet , liker))
                {
                    if (liker == "------------------------------------------")
                    {
                        break;
                    }
                    musers[username]->flike(musers[liker] , index);
                }
                //--------------------------
                in_tweet >> nummen ;

                while(nummen != "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
                {
                    Tweet tmen ;
                 nummen.pop_back() ;
                    tmen.set_number(stoi(nummen));
                    //--------------------------
                    getline(in_tweet ,men) ;
                    men.erase(0,1);
                    tmen.Set_Tweet(men) ;
                    //--------------------------
                    getline(in_tweet ,datemen) ;
                    datemen.append("\n");
                    tmen.Set_date(datemen) ;
                    //--------------------------
                    in_tweet.ignore();
                    getline(in_tweet , like);

                    while(getline(in_tweet , likemen))
                    {
                        if (likemen == "^^^^^")
                        {
                            break;
                        }
                        tmen.likes(musers[likemen]) ;
                    }
                   musers[username]->set_mention(tmen , index) ;
                   in_tweet >> nummen;
                }

            }

        }

    }

    in_tweet.close();
}

//----------------------------------------------------------------------------------------------------------------

void Twitterak :: in_follow()//reading (follow) from file
{
    ifstream in_follow;

    QMessageBox q;
    in_follow.open("follow.txt" , ios::in);

    if(in_follow.is_open())
    {
        while(!in_follow.eof())
        {
            string username;
            in_follow >> username;

            if(username == "")
            {
                break;
            }
            username.pop_back();

            string following;
            while(following != "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
            {
                in_follow >> following;
                if(following == "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
                {
                    break;
                }
                musers[username]->add_following2(following);
                musers[following]->increase_follower();
            }
        }
    }

in_follow.close();

}

