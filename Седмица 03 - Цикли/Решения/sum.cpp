#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  int sum = 0;
  for (int i = a; i <= b; ++i) {
    sum += i;
  }

  std::cout << sum << '\n';

  return 0;
}