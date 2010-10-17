#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include "mainobject.h"

#include "addresses/addresseswidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(MainObject *mOb, QWidget *parent = 0);
    ~MainWindow();

    MainObject *mainObject;
    QTabWidget *tabWidget;

    AddressesWidget *addressesWidget;
};

#endif // MAINWINDOW_H
