#ifndef DRAWINGSURFACE_H
#define DRAWINGSURFACE_H

#include <iostream>
#include <QGLWidget>

class DrawingSurface: public QGLWidget
{
public:
    DrawingSurface(QWidget *);

protected:

    void initializeGL();
    void resizeGL(int ,int);
    void paintGL();

private:

    void drawSurface();
};

#endif // DRAWINGSURFACE_H
