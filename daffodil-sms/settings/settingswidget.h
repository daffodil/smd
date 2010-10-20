#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QAction>
#include <QtGui/QTreeWidget>
#include "mainobject.h"

class SettingsWidget : public QWidget
{
Q_OBJECT
public:
    explicit SettingsWidget(MainObject *mOb, QWidget *parent = 0);

    MainObject *mainObject;
    QAction *actionEdit;
    QTreeWidget *treeWidget;

signals:

public slots:
    void on_tree_selection_changed();
    void on_tree_double_clicked(QTreeWidgetItem *, int);
    void load_providers();
};

#endif // SETTINGSWIDGET_H
