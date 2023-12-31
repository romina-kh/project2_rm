#include "login.h"
#include "ui_login.h"
#include "twitterak.h"
#include "user.h"
#include "mainwindow.h"


login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

//-----------------------------------------------------------------------------------

login::~login()
{
    delete ui;
}

//-----------------------------------------------------------------------------------

void login::on_btn_done_login_clicked()
{
    bool check = false;
    Twitterak app;
    string username , password;

    app.in_user();
    app.in_tweet();
    app.in_follow();
    //app.in_hashtag();

    username = ui->ln_username_l->text().toStdString();
    password = ui->ln_pass_l->text().toStdString();

    check = app.login(username , password);
    if(check == true)
    {
        app.show(username);
        this->close() ;
    }
}

//-----------------------------------------------------------------------------------

void login::on_total_exit_clicked()
{
    MainWindow * main_btn = nullptr ;
    main_btn = new MainWindow ;
    main_btn->show();
    this->close();
}

