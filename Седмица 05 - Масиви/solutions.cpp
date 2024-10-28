#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <optional>

constexpr std::size_t MAX_SIZE = 255;

int sum(const int arr[], std::size_t size) {
  int result = 0;

  for (std::size_t i = 0; i < size; ++i) {
    result += arr[i];
  }

  return result;
}

void print(const int arr[], std::size_t n) {
  for (std::size_t i = 0; i < n; i++)
  {
    std::cout << arr[i] << ' ';   
  }
  std::cout << '\n';
}

int find(const int arr[], std::size_t size, int element) {
  for (std::size_t i = 0; i < size; ++i) {
    if (arr[i] == element) {
      return i;
    }
  }

  return -1;
}

bool is_set(const int arr[], std::size_t size) {
  for (std::size_t i = 0; i < size - 1; ++i) {
    if (arr[i + 1] <= arr[i]) {
      return false;
    }
  }

  return true;
}

void reverse(int arr[], std::size_t size) {
  for (std::size_t i = 0; i < size / 2; ++i) {
    std::swap(arr[i], arr[size - 1 - i]);
  }
}

std::size_t filter(int destination[], const int source[], std::size_t size) {
  std::size_t destination_size = 0;

  for (std::size_t i = 0; i < size; ++i) {
    if (source[i] > 30 && source[i] % 7 == 0) {
      destination[destination_size++] = source[i];
    }
  }

  return destination_size;
}

int most_common(const int arr[], std::size_t size) {
  int number, occurences = 0;

  for (std::size_t i = 0; i < size; ++i) {
    int current_occurences = 0;

    for (std::size_t j = i; j < size; ++j) {
      if (arr[j] == arr[i]) {
        ++current_occurences;
      }
    }

    if (current_occurences > occurences) {
      number = arr[i];
      occurences = current_occurences;
    }
  }

  return number;
}

std::size_t longest_subarray_size(const int arr[], std::size_t size) {
  std::size_t max_size = 1, current_size = 1;
  int previous = arr[0];

  for (std::size_t i = 1; i < size; ++i) {
    if (previous == arr[i]) {
      ++current_size;
    } else {
      max_size = std::max(current_size, max_size);
      current_size = 1;
      previous = arr[i];
    }
  }

  max_size = std::max(current_size, max_size);

  return max_size;
}

std::size_t find_min_index(const int arr[], std::size_t begin, std::size_t end) {
  int min_element = std::numeric_limits<int>::max(), min_index = -1;

  for (std::size_t i = begin; i < end; ++i) {
    if (arr[i] < min_element) {
      min_element = arr[i];
      min_index = i;
    }
  }

  return min_index;
}

void selection_sort(int arr[], std::size_t size) {
  for (std::size_t i = 0; i < size - 1; ++i) {
    std::size_t min_index = find_min_index(arr, i, size);

    std::swap(arr[i], arr[min_index]);
  }
}

void bubble_sort(int arr[], std::size_t size) {
  for (std::size_t i = 0; i < size; ++i) {
    for (std::size_t j = 0; j < size - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int arr[]{10, 5, 8, 3, 13, 7};
  bubble_sort(arr, 6);
  print(arr, 6); // -> 3 5 7 8 10 13

  return 0;
}