#include "edge.h"

namespace s21 {

Edge::Edge(size_t begin, size_t end) : _begin(begin), _end(end) {}

size_t Edge::GetBegin() { return _begin; }

size_t Edge::GetEnd() { return _end; }

} // namespace s21