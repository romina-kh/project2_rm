#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "company.h"


using namespace std;

int Company::Set_Pic(string Picture)//This function set address of picture
{
    this-> Picture = Picture;
}

//------------------------------------------------------------------------------------------

string Company::Get_Pic()
{
    return Picture;
}

//------------------------------------------------------------------------------------------

bool Company::Bio_val(string Bio)//bio validation
{
    QMessageBox q;

    if(Bio.size() > 1100)
    {
        q.setText("!Your bio should not be more than 1100 characters.");
        q.exec();
        return false ;
    }
    else if (Bio == "")
    {
       return true;
    }
    else
    {
        return true;
    }
}

//------------------------------------------------------------------------------------------

int Company::Set_Bio(string Bio)
{
    this-> Bio = Bio;
    return 0;
}

//------------------------------------------------------------------------------------------

string Company::Get_Bio()
{
    return Bio;
}

//------------------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------------------

string Company::Get_Country()
{
    return Country;
}

//------------------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------------------

string Company::Get_Link()
{
    return Link;
}

//------------------------------------------------------------------------------------------

bool Company::Phone_val(string Phone_Number)//phone number validation
{
    QMessageBox q;
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
            return true ;
        }
        else
        {
            q.setText("! You are only allowed to enter numbers in this section.");
            q.exec();
        }
    }
    else
    {
        q.setText("! Error please Enter your phone number correctly." );
        q.exec();

       return false ;
    }

}

//------------------------------------------------------------------------------------------

string Company::Get_Phone()
{
    return Phone_Number;
}

