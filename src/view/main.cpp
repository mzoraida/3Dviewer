#include <QApplication>

#include "../controller/controller.h"
#include "mainwindow.h"
#include "widget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Parser figure;
  s21::Controller fig(&figure);
  s21::MainWindow w(&fig);
  w.show();
  return a.exec();
}
