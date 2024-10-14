#include <cmath>
#include <iostream>

int main() {
  unsigned n;
  std::cin >> n;

  if(n == 1 || n == 2) {
    std::cout << std::boolalpha << false << '\n';
    return 0;
  }

  unsigned current = 2;
  while (current <= std::sqrt(n) && n % current != 0) {
    ++current;
  }

  std::cout << std::boolalpha << (n % current != 0) << '\n';

  return 0;
}