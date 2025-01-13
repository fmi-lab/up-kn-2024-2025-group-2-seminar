#include <cstddef>
#include <cstdio>
#include <iostream>
#include <variant>

struct Array {
  int* data;
  std::size_t size, capacity;
};

void resize(Array& arr) {
  if (arr.capacity == 0) {
    ++arr.capacity;
  }

  int* new_data = new int[arr.capacity *= 2];
  for (std::size_t i = 0; i < arr.size; ++i) {
    new_data[i] = arr.data[i];
  }

  delete[] arr.data;
  arr.data = new_data;
}

void push_back(Array& arr, int n) {
  if (arr.size == arr.capacity) {
    resize(arr);
  }

  arr.data[arr.size++] = n;
}

void print(Array& arr) {
  for (std::size_t i = 0; i < arr.size; ++i) {
    std::cout << arr.data[i] << ' ';
  }
  std::cout << '\n';
}

void shift(Array& arr, std::size_t index) {
  for (std::size_t i = index; i < arr.size - 1; ++i) {
    std::swap(arr.data[i], arr.data[i + 1]);
  }
}

void remove(Array& arr, int element) {
  for (std::size_t i = 0; i < arr.size; ++i) {
    if (arr.data[i] == element) {
      shift(arr, i);
      --arr.size;
      return;
    }
  }
}

constexpr std::size_t MAX_SIZE = 255;

struct Mark {
  char subject[MAX_SIZE];
  double grade;
};

struct MarkArray {
  Mark* data;
  std::size_t size, capacity;
};

struct Student {
  char name[MAX_SIZE];
  short year;
  MarkArray marks;
};

struct StudentArray {
  Student* data;
  std::size_t size, capacity;
};

struct University {
  char name[MAX_SIZE];
  StudentArray students;
};

void resize(StudentArray& arr) {
  if (arr.capacity == 0) {
    ++arr.capacity;
  }

  Student* new_data = new Student[arr.capacity *= 2];
  for (std::size_t i = 0; i < arr.size; ++i) {
    new_data[i] = arr.data[i];
  }

  delete[] arr.data;
  arr.data = new_data;
}

void push_back(StudentArray& arr, const Student& n) {
  if (arr.size == arr.capacity) {
    resize(arr);
  }

  arr.data[arr.size++] = n;
}

void resize(MarkArray& arr) {
  if (arr.capacity == 0) {
    ++arr.capacity;
  }

  Mark* new_data = new Mark[arr.capacity *= 2];
  for (std::size_t i = 0; i < arr.size; ++i) {
    new_data[i] = arr.data[i];
  }

  delete[] arr.data;
  arr.data = new_data;
}

void push_back(MarkArray& arr, const Mark& n) {
  if (arr.size == arr.capacity) {
    resize(arr);
  }

  arr.data[arr.size++] = n;
}


void add_student(University& university, const Student& student) {
  push_back(university.students, student);
}

int strcmp(const char* str1, const char* str2) {
  while (*str1 && *str2 && *str1 == *str2) {
    ++str1;
    ++str2;
  }

  if (!*str1 && !*str2) {
    return 0;
  }

  return *str1 - *str2;
} 

void add_mark(University& university, const char student_name[MAX_SIZE], const Mark& mark) {
  for (std::size_t i = 0; i < university.students.size; ++i) {
    Student& student = university.students.data[i];
    if (strcmp(student_name, student.name) == 0) {
      push_back(student.marks, mark);
    }
  }
}

StudentArray get_by_year(const University& university, short year) {
  StudentArray result = {nullptr, 0, 0};

  for (std::size_t i = 0; i < university.students.size; ++i) {
    Student student = university.students.data[i];
    if (student.year == year) {
      push_back(result, student);
    }
  }

  return result;
}

void print(const MarkArray& arr) {
  for (std::size_t i = 0; i < arr.size; ++i) {
    Mark mark = arr.data[i];
    std::cout << mark.subject << ' ' << mark.grade << '\n';
  }
  std::cout << '\n';
}

void print(const StudentArray& arr) {
  for (std::size_t i = 0; i < arr.size; ++i) {
    Student student = arr.data[i];
    std::cout << student.name << ' ' << student.year;
    print(student.marks);
    std::cout << '\n';
  }
  std::cout << '\n';
}

void deallocate(University& university) {
  for (std::size_t i = 0; i < university.students.size; ++i) {
    Student student = university.students.data[i];
    delete[] student.marks.data; 
  }

  delete[] university.students.data; 
}

int main() {
  Array arr = {
    .data = nullptr,
    .size = 0,
    .capacity = 0
  };

  push_back(arr, 5);
  push_back(arr, 3);
  push_back(arr, 8);
  push_back(arr, 8);

  remove(arr, 8);
  print(arr);

  delete[] arr.data; 

  std::cout << strcmp("Healo", "Hello") << '\n';

  University university{"SU", {nullptr, 0, 0}};
  add_student(university, {"Ivan", 1, {nullptr, 0, 0}});
  add_student(university, {"Pesho", 2, {nullptr, 0, 0}});
  add_student(university, {"Gosho", 1, {nullptr, 0, 0}});

  add_mark(university, "Ivan", {"algebra", 3});

  StudentArray first_year = get_by_year(university, 1);
  print(first_year);

  deallocate(university);
  delete[] first_year.data;
  return 0;
}