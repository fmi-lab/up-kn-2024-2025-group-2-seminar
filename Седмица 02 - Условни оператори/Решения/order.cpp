#include <iostream>

int main() {
  double a, b, c;
  std::cin >> a >> b >> c;

  double max = a > b && a > c 
                  ? a 
                  : b > c 
                    ? b 
                    : c;

  double min = a < b && a < c
                ? a
                : b < c
                  ? b
                  : c;

  double middle = a + b + c - max - min;

  std::cout << min << ' ' << middle << ' ' << max << '\n'; 
  return 0;
}