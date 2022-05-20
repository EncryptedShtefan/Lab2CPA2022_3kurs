#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "QGridLayout"
#include "datamodel.h"
#include "editadddialog.h"
#include "editdelegate.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableView = new QTableView();
    dataModel = new DataModel(this);
    tableView->setModel( dataModel );

    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,2);

    QPushButton* pb1 = new QPushButton("Add row");
    QPushButton* pb2 = new QPushButton("Delete row");

    glay->addWidget(pb1,2,1);
    glay->addWidget(pb2,2,2);

    QObject::connect(pb1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(pb2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));


    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);

    //tableView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditAddDialog* addDialog = new EditAddDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Game* gm = new Game(addDialog->id(),addDialog->name(),addDialog->genre(), addDialog->developer(), addDialog->platform(), this);
        dataModel->AddGame(gm);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex delList = tableView->currentIndex();
   dataModel->DeleteGame(delList.row());
}
