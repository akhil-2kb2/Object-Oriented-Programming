
// Obtaining the number of array elements
#include <iostream>
#include <array>          // for std::size()
int main() {
  int values[] {200, 300, 500, 700, 110, 130, 170, 190, 230, 290};
  std::cout << "There are " << sizeof(values) / sizeof(values[0]) << " elements in the array." << std::endl;
  int sum {};
  for (size_t i {}; i < std::size(values); ++i)
  {
    sum += values[i];
  }
  std::cout << "The sum of the array elements is " << sum << std::endl;
}