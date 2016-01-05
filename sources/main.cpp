///
/// \file main.cpp
/// \brief TODO
/// \author Martin-Pierrat Louis (mart_p)
/// \version 1.0.0
/// \date October 13, 2015
///
/// TODO
///

#include    "worldparticles.hpp"
#include    "mainwindow.hpp"

#include    <QApplication>
#include    <log4cpp/PropertyConfigurator.hh>
#include    <log4cpp/Category.hh>

int     main(int argc, char *argv[])
{
    QApplication    a(argc, argv);
    MainWindow      w;
    log4cpp::PropertyConfigurator::configure(RESOURCES_PATH "/log4cpp.conf");
    log4cpp::Category& root = log4cpp::Category::getRoot();

    root << log4cpp::Priority::INFO << "Lancement worldparticles :";
    root << log4cpp::Priority::INFO << "\t version : " WORLD_PARTICLES_VERSION_FULL;
    w.show();
    return a.exec();
}
