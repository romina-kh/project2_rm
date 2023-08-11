#ifndef EDIT_PROFILE_H
#define EDIT_PROFILE_H

#include <QWidget>

namespace Ui {
class edit_profile;
}

class edit_profile : public QWidget
{
    Q_OBJECT

public:
    explicit edit_profile(QWidget *parent = nullptr);
    ~edit_profile();

private slots:

    void on_editprofile_dateEdit_userDateChanged(const QDate &date);

    void on_btn_back_editpro_clicked();

private:
    Ui::edit_profile *ui;
};

#endif // EDIT_PROFILE_H
