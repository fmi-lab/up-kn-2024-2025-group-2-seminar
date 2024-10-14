#include <iostream>

int main() {
  unsigned n;
  std::cin >> n;

  unsigned sum = 0;
  for (unsigned i = 1; i <= n; ++i) {
    if (n % i == 0) {
      sum += i;
    }
  }

  std::cout << sum << '\n';

  return 0;
}