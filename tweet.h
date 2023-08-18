#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


class Common;
class Tweet
{
    protected:


        vector<Tweet>mentions ;//vec for mention
        string userName ;//added for mention
        string tweet;
        string Date ;
        int number;


    public:

        void Set_Tweet(string);
        void set_number(int);
        void Set_User(string);//added for mention
        string get_classtweet();
        int get_number();
        void likes(Common* ,Common* , int);
        void likes(Common*);
        void dislike(Common* ,Common* , int);
        int show_numberlikes(Common*, int);
        void show_likers(Common*, int);
        int liker_size();
        void Set_date();
        string get_Date();
        void push_mention(Tweet);//mention func
        vector<Tweet>& Get_mention() ;//mention func
        int size_mention();
        int like_mntn(Common* , int );//mention func
        void show_numberlike_m(Common* , int ,int);//mention func
        string show_likers(int );
        void Set_date(string);

        void sett();

        //================

        vector<Common*>likers;


};


#endif
