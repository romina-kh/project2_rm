#include <iostream>
#include <unordered_map>
#include <string>
#include "user.h"
#include "tweet.h"
#include "twitterak.h"
#include <bitset>
#include <functional>
#include <vector>
#include <sstream>
#include "company.h"
#include "personal.h"
#include "anonymous.h"
#include <fstream>
#include <qmessagebox.h>
#include "profile.h"

using namespace std ;

//objects of classe
//Common* user = nullptr;
Common* user = nullptr;
Tweet tweet_object;

//********************************************************************************************************************************************

void Twitterak::ckeck_id(string &id) //This function ckeck the reserved word and @
{
    if(id[0]=='@')
    {
        id.erase(0 , 1) ;
    }
    if(id=="exit"
    || id=="edit"
    || id=="login"
    || id=="signup"
    || id=="delete"
    || id=="username"
    || id== "help" )
    {
        cout << "! This is a reserved keyword. you can not choose it as your username.\n" ;
    }

}

//*********************************************************************************************************************************************************
void header(string color)
{

    cout << endl;
    cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    \n";
    cout << endl <<"              ";

    for(int i = 0 ; i < color.size() ; i++)
    {
        cout << "   " << color[i] << "    " ;
    }

    cout << endl;
    cout << endl;
    cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    \n";
}

//********************************************************************************************************************************************************
void Twitterak::check_space(string& str3)
{
    size_t pos ;
    // Find the first non-space character in the string
    for( int i=0 ;i<str3.size() ;i++)
    {
        pos = str3.find_first_not_of(" ");
        if (pos != string::npos)
        {
            str3.erase(0, pos);
        }
    }
}

//************************************************************************************************************************************************************
void seperator(string original , string& characters , string& numbers) //This function seprate username from ":" and tweet number
{
    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] != ':')
        {
            characters += original[i];
        }
        else if (original[i] == ':')
        {
            for (int j = i+1; j < original.size(); j++)
            {
                if (isdigit(original[j]))
                {
                    numbers += original[j];
                }
            }
            break;
        }

    }

}

//********************************************************************************************************************************************


//****************************************************************************************************************************************

bool Twitterak::signup(string User , string Name, string Age ,string Phone_Number, string Country , string Link , string Bio , string Password , string img ,string header)
{
    bool fuser = false;
    bool fpass =false;
    bool fphone =false;
    bool fbio = false;
    QMessageBox q;


    user = new Personal;

    if(!musers.count(User))
    {
        if(user->User_val(User) == true)
        {
            user->Set_User(User);
            fuser = true;
        }

    }
    else
    {
        q.setText("! There is a user with this username .");
        q.exec();


    }
    user->Set_Name(Name);
    user->Set_Age(Age);

    if(user->Phone_val(Phone_Number) ==  true)
    {
         user->Set_Phone(Phone_Number);
         fphone = true;
    }

    user->Set_Country(Country);
    user->Set_Link(Link);
    if(user->Bio_val(Bio)==true)
    {
         user->Set_Bio(Bio);
         fbio = true;
    }
    user->Set_Bio(Bio);
    if(user->Pas_val(Password)== true)
    {
        user->Set_pass(Password);
        fpass = true;
    }

    user->Set_Pic(img);
    user->Set_Header(header) ;



   // musers[user->Get_User()] = user;

    if(fuser==true && fpass == true && fphone == true && fbio == true)
    {
         musers[user->Get_User()] = user;
        put_user();
        q.setText("signup!");
        q.exec();
        return true;


    }
    else
    {
        return false;
    }

}
//----------------------------------------------------------------------------------------------------------------------------

