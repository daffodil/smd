#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>


#include "addresses/addresseswidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTabWidget *tabWidget;

    AddressesWidget *addressesWidget;
};

#endif // MAINWINDOW_H
