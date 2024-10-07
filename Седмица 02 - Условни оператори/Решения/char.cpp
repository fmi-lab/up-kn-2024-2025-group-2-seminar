#include <iostream>

int main() {
  char c;
  std::cin >> c;

  if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
    std::cout << "letter\n";
  } else if (c >= '0' && c <= '9') {
    std::cout << "digit\n";
  } else {
    std::cout << "special\n";
  }
  return 0;
}