bool Twitterak::signup_ano(string User, string Password ,string header)
{
    bool fuser = false;
    bool fpass =false;


    QMessageBox q;

    user = new Anonymous;



    if(!musers.count(User))
    {
        if(user->User_val(User) == true)
        {
            user->Set_User(User);
            fuser = true;
        }

    }
    else
    {
        q.setText("! There is a user with this username .");
        q.exec();


    }

    user->Set_Header(header) ;
    user->Set_Name("Anonymous User");
    if(user->Pas_val(Password)== true)
    {
        user->Set_pass(Password);
        fpass = true;
    }


    if(fuser==true && fpass == true)
    {
         musers[user->Get_User()] = user;
        put_user();
        q.setText("signup!");
        q.exec();
        return true;


    }
    else
    {
        return false;
    }



}
//---------------------------------------------------------------------------------------------------------------------------

bool Twitterak::signup_org(string User , string Name ,string Phone_Number, string Country , string Link , string Bio , string Password , string manager , string img ,string header)
{
    bool fuser = false;
    bool fpass =false;
    bool fphone = false;
    bool fbio = false;

    QMessageBox q;
    if(musers.count(manager) == 1)
    {
        user = new Company;

        if(!musers.count(User))
        {
            if(user->User_val(User) == true)
            {
                user->Set_User(User);
                fuser = true;
            }

        }
        else
        {
            q.setText("! There is a user with this username .");
            q.exec();

        }

        user->Set_Name(Name);
        user->Set_Header(header) ;

        if(user->Phone_val(Phone_Number) ==  true)
        {
             user->Set_Phone(Phone_Number);
             fphone = true;
        }

        user->Set_Country(Country);
        user->Set_Link(Link);
        if(user->Bio_val(Bio)==true)
        {
             user->Set_Bio(Bio);
             fbio = true;
        }
        if(user->Pas_val(Password)== true)
        {
            user->Set_pass(Password);
            fpass = true;
        }
        user->Set_Pic(img);

        if(fuser==true && fpass == true && fphone == true &&  fbio == true)
        {
            musers[user->Get_User()] = user;
            temp = user->Get_User() ;
            put_user();
            q.setText("signup!");
            q.exec();
            return true;


        }
        else
        {
            return false;
        }
    }
    else
    {
        q.setText("! There is no user with this username.");
        q.exec();
        return false;
    }


    //temp

}

//****************************************************************************************************************************
bool Twitterak::login(string usern , string pass)//using hash for safety
{

    QMessageBox q;

        ckeck_id(usern);

        if(musers.count(usern) == 1)//login
        {
            if(musers[usern]->Get_Password() ==  pass)
            {
                user = musers[usern] ;
                temp = usern;
                //checkin = 1 ;
                q.setText("login!");

                q.exec();
                //show(usern);


                return true;

                //choice_login();
            }
            else
            {
                q.setText("! Your password is incorect.");
                q.exec();
                return false;

            }

        }
        else
        {
            q.setText("! This Username is not found.");
            q.exec();
           return false;

        }


}



//*********************************************************************************************************************************************************

void Twitterak::logout()
{
    checkin = 0;
    cout << "* You successfully logged out.\n" ;
}

void Twitterak::men_check(string mention , int num ,string temp , string person)
{
     musers[person]->create_mention( mention , num , temp) ;
}

//====================================================================================================================================
void Twitterak :: qttweet(string tweet)
{
    Tweet new1; //new object from Tweet

cout << "first\n";
    new1.Set_date();
    check_space(tweet) ;
    new1.Set_Tweet(tweet);
    musers[temp]->set_index();
    new1.set_number(musers[temp]->get_index());

    musers[temp]->push_tweet(new1);
    string str = new1.get_classtweet();


    findhash(str, new1);
    cout << "last\n";


}

