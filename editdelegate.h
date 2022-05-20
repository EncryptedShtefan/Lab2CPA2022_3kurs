#ifndef EDITDELEGATE_H
#define EDITDELEGATE_H

#include "QtWidgets"

class EditDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    EditDelegate(QObject *parent = nullptr, QWidget* parentWidget = nullptr);
    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option, const QModelIndex &index);

    private:
    QWidget* dparentWidget;
};

#endif // EDITDELEGATE_H
