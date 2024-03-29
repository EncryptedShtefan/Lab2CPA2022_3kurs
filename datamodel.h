#pragma once
#define DATAMODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <game.h>

class DataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    DataModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;

    void AddGame(Game* game);
    void DeleteGame(int row);

private:
    QList<Game*> games;
};

