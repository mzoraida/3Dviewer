#include "parser.h"

// #include <QDebug>

namespace s21 {

std::vector<Vertex> &Parser::GetVertices() { return _vertices; }
std::vector<Edge> &Parser::GetEdges() { return _edges; }

void Parser::ParseVertex() {
  std::vector<double> numbers = split(_line);
  if (numbers.size() != 3)
    throw std::invalid_argument("Wrong file structure!");
  _vertices.push_back(Vertex(Point(numbers[0], numbers[1], numbers[2])));
}

void Parser::ParseEdge() {
  std::vector<double> numbers = split(_line);
  for (size_t i = 0; i < numbers.size() - 1; i++) {
    _edges.push_back(Edge((numbers[i] - 1), (numbers[i + 1] - 1)));
  }
  _edges.push_back(Edge((numbers[0] - 1), (numbers[numbers.size() - 1] - 1)));
}

void Parser::ParseFile(std::string fileName) {
  if (!_vertices.empty())
    _vertices.clear();
  if (!_edges.empty())
    _edges.clear();
  std::ifstream fout(fileName);
  if (!fout.is_open())
    throw std::invalid_argument("Wrong file name!");
  while (fout) {
    std::string line;
    getline(fout, line);
    _line = line;
    DetermineType();
  }
  fout.close();
}

void Parser::DetermineType() {
  if (_line.length() > 2 && _line[1] == ' ') {
    if (_line[0] == 'v') {
      ParseVertex();
    } else if (_line[0] == 'f') {
      ParseEdge();
    }
  }
}

std::vector<double> split(std::string line) {
  std::vector<double> valixan;
  std::string number;
  size_t len = line.size();
  for (size_t i = 2; i < len; i++) {
    double value;
    if (line[i] == ' ') {
      value = convertToNumber(number);
      valixan.push_back(value);
      number.clear();
    } else {
      number.push_back(line[i]);
    }
    if (i == len - 1) {
      value = convertToNumber(number);
      valixan.push_back(value);
      number.clear();
    }
  }
  return valixan;
}

double convertToNumber(std::string number) {
  std::string::size_type sz;
  double num = std::stod(number, &sz);
  return num;
}

} // namespace s21
