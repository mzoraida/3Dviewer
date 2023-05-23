#include "controller.h"

void s21::Controller::LoadModel(const std::string &fileName) {
  parser_->ParseFile(fileName);
}

std::vector<s21::Vertex> &s21::Controller::GetVertices() {
  return parser_->GetVertices();
}

std::vector<s21::Edge> &s21::Controller::GetEdges() {
  return parser_->GetEdges();
}
