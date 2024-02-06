// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    z = 0;
}

void MyGLWidget::changeZ(int value)
{
    if (m_angle == 360)
    {
        m_angle = 60;
    }
    m_angle += 1;
    
    updateGL();
}

MyGLWidget::~MyGLWidget()
{
}


void MyGLWidget::drawCube()
{
    m_data = {
        // FRONT FACE
        {{-0.5, -0.5,  0.5}},        {{ 0.5, -0.5,  0.5}},
        {{ 0.5,  0.5,  0.5}},        {{-0.5,  0.5,  0.5}},

        // TOP FACE
        {{-0.5,  0.5,  0.5}},        {{ 0.5,  0.5,  0.5}},
        {{ 0.5,  0.5, -0.5}},        {{-0.5,  0.5, -0.5}},

        // BACK FACE
        {{-0.5,  0.5, -0.5}},        {{ 0.5,  0.5, -0.5}},
        {{ 0.5, -0.5, -0.5}},        {{-0.5, -0.5, -0.5}},

         // BOTTOM FACE
        {{-0.5, -0.5, -0.5}},        {{ 0.5, -0.5, -0.5}},
        {{ 0.5, -0.5,  0.5}},        {{-0.5, -0.5,  0.5}},

        // LEFT FACE
        {{-0.5, -0.5, -0.5}},        {{-0.5, -0.5,  0.5}},
        {{-0.5,  0.5,  0.5}},        {{-0.5,  0.5, -0.5}},

        // RIGHT FACE
        {{ 0.5, -0.5,  0.5}},        {{ 0.5, -0.5, -0.5}},
        {{ 0.5,  0.5, -0.5}},        {{ 0.5,  0.5,  0.5}},
    };
}


void MyGLWidget::initializeGL()
{
    /*qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);*/
    drawCube();
    glClearColor(1, 1, 1, 0);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Keep the OpenGL viewport and the window the same
    glViewport(0, 0, width(), height());

    // Reset the transformation matrix
    glLoadIdentity();
    glScaled(0.5, 0.5, 0.5);
    // In order to view the convenience of the view
    glRotatef(60, 1.0, 0.0, 0.0);
    glRotatef(m_angle, 0.0, 1.0, 0.0);

    glEnable(GL_TEXTURE_2D);
    qglColor(Qt::black);
    glBegin(GL_QUADS);
    for (const CubePoint& point : m_data) {
        glVertex3f(point.posCoord.x(), point.posCoord.y(), point.posCoord.z());
    }
    glEnd();
}

void MyGLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 1, 2);
}





