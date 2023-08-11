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
    explicit profile(unordered_map<string , Common*>& ,Common*,QWidget *parent = nullptr);
    void set_pro(Common* user);
    void ptweet();
    void pfollow();
    ~profile();

private slots:
    void on_btn_tweet_pro_clicked();

    void on_btn_like_pro_clicked();

     void on_btn_setting_clicked();


     void on_btn_follow_pro_clicked();

private:

    Ui::profile *ui;
    Common* User;
    unordered_map<string , Common*> musers;
};

#endif // PROFILE_H
