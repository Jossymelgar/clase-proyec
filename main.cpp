#include "principal.h"
#include <QApplication>
#include "carros.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    principal w;
    w.show();

    return a.exec();
}
