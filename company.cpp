#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "company.h"


using namespace std;

int Company::Set_Bio(string Bio)
{

    if(Bio.size() < 1101)
    {
        this-> Bio = Bio;
        return 1;
    }
    else if (Bio == "")
    {
        this-> Bio = Bio;
    }
    else
    {
        cout << "! Error please Enter another Biography.\n";
        return 0 ;
    }
}


string Company::Get_Bio()
{
    return Bio;
}

int Company::Set_Country(string Country)
{
    if(Country.size() < 51)
    {
        this-> Country = Country;
        return 1;
    }
    else if (Country == "")
    {
        this-> Country = Country;
    }
    else
    {
        cout << "! Error please Enter another Country.\n";
        return 0 ;
    }
}


string Company::Get_Country()
{
    return Country;
}

int Company::Set_Link(string Link)
{
    if(Link.size() < 500)
    {
        this-> Link = "https://" + Link;
        return 1;
    }
    else if (Link == "")
    {
        this-> Link = Link;
        return 0;
    }
    else
    {
        cout << "! Error please Enter another Link.\n";
        return 0 ;
    }

}


string Company::Get_Link()
{
    return Link;
}

int Company::Set_Phone(string Phone_Number)
{
    int counter = 0;
    if(Phone_Number.size()==12)
    {
        for( int i=0 ;i<Phone_Number.size();i++)
        {
            if(Phone_Number[i]>='0' && Phone_Number[i]<='9')
            {
                counter++;
            }

        }
        if (counter == 12)
        {
            this->Phone_Number = Phone_Number;
            return 1 ;
        }
        else
        {
            cout << "! You are only allowed to enter numbers in this section.\n";
        }
    }
    else
    {
       cout << "! Error please Enter your phone number correctly.\n" ;
       return 0 ;
    }


}

string Company::Get_Phone()
{
    return Phone_Number;
}


void Company:: profile_me()
{
            cout << "$ Name : ";
            cout << Get_Name()<< endl ;
            cout << "$ Username : ";
            cout << Get_User() << endl ;
            cout << "$ Phone number : ";
            cout << Get_Phone() << endl ;
            cout << "$ Bio : ";
            cout << Get_Bio() << endl ;
            cout << "$ Country : ";
            cout << Get_Country() << endl ;
            cout << "$ Link : ";
            cout << Get_Link() << endl ;
            cout << "$ follower : " ;
            cout << Get_followers() << endl ;
}

void Company:: profile_other()
{
            cout << "$ Name : ";
            cout << Get_Name()<< endl ;
            cout << "$ Username : ";
            cout << Get_User() << endl ;
            cout << "$ Bio : ";
            cout << Get_Bio() << endl ;
            cout << "$ Country : ";
            cout << Get_Country() << endl ;
            cout << "$ Link : ";
            cout << Get_Link() << endl ;
            cout << "$ follower : " ;
            cout << Get_followers() << endl ;

}

void Company :: edit_pro(string edit ,string changable)
{
        if(edit == "age")
            {

            }

            else if(edit == "phone number")
            {
                Set_Phone(changable) ;
                cout << "* Your phone number has been successfully changed.\n" ;
            }

            else if(edit == "country")
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                Set_Country(changable) ;
                cout << "* Your country has been successfully changed.\n" ;
            }

            else if(edit == "link")
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                Set_Link(changable) ;
                cout << "* Your link has been successfully changed.\n" ;
            }
            else if(edit == "bio")
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                Set_Bio(changable) ;
                cout << "* Your bio has been successfully changed.\n" ;

            }

}
