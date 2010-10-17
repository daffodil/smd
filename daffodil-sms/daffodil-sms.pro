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
    xwidgets/xstatusbar.cpp
HEADERS += mainwindows/mainwindow.h \
    mainobject.h \
    addresses/addresseswidget.h \
    xwidgets/xstatusbar.h
RESOURCES += icons/icons.qrc
