#include <algorithm>
#include <iostream>
#include <limits>

int main() {
  std::size_t n;
  std::cin >> n;

  int max_number = std::numeric_limits<int>().min();
  for (std::size_t i = 0; i < n; ++i) {
    int a;
    std::cin >> a;

    max_number = std::max(max_number, a);
  }

  std::cout << max_number << '\n';

  return 0;
}