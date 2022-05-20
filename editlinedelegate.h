#ifndef EDITLINEDELEGATE_H
#define EDITLINEDELEGATE_H

#include <QtWidgets>

class editlinedelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    editlinedelegate(QObject *parent);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
        void setModelData(QWidget *editor, QAbstractItemModel *model,
                          const QModelIndex &index) const;
        void setEditorData(QWidget *editor, const QModelIndex &index) const;
        void paint(QPainter* painter,
                   const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;

    };

#endif



