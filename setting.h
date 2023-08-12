#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include "user.h"
#include <unordered_map>
#include "edit_profile.h"

namespace Ui {
class setting;
}

class setting : public QWidget
{
    Q_OBJECT

public:
    explicit setting(map <string , vector<Tweet>>& ,unordered_map<string , Common*>&,Common*,QWidget *parent = nullptr);

    Common* User;
    unordered_map<string , Common*>musers;
    map <string , vector<Tweet> > mhashtag;
    void put_user();

    ~setting();

private slots:
    void on_btn_exit_setting_clicked();

    void on_btn_logout_setting_clicked();

    void on_btn_delete_setting_clicked();

    void on_btn_edit_setting_clicked();

    void on_btn_back_clicked();

private:

    Ui::setting *ui;


};

#endif // SETTING_H