//*********************************************************************************************************************************************************
void Twitterak::choice_login() //Showing diffrent oprtions after login
{
    vector <string> vec;
    string choice2 , tweet;
    string t; //string that we use to separate words from each other(words between space)
    string checkname="likes";
    bool flag = true;

    while(flag == true)
    {
        if(musers.count(temp) == 1)
        {
            cout << "> @" << temp;
        }
        cout << "> " ;
        getline(cin ,choice2);

        while(choice2.empty())
        {
            if(musers.count(temp) == 1)
            {
                cout << "> @" << temp;
            }
            cout << "> " ;
            getline(cin ,choice2);
        }
        for (int i = 0 ; i < choice2.size() ; i++)
        {
            choice2[i] = tolower(choice2[i]);
        }
        check_space(choice2) ;
        stringstream word(choice2);
        while (getline(word , t , ' '))
        {
            vec.push_back(t);
        }

        for (int i = 0 ; i < choice2.size() ; i++)
        {
            choice2[i] = tolower(choice2[i]);
        }

        size_t chec=vec[0].find(checkname) ;

        if(vec[0] == "logout")
        {
            logout();
            flag = false;

        }

        else if(vec[0] == "edit" && vec[1] == "profile")
        {

            string str_edit1 ,str_edit2;
            str_edit1=vec[2] ;
            str_edit2=vec[3] ;

            edit_profile(str_edit1 ,str_edit2);
        }


        else if (vec[0][0] == '#' )
        {
            string key = vec[0];
            showhash(key);
            choice_login();

        }

        else if(vec[0]=="retweet")
        {
            string sme2=vec[1] ; // A string for checking ":" and "@" and...
             if(sme2.find(':') != string :: npos)
            {
                ckeck_id(sme2);
                string numbers = "";
                string characters = "";
                seperator(sme2 , characters , numbers);//seprate username from tweet number

                int m = stoi(numbers) ; //convert string into integer

                if(musers.count(characters) == 1)
                {
                    string temp2 = musers[characters]->backstring(m) ;
                    Tweet new2;
                    new2.Set_date();
                    check_space(tweet) ;
                    new2.Set_Tweet(temp2);
                    musers[temp]->set_index();
                    new2.set_number(musers[temp]->get_index());
                    musers[temp]->push_tweet(new2);
                    choice_login() ;
                }
                else
                {
                    cout<< "! Tweet has not found.\n" ;
                }
            }
        }

        else if(vec[0] == "mention")// mention for tweets.
        {


            string str = vec[1] ;
            ckeck_id(str);
            string numbers = "";
            string characters = "";
            //Tweet t ;
            string mention ;
            seperator(str , characters , numbers) ;
            //cout << "Enter mention:\n";
            //getline(cin , mention) ;
            int num = stoi(numbers) ;
            musers[characters]->create_mention( mention , num , temp) ;
            choice_login() ;


        }

        else if(vec[0] == "show" && vec[1] == "mention")//show the mentions of each tweet
        {
            string str = vec[2] ;
            ckeck_id(str);
            string numbers = "";
            string characters = "";

            seperator(str , characters , numbers) ;
            int num = stoi(numbers) ;
            musers[characters]->show_mention(num) ;
            choice_login() ;

        }

        else if(vec[0] == "show" && vec[1] =="tweet")
        {
            string sme; //string for using in function
            sme = vec[2];
            if (sme == "@me")
            {
                musers[temp]->get_tweet();
                choice_login() ;
            }

            else if(sme.find(':') != string :: npos)
            {
                ckeck_id(sme);
                string numbers = "";
                string characters = "";
                seperator(sme , characters , numbers);//seprate username from tweet number

                int n = stoi(numbers) ;

                if(musers.count(characters) == 1)//checking this character exist
                {

                   musers[characters]->get_tweet1(n);
                   tweet_object.show_numberlikes( musers[characters], n);

                   choice_login() ;
                }
                else
                {
                    cout << "! We can not find this member.\n";
                    choice_login() ;
                }

            }
            else
            {
                ckeck_id(sme);//ckeck the reserved word and @
                if(musers.count(sme) == 1)
                {
                   musers[sme]->get_tweet();
                   choice_login() ;
                }
                else
                {
                    cout << "! We can not find this member.\n";
                    choice_login() ;
                }

            }

        }

//        else if(vec[0] == "edit" && vec[1]== "tweet")
//        {
//            int edit_tw = stoi(vec[2]);
//            musers[temp]->edit_tweet(edit_tw) ;


//            choice_login() ;

       // }

        else if(vec[0] == "delete" && vec[1]== "tweet")
        {

            if (save == "personal" || save == "organisation")
            {
            int delete_tw=stoi(vec[2]) ;
            musers[temp]->delete_tweet(delete_tw) ;
            }
            else
            {
                cout << "! This account is not allowed to delete tweet.\n";
            }
            choice_login();
        }

        else if(vec[0] == "like" && vec[1] == "mention")//check this person to like or already liked.
        {
            string str = vec[2];
            int nummention =stoi(vec[3]);
            ckeck_id(str);
            string numbers = "";
            string characters = "";

            seperator(str , characters , numbers);

            int num = stoi(numbers) ;
            if(musers.count(characters) == 1)//checking this character exist
            {
               musers[characters]->like_mention(musers[temp] , num , nummention) ;

               choice_login() ;
            }
        }



    }
 }
 //********************************************************************************************************************************************************
