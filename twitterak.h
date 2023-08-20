#ifndef TWITTERAK_H
#define TWITTERAK_H
#include <iostream>
#include <unordered_map>
#include <map>
#include "user.h"
#include "tweet.h"
#include <string>
#include <vector>
using namespace std;

class Twitterak
{
    private:
        unordered_map<string , Common*> musers;// map users
        map <string , vector<Tweet> > mhashtag;// map hashtag

    public:
    string temp = "";

    bool signup(string , string , string , string , string , string , string , string , string ,string);
    bool signup_ano(string , string ,string);
    bool signup_org(string , string , string , string , string , string , string , string, string ,string);
    bool login(string , string);
    void show(string);//show profile
    void findhash(string, Tweet);//finding hashtag
    //-----------------------------------
    void put_user();//writing in file(user)
    void ptweet();//writing in file(tweet)
    //-----------------------------------
    void in_user();//reading (user) from file
    void in_tweet();//reading (tweet) from file
    void in_follow();//reading (follow) from file

};
#endif

