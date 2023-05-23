#include "mainwindow.h"

#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);
  ui->openGLWidget->setController(controller);
  facade_ = new s21::Facade(ui->openGLWidget);
}

MainWindow::~MainWindow() {
  facade_->saveSettings();
  delete ui;
  delete facade_;
}

void MainWindow::on_openfile_clicked() {
  QString str =
      QFileDialog::getOpenFileName(this, "open file", "/src/", "*.obj");
  if (!str.isEmpty()) {
    facade_->openFile(str);
    QString vertexes = QString::number(controller_->GetVertices().size());
    QString facets = QString::number(controller_->GetEdges().size());
    QList<QString> name = str.split('/');
    ui->filename->setText(name.last());
    ui->vertexes->setText("Vertexes: " + vertexes);
    ui->facets->setText("Facets: " + facets);
  }
}

void MainWindow::on_color_back_clicked() {
  QColor ColorBack =
      QColorDialog::getColor(facade_->getBackgroundColor(), this);
  facade_->setBackgroundColor(ColorBack);
}

void MainWindow::on_color_lines_clicked() {
  QColor LineColor = QColorDialog::getColor(facade_->getLineColor(), this);
  facade_->setLineColor(LineColor);
}

void MainWindow::on_color_vertexes_clicked() {
  QColor VerColor = QColorDialog::getColor(facade_->getVertexColor(), this);
  facade_->setVertexColor(VerColor);
}

void MainWindow::on_apply_line_clicked() {
  facade_->applyLineWidth(ui->spinBox_linethickness->value());
  facade_->setLineSize(ui->spinBox_linethickness->value());
}

void MainWindow::on_apply_vertexes_clicked() {
  facade_->applyVertexWidth(ui->spinBox_size_vertexes->value());
  facade_->setVertexSize(ui->spinBox_size_vertexes->value());
}

void MainWindow::on_scale_clicked() {
  facade_->scale((double)ui->scale_2->value());
  facade_->update();
}

void MainWindow::on_move_clicked() {
  facade_->move((double)ui->move_x_2->value(), (double)ui->move_y_2->value(),
                (double)ui->move_z_2->value());
  ui->move_x_Slider->setValue((double)ui->move_x_2->value() * 100);
  ui->move_y_Slider->setValue((double)ui->move_y_2->value() * 100);
  ui->move_z_Slider->setValue((double)ui->move_z_2->value() * 100);
  facade_->update();
}

void MainWindow::on_rotation_clicked() {
  facade_->rotate((double)ui->rotate_x->value(), (double)ui->rotate_y->value(),
                  (double)ui->rotate_z->value());
  ui->rotation_x_Slider->setValue((double)ui->rotate_x->value());
  ui->rotation_y_Slider->setValue((double)ui->rotate_y->value());
  ui->rotation_z_Slider->setValue((double)ui->rotate_z->value());
  facade_->update();
}

void MainWindow::on_scale_Slider_valueChanged(int value) {
  ui->scale_2->setValue((double)value / 100);
  facade_->scale((double)value / 100);
  facade_->update();
}

void MainWindow::on_move_x_Slider_valueChanged(int value) {
  ui->move_x_2->setValue((double)value / 100);
  facade_->moveX((double)value / 100);
  facade_->update();
}

void MainWindow::on_move_y_Slider_valueChanged(int value) {
  ui->move_y_2->setValue((double)value / 100);
  facade_->moveY((double)value / 100);
  facade_->update();
}
void MainWindow::on_move_z_Slider_valueChanged(int value) {
  ui->move_z_2->setValue((double)value / 100);
  facade_->moveZ((double)value / 100);
  facade_->update();
}

void MainWindow::on_rotation_x_Slider_valueChanged(int value) {
  ui->rotate_x->setValue((double)value);
  facade_->rotateX((double)value);
  facade_->update();
}

void MainWindow::on_rotation_y_Slider_valueChanged(int value) {
  ui->rotate_y->setValue((double)value);
  facade_->rotateY((double)value);
  facade_->update();
}

void MainWindow::on_rotation_z_Slider_valueChanged(int value) {
  ui->rotate_z->setValue((double)value);
  facade_->rotateZ((double)value);
  facade_->update();
}

void MainWindow::on_apply_vertex_type_clicked() {
  if (ui->no_vertex->isChecked())
    facade_->setVertexType(s21::Settings::TypeVertex::None);
  if (ui->round_vertex->isChecked())
    facade_->setVertexType(s21::Settings::TypeVertex::Round);
  if (ui->square_vertex->isChecked())
    facade_->setVertexType(s21::Settings::TypeVertex::Square);
}

void MainWindow::on_apply_vid_line_clicked() {
  if (ui->dotted_line->isChecked())
    facade_->setLineType(s21::Settings::TypeLines::DotedLine);
  if (ui->continuous->isChecked())
    facade_->setLineType(s21::Settings::TypeLines::Solid);
}

void MainWindow::on_apply_projection_clicked() {
  if (ui->centre->isChecked())
    facade_->setProjectionType(s21::Settings::Projection::Central);
  if (ui->parallel->isChecked())
    facade_->setProjectionType(s21::Settings::Projection::Parallel);
  facade_->resize(640, 480);
}

void MainWindow::on_default_2_clicked() {
  ui->rotation_x_Slider->setValue(0);
  ui->rotation_y_Slider->setValue(0);
  ui->rotation_z_Slider->setValue(0);
  ui->move_x_Slider->setValue(0);
  ui->move_y_Slider->setValue(0);
  ui->move_z_Slider->setValue(-700);
  ui->scale_Slider->setValue(40);
  facade_->setDefaultSettings();
}

void MainWindow::on_screenshot_clicked() { facade_->makeScreenshot(); }

void MainWindow::on_GIF_clicked() { facade_->makeGif(); }
} // namespace s21
