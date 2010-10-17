#ifndef ADDRESSESWIDGET_H
#define ADDRESSESWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QProgressBar>

#include "mainobject.h"
#include "xwidgets/xstatusbar.h"

class AddressesWidget : public QWidget
{
Q_OBJECT

public:

    enum COLS{
        C_NAME = 0,
        C_SALUTATION = 1,
        C_COMPANY = 2,
        C_MOBILE = 3
    };


    explicit AddressesWidget(MainObject *mOb, QWidget *parent = 0);

    MainObject *mainObject;

    QTreeWidget *treeWidget;

    QAction *actionAdd;
    QAction *actionEdit;
    QAction *actionDelete;

    XStatusBar *statusBar;
    QProgressBar *progressBar;

signals:

public slots:

    void on_tree_selection_changed();

    void on_action_add();
    void on_action_edit();
    void on_action_delete();
};

#endif // ADDRESSESWIDGET_H
