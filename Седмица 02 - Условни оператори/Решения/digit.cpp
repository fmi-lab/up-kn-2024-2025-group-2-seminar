#include <iostream>

int main() {
  int n, x;
  std::cin >> n >> x;

  if (n < 1000 || n > 9999) {
    std::cout << "invalid number\n";

    return 1;
  }

  unsigned short last_digit = n % 10;
  n /= 10;
  unsigned short second_digit = n % 10;
  n /= 10;
  unsigned short third_digit = n % 10;
  unsigned short first_digit = n;

  std::cout << std::boolalpha
            << (last_digit == x || second_digit == x || third_digit == x ||
                first_digit == x)
            << '\n';
  return 0;
}