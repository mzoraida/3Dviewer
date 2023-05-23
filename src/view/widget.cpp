#include "widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent), settings_(&s21::Settings::getInstance()),
      geometries_(nullptr) {
  settings_->loadSettings();
  controller_ = nullptr;
  perspective = true;
  gif = nullptr;
}

Widget::~Widget() {
  makeCurrent();
  delete geometries_;
  doneCurrent();
}

void Widget::set_position() {
  rotateX(0);
  rotateY(0);
  rotateZ(0);
  moveX(0);
  moveY(0);
  moveZ(-7);
  scale(0.4);
}

void Widget::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(0, 0, 0, 1);
  initShaders();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  geometries_ = new GeometryEngine(controller_);
}

void Widget::rotateX(double angleX) {
  QVector3D n = QVector3D(1.0, 0, 0.0);
  rotation = QQuaternion::fromAxisAndAngle(n, angleX - xRot) * rotation;
  update();
  xRot = angleX;
}

void Widget::rotateY(double angleY) {
  QVector3D n = QVector3D(0.0, 1, 0.0);
  rotation = QQuaternion::fromAxisAndAngle(n, angleY - yRot) * rotation;
  update();
  yRot = angleY;
}

void Widget::rotateZ(double angleZ) {
  QVector3D n = QVector3D(0.0, 0.0, 1.0);
  rotation = QQuaternion::fromAxisAndAngle(n, angleZ - zRot) * rotation;
  update();
  zRot = angleZ;
}

void Widget::moveX(double lenX) { xMove = lenX; }

void Widget::moveY(double lenY) { yMove = lenY; }

void Widget::moveZ(double lenZ) { zMove = lenZ; }

void Widget::scale(double zoom) { scaleZ = zoom; }

void Widget::initShaders() {
  if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":vshader.glsl"))
    close();

  if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                       ":fshader.glsl"))
    close();

  if (!program.link())
    close();

  if (!program.bind())
    close();
}

void Widget::initColors() {
  QColor color_lines = settings_->getLinesColor();
  glClearColor(color_lines.redF(), color_lines.greenF(), color_lines.blueF(),
               0);
  program.setUniformValue("color", color_lines);
}

void Widget::initColorsVer() {
  QColor color_vertex = settings_->getVertexColor();
  glClearColor(color_vertex.redF(), color_vertex.greenF(), color_vertex.blueF(),
               0);

  program.setUniformValue("color", color_vertex);
}

void Widget::resizeGL(int w, int h) {
  float aspect = qreal(w) / qreal(h ? h : 1);
  projection.setToIdentity();
  if (settings_->getProjection() == s21::Settings::Projection::Parallel)
    perspective = true;
  else
    perspective = false;
  if (perspective) {
    QRectF orthoRectangle;
    orthoRectangle.setHeight(h);
    orthoRectangle.setWidth(w);
    projection.ortho(-10.0, 10.0, -10.0, 10.0, -50, 50);
  } else {
    projection.perspective(45.0, aspect, 0.5, 15);
  }
}

void Widget::paintGL() {
  QColor backColor = settings_->getBackgroundColor();
  glClearColor(backColor.redF(), backColor.greenF(), backColor.blueF(),
               backColor.alphaF());
  program.setUniformValue("color", backColor);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  line_width = settings_->getLinesSize();
  glLineWidth(line_width);
  vertex_size = settings_->getVertexSize();
  glPointSize(vertex_size);
  initColors();

  QMatrix4x4 matrix;
  matrix.translate(xMove, yMove, zMove);
  matrix.rotate(rotation);
  matrix.scale(scaleZ);

  program.setUniformValue("mvp_matrix", projection * matrix);

  if (settings_->getLinesType() == s21::Settings::TypeLines::DotedLine) {
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 58360);
    geometries_->drawLine(&program);
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_LINE_STIPPLE);
  } else {
    geometries_->drawLine(&program);
  }

  initColorsVer();
  if (settings_->getVertexType() == s21::Settings::TypeVertex::Square) {
    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_POINT_SIZE);
    geometries_->drawDot(&program);
  }
  if (settings_->getVertexType() == s21::Settings::TypeVertex::Round) {
    glDisable(GL_POINT_SIZE);
    glEnable(GL_POINT_SMOOTH);
    geometries_->drawDot(&program);
  }
}

void Widget::timerEvent(QTimerEvent *) { recordGif(); }

void Widget::startGif(const QString path) {
  if (!path.isEmpty()) {
    gifPath = path + "/";
    frameCount = 0;
    gif = new QGifImage();
    gif->setDefaultDelay(10);
    timerGif.start(100, this);
  }
}

void Widget::recordGif() {
  if (frameCount < 50) {
    gif->addFrame(grabFramebuffer());
    frameCount++;
  } else {
    timerGif.stop();
    gif->save(gifPath + QDate::currentDate().toString() +
              QTime::currentTime().toString() + ".gif");
  }
}
