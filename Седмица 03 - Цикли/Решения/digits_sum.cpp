#include <iostream>

int main() {
  unsigned n;
  std::cin >> n;

  unsigned sum = 0;

  while (n) {
    sum += n % 10;
    n /= 10;
  }

  std::cout << sum << '\n';

  return 0;
}