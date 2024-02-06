// window.cpp

#include <QtWidgets>
#include "window.h"
#include "ui_window.h"

#include "myglwidget.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
   
    connect(ui->rotXSlider, &QSlider::valueChanged, ui->myGLWidget, &MyGLWidget::changeZ);
  
}

Window::~Window()
{
    delete ui;
}

//void Window::keyPressEvent(QKeyEvent *e)
//{
//    if (e->key() == Qt::Key_Escape)
//        close();
//    else
//        QWidget::keyPressEvent(e);
//}
