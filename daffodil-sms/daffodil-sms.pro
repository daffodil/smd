# -------------------------------------------------
# Project created by QtCreator 2010-10-16T18:11:59
# -------------------------------------------------
QT += network \
    sql \
    webkit
TARGET = daffodil-sms
TEMPLATE = app
SOURCES += main.cpp \
    mainobject.cpp \
    mainwindows/mainwindow.cpp \
    addresses/addresseswidget.cpp \
    xwidgets/xstatusbar.cpp \
    services/serviceclient.cpp \
    services/textmarketer.cpp \
    services/x24com.cpp \
    settings/settingswidget.cpp \
    settings/providerdialog.cpp \
    setup/dbsetupwizard.cpp \
    setup/dbwizzselectpage.cpp \
    setup/dbwizzmysqlpage.cpp \
    setup/dbwizzsqlitepage.cpp \
    import/importwizard.cpp \
    import/importwizzselectmodepage.cpp
HEADERS += mainwindows/mainwindow.h \
    mainobject.h \
    addresses/addresseswidget.h \
    xwidgets/xstatusbar.h \
    services/serviceclient.h \
    services/textmarketer.h \
    services/x24com.h \
    settings/settingswidget.h \
    settings/providerdialog.h \
    setup/dbsetupwizard.h \
    setup/dbwizzselectpage.h \
    setup/dbwizzmysqlpage.h \
    setup/dbwizzsqlitepage.h \
    import/importwizard.h \
    import/importwizzselectmodepage.h
RESOURCES += icons/icons.qrc
