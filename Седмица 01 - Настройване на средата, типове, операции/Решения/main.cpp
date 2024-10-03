#include <cmath>
#include <iostream>

int main() {
  std::cout << "Hello world\n";
  std::cout << "Hello world" << std::endl;

  int a, b;
  std::cin >> a >> b;

  // int c = a;
  // a = b;
  // b = c;

  a += b;
  b = a - b;
  a -= b;

  unsigned n;
  std::cin >> n;

  int x = n % 10;
  n /= 10;
  int y = n % 10;
  n /= 10;
  int z = n % 10;
  n /= 10;

  n = x * 1000 + y * 100 + z * 10 + n;

  std::cout << x << ' ' << n << '\n';

  char ch;
  std::cin >> ch;

  ch = ch - 'a' + 'A';

  std::cout << ch << '\n';

  double x1, y1, x2, y2, x3, y3;

  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  double p1 = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

  int year;
  std::cin >> year;

  bool e = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);

  std::cout << std::boolalpha << e << '\n';
  return 0;
}