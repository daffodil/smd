#ifndef ADDRESSESWIDGET_H
#define ADDRESSESWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QStandardItemModel>
#include <QtGui/QSortFilterProxyModel>
#include <QtGui/QTreeView>
#include <QtGui/QProgressBar>

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


    explicit AddressesWidget(QWidget *parent = 0);

    QStandardItemModel *model;
    QSortFilterProxyModel *proxyModel;
    QTreeView *treeView;

    XStatusBar *statusBar;
    QProgressBar *progressBar;

signals:

public slots:

};

#endif // ADDRESSESWIDGET_H
