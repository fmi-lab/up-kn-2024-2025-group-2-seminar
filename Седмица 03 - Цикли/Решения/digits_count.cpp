#include <iostream>

int main() {
  unsigned n;
  std::cin >> n;

  unsigned counter = 0;
  while (n) {
    ++counter;
    n /= 10;
  }

  std::cout << counter << '\n';

  return 0;
}