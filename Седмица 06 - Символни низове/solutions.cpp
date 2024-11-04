#include <algorithm>
#include <cstddef>
#include <iostream>

constexpr std::size_t MAX_SIZE = 255;

void to_upper_case(char str[]) {
  std::size_t i = 0;
  while (str[i]) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 'a' - 'A';
    }

    ++i;
  }
}

bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

int to_digit(char c) {
  return c - '0';
}

int atoi(const char str[]) {
  bool negative = str[0] == '-';
  int result = 0;

  std::size_t i = negative;
  while (str[i] && is_digit(str[i])) {
    result = result * 10 + to_digit(str[i]);
    ++i;
  }

  return negative ? -result : result;
}

bool is_letter(char c) {
  return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

std::size_t find_longest_word(const char str[]) {
  std::size_t max_index = 0, max_length = 0, current_length = 0, i = 0;

  while (str[i]) {
    if (!is_letter(str[i])) {
      if (current_length > max_length) {
        max_length = current_length;
        max_index = i - current_length;
      }

      current_length = 0;
    } else {
      ++current_length;
    }

    ++i;
  }

  if (current_length > max_length) {
    max_length = current_length;
    max_index = i - current_length;
  }

  return max_index;
}

void trim(char str[]) {
  std::size_t start, end, i = 0;

  while (str[i] == ' ') {
    ++i;
  }
  start = i;

  while (str[i]) {
    if (str[i] != ' ') {
      end = i;
    }

    ++i;
  }

  for (std::size_t index = start; index <= end; ++index) {
    str[index - start] = str[index];
  }

  str[end - start + 1] = '\0';
}

void decode(char destination[], const char source[]) {
  std::size_t source_index = 0, destination_index = 0;
  int count = 0;

  while (source[source_index]) {
    if (is_digit(source[source_index])) {
      count = count * 10 + to_digit(source[source_index]);
    } else {
      for (std::size_t i = 0; i < std::max(count, 1); ++i) {
        destination[destination_index++] = source[source_index];
      }

      count = 0;
    }

    ++source_index;
  }

  destination[destination_index] = '\0';
}

bool begins_with(const char str[], std::size_t start, const char word[]) {
  std::size_t word_start = 0;

  while (str[start] && word[word_start] && str[start] == word[word_start]) {
    ++start;
    ++word_start;
  }

  return word[word_start] == '\0';
}

std::size_t length(const char str[]) {
  std::size_t i = 0;

  while (str[i]) {
    ++i;
  }

  return i;
}

int find_word(const char str[], const char word[]) {
  std::size_t i = 0;

  while (str[i]) {
    if (begins_with(str, i, word) && !is_letter(str[i + length(word)])) {
      return i;
    }

    ++i;
  }

  return -1;
}

void remove_word(char str[], const char word[]) {
  int occurence_index = find_word(str, word);
  std::size_t word_length = length(word);

  while (occurence_index != -1) {
    std::size_t index = occurence_index + word_length;
    while (str[index]) {
      str[index - word_length - 1] = str[index];
      ++index;
    }
    str[index - word_length - 1] = '\0';

    occurence_index = find_word(str, word);
  }
}

int main() {
  char str[] = "I am the best programmer ever programmer";
  remove_word(str, "programmer");
  std::cout << str << '\n'; // -> I am the best ever
  return 0;
}