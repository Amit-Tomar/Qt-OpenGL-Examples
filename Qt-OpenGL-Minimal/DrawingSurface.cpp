#include "DrawingSurface.h"

DrawingSurface::DrawingSurface(QWidget * parent = 0) : QGLWidget(parent)
{
}

void DrawingSurface::initializeGL()
{
    glClearColor(0.0,1.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void DrawingSurface::drawSurface()
{
    glPointSize(10);
    glBegin(GL_TRIANGLES);
        glVertex3f(0.0,0.0,0);
        glVertex3f(1.0,0.0,0);
        glVertex3f(0.5,1.0,0);
    glEnd();
}

void DrawingSurface::resizeGL(int width, int height)
{
    glViewport(0, 0, (GLint)width, (GLint)height);
}

void DrawingSurface::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

    drawSurface();
}
