#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:


    void on_btn_done_signup_clicked();


    void on_dateEdit_age_s_userDateChanged(const QDate &date);

    void on_rbtn_organ_s_clicked();

    void on_rbtn_personal_s_clicked();

    void on_rbtn_ano_s_clicked();



private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