void Twitterak::delete_account()
    {
        cout << "? Are you sure that you want to delete your account(y/n) ?" ;
        string ch ;
        getline(cin ,ch) ;
        if(ch[0]=='y')
        {
            musers.erase(temp) ;
            logout() ;
            cout << "* Your account has been deleted.\n" ;
        }
        else
        {
          choice_login() ;
        }
    }

//************************************************************************************************************************************************************
void Twitterak:: edit_profile(string edit ,string changable)
    {

        cout << "> ";

        if(musers.count(temp)==1)
        {
            if (edit == "age" || edit == "phone number" || edit == "country" || edit == "link" || edit == "bio")
            {
            musers[temp]->edit_pro(edit ,changable);
            choice_login();
            }

            if(edit == "name")
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                musers[temp]->Set_Name(changable) ;
                cout << "* Your name has been successfully changed.\n" ;
                choice_login();
            }
            else if(edit == "username")
            {
                changable.erase(0, 1);
                changable.erase(changable.size() - 1 , 1);
                ckeck_id(changable);
                musers[temp]->Set_User(changable) ;
                Common *temp2 = musers[temp];
                musers.erase(temp) ;
                musers[temp2->Get_User()] = temp2 ;
                temp = temp2->Get_User() ;
                cout << "* Your user name has been successfully changed.\n" ;
                choice_login();
            }

            else if(edit == "header")
            {

                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                color = changable;
                musers[temp]->Set_Header(color) ;
                header(color);
                choice_login();
            }

            else if(edit == "password")//final change!!!!!!!!!
            {
                changable.erase(0, 1);
                changable.erase(changable.size()-1, 1);
                hash<string>mystd;
                if(musers[temp]->Get_Password() == changable)/*musers[temp]->Get_Password_nonhash() == changable)*///mystd
                {
                    cout << "! Registration failed.\n" ;
                }
                else
                {
                    musers[temp]->Set_pass(changable) ;
                    cout << "* Your password has been successfully changed.\n" ;

                }
                choice_login();
            }

        }
        else
        {
            cout << "! edit undefined command.\n" ;
        }

    }
//*************************************************************************************************************************************************************

void Twitterak::show(string account)
    {

        profile* pro = new profile(mhashtag,musers , musers[account]);
        pro->set_pro(musers[account]);

        pro->show();
//        ckeck_id(profile);

//        if(profile=="me" || profile=="profile")
//        {

//            if(musers.count(temp) == 1){

//            musers[temp]->Get_Header();
//            header(color);
//            musers[temp]->profile_me();
//            choice_login() ;
//            }
//        }

//        else if(musers.count(profile)==1)
//        {
//            musers[profile]->Get_Header();
//            header(color);
//            musers[profile]->profile_other();
//          choice_login() ;
//        }
//        else
//        {
//            cout << "!we can not find this member.\n" ;
//            choice_login() ;
//        }


    }

