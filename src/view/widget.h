#ifndef WIDGET_H
#define WIDGET_H

#include <qgifimage.h>

#include <QBasicTimer>
#include <QDir>
#include <QOpenGLWidget>
#include <QWidget>

#include "geometry.h"
#include "settings.h"

class GeometryEngine;

class Widget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

public:
  explicit Widget(QWidget *parent);
  ~Widget();
  QOpenGLShaderProgram program;
  void initColors();
  void initColorsVer();
  void initShaders();
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
  void timerEvent(QTimerEvent *e) override;
  void setController(s21::Controller *cnt) { controller_ = cnt; }
  void startGif(const QString path);
  void recordGif();
  s21::Settings *settings_;
  GeometryEngine *geometries_ = nullptr;
  size_t line_width = 2;
  int vertex_size = 0;

  // MOVE, SCALE, ROTATE
  void rotateX(double angleX);
  void rotateY(double angleY);
  void rotateZ(double angleZ);
  void moveX(double lenX);
  void moveY(double lenY);
  void moveZ(double lenZ);
  void scale(double zoom);
  void set_position();

private:
  s21::Controller *controller_;
  QMatrix4x4 projection;
  QQuaternion rotation;
  bool perspective;
  double xRot{0}, yRot{0}, zRot{0}, xMove{0}, yMove{0}, zMove{-7}, scaleZ{0.4};
  QGifImage *gif;
  QString gifPath;
  unsigned frameCount = 50;
  QBasicTimer timerGif;
};

#endif // WIDGET_H
