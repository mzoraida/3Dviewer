#include "settings.h"

s21::Settings &s21::Settings::getInstance() {
  static Settings settings;
  return settings;
}

QColor s21::Settings::getLinesColor() { return *lines_color_; }

QColor s21::Settings::getVertexColor() { return *vertex_color_; }

QColor s21::Settings::getBackgroundColor() { return *background_color_; }

int s21::Settings::getVertexSize() { return vertex_size_; }

int s21::Settings::getLinesSize() { return lines_size_; }

s21::Settings::Projection s21::Settings::getProjection() {
  return projection_type_;
}

s21::Settings::TypeLines s21::Settings::getLinesType() { return lines_type_; }

s21::Settings::TypeVertex s21::Settings::getVertexType() {
  return vertex_type_;
}

void s21::Settings::setProjection(s21::Settings::Projection projection_type) {
  projection_type_ = projection_type;
}

void s21::Settings::setLinesType(s21::Settings::TypeLines lines_type) {
  lines_type_ = lines_type;
}

void s21::Settings::setVertexType(s21::Settings::TypeVertex vertex_type) {
  vertex_type_ = vertex_type;
}

void s21::Settings::setLinesColor(QColor lines_color) {
  *lines_color_ = lines_color;
}

void s21::Settings::setVertexColor(QColor vertex_color) {
  *vertex_color_ = vertex_color;
}

void s21::Settings::setBackgroundColor(QColor background_color) {
  *background_color_ = background_color;
}

void s21::Settings::setLinesSize(int lines_size) { lines_size_ = lines_size; }

void s21::Settings::setVertexSize(int vertex_size) {
  vertex_size_ = vertex_size;
}

void s21::Settings::saveSettings() {
  past_settings.setValue("Projection", projection_type_);

  past_settings.setValue("Lines_type", lines_type_);
  past_settings.setValue("Lines_size", lines_size_);
  past_settings.setValue("Lines_color", *lines_color_);

  past_settings.setValue("Vertex_color", *vertex_color_);
  past_settings.setValue("Vertex_type", vertex_type_);
  past_settings.setValue("Vertex_size", vertex_size_);

  past_settings.setValue("Background_color", *background_color_);
}

void s21::Settings::loadSettings() {
  Projection past_projection =
      (Projection)past_settings
          .value("Projection", s21::Settings::Projection::Central)
          .toInt();
  TypeLines past_lines_type =
      (TypeLines)past_settings
          .value("Lines_type", s21::Settings::TypeLines::Solid)
          .toInt();
  setProjection(past_projection);
  setLinesType(past_lines_type);

  int past_lines_size = past_settings.value("Lines_size", 5).toInt();
  setLinesSize(past_lines_size);

  QColor past_lines_color =
      past_settings.value("Lines_color", QColor(Qt::white)).value<QColor>();
  setLinesColor(past_lines_color);

  QColor past_background_color =
      past_settings.value("Background_color", QColor(Qt::blue)).value<QColor>();
  setBackgroundColor(past_background_color);

  QColor past_vertex_color =
      past_settings.value("Vertex_color", QColor(Qt::black)).value<QColor>();
  setVertexColor(past_vertex_color);

  TypeVertex past_vertex_type =
      (TypeVertex)past_settings
          .value("Vertex_type", s21::Settings::TypeVertex::None)
          .toInt();
  setVertexType(past_vertex_type);

  int past_vertex_size = past_settings.value("Vertex_size", 5).toInt();
  setVertexSize(past_vertex_size);
}
