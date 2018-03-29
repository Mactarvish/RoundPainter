#include "widget.h"
#include "brushrevolver.h"
#include <QDebug>
#include <vector>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    BrushRevolver revolver;\


    return a.exec();
}
