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
    explicit setting(unordered_map<string , Common*>&,Common*,QWidget *parent = nullptr);
    ~setting();

private slots:
    void on_btn_exit_setting_clicked();

    void on_btn_logout_setting_clicked();

    void on_btn_delete_setting_clicked();

    void on_btn_edit_setting_clicked();

    void on_btn_back_clicked();

private:

    Ui::setting *ui;
    Common* User;
    unordered_map<string , Common*>musers;

};

#endif // SETTING_H
