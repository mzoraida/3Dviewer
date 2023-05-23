#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QWidget>

namespace s21 {
class Settings {
public:
  static Settings &getInstance();
  void saveSettings();
  void loadSettings();
  enum Projection { Parallel, Central };
  enum TypeLines { Solid, DotedLine };
  enum TypeVertex { None, Round, Square };

  QColor getLinesColor();
  QColor getVertexColor();
  QColor getBackgroundColor();
  int getVertexSize();
  int getLinesSize();
  Projection getProjection();
  TypeLines getLinesType();
  TypeVertex getVertexType();

  void setLinesColor(QColor lines_color);
  void setVertexColor(QColor vertex_color);
  void setBackgroundColor(QColor background_color);
  void setLinesSize(int lines_size);
  void setVertexSize(int vertex_size);
  void setProjection(Projection projection_type);
  void setLinesType(TypeLines lines_type);
  void setVertexType(TypeVertex vertex_type);

  int vertexSize();
  int linesSize();

  QSettings past_settings;

private:
  Settings() = default;
  QColor *lines_color_ = new QColor(255, 255, 0, 0);
  QColor *vertex_color_ = new QColor(200, 210, 0, 0);
  QColor *background_color_ = new QColor(182, 55, 0, 0);
  int vertex_size_ = 0;
  int lines_size_ = 0;
  Projection projection_type_ = Parallel;
  TypeLines lines_type_ = Solid;
  TypeVertex vertex_type_ = None;
};
} // namespace s21

#endif // SETTINGS_H
