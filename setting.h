#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include "user.h"
#include <unordered_map>

namespace Ui {
class setting;
}

class setting : public QWidget
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = nullptr);
    ~setting();

private slots:
    void on_btn_exit_setting_clicked();

    void on_btn_logout_setting_clicked();

    void on_btn_delete_setting_clicked();

private:

    Ui::setting *ui;
    //Common* User;
    //unordered_map<string , Common*> musers;
};

#endif // SETTING_H
