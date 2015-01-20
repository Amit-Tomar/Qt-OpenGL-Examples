#include "DrawingSurface.h"

DrawingSurface::DrawingSurface(QWidget * parent = 0) : QGLWidget(parent)
{
}

/*
    Called only once at the beginning. Write constant initialization settings here.
*/
void DrawingSurface::initializeGL()
{
    glClearColor(1.0,1.0,1.0,1.0); // Set the background color
    glEnable(GL_DEPTH_TEST);

    // Improves performance by ignoring the rendering of back faces
    glEnable(GL_CULL_FACE);

    // Normalises all the normals automatically
    glEnable(GL_NORMALIZE);


    // Allows Alpha value blending to be enabled
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /*
        By default the OpenGL centre is at the centre of the screen.
        We can change it to other parts be using diffent projection methods.

        glOrtho(xmin,xmax,ymin,ymax,znear,zfar);
    */

    // Make bottom left as the coordinate system
    // glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    // Make top left as the coordinate system
    // glOrtho(0.0, 1.0, 1.0, 0.0, -1.0, 1.0);
}

void DrawingSurface::drawSurface()
{
    glPointSize(5);
    glColor4f(1.0,0.0,0.0,.5);

    // Triangle
    glBegin(GL_TRIANGLES);
        glVertex3f(0.0,0.0,0);
        glVertex3f(1.0,0.0,0);
        glVertex3f(0.5,1.0,0);
    glEnd();

    // Cube using GLUT
    glColor3f(.30,.90,.10);
    glutSolidCube(1.5);

    // Circle
    glPointSize(2);
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POINTS);

    float radius = .75;

    for( float theta = 0 ; theta < 360 ; theta+=.01 )
        glVertex3f( radius * cos(theta), radius * sin(theta), 0  );

    glEnd();

    // Using Vertex arrays to draw something
    glColor4f(0.0, 0.0, 0.0, 1.0);
    GLfloat vertexArray [] = {
                                -.5, -.5, 0,
                                .5, -.5, 0,
                                .5, .5, 0,
                               -.5, .5, 0,
                             };

    GLfloat colorArray [] = {
                                .1, .1, .1,
                                .5, .5, .5,
                                .1, .5, .5,
                               -.5, .1, .5,
                                .1, .1, .5
                            };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertexArray);
    glColorPointer (3, GL_FLOAT, 0, colorArray);

    glBegin(GL_POLYGON);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();


    /* Note this won't work because the normals will not be proper.
     * Give the vertices of triangle in an order such that Normals are
     * outside towards the viewer. Definition of outwards can be changed
     * by a setting however. By default counter clockwise vertex order in
     * considerer outside normal because of the right hand rule.
     * glBegin(GL_TRIANGLES);

            glVertex3f(0.5,1.0,0);
            glVertex3f(1.0,0.0,0);
            glVertex3f(0.0,0.0,0);

       glEnd();
    */

    // To get current system variable values
    float currentColor[] = { 0,0,0 };
    glGetFloatv(GL_CURRENT_COLOR, currentColor);
    std::cout << "Current Color is: " << currentColor[0] << " " << currentColor[1] << " " << currentColor[2] << std::endl;
}

void DrawingSurface::resizeGL(int width, int height)
{
    // Update the drawable area in case the widget area changes
    glViewport(0, 0, (GLint)width, (GLint)height);
}

void DrawingSurface::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawSurface();
}
