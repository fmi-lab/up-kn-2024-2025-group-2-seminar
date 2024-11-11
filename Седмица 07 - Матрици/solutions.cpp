#include <algorithm>
#include <cstddef>
#include <iostream>

constexpr std::size_t MAX_SIZE{255};

void print(const int matrix[][MAX_SIZE], std::size_t rows, std::size_t columns) {
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

std::size_t min_elements(const int matrix[][MAX_SIZE], std::size_t rows, std::size_t columns, int output[]) {
  for (std::size_t i = 0; i < rows; ++i) {
    int min_element = matrix[i][0];

    for (std::size_t j = 1; j < columns; ++j) {
      min_element = std::min(min_element, matrix[i][j]);
    }

    output[i] = min_element;
  }

  return rows;
}

void print_main_diagonal(const int matrix[][MAX_SIZE], std::size_t n) {
  for (std::size_t i = 0; i < n; ++i) {
    std::cout << matrix[i][i] << ' ';
  }
}

void print_secondary_diagonal(const int matrix[][MAX_SIZE], std::size_t n) {
  for (std::size_t i = 0; i < n; ++i) {
    std::cout << matrix[i][n - 1 - i] << ' ';
  }
}

bool is_triangular(const int matrix[][MAX_SIZE], std::size_t n) {
  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < i; ++j) {
      if (matrix[i][j] != 0) {
        return false;
      }
    }
  }

  return true;
}

void transpose(const int matrix[][MAX_SIZE], std::size_t rows, std::size_t columns, int destination[][MAX_SIZE]) {
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      destination[j][i] = matrix[i][j];
    }
  }
}

void multiply(const int lhs[][MAX_SIZE], 
              std::size_t lhs_rows, 
              std::size_t lhs_columns, 
              const int rhs[][MAX_SIZE],
              std::size_t rhs_columns,
              int destination[][MAX_SIZE]) {
  for (std::size_t i = 0; i < lhs_rows; ++i) {
    for (std::size_t j = 0; j < rhs_columns; ++j) {
      for (std::size_t k = 0; k < lhs_columns; ++k) {
        destination[i][j] += lhs[i][k] * rhs[k][j];
      }
    }
  }
}

void traverse(const int matrix[][MAX_SIZE], std::size_t rows, std::size_t columns) {
  for (int i = 0; i < rows; ++i) {
    int j = 0;
    while (i - j >= 0 && j < columns) {
      std::cout << matrix[i - j][j] << ' ';
      ++j;
    }
  }

  for (std::size_t i = 1; i < columns; ++i) {
    int j = 0;
    while (rows - 1 - j >= 0 && i + j < columns) {
      std::cout << matrix[rows - 1 - j][i + j] << ' ';
      ++j;
    }
  }
}

void traverse_row(const int matrix[][MAX_SIZE], 
                  int start_row, 
                  int start_column, 
                  int steps, 
                  bool direction) {
  for (std::size_t i = 0; i < steps; ++i) {
    int mod = direction ? 1 : -1;
    std::cout << matrix[start_row][start_column + i * mod] << ' ';
  }
}

void traverse_column(const int matrix[][MAX_SIZE], 
                     int start_row, 
                     int start_column, 
                     int steps, 
                     bool direction) {
  for (std::size_t i = 0; i < steps; ++i) {
    std::cout << matrix[direction ? start_row + i : start_row - i][start_column] << ' ';
  }
}

void traverse_spiral(const int matrix[][MAX_SIZE], int rows, int columns) {
  bool direction = true;
  int row_steps = rows - 1;
  int column_steps = columns;

  int start_row = 0, start_column = 0;
  while (row_steps >= 0 && column_steps >= 0) {
    traverse_row(matrix, start_row, start_column, column_steps, direction);
    --column_steps;
    start_row = direction ? start_row + 1 : start_row - 1;
    start_column = direction ? start_column + column_steps : start_column - column_steps;

    traverse_column(matrix, start_row, start_column, row_steps, direction);
    --row_steps;
    
    direction = !direction;

    start_row = direction ? start_row - row_steps : start_row + row_steps;
    start_column = direction ? start_column + 1 : start_column - 1;
  }
}

int main() {
  int matrix[][MAX_SIZE] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };

  traverse_spiral(matrix, 3, 4); // -> 1 2 3 6 9 8 7 4 5
  std::cout << '\n';
  return 0;
}