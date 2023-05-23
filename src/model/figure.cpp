#include "figure.h"

namespace s21 {

Figure::Figure(const std::vector<Vertex> &vertices,
               const std::vector<Edge> &edges)
    : _vertices(vertices), _edges(edges) {}

std::vector<Vertex> &Figure::GetVertices() { return _vertices; }

std::vector<Edge> &Figure::GetEdges() { return _edges; }
} // namespace s21
