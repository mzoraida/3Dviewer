#ifndef TEST_H
#define TEST_H

#include "../model/parser.h"
#include "gtest/gtest.h"
using namespace testing;
using namespace s21;

TEST(parser_tests, parsVertices) {
  Parser TestParser;
  TestParser.ParseFile("cub.obj");
  std::vector<Edge> Edges;
  std::vector<Vertex> Vertices;

  Vertices.push_back(Vertex(Point(0.000000, 1.000000, 1.000000)));
  Vertices.push_back(Vertex(Point(0.000000, 0.000000, 1.000000)));
  Vertices.push_back(Vertex(Point(1.000000, 0.000000, 1.000000)));
  Vertices.push_back(Vertex(Point(1.000000, 1.000000, 1.000000)));
  Vertices.push_back(Vertex(Point(0.000000, 1.000000, 0.000000)));
  Vertices.push_back(Vertex(Point(0.000000, 0.000000, 0.000000)));
  Vertices.push_back(Vertex(Point(1.000000, 0.000000, 0.000000)));
  Vertices.push_back(Vertex(Point(1.000000, 1.000000, 0.000000)));

  for (int i = 0; i < 8; i++) {
    EXPECT_EQ(Vertices[i].GetPosition().X,
              TestParser.GetVertices()[i].GetPosition().X);
    EXPECT_EQ(Vertices[i].GetPosition().Y,
              TestParser.GetVertices()[i].GetPosition().Y);
    EXPECT_EQ(Vertices[i].GetPosition().Z,
              TestParser.GetVertices()[i].GetPosition().Z);
  }
}

TEST(parser_tests, parsEdges) {
  Parser TestParser;
  TestParser.ParseFile("cub.obj");
  std::vector<Edge> Edges;
  std::vector<Vertex> Vertices;

  Edges.push_back(Edge(0, 1));
  Edges.push_back(Edge(1, 2));
  Edges.push_back(Edge(2, 3));
  Edges.push_back(Edge(0, 3));

  Edges.push_back(Edge(7, 6));
  Edges.push_back(Edge(6, 5));
  Edges.push_back(Edge(5, 4));
  Edges.push_back(Edge(7, 4));

  for (int i = 0; i < 8; i++) {
    EXPECT_EQ(Edges[i].GetBegin(), TestParser.GetEdges()[i].GetBegin());
    EXPECT_EQ(Edges[i].GetEnd(), TestParser.GetEdges()[i].GetEnd());
  }
}

#endif  // TEST_H
