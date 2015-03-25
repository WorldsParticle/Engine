#include <qinputdialog.h>
#include <qdebug.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _model()
{
    _ui->setupUi(this);

    makeConnections();
	newWorld();
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void    MainWindow::makeConnections()
{
    connect(_ui->actionNouveau, SIGNAL(triggered()), this, SLOT(newWorld()));
    connect(_ui->actionExplorer, SIGNAL(triggered()), this, SLOT(explore()));
    connect(_ui->actionExporter, SIGNAL(triggered()), this, SLOT(exportConf()));
    connect(_ui->actionGenerer, SIGNAL(triggered()), this, SLOT(generate()));
    connect(_ui->actionImporter, SIGNAL(triggered()), this, SLOT(importConf()));
    connect(_ui->actionExplorer, SIGNAL(triggered()), this, SLOT(explore()));
    connect(_ui->actionQuitter, SIGNAL(triggered()), this, SLOT(exit()));
}

void    MainWindow::newWorld()
{
    bool                ok;
    Model::WorldConf    *world = NULL;

    String text = QInputDialog::getText(this, tr("Nouveau Monde"),
                                              tr("Nom du monde"), QLineEdit::Normal,
                                              QString(),
                                              &ok);
    if (ok && !text.isEmpty())
    {
        world = _model.createWorldConf(text);
        qDebug() << "toto";
        _ui->toolBox->setConfiguration(world);
        qDebug() << "toto";
    }
}

void    MainWindow::generate()
{
    /*
     * this->scene->generate(conf)
     * this->_ui->graphicsView->setScene(this->scene);
     */
}

void    MainWindow::explore()
{
    // c'est la qu'on balance l'occulus
}

void    MainWindow::importConf()
{
    // pop up window here
    // charger un xml ca le fait
}

void    MainWindow::exportConf()
{
    // idem
}

void    MainWindow::exit()
{
    // la flemme y'a la croix rouge
}
