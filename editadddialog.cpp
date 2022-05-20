#include "editadddialog.h"
#include "game.h"

EditAddDialog::EditAddDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editGenre = new QComboBox();
    editDeveloper = new QLineEdit();
    editPlatform = new QComboBox();
    QStringList genres = Game::GetGenres();
    QStringList platforms = Game::GetPlatforms();

    foreach  (QString sh, genres)
    {
        editGenre->addItem(sh);
    }

    foreach(QString sh,  platforms)
    {
         editPlatform->addItem(sh);
    }

    QGridLayout* mainLayout = new QGridLayout; //грид окна добавления

    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Name"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Genre"),3,1);
    mainLayout->addWidget(editGenre,3,2);
    mainLayout->addWidget(new QLabel("Developer"),4,1);
    mainLayout->addWidget(editDeveloper,4,2);
     mainLayout->addWidget(new QLabel("Platform"),5,1);
    mainLayout->addWidget(editPlatform,5,2);

    QPushButton* btnOk = new QPushButton("&ОК");

    mainLayout->addWidget(btnOk,6,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Game Info");

    int gx;
    int gy;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();
    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditAddDialog::id() const
{
    return editID->text();
}
QString EditAddDialog::name() const
{
    return editName->text();
}
QString EditAddDialog::genre() const
{
    return editGenre->currentText();
}

QString EditAddDialog::developer() const
{
    return editDeveloper->text();
}

QString EditAddDialog::platform() const
{
    return editPlatform->currentText();
}

void EditAddDialog::SetUpDialog(QString id, QString name,QString genre, QString developer, QString platform)
{
    editID->setText(id);
    editName->setText(name);
    editDeveloper->setText(developer);


    int index = editGenre->findText(genre);
    if (index>=0)
    {
        editGenre->setCurrentIndex(index);
    }
    index = editPlatform->findText(platform);
    if (index>=0)
    {
        editPlatform->setCurrentIndex(index);
    }
}
