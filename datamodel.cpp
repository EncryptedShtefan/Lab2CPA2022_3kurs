#include "datamodel.h"

//это у нас короче моделька данных, ниже добавляем игрушек со всеми необходимыми, указанными в game параметрами

DataModel::DataModel(QObject *parent)
                     :QAbstractTableModel(parent)
{
    Game *gm1 = new Game("100", "WarThunder", "Action", "Gaijin", "Windows PC", this);
    Game *gm2 = new Game("101", "WorldOfTanks", "Action", "Kartoshka)", "Windows PC", this);
    Game *gm3 = new Game("102", "Battlefield 4", "Action", "DICE", "Windows PC", this);
    Game *gm4 = new Game("103", "7 Days to Die", "Survival", "The Fun Pimps", "Windows PC", this);
    AddGame(gm1);
    AddGame(gm2);
    AddGame(gm3);
    AddGame(gm4);
}


int DataModel::rowCount(const QModelIndex &) const
{
    return games.count();
}

int DataModel::columnCount(const QModelIndex &) const
{
    return 5;
}

QVariant DataModel::data(const QModelIndex &index, int role) const //вывод данных
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Game* std = games.at(index.row());
        if (index.column() == 0){Value = std->ID();}
        else if (index.column() == 1){Value = std->Name();}
        else if (index.column() == 2){Value = std->Genre();}
        else if (index.column() == 3){Value = std->Developer();}
        else if (index.column() == 4){Value = std->Platform();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}

QVariant DataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Name");
            case 2:
                return QString("Genre");
            case 3:
                return QString("Developer");
            case 4:
                return QString("Platform");
            }
        }
    }
    return QVariant();
}

bool DataModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
     {
         Game* std = games.at(index.row());
         if (index.column() == 0){std->SetID(value.toString());}
         else if (index.column() == 1){std->SetName(value.toString());}
         else if (index.column() == 2){std->SetGenre(value.toString());}
         else if (index.column() == 3){std->SetDeveloper(value.toString());}
         else if (index.column() == 4){std->SetPlatform(value.toString());}
     }
     return true;
}

Qt::ItemFlags DataModel::flags(const QModelIndex &) const
{
     return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void DataModel::AddGame(Game *game)
{
    beginInsertRows(QModelIndex(),games.size(),games.size());
    games.append(game);
    endInsertRows();
}

void DataModel::DeleteGame(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    games.removeAt(row);
    endRemoveRows();
}















