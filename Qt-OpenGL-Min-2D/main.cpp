#include <QApplication>
#include "DrawingSurface.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //initialize glut
    QApplication graphicalApplication(argc, argv);
    DrawingSurface * testSurface = new DrawingSurface(NULL);
    testSurface->setGeometry(0,0,500,500);
    testSurface->show();
    return graphicalApplication.exec();
}
