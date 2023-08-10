#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "company.h"
#include "personal.h"
#include "anonymous.h"
#include "tweet.h"

using namespace std;

void Anonymous :: push_tweet(Tweet t)
{
    cout << "! This account is not allowed to tweet.\n";
}

void Anonymous::edit_tweet(int nUmber)
{
cout << "! This account is not allowed to edit tweet.\n";

}

void Anonymous::get_tweet()
{

}

void Anonymous::delete_tweet(int number)
{
    cout << "! This account is not allowed to edit tweet.\n";
}

void Anonymous :: get_tweet1(int index)
{

}



void Anonymous:: profile_me()
{
    cout << "$ Name : ";
    cout << Get_Name()<< endl ;
    cout << "$ Username : ";
    cout << Get_User() << endl ;
    cout << "$ following : " ;
    show_following() ;
}

void Anonymous:: profile_other()
{
    cout << "$ Name : ";
    cout << Get_Name()<< endl ;
    cout << "$ Username : ";
    cout << Get_User() << endl ;
    cout << "$ following : " ;
    cout << Get_following() << endl ;

}

