#include <cmath>
#include <iostream>

unsigned to_binary(unsigned n) {
  unsigned result = 0, degree = 0;

  while (n > 0) {
    result += std::pow(10, degree++) * (n % 2);
    n /= 2;
  }

  return result;
}

void cubes(unsigned n) {
  for (unsigned i = 1, cube = 1; cube < n; ++i, cube = std::pow(i, 3)) {
    std::cout << cube << ' ';
  }
  std::cout << '\n';
}

void sequence(unsigned n) {
  for (unsigned i = 1; i <= n; ++i) {
    std::cout << 2 * std::pow(i, 3) + 3 * i << ' ';
  }
  std::cout << '\n';
}

bool is_prime(unsigned n) {
  unsigned i = 2;

  while (i <= std::sqrt(n)) {
    if (n % i == 0) {
      return false;
    }

    ++i;
  }

  return true;
}

void primes(unsigned n) {
  unsigned i = 2;
  while (n > 0) {
    if(is_prime(i)) {
      std::cout << i << ' ';
      --n;
    }

    ++i;
  }

  std::cout << '\n';
}

unsigned factorial(unsigned n) {
  unsigned result = 1;

  for (unsigned i = 1; i <= n; ++i) {
    result *= i;
  }

  return result;
}

double combinations(unsigned n, unsigned k) {
  return static_cast<double>(factorial(n)) / (factorial(k) * factorial(n - k));
}

unsigned divisors_sum(unsigned n) {
  unsigned sum = 1;

  for (unsigned i = 2; i <= std::sqrt(n); ++i) {
    if (n % i == 0) {
      sum += i + n / i;
    }
  }

  return sum;
}

bool is_magic(unsigned n) {
  return divisors_sum(n) == n;
}

unsigned digits_sum(unsigned n) {
  unsigned sum = 0;

  while (n) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}

unsigned biggest_digit_sum(unsigned n) {
  unsigned number, max_sum = 0, max_number;

  for (unsigned i = 0; i < n; ++i) {
    std::cin >> number;

    unsigned sum = digits_sum(number);
    if(sum >= max_sum) {
      max_sum = sum;
      max_number = number;
    }
  }

  return max_number;
}

bool is_digit_amplitude_3(unsigned n) {
  unsigned min = 9, max = 0;

  while (n) {
    min = std::min(min, n % 10);
    max = std::max(max, n % 10);

    n /= 10;
  }

  return max - min == 3;
}

void print_satisfying_predicates(unsigned n) {
  unsigned i = 0;

  while (n > 0) {
    if (is_digit_amplitude_3(i) && is_prime(digits_sum(i))) {
      std::cout << i << ' ';
      --n;
    }

    ++i;
  }

  std::cout << '\n';
}

unsigned gcd(unsigned a, unsigned b) {
  unsigned min = std::min(a, b), max = std::max(a, b);

  while (min != max) {
    unsigned old_min = min;
    min = std::min(max - min, min);
    max = std::max(max - min, old_min);
  }

  return min;
}

int main() {
  std::cout << to_binary(13) << '\n'; // -> 1101
  cubes(900); // -> 1 8 27 64 125 216 343 512 729
  sequence(6); // -> 5 22 63 140 265 450
  primes(5); // -> 2 3 5 7 11
  std::cout << combinations(10, 4) << '\n'; // -> 210
  std::cout << combinations(5, 0) << '\n'; // -> 1
  std::cout << std::boolalpha << is_magic(28) << '\n'; // -> true
  std::cout << std::boolalpha << is_magic(12) << '\n'; // -> false
  print_satisfying_predicates(7); // -> 14 25 30 41 47 52 58
  std::cout << gcd(13, 17) << '\n';
  return 0;
}