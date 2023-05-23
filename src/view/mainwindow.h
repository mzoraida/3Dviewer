#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../controller/controller.h"
#include "facade.h"

namespace Ui {
class MainWindow;
}
namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(s21::Controller *controller, QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_openfile_clicked();
  void on_color_back_clicked();
  void on_color_lines_clicked();
  void on_color_vertexes_clicked();
  void on_apply_line_clicked();
  void on_apply_vertexes_clicked();
  void on_scale_clicked();
  void on_move_clicked();
  void on_rotation_clicked();
  void on_scale_Slider_valueChanged(int value);
  void on_move_x_Slider_valueChanged(int value);
  void on_move_y_Slider_valueChanged(int value);
  void on_move_z_Slider_valueChanged(int value);
  void on_rotation_x_Slider_valueChanged(int value);
  void on_rotation_y_Slider_valueChanged(int value);
  void on_rotation_z_Slider_valueChanged(int value);
  void on_apply_vertex_type_clicked();
  void on_apply_vid_line_clicked();
  void on_apply_projection_clicked();
  void on_default_2_clicked();
  void on_screenshot_clicked();
  void on_GIF_clicked();

private:
  Ui::MainWindow *ui;
  s21::Controller *controller_;
  s21::Facade *facade_;
};
} // namespace s21

#endif // MAINWINDOW_H
