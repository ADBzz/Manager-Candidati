#include "managercandidati.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ManagerCandidati w;

    w.load();
    w.show();
    return a.exec();
}
