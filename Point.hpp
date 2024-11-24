#ifndef POINT_HPP
#define POINT_HPP

class Point {
public:
  int X;
  int Y;

  Point(int XParam, int YParam) : X(XParam), Y(YParam) {};

  Point() {};

  bool operator==(const Point& Other) const {
    return X == Other.X && Y == Other.Y;
  }
};



#endif //POINT_HPP
