#include "settingswidget.h"
#include "settings/providerdialog.h"

#include <QtCore/QtDebug>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QTreeWidgetItem>
#include <QtGui/QHeaderView>
#include <QtGui/QItemSelectionModel>
#include <QtGui/QToolBar>

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

SettingsWidget::SettingsWidget(QWidget *parent) :
    QWidget(parent)
{

    setWindowIcon(QIcon(":/icons/settings"));
    setWindowTitle("Settings");
    setFixedWidth(500);
    setFixedHeight(500);
    move(30,30);


    QVBoxLayout *mainLayout = new QVBoxLayout();
    this->setLayout(mainLayout);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);

    //** Header Label
    QLabel *headerLabel = new QLabel();
    headerLabel->setText("Settings");
    headerLabel->setStyleSheet("font-size: 20pt; background-color: white; color: green;");
    mainLayout->addWidget(headerLabel);


    //*** Tab Widget
    QTabWidget *tabWidget = new QTabWidget();
    mainLayout->addWidget(tabWidget);

    //*****************************************************
    //** Providers
    QWidget *providersWidget = new QWidget();
    QVBoxLayout *providersLayout = new QVBoxLayout();
    providersWidget->setLayout(providersLayout);
    tabWidget->addTab(providersWidget, QIcon(":/icons/providers"), "Providers");

    //** Toolbar
    QToolBar *toolBar = new QToolBar();
    providersLayout->addWidget(toolBar);
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBar->layout()->setSpacing(2);

    //** Edit Contact
    actionEdit = new QAction(toolBar);
    toolBar->addAction(actionEdit);
    actionEdit->setIcon(QIcon(":/icons/provider"));
    actionEdit->setText("Edit");
    actionEdit->setDisabled(true);

    //** Tree Widget
    treeWidget = new QTreeWidget();
    providersLayout->addWidget(treeWidget);
    treeWidget->setAlternatingRowColors(true);
    treeWidget->setRootIsDecorated(true);
    treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    QTreeWidgetItem *headerItem = treeWidget->headerItem();
    headerItem->setText(0, "Enabled");
    headerItem->setText(1, "Provider");
    headerItem->setText(2, "User");
    headerItem->setText(3, "Password");
    treeWidget->header()->setStretchLastSection(true);
    treeWidget->setColumnWidth(0, 80);

    connect(treeWidget, SIGNAL(itemSelectionChanged()), this, SLOT(on_tree_selection_changed()));
    connect(treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(on_tree_double_clicked(QTreeWidgetItem*,int)));

    load_providers();

}


void SettingsWidget::on_tree_selection_changed()
{
    actionEdit->setDisabled( !treeWidget->selectionModel()->hasSelection() );
}

void SettingsWidget::on_tree_double_clicked(QTreeWidgetItem *item, int column)
{
    //ProviderDialog *dialog = new ProviderDialog();
    //dialog->exec();
}




void SettingsWidget::load_providers()
{
    QSqlQuery query("Select active, provider, username, password from providers order by provider");
    while(query.next()){
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setCheckState(0, query.value(0).toBool() ? Qt::Checked : Qt::Unchecked);
        item->setText(1, query.value(1).toString());
        //item->setText(2, query.value(1).toString());
        //item->setText(3, query.value(2).toString());
        treeWidget->addTopLevelItem(item);
    }

}
