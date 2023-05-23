#pragma once

#include <widget.h>

#include "settings.h"

namespace s21 {
class Facade {
public:
  explicit Facade(Widget *openGLWidget);
  ~Facade() = default;

  void openFile(const QString &str);
  void scale(double val);
  void applyLineWidth(double val);
  void applyVertexWidth(double val);
  void move(double x, double y, double z);
  void rotate(double x, double y, double z);
  void moveX(double val);
  void moveY(double val);
  void moveZ(double val);
  void rotateX(double val);
  void rotateY(double val);
  void rotateZ(double val);
  void resize(double h, double w);
  void update();

  void saveSettings();
  void setPosition();
  void setBackgroundColor(QColor color);
  QColor getBackgroundColor();
  void setVertexColor(QColor color);
  QColor getVertexColor();
  void setLineColor(QColor color);
  QColor getLineColor();
  void setVertexSize(double val);
  void setLineSize(double val);
  void setVertexType(Settings::TypeVertex type);
  void setLineType(Settings::TypeLines type);
  void setProjectionType(Settings::Projection type);
  void setDefaultSettings();
  void makeScreenshot();
  void makeGif();

private:
  Widget *openGLWidget_;
  Settings *settings_;
};
} // namespace s21
