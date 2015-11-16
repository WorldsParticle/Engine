///
/// \file main.cpp
/// \brief TODO
/// \author Martin-Pierrat Louis (mart_p)
/// \version 1.0.0
/// \date October 13, 2015
///
/// TODO
///

#include    "mainwindow.h"

#include    <QApplication>

int     main(int argc, char *argv[])
{
    QApplication    a(argc, argv);
    MainWindow      w;

    w.show();
    return a.exec();
}
