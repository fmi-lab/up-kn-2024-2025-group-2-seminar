#include <iostream>

int main() {
  unsigned n;
  std::cin >> n;

  unsigned a = 1, b = 1;
  for (int i = 2; i < n; ++i) {
    unsigned temp = b;
    b = a;
    a = a + temp;
  }

  std::cout << a << '\n';

  return 0;
}