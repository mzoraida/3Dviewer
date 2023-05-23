#include "geometry.h"

struct VertexData {
  QVector3D position;
};

GeometryEngine::GeometryEngine(s21::Controller *controller)
    : indexBuf_(QOpenGLBuffer::IndexBuffer), ctrl_(controller) {
  initializeOpenGLFunctions();
  arrayBuf_.create();
  indexBuf_.create();
}

GeometryEngine::~GeometryEngine() {
  arrayBuf_.destroy();
  indexBuf_.destroy();
}

void GeometryEngine::ConvertingToQVector3D() {
  if (this->filepath == "") {
    return;
  }
  ctrl_->LoadModel(filepath.toStdString());
  QVector<VertexData> vertices;
  for (size_t i = 0, j = 0; i < ctrl_->GetVertices().size(); i++, j++) {
    VertexData tmp_vert = {QVector3D(ctrl_->GetVertices()[i].GetPosition().X,
                                     ctrl_->GetVertices()[i].GetPosition().Y,
                                     ctrl_->GetVertices()[i].GetPosition().Z)};
    vertices.push_back(tmp_vert);
  }
  QVector<GLuint> indices;
  for (size_t i = 0; i < ctrl_->GetEdges().size(); i++) {
    indices.push_back(ctrl_->GetEdges()[i].GetBegin());
    indices.push_back(ctrl_->GetEdges()[i].GetEnd());
  }
  lines_ = indices.length();

  arrayBuf_.bind();
  arrayBuf_.allocate(vertices.data(), sizeof(VertexData) * vertices.size());
  arrayBuf_.release();

  indexBuf_.bind();
  indexBuf_.allocate(indices.data(), sizeof(GLuint) * indices.size());
  indexBuf_.release();
}

void GeometryEngine::drawLine(QOpenGLShaderProgram *program) {
  arrayBuf_.bind();
  indexBuf_.bind();

  int LineLocation = program->attributeLocation("a_position");
  program->enableAttributeArray(LineLocation);
  program->setAttributeBuffer(LineLocation, GL_FLOAT, 0, 3, sizeof(VertexData));

  glDrawElements(GL_LINES, lines_, GL_UNSIGNED_INT, nullptr);
}

void GeometryEngine::drawDot(QOpenGLShaderProgram *program) {
  arrayBuf_.bind();
  indexBuf_.bind();

  int vertexLocation = program->attributeLocation("a_position");
  program->enableAttributeArray(vertexLocation);
  program->setAttributeBuffer(vertexLocation, GL_FLOAT, 0, 3,
                              sizeof(VertexData));

  glDrawElements(GL_POINTS, lines_, GL_UNSIGNED_INT, nullptr);
}
