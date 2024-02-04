// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
   
}

MyGLWidget::~MyGLWidget()
{
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
}

void MyGLWidget::paintGL()
{
    glClearColor(0, 1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT );
   
   
    qglColor(Qt::red);
    glBegin(GL_TRIANGLES);
    glColor3d(1, 0, 0);
    glVertex2d(0, 0);
    glVertex2d(1, 0);
    glVertex2d(0, 1);
    glEnd();
}

void MyGLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}





