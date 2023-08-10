#include "login.h"
#include "ui_login.h"
#include "twitterak.h"
#include "user.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_btn_done_login_clicked()
{
    Twitterak app;
    app.in_user();
//    app.in_tweet();
//    app.in_follow();
//    app.in_hashtag();

    string username , password;
    username = ui->ln_username_l->text().toStdString();
    password = ui->ln_pass_l->text().toStdString();
    app.login(username , password);




}

