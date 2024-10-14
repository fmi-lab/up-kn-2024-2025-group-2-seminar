#include <iostream>

int main() {
  double x;
  int n;
  std::cin >> x >> n;

  if(n < 0) {
    x = 1/x;
    n = -n;
  }

  double result = 1;
  while (n != 0) {
    if(n % 2) {
      result *= x;
      --n;
    } else {
      x *= x;
      n /= 2;
    }
  }

  std::cout << result << '\n';

  return 0;
}