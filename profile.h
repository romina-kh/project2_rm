#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include "user.h"

namespace Ui {
class profile;
}

class profile : public QWidget
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = nullptr);
    void set_pro(Common* user);
    ~profile();

private slots:
    void on_btn_tweet_pro_clicked();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
