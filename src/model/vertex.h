#ifndef VERTEX_H
#define VERTEX_H

// #include "temp.h"
namespace s21 {
struct Point {
  double X;
  double Y;
  double Z;
  Point(double x, double y, double z) : X(x), Y(y), Z(z) {}
};

class Vertex {
public:
  explicit Vertex(const Point &position);
  ~Vertex() = default;

private:
  Point _position;

public:
  Point GetPosition();
  void SetPosition(const Point &position);
};
} // namespace s21
#endif // VERTEX_H
