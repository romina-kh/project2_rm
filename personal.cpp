#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "company.h"
#include "personal.h"


using namespace std;


int Personal::Set_Pic(string Picture)//This function set the picture address
{
    this-> Picture = Picture;
}

//-----------------------------------------------------------------------------------

string Personal::Get_Pic()
{
    return Picture;
}

//---------------------------------------------------------------------------------

bool Personal::Bio_val(string Bio)//bio validation
{
    QMessageBox q;

    if(Bio.size() > 160)
    {
        q.setText("!Your bio should not be more than 160 characters.");
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

//-----------------------------------------------------------------------------------

int Personal::Set_Bio(string Bio)
{
    this-> Bio = Bio;
    return 0;
}

//-----------------------------------------------------------------------------------

string Personal::Get_Bio()
{
    return Bio;
}

//-----------------------------------------------------------------------------------

int Personal::Set_Country(string Country)
{
    if(Country.size() < 101)
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

//-----------------------------------------------------------------------------------

string Personal::Get_Country()
{
    return Country;
}

//-----------------------------------------------------------------------------------

int Personal::Set_Link(string Link)
{
    if(Link.substr(0 , 8) != "https://"  )
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
        this-> Link = Link;
        return 0 ;
    }

}

//-----------------------------------------------------------------------------------

string Personal::Get_Link()
{
    return Link;
}

//-----------------------------------------------------------------------------------

int Personal::Set_Age(string Age)
{
       this->Age = Age;
       return 0 ;
}

//-----------------------------------------------------------------------------------

string Personal::Get_Age()
{
    return Age;
}

//-----------------------------------------------------------------------------------

bool Personal::Phone_val(string Phone_Number)//phone number validation
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

//-----------------------------------------------------------------------------------

string Personal::Get_Phone()
{
    return Phone_Number;
}



