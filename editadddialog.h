#ifndef EDITADDDIALOG_H
#define EDITADDDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <game.h>

class EditAddDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* editID;
    QLineEdit* editName;
    QComboBox* editGenre;
    QLineEdit* editDeveloper;
    QComboBox* editPlatform;

public:
    EditAddDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString genre() const;
    QString developer() const;
    QString platform() const;

    void SetUpDialog(QString id, QString name,QString genre, QString developer, QString platform);
};

#endif // EDITADDDIALOG_H
