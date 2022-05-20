#ifndef GAME_H
#define GAME_H
#include "QString"
#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    Game(QString ID, QString Name, QString Genre, QString Developer, QString Platform, QObject *parent = nullptr );
    virtual ~Game();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetGenre(QString Genre);
    void SetDeveloper(QString Developer);
    void SetPlatform(QString Platform);

    QString ID();
    QString Name();
    QString Genre();
    QString Developer();
    QString Platform();
    static QStringList GetGenres();
    static QStringList GetPlatforms();
private:
    QString id;
    QString name;
    QString genre;
    QString developer;
    QString platform;
};

#endif // GAME_H
