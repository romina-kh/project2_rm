#ifndef ANONYMOUS_H
#define ANONYMOUS_H

#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;



class Anonymous : public Common
{
    public:
    void push_tweet(Tweet t) override;
    void edit_tweet(int nUmber) override ;
    void get_tweet();
    void get_tweet1(int index);
    void delete_tweet(int number);
    void profile_me();
    void profile_other();
    void edit_pro(string ,string ){};

};

#endif
