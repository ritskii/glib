#include <iostream>
#include <fstream>
#include "Point.hpp"

int main() {
  Point P(1, 2);





  std::ofstream File("../points.txt");
  if (File.is_open()) {
    File << P.X << " " << P.Y << "\n";
    File.close();
  }
}
