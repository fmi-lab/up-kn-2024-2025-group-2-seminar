#include <iostream>

int main() {
  unsigned n;
  std::cin >> n;

  for (unsigned i = 0; i < n/2 + 1; ++i) {
    for (unsigned j = 0; j < n/2 - i; ++j) {
      std::cout << ' ';
    }

    for (unsigned j = 0; j < 2 * i + 1; ++j) {
      std::cout << '*';
    }

    std::cout << '\n';
  }

  for (unsigned i = 0; i < n/2; ++i) {
    std::cout << ' ';
  }
  std::cout << '|' << '\n';

  return 0;
}