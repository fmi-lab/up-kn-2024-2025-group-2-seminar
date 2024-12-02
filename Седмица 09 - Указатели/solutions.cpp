#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>

void print(const int* begin, const int* end) {
  while (begin != end) {
    std::cout << *begin++ << ' ';
  }
  std::cout << '\n';
}

const int* upper_bound(const int* begin, const int* end, int element) {
  while (begin < end) {
    const int* mid = begin + (end - begin) / 2;

    if (element <= *mid) {
      end = mid;
    } else {
      begin = mid + 1;
    }
  }

  return *begin >= element ? begin : nullptr;
}

bool equal(const int* first_begin, const int* first_end, const int* second_begin, const int* second_end) {
  while (first_begin != first_end && 
         second_begin != second_end && 
         *first_begin == *second_begin) {
    ++first_begin;
    ++second_begin;
  }

  return first_begin == first_end && second_begin == second_end;
}

void replace(int* begin, int* end, int old_value, int new_value) {
  while (begin != end) {
    if (*begin == old_value) {
      *begin = new_value;
    }

    ++begin;
  }
}

void reverse(int* begin, int* end) {
  while (begin < end) {
    std::iter_swap(begin, end - 1);
    ++begin;
    --end;
  }
}

void rotate(int* begin, int* mid, int* end) {
  reverse(begin, mid);
  reverse(mid, end);
  reverse(begin, end);
}

const int* search(const int* first_begin, const int* first_end, const int* second_begin, const int* second_end) {
  std::size_t second_size = second_end - second_begin;

  while (first_begin != first_end) {
    if (equal(first_begin, first_begin + second_size, second_begin, second_end)) {
      return first_begin;
    }

    ++first_begin;
  }

  return nullptr;
}

bool ends_with(const int* first_begin, const int* first_end, const int* second_begin, const int* second_end) {
  std::size_t second_size = second_end - second_begin;

  return first_begin <= first_end - second_size && 
         equal(first_end - second_size, first_end, second_begin, second_end);
}

const int* find_end(const int* first_begin, const int* first_end, const int* second_begin, const int* second_end) {
  const int *occurence = search(first_begin, first_end, second_begin, second_end);
  const int* previous_occurence = occurence;

  while (occurence) {
    previous_occurence = occurence;
    occurence = search(occurence + 1, first_end, second_begin, second_end);
  }

  return previous_occurence;
}

int* unique(int* begin, int* end) {
  int previous = *begin;
  ++begin;
  while (begin != end) {
    if (previous == *begin) {
      rotate(begin, begin + 1, end);
      --end;
    } else {
      previous = *begin;
      ++begin;
    }
  }

  return end;
}

int main() {
  int arr[]{1, 2, 1, 1, 3, 3, 3, 4, 4, 5, 4};
  int* end = unique(std::begin(arr), std::end(arr));
  print(std::cbegin(arr), end); // -> 1 2 1 3 4 5 4
  return 0;
}