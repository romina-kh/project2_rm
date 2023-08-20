#ifndef EDIT_PROFILE_H
#define EDIT_PROFILE_H

#include <QWidget>
#include "user.h"
#include "QMessageBox"

namespace Ui {
class edit_profile;
}

class edit_profile : public QWidget
{
    Q_OBJECT

public:
    explicit edit_profile(unordered_map<string , Common*>& ,Common*,QWidget *parent = nullptr);//
    void put_user();
    ~edit_profile();

private slots:

    void on_editprofile_dateEdit_userDateChanged(const QDate &date);

    void on_btn_back_editpro_clicked();

    void on_btn_save_edit_clicked();

    void on_btn_edit_name_clicked();

    void on_btn_edit_user_clicked();

    void on_btn_edit_pass_clicked();

    void on_btn_edit_age_clicked();

    void on_btn_edit_phone_clicked();

    void on_btn_edit_country_clicked();

    void on_btn_edit_link_clicked();

    void on_btn_edit_bio_clicked();

    void on_btn_edit_headr_clicked();

    void on_btn_edit_img_clicked();

private:
    Ui::edit_profile *ui;
    Common* User;
    unordered_map<string , Common*>musers;

};

#endif // EDIT_PROFILE_H
