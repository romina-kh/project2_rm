#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <string>
#include <vector>
#include "tweet.h"
#include <map>

using namespace std;
class Common //parent
{
    friend void Tweet:: likes(Common* currentuser, Common* target, int index);
    friend void Tweet:: likes(Common* target);
    friend void Tweet:: show_numberlikes( Common *target, int index);
    friend void Tweet:: show_likers(Common* target, int index);
    friend void Tweet:: dislike(Common* currentuser ,Common* target, int index);
    friend void Tweet::show_numberlike_m( Common *purpose, int index ,int indexm);//friend for liking mention
    protected:
        // map<string , vector<Tweet*>>
        vector<string> vecfollowing ;
        string Name;
        string User_Name;
        string Password;
        string Password_nohash;//size_t
        string Picture; //profile pic
        string Header; //header color
        string Age;
        string Phone_Number;
        string Country;
        string Link;
        string Bio;
        int followers = 0;


        int index = 0 ;

    public:
map<int ,Tweet> mtweet;
        virtual int Set_Name(string Name);
        virtual string Get_Name();

        virtual int Set_User(string User_Name);
        virtual string Get_User();

        virtual int Set_Password(string Password);
        virtual string Get_Password();//string / size_t
        virtual int Set_Password_nohash(string Password);
        virtual string Get_Password_nonhash();

        virtual int Set_Bio(string Bio){};
        virtual string Get_Bio(){return "______";};

        virtual int Set_Country(string Country){};
        virtual string Get_Country(){return "______";};

        virtual int Set_Link(string Link){};
        virtual string Get_Link(){return "______";};

        virtual int Set_Age(string Age){};
        virtual string Get_Age(){return "______";};

        virtual int Set_Phone(string Phone_Number){};
        virtual string Get_Phone(){return "______";};

        virtual void Set_Header(string Header);
        virtual string Get_Header();

        // virtual void push_tweet(string t);
        virtual void push_tweet(Tweet t);
        virtual void get_tweet();
        virtual void get_tweet1(int index);
        virtual void delete_tweet(int number);
        virtual void edit_tweet(int nUmber) ;
        virtual string backstring(int number) ;

        virtual void set_index();
        virtual int get_index(){return index;}

        //virtual void Set_following(int following);
        virtual int Get_following() ;

        virtual void Set_followers(int followers);
        virtual int Get_followers() ;

        virtual void add_following(string) ;
        virtual void show_following() ;
        virtual void increase_follower();

        virtual void profile_me(){};
        virtual void profile_other(){};
        virtual void edit_pro(string ,string ){};

        virtual void create_mention(int number ,string person) ;//mention func
        virtual void show_mention(int);//mention func
        virtual void like_mention(Common* mmtn ,int NUMt , int NUMM);//mention func         ****changed Account****

        void put_tweet();
        void put_follow();
        void flike(Common* , int);
        void follow_f(string purpose);
        Tweet &indx(int x)
        {
            // cout << this->mtweet[x].get_classtweet();
            return this->mtweet[x];
        }

};



#endif
