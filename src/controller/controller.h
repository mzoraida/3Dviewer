#ifndef SRC_CONTROLLER_CONTROLLER_H
#define SRC_CONTROLLER_CONTROLLER_H

#include "../model/parser.h"
namespace s21 {

class Controller {
public:
  explicit Controller(Parser *parser) : parser_(parser){};
  ~Controller() = default;
  void LoadModel(const std::string &fileName);
  std::vector<Vertex> &GetVertices();
  std::vector<Edge> &GetEdges();

private:
  Parser *parser_;
};
} // namespace s21

#endif // SRC_CONTROLLER_CONTROLLER_H
