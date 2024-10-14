#include <iostream>

int main() {
  unsigned n;
  std::cin >> n;

  unsigned factorial = 1;

  for (int i = n; i > 0; i -= 2) {
    factorial *= i;
  }

  std::cout << factorial << '\n';

  return 0;
}