//*****************************************************************************************************************
void Twitterak :: findhash(string str, Tweet tobj)
{
    string key;
    cout << "fiiiiiiiiiind hasssssshhh \n";
    // string str = musers[temp]->indx(musers[temp]->get_index()).get_classtweet();
    size_t found = str.find('#');
    int index = musers[temp]->get_index();
    if (found != string::npos)
    {
       for (int i = 0; i < str.size() ; i++)
       {
            if(str[i] == '#')
            {
                cout << "2" << endl;
                for(int j = i + 1 ; j < str.size() ; j++)
                {

                    if(str[j] != ' ')
                    {
                        key += str[j];
                    }
                    else
                    {
                        i = j + 1;
                        break;
                    }
                }
                for ( int i = 0 ; i < key.size() ; i++)
                {
                    key[i] = tolower(key[i]);
                }
                mhashtag[key].push_back(tobj);
                key = "";
            }
       }

    }
}
//*******************************************************************************************************************************
void Twitterak :: showhash(string look)
{
    string ch = look.erase(0,1);
    for (int i = 0 ; i < ch.size() ; i++)
    {
        ch[i] = tolower(ch[i]);
    }

    if (mhashtag.count(ch) == 1)
    {
        for (auto i : mhashtag[look])
        {

        }
    }
    else
    {
        cout << "! This hashtag does not exist. \n";
    }

}
//==================================================================================================================


void Twitterak :: put_user()
{
    ofstream outuser;
    outuser.open("user.txt", ios::out);

    Personal* per;
    Anonymous* ano;
    Company* org;

    for (auto i : musers)
    {
        per = dynamic_cast<Personal*>(i.second);
        ano = dynamic_cast<Anonymous*>(i.second);
        org = dynamic_cast<Company*>(i.second);

        if (per != NULL)
        {
            outuser << i.second->Get_User() << "p" ;
        }
        if (ano != NULL)
        {
            outuser << i.second->Get_User() << "a" ;
        }
        if (org != NULL)
        {
            outuser << i.second->Get_User() << "o" ;
        }
        outuser << endl << i.second->Get_Name()
                << endl << i.second->Get_Age()
                << endl << i.second->Get_Phone()
                << endl << i.second->Get_Country()
                << endl << i.second->Get_Link()
                << endl << i.second->Get_Bio()
                << endl << i.second->Get_Password()
                << endl << i.second->Get_Pic()
                << endl << i.second->Get_Header()
                << endl
        << "************************************************\n";

    }

    outuser.close();
}

 //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//----------------------------------------------------------------------------------------------------------------
