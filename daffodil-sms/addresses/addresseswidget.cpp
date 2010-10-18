

#include <QtGui/QVBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QToolBar>
#include <QtGui/QIcon>
#include <QtGui/QAction>
#include <QtGui/QTreeWidgetItem>

#include "addresseswidget.h"
#include "services/textmarketer.h"

AddressesWidget::AddressesWidget(MainObject *mOb, QWidget *parent) :
    QWidget(parent)
{
    mainObject = mOb;

    QVBoxLayout *mainLayout = new QVBoxLayout();
    setLayout(mainLayout);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);



    //*************************************************
    //** Toolbar
    QToolBar *toolBar = new QToolBar();
    mainLayout->addWidget(toolBar);
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBar->layout()->setSpacing(2);


    //** Add Contact
    actionAdd = new QAction(toolBar);
    toolBar->addAction(actionAdd);
    actionAdd->setIcon(QIcon(":/icons/contact_add"));
    actionAdd->setText("Add");
    connect(actionAdd, SIGNAL(triggered()), this, SLOT(on_action_add()));

    //** Edit Contact
    actionEdit = new QAction(toolBar);
    toolBar->addAction(actionEdit);
    actionEdit->setIcon(QIcon(":/icons/contact_edit"));
    actionEdit->setText("Edit");
    actionEdit->setDisabled(true);

    //** Delete Contact
    actionDelete = new QAction(toolBar);
    toolBar->addAction(actionDelete);
    actionDelete->setIcon(QIcon(":/icons/contact_delete"));
    actionDelete->setText("Delete");
    actionDelete->setDisabled(true);

    toolBar->addSeparator();

    //** TEST Contact
    QAction *actionTest = new QAction(toolBar);
    toolBar->addAction(actionTest);
    actionTest->setIcon(QIcon(":/icons/contact_delete"));
    actionTest->setText("Delete");
    connect(actionTest, SIGNAL(triggered()), this, SLOT(on_test_123()));

    //******************************************************
    //**  Tree
    treeWidget = new QTreeWidget(this);
    mainLayout->addWidget(treeWidget);   

    treeWidget->setUniformRowHeights(true);
    treeWidget->setAlternatingRowColors(true);
    treeWidget->setRootIsDecorated(false);
    treeWidget->setSortingEnabled(true);
    treeWidget->sortByColumn(C_NAME, Qt::AscendingOrder);
    treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
   // treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    treeWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);

    //** Deaders and columns
    treeWidget->header()->setStretchLastSection(true);
    QTreeWidgetItem *headerItem = treeWidget->headerItem();
    headerItem->setText(C_NAME, "Contact");
    headerItem->setText(C_SALUTATION, "Salutation");
    headerItem->setText(C_COMPANY, "Company");
    headerItem->setText(C_MOBILE, "Mobile");

    treeWidget->setColumnWidth(C_NAME, 100);
    treeWidget->setColumnWidth(C_SALUTATION, 100);
    treeWidget->setColumnWidth(C_COMPANY, 100);
    treeWidget->setColumnWidth(C_MOBILE, 100);

    connect( treeWidget,SIGNAL( itemSelectionChanged() ),
             this,      SLOT( on_tree_selection_changed() )
    );


    //************************************************************************
    //*** Status Bar
    statusBar = new XStatusBar();
    mainLayout->addWidget(statusBar);
    statusBar->showMessage("Idle");

    progressBar = new QProgressBar();
    statusBar->addPermanentWidget(progressBar);

}

void AddressesWidget::on_tree_selection_changed(){
    bool has_sel = treeWidget->selectionModel()->hasSelection();
    actionEdit->setDisabled(!has_sel);
    actionDelete->setDisabled(!has_sel);
}



void AddressesWidget::on_action_add(){
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(C_NAME, "name");
    item->setText(C_SALUTATION, "s");
    item->setText(C_COMPANY, "co");
    item->setText(C_MOBILE, "mo");
    treeWidget->insertTopLevelItem(0, item);
    treeWidget->setCurrentItem(item);
    treeWidget->editItem(item, C_NAME);
}
void AddressesWidget::on_action_edit(){

}
void AddressesWidget::on_action_delete(){
}


void AddressesWidget::on_test_123(){
    qDebug("test123");
    TextMarketer *m = new TextMarketer();
    qDebug() << m->credits();
}
