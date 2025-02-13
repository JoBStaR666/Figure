#include "figurewindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FigureWindow w;
    w.show();
    return a.exec();
}
