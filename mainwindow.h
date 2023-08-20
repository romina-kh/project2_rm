#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn_login_m_clicked();

    void on_btn_signup_m_clicked();

    void on_btn_exit_m_clicked();

    void on_total_help_m_clicked();

private:

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
