#include <iostream>

int main() {
  int *myArray = new int[10];
  for (int i = 0; i < 10; i++) {
    myArray[i] = i + 1;
  }

  for (int i = 0; i < 10; i++) {
    std::cout << myArray[i] << std::endl;
  }

  // 2 x 4

  // int* <- 00 01 02 03
  // int* <- 10 11 12 13

  int numRows = 2;
  int numCols = 4;

  // Size of an array = Actual number of used variables
  // Capacity of an array = Ammount of memory allocated

  // NUM NEWS = number of rows + 1

  int **twoArray = new int *[numRows];
  for (int r = 0; r < numRows; r++) {
    twoArray[r] = new int[numCols];
  }

  // Size = 3 = 1 x 3
  // Cap = 8 = 2 x 4
  for (int r = 0; r < (numRows - 1); r++) {
    {
      for (int c = 0; c < (numCols - 1); c++) {
        twoArray[r][c] = r * 10 + c;
      }
    }
    std::cout << std::endl;
  }

  for (int r = 0; r < numRows; r++) {
    {
      for (int c = 0; c < numCols; c++) {
        std::cout << twoArray[r][c] << ", ";
      }
    }
    std::cout << std::endl;
  }

  // Deallocation
  for (int r = 0; r < numRows; r++) {
    delete[] twoArray[r];
    twoArray[r] = nullptr;
  }
  delete[] twoArray;

  twoArray = nullptr;

  // Print out the variables
  if (twoArray) {
    for (int r = 0; r < numRows; r++) {
      {
        for (int c = 0; c < numCols; c++) {

          std::cout << twoArray[r][c] << ", ";
        }
      }
    }
    std::cout << std::endl;
  }

  return 0;
}