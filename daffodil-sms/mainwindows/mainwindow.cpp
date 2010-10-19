#include "mainwindow.h"

#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QToolBar>

#include "settings/settingswidget.h"

MainWindow::MainWindow(MainObject *mOb, QWidget *parent)
    : QMainWindow(parent)
{
    mainObject = mOb;

    setWindowIcon(QIcon(":/icons/favicon"));
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

    //** Header Label
    QLabel *headerLabel = new QLabel();
    headerLabel->setText("SMS Desktop");
    headerLabel->setStyleSheet("font-size: 20pt; background-color: white; color: green;");
    mainLayout->addWidget(headerLabel);

    //**** Toolbar
    QToolBar *toolBar = new QToolBar();
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    mainLayout->addWidget(toolBar);

    //** Settings
    QAction *actionSettings = new QAction(toolBar);
    actionSettings->setIcon(QIcon(":/icons/settings"));
    actionSettings->setText("Settings");
    toolBar->addAction(actionSettings);
    connect(actionSettings, SIGNAL(triggered()), this, SLOT(on_settings()));

    mainLayout->addSpacing(20);


    //**** Tab Widget
    tabWidget = new QTabWidget();
    mainLayout->addWidget(tabWidget);

    //** Addresses Pane
    addressesWidget = new AddressesWidget(mainObject);
    tabWidget->addTab(addressesWidget, "Addresses");



}

MainWindow::~MainWindow()
{

}

void MainWindow::on_settings()
{
    SettingsWidget *widget = new SettingsWidget();
    widget->show();
}
