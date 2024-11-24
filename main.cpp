#include <iostream>
#include <fstream>
#include "Point.hpp"
#include <vector>
#include <math.h>
#include <string>

void write(const std::vector<Point>& Cloud, std::string Path = "points.txt") {
  std::ofstream File("../" + Path);
  if (File.is_open()) {
    for(const auto& Point : Cloud) {
      File << Point.X << " " << Point.Y << "\n";
    }
  }
  File.close();
}

std::vector<Point> evaluateConvexHull(std::vector<Point> Set) {
  std::vector<Point> Hull;

  Point Start;
  int LowestX = INT_MAX, LowestY = INT_MAX;
  for (const auto& Point : Set) {
    if (Point.X < LowestX || (Point.X == LowestX && Point.Y < LowestY)) {
      LowestX = Point.X;
      LowestY = Point.Y;
      Start = Point;
    }
  }
  Hull.emplace_back(Start);

  Point Current = Start;

  while (true) {
    Point Next = Set[0];
    for (const auto& Candidate : Set) {
      if (Candidate == Current) continue;

      int CrossProduct = (Next.X - Current.X) * (Candidate.Y - Current.Y) -
                         (Next.Y - Current.Y) * (Candidate.X - Current.X);

      if (CrossProduct < 0 || (CrossProduct == 0 &&
                               std::hypot(Candidate.X - Current.X, Candidate.Y - Current.Y) >
                               std::hypot(Next.X - Current.X, Next.Y - Current.Y))) {
        Next = Candidate;
      }
    }

    if (Next == Start) break;

    Hull.emplace_back(Next);
    Current = Next;
  }
  return Hull;
}

int main() {
  std::vector<Point> Cloud = {
    Point(0, 0),
    Point(2, 3),
    Point(4, 1),
    Point(1, 4),
    Point(3, 2),
    Point(5, 0),
  };
  write(Cloud);

  std::vector<Point> Test = evaluateConvexHull(Cloud);
  write(Test, "hull.txt");

}
