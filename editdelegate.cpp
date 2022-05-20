#include "editdelegate.h"
#include "QtWidgets"
#include "editadddialog.h"

EditDelegate::EditDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}


bool EditDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditAddDialog* editDialog = new EditAddDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Genre = model->data(model->index(index.row(),2,index)).toString();
        QString Developer = model->data(model->index(index.row(),3,index)).toString();
        QString Platform = model->data(model->index(index.row(),4,index)).toString();

        editDialog->SetUpDialog(ID, Name, Genre, Developer, Platform);

        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->genre());
            model->setData(model->index(index.row(),3,index),editDialog->developer());
            model->setData(model->index(index.row(),4,index),editDialog->platform());
        }

         editDialog->deleteLater();
    }
    return false;
}

//QWidget *EditDelegate::createEditor(QWidget* /* parent */,
//    const QStyleOptionViewItem &/* option */,
//    const QModelIndex &/* index */) const
//{
//    return nullptr;
//}
