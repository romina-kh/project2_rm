#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include "user.h"
#include <unordered_map>
#include "setting.h"

namespace Ui {
class profile;
}

class profile : public QWidget
{
    Q_OBJECT

public:
    explicit profile(map <string , vector<Tweet>>&,unordered_map<string , Common*>& ,Common*,QWidget *parent = nullptr);
    void set_pro(Common* user);
    void ptweet();
    void pfollow();
    void findhash(string, Tweet);
    void put_hashtag();
    void in_hashtag();

    ~profile();

private slots:
    void on_btn_tweet_pro_clicked();

    void on_btn_like_pro_clicked();

     void on_btn_setting_clicked();


     void on_btn_follow_pro_clicked();

     void on_btn_dislike_pro_clicked();



     void on_btn_search_clicked();


     void on_btn_deletetw_pro_clicked();

     void on_btn_mention_pro_2_clicked();

private:

    Ui::profile *ui;
    Common* User;
    unordered_map<string , Common*> musers;
    map <string , vector<Tweet> > mhashtag;
};

#endif // PROFILE_H
