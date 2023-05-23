#ifndef FIGURE_H
#define FIGURE_H
#include <vector>

#include "edge.h"
#include "vertex.h"
namespace s21 {
class Figure {
private:
  std::vector<Vertex> _vertices;
  std::vector<Edge> _edges;

public:
  Figure(const std::vector<Vertex> &vertices, const std::vector<Edge> &edges);
  ~Figure() = default;
  std::vector<Vertex> &GetVertices();
  std::vector<Edge> &GetEdges();
};
} // namespace s21
#endif // FIGURE_H
