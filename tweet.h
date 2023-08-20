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
        vector<Tweet>mentions ;//vector for mentions.
        string userName ;
        string tweet;
        string Date ;
        int number;

    public:

        vector<Common*>likers;
        void Set_Tweet(string);
        void set_number(int);
        void Set_User(string);
        void Set_date();
        void Set_date(string);
        string get_classtweet();
        string get_Date();
        int get_number();
        vector<Tweet> Get_mention() ;
        void likes(Common* ,Common* , int);
        void likes(Common*);
        void dislike(Common* ,Common* , int);
        int show_numberlikes(Common*, int);
        void show_likers(Common*, int);
        string show_likers(int );
        int like_mntn(Common* , int);
        int liker_size();//get size of vector(liker)
        bool check_like(Common* purpose);//check this tweet is liked or not (for dislike)
        void push_mention(Tweet);
        int size_mention();

};



#endif
