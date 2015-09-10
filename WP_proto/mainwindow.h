#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "toolwidget.h"
#include "model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void newWorld();
    void generate();
    void explore();
    void importConf();
    void exportConf();
    void exit();

private:
    void    makeConnections(); // connection avec les signaux de l'ui. on peut le faire depuis l'ui design, mais c'est moche

    Ui::MainWindow* _ui;
    Model           _model;
};

#endif // MAINWINDOW_H
