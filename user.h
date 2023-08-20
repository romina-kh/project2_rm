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

protected:

        map<int ,Tweet> mtweet; //map for tweets
        vector<string> vecfollowing ; //following's name
        //---------------------------
        string Name;
        string User_Name;
        string Password;
        string Picture; //profile pic
        string Header; //header color
        string Age;
        string Phone_Number;
        string Country;
        string Link;
        string Bio;
        //---------------------------
        int followers = 0; //number of followers
        int index = 0 ; //index tweet

    public:
        //Common (anonymous , organization , personal)
        virtual bool ckeck_id(string &id);
        virtual int Set_User(string User_Name);
        virtual bool User_val(string User_name);//username validation
        virtual string Get_User();
        //---------------------------
        virtual int Set_Name(string Name);
        virtual string Get_Name();
        //---------------------------
        virtual bool Pas_val(string Password);//password validation
        virtual int Set_pass(string Password);
        virtual string Get_Password();
        //---------------------------
        virtual void Set_Header(string Header);
        virtual string Get_Header();


        //based on anonymous
        virtual int Set_Pic(string ){};
        virtual string Get_Pic(){return "______";};
        //---------------------------
        virtual bool Bio_val(string Bio){};
        virtual int Set_Bio(string Bio){};
        virtual string Get_Bio(){return "______";};
        //---------------------------
        virtual int Set_Country(string Country){};
        virtual string Get_Country(){return "______";};
        //---------------------------
        virtual int Set_Link(string Link){};
        virtual string Get_Link(){return "______";};
        //---------------------------
        virtual int Set_Age(string Age){};
        virtual string Get_Age(){return "______";};
        //---------------------------
        virtual bool Phone_val(string Phone_Number){};//phone number validation
        virtual int Set_Phone(string Phone_Number);
        virtual string Get_Phone(){return "______";};
        //---------------------------
        virtual void push_tweet(Tweet t); //push tweet with showing message
        virtual void push_tweet2(Tweet t); //push tweet without showing message
        virtual void delete_tweet(int number);
        virtual string backstring(int number);//This function checks that there is a tweet or not (in mtweet)
        virtual void put_tweet();//putting our tweet in a text file with this function
        //---------------------------
        virtual void set_index();//This function increase tweet's number
        virtual int get_index(){return index;}
        //---------------------------
        virtual int Get_following() ;//This function return size of vector(following)
        virtual string Get_indx_following(int);//This function return index(following)
        virtual void Set_followers(int followers);//This function sets follower(number)
        virtual int Get_followers() ;
        virtual void increase_follower();
        virtual void add_following(string) ;//This function pushback following's name in vector --with showing message
        virtual void add_following2(string) ;//This function pushback following's name in vector --without showing message
        virtual void follow_f(string purpose);//This function is used for adding following in file
        virtual int  get_follow_person(string) ;//check we have this person in our following or not
        //---------------------------
        virtual void create_mention(string mentions ,int number ,string person); //This function make mention
        virtual void like_mention(Common* mmtn ,int NUMt , int NUMM);
        virtual string get_mention(int numtweet , int i);
        virtual int size_mention(int numbtweet);
        virtual string getdate_mention(int , int);
        virtual int get_mention_likes( Common *purpose, int index , int indexm);
        virtual void set_mention(Tweet ,int);
        //---------------------------
        virtual bool check_indx(int  , int);//check if we have one specific tweet (and mention) or not
        virtual void flike(Common* , int);//for liking tweets in file
        virtual Tweet &indx(int x);//check if we have one specific tweet or not
        virtual int get_size_mtweet();













};



#endif
