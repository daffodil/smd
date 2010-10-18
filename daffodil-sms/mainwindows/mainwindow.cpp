#include "mainwindow.h"

#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>



MainWindow::MainWindow(MainObject *mOb, QWidget *parent)
    : QMainWindow(parent)
{
    mainObject = mOb;

    setWindowTitle("SMS Desktop");
    setFixedWidth(800);
    setFixedHeight(500);
    move(30,30);

    QWidget *centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    centralWidget->setLayout(mainLayout);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);

    QLabel *headerLabel = new QLabel();
    headerLabel->setText("SMS Desktop");
    mainLayout->addWidget(headerLabel);

    tabWidget = new QTabWidget();

    mainLayout->addWidget(tabWidget);

    addressesWidget = new AddressesWidget(mainObject);
    tabWidget->addTab(addressesWidget, "Addresses");



}

MainWindow::~MainWindow()
{

}
