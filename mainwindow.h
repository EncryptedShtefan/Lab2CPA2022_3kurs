#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datamodel.h"
#include "QTableView"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
   void AddRow();
  void DeleteRow();

private:
    Ui::MainWindow *ui;
    DataModel* dataModel;
    QTableView* tableView;
};
#endif // MAINWINDOW_H
