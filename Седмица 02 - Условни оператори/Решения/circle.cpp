#include <cmath>
#include <iostream>

int main() {
  double x, y, rx, ry, r;

  std::cin >> x >> y >> rx >> ry >> r;

  double distance = std::sqrt((x-rx)*(x-rx) + (y-ry)*(y-ry));

  constexpr double EPSILON = 10e-6; // 0.000001

  if(std::fabs(distance - r) < EPSILON) {
    std::cout << "on\n";
  } else if (distance < r) {
    std::cout << "inside\n";
  } else {
    std::cout << "outside\n";
  }

  return 0;
}