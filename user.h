#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <string>
#include <vector>
#include "tweet.h"
#include <map>
#include "setting.h"

using namespace std;
class Common //parent
{
    friend void Tweet:: likes(Common* currentuser, Common* target, int index);
    friend void Tweet:: likes(Common* target);
    friend int Tweet:: show_numberlikes( Common *target, int index);
    friend void Tweet:: show_likers(Common* target, int index);
    friend void Tweet:: dislike(Common* currentuser ,Common* target, int index);
    friend void Tweet::show_numberlike_m( Common *purpose, int index ,int indexm);//friend for liking mention
    protected:
        // map<string , vector<Tweet*>>
         map<int ,Tweet> mtweet;
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

        virtual bool ckeck_id(string &id);
        virtual int Set_Name(string Name);
        virtual string Get_Name();

        virtual int Set_Pic(string ){};
        virtual string Get_Pic(){return "______";};



        virtual int Set_User(string User_Name);
        virtual bool User_val(string User_name);
        virtual string Get_User();

        virtual bool Pas_val(string Password);
        virtual int Set_pass(string Password);
        virtual string Get_Password();//string / size_t

       // virtual bool
        virtual bool Bio_val(string Bio){};
        virtual int Set_Bio(string Bio){};
        virtual string Get_Bio(){return "______";};

        virtual int Set_Country(string Country){};
        virtual string Get_Country(){return "______";};

        virtual int Set_Link(string Link){};
        virtual string Get_Link(){return "______";};

        virtual int Set_Age(string Age){};
        virtual string Get_Age(){return "______";};

        virtual bool Phone_val(string Phone_Number){};
        virtual int Set_Phone(string Phone_Number);
        virtual string Get_Phone(){return "______";};

        virtual void Set_Header(string Header);
        virtual string Get_Header();

        // virtual void push_tweet(string t);
        virtual void push_tweet(Tweet t);
        virtual void push_tweet2(Tweet t);
        virtual void get_tweet();
        virtual string get_tweet_hash();
        virtual void get_tweet1(int index);
        virtual void delete_tweet(int number);
        virtual void edit_tweet(int nUmber) ;
        virtual string backstring(int number) ;

        virtual void set_index();
        virtual int get_index(){return index;}

        //virtual void Set_following(int following);
        virtual int Get_following() ;
        virtual string Get_indx_following(int);

        virtual void Set_followers(int followers);
        virtual int Get_followers() ;

        virtual void add_following(string) ;
        virtual void add_following2(string) ;
        virtual int  get_follow_person(string) ;
        virtual void show_following() ;
        virtual void increase_follower();

        virtual void profile_me(){};
        virtual void profile_other(){};
        virtual void edit_pro(string ,string ){};

        virtual void create_mention(string mentions ,int number ,string person) ;//mention func
        virtual void show_mention(int);//mention func
        virtual void like_mention(Common* mmtn ,int NUMt , int NUMM);//mention func         ****changed Account****

        void put_tweet();
        void put_follow();
        void flike(Common* , int);
        void follow_f(string purpose);
        Tweet &indx(int x);
        int get_size_mtweet();
         string get_mention( int numtweet  , int i);
         int size_mention(int numbtweet);
         string getdate_mention(int , int);
         int get_mention_likes( Common *purpose, int index , int indexm);
         void set_mention(Tweet ,int);
         bool check_indx(int  , int);

         virtual int vec_follow_size();
         virtual string fmember(int i);











};



#endif
