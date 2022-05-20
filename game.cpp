#include "game.h"

Game::Game(QString ID, QString Name, QString Genre, QString Developer, QString Platform, QObject *parent):QObject(parent)
{
    id = ID;
    name = Name;
    genre = Genre;
    developer = Developer;
    platform = Platform;
}

void Game::SetID(QString ID)
{
    id = ID;
}

void Game::SetName(QString Name)
{
    name = Name;
}

void Game::SetGenre(QString Genre)
{
    genre = Genre;
}

void Game::SetDeveloper(QString Developer)
{
    developer = Developer;
}

void Game::SetPlatform(QString Platform)
{
    platform = Platform;
}

QString Game::Name()
{
    return name;
}

QString Game::ID()
{
    return id;
}

QString Game::Platform()
{
    return platform;
}

QString Game::Developer()
{
    return developer;
}

QString Game::Genre()
{
    return genre;
}

QStringList Game::GetGenres()
{
    QStringList value;
    value.append("Action");
    value.append("RPG");
    value.append("Strategy");
    value.append("Economic");
    value.append("SIM");
    value.append("RTS");
    value.append("Browser's");
    value.append("Quest");
    value.append("Platformer");
    value.append("Arcade");
    value.append("Survival");
    return value;
}
QStringList Game::GetPlatforms()
{
    QStringList value;
    value.append("Windows PC");
    value.append("PlayStation");
    value.append("Xbox");
    value.append("Other");
    return value;
}

Game::~Game()
{}
