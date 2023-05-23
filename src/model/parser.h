#ifndef PARSER_H
#define PARSER_H
#include <fstream>
#include <regex>
#include <string>

#include "figure.h"

namespace s21 {
class Parser {
private:
  std::vector<Vertex> _vertices;
  std::vector<Edge> _edges;
  std::string _line;

public:
  Parser() = default;
  ~Parser() = default;
  void ParseFile(std::string fileName);
  std::vector<Vertex> &GetVertices();
  std::vector<Edge> &GetEdges();

private:
  void ParseVertex();
  void ParseEdge();
  void DetermineType();
};

std::vector<double> split(std::string line);
double convertToNumber(std::string number);

} // namespace s21
#endif // PARSER_H
