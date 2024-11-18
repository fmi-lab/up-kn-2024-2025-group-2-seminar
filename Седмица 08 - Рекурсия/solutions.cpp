#include <iostream>

int sum_interval(int begin, int end) {
  if (begin == end) {
    return begin;
  }

  return begin + sum_interval(begin + 1, end);
}

unsigned count_digits(unsigned n) {
  if (n < 10) {
    return 1;
  }

  return 1 + count_digits(n / 10);
}

unsigned gcd_rec(unsigned a, unsigned b) {
  if (a == b) {
    return a;
  }

  if (a > b) {
    return gcd_rec(b, a);
  }

  return gcd_rec(a, b - a);
}

double quick_pow(double x, int n) {
  if (n == 0) {
    return 1;
  }

  if (n % 2 == 0) {
    return quick_pow(x * x, n / 2);
  }

  return x * quick_pow(x, n - 1);
}

void print_reverse(const char str[], std::size_t begin = 0) {
  if (!str[begin]) {
    return;
  }

  print_reverse(str, begin + 1);

  std::cout << str[begin];
}

int find_first_even(const int arr[], std::size_t begin, std::size_t end) {
  if (begin == end) {
    return -1;
  }

  if (arr[begin] % 2 == 0) {
    return begin;
  }

  return find_first_even(arr, begin + 1, end);
}

bool is_sorted(const int arr[], std::size_t begin, std::size_t end) {
  if (begin + 1 == end) {
    return true;
  }

  if (arr[begin] > arr[begin + 1]) {
    return false;
  }

  return is_sorted(arr, begin + 1, end);
}

bool is_palindrome(const int arr[], std::size_t begin, std::size_t end) {
  if (begin + 1 >= end) {
    return true;
  }

  if (arr[begin] != arr[end - 1]) {
    return false;
  }

  return is_palindrome(arr, begin + 1, end - 1);
}

int lower_bound(const int arr[], std::size_t begin, std::size_t end, int element) {
  if (begin >= end) {
    return end;
  }

  int mid = (end + begin) / 2;
  if (arr[mid] < element) {
    return lower_bound(arr, mid + 1, end, element);
  }

  return lower_bound(arr, begin, mid, element);
}

int max_repeated_helper(const int arr[], std::size_t begin, std::size_t end, int current, std::size_t max_size, std::size_t current_size) {
  if (begin == end) {
    return std::max(max_size, current_size);
  }

  if (arr[begin] == current) {
    return max_repeated_helper(arr, begin + 1, end, current, max_size, current_size + 1);
  }

  return max_repeated_helper(arr, begin + 1, end, arr[begin], std::max(current_size, max_size), 1);
}

int max_repeated(const int arr[], std::size_t begin, std::size_t end) {
  return max_repeated_helper(arr, begin + 1, end, arr[begin], 1, 1);
}

int extract_number(const char source[], int begin, int number = 0) {
  if (source[begin] < '0' || source[begin] > '9') {
    return number;
  }

  return extract_number(source, begin + 1, number * 10 + (source[begin] - '0'));
}

std::size_t extract_evens_helper(const char source[], std::size_t begin, int destination[], std::size_t index) {
  if (!source[begin]) {
    return index;
  }

  if (source[begin] >= '0' && source[begin] <= '9') {
    int number = extract_number(source, begin);

    if (number % 2 == 0) {
      destination[index] = number;
      return extract_evens_helper(source, begin + count_digits(number), destination, index + 1);
    }

    return extract_evens_helper(source, begin + count_digits(number), destination, index);
  }

  return extract_evens_helper(source, begin + 1, destination, index);
}


std::size_t extract_evens(const char source[], std::size_t begin, int destination[]) {
  return extract_evens_helper(source, begin, destination, 0);
}

void towers_of_hanoi(unsigned n, char rod1, char rod2, char rod3) {
  if (n == 0) {
    return;
  }

  towers_of_hanoi(n - 1, rod1, rod3, rod2);
  std::cout << "Move disc " << n << " from rod " << rod1 << " to rod " << rod3 << '\n';
  towers_of_hanoi(n - 1, rod2, rod1, rod3);
}

int main() {
  const int arr[]{6, 7, 9, 10, 12, 15};

  std::cout << lower_bound(arr, 0, 6, 12) << '\n'; // -> 4
  std::cout << lower_bound(arr, 0, 6, 13) << '\n'; // -> 5
  std::cout << lower_bound(arr, 0, 6, 16) << '\n'; // -> 6

  return 0;
}