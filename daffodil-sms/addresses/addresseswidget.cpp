

#include <QtGui/QVBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QToolBar>


#include "addresseswidget.h"

AddressesWidget::AddressesWidget(MainObject *mOb, QWidget *parent) :
    QWidget(parent)
{
    mainObject = mOb;

    QVBoxLayout *mainLayout = new QVBoxLayout();
    setLayout(mainLayout);



    //*************************************************
    //** Toolbar
    QToolBar *toolBar = new QToolBar();
    mainLayout->addWidget(toolBar);
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBar->layout()->setSpacing(10);




    //******************************************************
    //** Models
    model = new QStandardItemModel(this);
    model->setColumnCount(2);
    QStringList headerLabelsList;
    headerLabelsList << "Name" << "Salutation"  << "Company" <<  "Mobile" << "#";
    model->setHorizontalHeaderLabels(headerLabelsList);

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterKeyColumn( C_NAME );

    //******************************************************
    //**  Tree
    treeView = new QTreeView(this);
    mainLayout->addWidget(treeView);
    treeView->setModel(proxyModel);

    treeView->setUniformRowHeights(true);
    treeView->setAlternatingRowColors(true);
    treeView->setRootIsDecorated(false);
    treeView->setSortingEnabled(true);
    treeView->sortByColumn(C_NAME, Qt::AscendingOrder);
    treeView->setSelectionMode(QAbstractItemView::SingleSelection);
    treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
    treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //** Deaders and columns
    treeView->header()->setStretchLastSection(true);
    //treeView->setColumnHidden(C_ELEVATION, true);
    //treeView->setColumnHidden(C_TOWER, true);
    treeView->setColumnWidth(C_NAME, 100);
    treeView->setColumnWidth(C_SALUTATION, 100);
    treeView->setColumnWidth(C_COMPANY, 100);
    treeView->setColumnWidth(C_MOBILE, 100);

    connect( treeView->selectionModel(),
             SIGNAL( selectionChanged (const QItemSelection&, const QItemSelection&) ),
             SLOT( on_aiport_clicked(const QItemSelection&, const QItemSelection&) )
    );

    //connect(treeView,
    //        SIGNAL(clicked(QModelIndex)),
    //        this, SLOT(on_tree_clicked(QModelIndex))
    //);

    //************************************************************************
    //*** Status Bar
    statusBar = new XStatusBar();
    mainLayout->addWidget(statusBar);
    statusBar->showMessage("Idle");

    progressBar = new QProgressBar();
    statusBar->addPermanentWidget(progressBar);

}
