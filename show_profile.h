#ifndef SHOW_PROFILE_H
#define SHOW_PROFILE_H

#include <QWidget>
#include"user.h"

namespace Ui {
class show_profile;
}

class show_profile : public QWidget
{
    Q_OBJECT

public:
    explicit show_profile(Common*,QWidget *parent = nullptr);
    void set_pro2(Common *);
    void show_tweet();
    void show_follow();
    ~show_profile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::show_profile *ui;
    Common * user ;
};

#endif // SHOW_PROFILE_H
