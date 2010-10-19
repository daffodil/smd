#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QAction>
#include <QtGui/QTreeWidget>

class SettingsWidget : public QWidget
{
Q_OBJECT
public:
    explicit SettingsWidget(QWidget *parent = 0);

    QAction *actionEdit;
    QTreeWidget *treeWidget;

signals:

public slots:
    void on_tree_selection_changed();
    void on_tree_double_clicked(QTreeWidgetItem *, int);
};

#endif // SETTINGSWIDGET_H
