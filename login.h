#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_btn_done_login_clicked();

    void on_total_exit_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
