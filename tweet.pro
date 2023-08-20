QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    anonymous.cpp \
    company.cpp \
    edit_profile.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    personal.cpp \
    profile.cpp \
    setting.cpp \
    show_profile.cpp \
    signup.cpp \
    tweet.cpp \
    twitterak.cpp \
    user.cpp

HEADERS += \
    anonymous.h \
    company.h \
    edit_profile.h \
    login.h \
    mainwindow.h \
    personal.h \
    profile.h \
    setting.h \
    show_profile.h \
    signup.h \
    tweet.h \
    twitterak.h \
    user.h

FORMS += \
    edit_profile.ui \
    login.ui \
    mainwindow.ui \
    profile.ui \
    setting.ui \
    show_profile.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES +=

RESOURCES += \
    resource_file.qrc
