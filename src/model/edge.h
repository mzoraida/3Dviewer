#ifndef EDGE_H
#define EDGE_H

#include <iostream>

namespace s21 {
class Edge {
private:
  size_t _begin;
  size_t _end;

public:
  Edge(size_t begin, size_t end);
  ~Edge() = default;
  size_t GetBegin();
  size_t GetEnd();
};
} // namespace s21
#endif // EDGE_H
