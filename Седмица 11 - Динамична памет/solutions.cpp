#include <cstddef>
#include <iostream>

void print(const int arr[], std::size_t size) {
  for (std::size_t i = 0; i < size; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

int* merge(const int* first_begin, 
           const int* first_end, 
           const int* second_begin, 
           const int* second_end) {
  std::size_t size = first_end - first_begin + second_end - second_begin;
  int* result = new int[size];
  std::size_t index = 0;

  while (first_begin != first_end && second_begin != second_end) {
    if (*first_begin < *second_begin) {
      result[index++] = *first_begin++;
    } else {
      result[index++] = *second_begin++;
    }
  }

  while (first_begin != first_end) {
    result[index++] = *first_begin++;    
  }

  while (second_begin != second_end) {
    result[index++] = *second_begin++;    
  }

  return result;
}

void strcpy(char* destination, char* source) {
  if (!source) {
    return;
  }
  
  std::size_t index = 0;
  while (*source) {
    destination[index++] = *source++; 
  }
}

void resize(char*& data, std::size_t size, std::size_t new_size) {
  char* new_data = new char[new_size + 1]{};
  strcpy(new_data, data);

  delete[] data;
  data = new_data;
}

char* filter(const char* str) {
  std::size_t size = 0;
  char* result = nullptr;

  while (*str) {
    if (*str != ' ') {
      resize(result, size, size + 1);
      result[size++] = *str;
    }

    ++str;
  }

  return result;
}

int** allocate_matrix(std::size_t rows, std::size_t columns) {
  int** matrix = new int*[rows];

  for (std::size_t i = 0; i < rows; ++i) {
    matrix[i] = new int[columns];
  }

  return matrix;
}

void deallocate_matrix(int** matrix, std::size_t rows, std::size_t columns) {
  for (std::size_t i = 0; i < rows; ++i) {
    delete[] matrix[i];
  }

  delete[] matrix;
}

void print_matrix(int** matrix, std::size_t rows, std::size_t columns) {
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void copy_matrix(int** destination, int** source, std::size_t rows, std::size_t columns) {
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      destination[i][j] = source[i][j];
    }
  }
}

int** add_products(int** matrix, std::size_t rows, std::size_t columns) {
  int** new_matrix = allocate_matrix(rows + 1, columns);
  copy_matrix(new_matrix, matrix, rows, columns);

  for (std::size_t i = 0; i < columns; ++i) {
    int product = 1;
    for (std::size_t j = 0; j < rows; ++j) {
      product *= new_matrix[j][i];
    }

    new_matrix[rows][i] = product;
  }

  return new_matrix;
}

int main() {
  std::size_t rows, columns;
  std::cin >> rows >> columns;

  int** matrix = allocate_matrix(rows, columns);

  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  int** new_matrix = add_products(matrix, rows, columns);

  print_matrix(new_matrix, rows + 1, columns);

  deallocate_matrix(matrix, rows, columns);
  deallocate_matrix(new_matrix, rows + 1, columns);
  return 0;
}