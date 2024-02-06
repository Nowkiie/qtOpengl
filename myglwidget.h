// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include <qvector3d.h>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
signals:

public slots:

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);

   

private:
   // QTimer tmr;
    float z;
    void drawCube();

    struct CubePoint {
        QVector3D posCoord;        // Space coordinates
        CubePoint(const QVector3D& position = QVector3D()
           ) :posCoord(position) {
        }
    };
    qreal m_angle = 60;
    QVector<CubePoint> m_data;

public slots:
    void changeZ(int value);
};

#endif // MYGLWIDGET_H

