#include <cstddef>
#include <iostream>

constexpr std::size_t MAX_SIZE = 255;

bool candidates_goal(unsigned candidates[], std::size_t n, unsigned target) {
  if (target == 0) {
    return true;
  }

  for (std::size_t i = 0; i < n; ++i) {
    if (target >= candidates[i] && 
        candidates_goal(candidates, n, target - candidates[i])) {
      return true;
    }
  }

  return false;
}

bool is_valid(std::size_t height, std::size_t width, int x, int y) {
  return x >= 0 && x < height && y >= 0 && y < width;
}

void flood_fill(int canvas[][255], 
                std::size_t height, 
                std::size_t width, 
                int x, int y, int color) {
  if (canvas[x][y] == color) {
    return;
  }

  int previous_color = canvas[x][y];
  canvas[x][y] = color;

  for (int i = -1; i <= 1; i += 2) {
    if (is_valid(height, width, x + i, y) && canvas[x + i][y] == previous_color) {
      flood_fill(canvas, height, width, x + i, y, color);
    }

    if (is_valid(height, width, x, y + i) && canvas[x][y + i] == previous_color) {
      flood_fill(canvas, height, width, x, y + i, color);
    }
  }

  // if (is_valid(height, width, x + 1, y) && canvas[x + 1][y] == previous_color) {
  //   flood_fill(canvas, height, width, x + 1, y, color);
  // }

  // if (is_valid(height, width, x - 1, y) && canvas[x - 1][y] == previous_color) {
  //   flood_fill(canvas, height, width, x - 1, y, color);
  // }

  // if (is_valid(height, width, x, y + 1) && canvas[x][y + 1] == previous_color) {
  //   flood_fill(canvas, height, width, x, y + 1, color);
  // }

  // if (is_valid(height, width, x, y - 1) && canvas[x][y - 1] == previous_color) {
  //   flood_fill(canvas, height, width, x, y - 1, color);
  // }
}

bool winning_sequence(int sequence[], std::size_t length, int previous, bool removed[], std::size_t left) {
  if (left == 0) {
    return true;
  }

  for (std::size_t i = 0; i < length; ++i) {
    int current = sequence[i];
    if (!removed[i] && (current % previous == 0 || previous % current == 0)) {
      removed[i] = true;

      if(winning_sequence(sequence, length, current, removed, left - 1)) {
        return true;
      }

      removed[i] = false;
    }
  }

  return false;
}

bool winning_sequence(int sequence[], std::size_t length) {
  for (std::size_t i = 0; i < length; ++i) {
    bool removed[MAX_SIZE]{};

    removed[i] = true;
    if (winning_sequence(sequence, length, sequence[i], removed, length - 1)) {
      return true;
    }

    removed[i] = false;
  }

  return false;
}

void print_matrix(const int matrix[][255], std::size_t height, std::size_t width) {
  for (std::size_t i = 0; i < height; ++i) {
    for (std::size_t j = 0; j < width; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

bool find_word(char matrix[][MAX_SIZE], 
               std::size_t rows,
               std::size_t cols,
               char word[], 
               bool visited[][MAX_SIZE],
               int x, int y) {
  if (*word == '\0') {
    return true;
  }

  if (*word != matrix[x][y]) {
    return false;
  }

  visited[x][y] = true;

  if(is_valid(rows, cols, x + 1, y) && 
    !visited[x + 1][y] && 
    find_word(matrix, rows, cols, word + 1, visited, x + 1, y)) {
    return true;
  }

  if(is_valid(rows, cols, x - 1, y) && 
    !visited[x - 1][y] && 
    find_word(matrix, rows, cols, word + 1, visited, x - 1, y)) {
    return true;
  }

  if(is_valid(rows, cols, x, y + 1) && 
    !visited[x][y + 1] && 
    find_word(matrix, rows, cols, word + 1, visited, x, y + 1)) {
    return true;
  }

  if(is_valid(rows, cols, x, y - 1) && 
    !visited[x][y - 1] && 
    find_word(matrix, rows, cols, word + 1, visited, x, y - 1)) {
    return true;
  }

  visited[x][y] = false;

  return false;
}

unsigned find_words_in_crossword(char matrix[][255], std::size_t rows, std::size_t cols, char words[][255], std::size_t n) {
  unsigned counter = 0;

  for (std::size_t i = 0; i < n; ++i) {
    bool visited[MAX_SIZE][MAX_SIZE]{};

    for (std::size_t j = 0; j < rows; ++j) {
      for (std::size_t k = 0; k < cols; ++k) {
        if (find_word(matrix, rows, cols, words[i], visited, j, k)) {
          ++counter;
        }
      }
    }
  }

  return counter;
}

int main() {
  char matrix[][255] = {{'c', 'a', 't'},
                        {'w', 'h', 'o'},
                        {'w', 'i', 'n'}};
  char words[][255] = {"cat", "hello", "what", "caca"};
  std::cout << find_words_in_crossword(matrix, 3, 3, words, 4) << '\n'; // -> 2
  // -> cat, what

  return 0;
}