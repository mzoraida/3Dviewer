#include "facade.h"

#include <QDate>
#include <QFileDialog>
#include <QTime>

namespace s21 {

Facade::Facade(Widget *openGLWidget) : openGLWidget_(openGLWidget) {
  settings_ = openGLWidget_->settings_;
};

void Facade::openFile(const QString &str) {
  openGLWidget_->geometries_->filepath = str;
  openGLWidget_->geometries_->ConvertingToQVector3D();
  openGLWidget_->geometries_->drawLine(&openGLWidget_->program);
}

void Facade::scale(double val) { openGLWidget_->scale(val); }

void Facade::applyLineWidth(double val) { openGLWidget_->line_width = val; }

void Facade::applyVertexWidth(double val) { openGLWidget_->vertex_size = val; }

void Facade::move(double x, double y, double z) {
  moveX(x);
  moveY(y);
  moveZ(z);
}

void Facade::rotate(double x, double y, double z) {
  rotateX(x);
  rotateY(y);
  rotateZ(z);
}

void Facade::moveX(double val) { openGLWidget_->moveX(val); }

void Facade::moveY(double val) { openGLWidget_->moveY(val); }

void Facade::moveZ(double val) { openGLWidget_->moveZ(val); }

void Facade::rotateX(double val) { openGLWidget_->rotateX(val); }

void Facade::rotateY(double val) { openGLWidget_->rotateY(val); }

void Facade::rotateZ(double val) { openGLWidget_->rotateZ(val); }

void Facade::update() { openGLWidget_->update(); }

void Facade::resize(double h, double w) { openGLWidget_->resizeGL(h, w); }

void Facade::saveSettings() { settings_->saveSettings(); }

void Facade::setBackgroundColor(QColor color) {
  settings_->setBackgroundColor(color);
  openGLWidget_->update();
}

QColor Facade::getBackgroundColor() { return settings_->getBackgroundColor(); }

void Facade::setVertexColor(QColor color) {
  settings_->setVertexColor(color);
  openGLWidget_->update();
}

QColor Facade::getVertexColor() { return settings_->getVertexColor(); }

void Facade::setLineColor(QColor color) {
  settings_->setLinesColor(color);
  openGLWidget_->update();
}

QColor Facade::getLineColor() { return settings_->getLinesColor(); }

void Facade::setVertexSize(double val) {
  settings_->setVertexSize(val);
  openGLWidget_->update();
}

void Facade::setLineSize(double val) {
  settings_->setLinesSize(val);
  openGLWidget_->update();
}

void Facade::setVertexType(Settings::TypeVertex type) {
  settings_->setVertexType(type);
  openGLWidget_->update();
}

void Facade::setLineType(Settings::TypeLines type) {
  settings_->setLinesType(type);
  openGLWidget_->update();
}

void Facade::setProjectionType(Settings::Projection type) {
  settings_->setProjection(type);
  openGLWidget_->update();
}

void Facade::setPosition() {
  openGLWidget_->set_position();
  openGLWidget_->update();
}

void Facade::setDefaultSettings() {
  setProjectionType(s21::Settings::Projection::Central);
  resize(640, 480);
  setVertexType(s21::Settings::TypeVertex::None);
  setLineType(s21::Settings::TypeLines::Solid);
  setLineSize(2);
  setLineColor(QColor(255, 255, 255, 0));
  setBackgroundColor(QColor(157, 104, 255, 0));
  setPosition();
}

void Facade::makeScreenshot() {
  QDate curDate;
  QTime curTime;
  QString curTimeStr = curTime.currentTime().toString();
  QString curDateStr = curDate.currentDate().toString();
  QString pathToSave = QFileDialog::getExistingDirectory();
  openGLWidget_->grabFramebuffer().save(
      pathToSave + "/" + curDateStr + curTimeStr + ".BMP", NULL, 100);
  openGLWidget_->grabFramebuffer().save(
      pathToSave + "/" + curDateStr + curTimeStr + ".JPG", NULL, 100);
}

void Facade::makeGif() {
  openGLWidget_->startGif(QFileDialog::getExistingDirectory());
}

} // namespace s21