void Twitterak :: in_hashtag()
{
    ifstream in_hash;
    in_hash.open("hashtag.txt" , ios::in);

    if(in_hash.is_open())
    {
        while(!in_hash.eof())
        {
            string hashtag;
            in_hash >> hashtag;

            if(hashtag == "")
            {
                break;
            }

            hashtag.pop_back();
            while(true)
            {
                Tweet tweet;
                string num;
                string twt;
                string date;

                in_hash >> num;
                if (num == "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
                {
                    in_hash.ignore(1);
                    break;
                }

                num.pop_back();
                int index = stoi(num);
                tweet.set_number(index);

                getline(in_hash , twt);
                twt = twt.substr(1 , twt.size()) ;
                tweet.Set_Tweet(twt);

                 mhashtag[hashtag].push_back(tweet);

                while(getline(in_hash , date))
                {
                    if (date == "________________________________________________________________")
                    {
                        break;
                    }
                }
            }
        }
    }

    in_hash.close();
}

//----------------------------------------------------------------------------------------------------------------
void Twitterak :: ptweet()
{
    remove("tweet.txt");
    for ( auto i : musers)
    {
        i.second->put_tweet();
    }
}

//----------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------
void Twitterak :: in_user()
{
    QMessageBox q;
    string username;
    string name;
    string age;
    string phone_number;
    string country;
    string link;
    string bio;
    string password;
    string picture;
    string Header ;

    ifstream in_user;
    in_user.open("user.txt" , ios::in);

    if(in_user.is_open())
    {
        while(!in_user.eof())
        {
            Common* file_user;

            getline (in_user, username);
            if (username[username.size()-1] == 'p')
            {
                file_user = new Personal;
            }
            else if (username[username.size()-1] == 'a')
            {
                file_user = new Anonymous;
            }
            else if (username[username.size()-1] == 'o')
            {
                file_user = new Company;
            }

            username.pop_back();
            file_user->Set_User(username);
            musers[username] = file_user;

            getline (in_user, name);
            musers[username]->Set_Name(name);

            getline (in_user, age);
            musers[username]->Set_Age(age);

            getline (in_user, phone_number);
            musers[username]->Set_Phone(phone_number);

            getline (in_user, country);
            musers[username]->Set_Country(country);

            getline (in_user, link);
            musers[username]->Set_Link(link);

            getline (in_user, bio);
            musers[username]->Set_Bio(bio);

            getline (in_user, password);
            musers[username]->Set_pass(password);

            getline(in_user , picture );
            musers[username]->Set_Pic(picture);

            getline(in_user ,Header);
            musers[username]->Set_Header(Header);

            in_user.ignore(49);
        }
    }
    in_user.close();
}
//======================================================================================================
void Twitterak :: in_tweet()
{

    ifstream in_tweet;
    in_tweet.open("tweet.txt" , ios::in);


    if(in_tweet.is_open())
    {
        while(!in_tweet.eof())
        {
            string username;
            in_tweet >> username;
            if(username == "")
            {
                break;
            }

            while(true)
            {
                Tweet t;
                string date;
                string like ;
                string liker;
                string tweet;
                string numb;
                string nummen ;
                string men ;
                string datemen ;
                string likemen ;
                string empty;

                in_tweet >> numb ;
                if (numb == "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
                {
                    in_tweet.ignore(1);
                    break;
                }
                //--------------------------
                numb.pop_back();
                int index = stoi(numb);
                t.set_number(index);
                //--------------------------
                getline(in_tweet , tweet);
                tweet = tweet.substr(1 , tweet.size()) ;
                t.Set_Tweet(tweet);
                //--------------------------
                getline (in_tweet , date);
                date.append("\n");
                t.Set_date(date);
                musers[username]->set_index();
                musers[username]->push_tweet2(t);
                //--------------------------
                getline(in_tweet , like);

                while(getline(in_tweet , liker))
                {
                    if (liker == "------------------------------------------")
                    {
                        break;
                    }
                    musers[username]->flike(musers[liker] , index);
                }
                //--------------------------
                in_tweet >> nummen ;

                while(nummen != "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
                {
                    Tweet tmen ;
//                    if(nummen== "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
//                    {
//                        break;
//                    }
                    nummen.pop_back() ;
                    tmen.set_number(stoi(nummen));
                    //--------------------------
                    getline(in_tweet ,men) ;
                    men.erase(0,1);
                    tmen.Set_Tweet(men) ;
                    //--------------------------
                    getline(in_tweet ,datemen) ;
                    datemen.append("\n");
                    tmen.Set_date(datemen) ;
                    //--------------------------
                    in_tweet.ignore();
                    getline(in_tweet , like);

                    while(getline(in_tweet , likemen))
                    {
                        if (likemen == "^^^^^")
                        {
                            break;
                        }
                        tmen.likes(musers[likemen]) ;
                    }
                   musers[username]->set_mention(tmen , index) ;
                   in_tweet >> nummen;
                }

            }

        }

    }

    in_tweet.close();
}
//======================================================================================================
void Twitterak :: in_follow()
{
    ifstream in_follow;

    QMessageBox q;
    in_follow.open("follow.txt" , ios::in);

    if(in_follow.is_open())
    {
        while(!in_follow.eof())
        {
            string username;
            in_follow >> username;

            if(username == "")
            {
                break;
            }
            username.pop_back();

            string following;
            while(following != "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
            {
                in_follow >> following;
                if(following == "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
                {
                    break;
                }
                musers[username]->add_following2(following);
                musers[following]->increase_follower();
            }
        }
    }

in_follow.close();

}

