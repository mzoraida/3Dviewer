#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <qmath.h>

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

#include "../controller/controller.h"
#include "settings.h"

class GeometryEngine : public QOpenGLFunctions {
  struct VertexData {
    QVector3D position;
  };

public:
  explicit GeometryEngine(s21::Controller *controller);
  virtual ~GeometryEngine();
  void drawLine(QOpenGLShaderProgram *program);
  void drawDot(QOpenGLShaderProgram *program);
  void ConvertingToQVector3D();
  QString filepath;

private:
  QOpenGLBuffer arrayBuf_;
  QOpenGLBuffer indexBuf_;
  s21::Controller *ctrl_;
  GLsizei lines_{0};
};

#endif // GEOMETRY_H
