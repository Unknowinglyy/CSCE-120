#include <iostream>

class DynamicArray {

public:
  DynamicArray() : m_pValues(nullptr), m_cap(0), m_size(0){};

  DynamicArray(int cap) : m_pValues(nullptr), m_cap(cap), m_size(0) {
    m_pValues = new int[cap];
    for (int i = 0; i < cap; i++) {
      m_pValues[i] = i + 1;
    }
    m_size = cap;
  };

  DynamicArray(const DynamicArray &other)
      : m_pValues(nullptr), m_cap(other.m_cap), m_size(other.m_size) {
    m_pValues = new int[other.m_cap];
    for (int idx = 0; idx < other.m_size; idx++) {
      m_pValues[idx] = other.m_pValues[idx];
    }
  }

  DynamicArray &operator=(const DynamicArray &rhs) {
    if (this == &rhs) {
      return (*this);
    }

    // Clean it up
    if (m_pValues) {
      // if (m_pValues != nullptr) {
      delete[] m_pValues;

      m_pValues = nullptr;
    }
    m_size = 0;
    m_cap = 0;

    m_pValues = new int[rhs.m_cap];
    for (int idx = 0; idx < rhs.m_size; idx++) {
      m_pValues[idx] = rhs.m_pValues[idx];
    }
    m_size = rhs.m_size;
    m_cap = rhs.m_cap;
    return (*this);
  }

  void Print() const;

  ~DynamicArray() {
    delete[] m_pValues;
    m_pValues = nullptr;
  }

  int &At(int idx) { return m_pValues[idx]; }

private:
  int *m_pValues = nullptr;
  int m_cap = 0;
  int m_size = 0;
};

void DynamicArray::Print() const {
  for (int i = 0; i < m_cap; i++) {
    std::cout << m_pValues[i] << ", ";
  }
  std::cout << std::endl;
}

int main() {

  const DynamicArray myDA(10);

  myDA.Print();

  return 0;
}