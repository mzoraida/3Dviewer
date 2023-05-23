#include "vertex.h"

namespace s21 {

Vertex::Vertex(const Point &position) : _position(position) {}

Point Vertex::GetPosition() { return _position; }

void Vertex::SetPosition(const Point &position) { _position = position; }

} // namespace s21
