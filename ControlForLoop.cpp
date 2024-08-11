// Floating-point control in a for loop
#include <iostream>
#include <iomanip>
int main() {
  const double pi { 3.14159265358979323846 }; // The famous pi
  const size_t perline {3};                   // Outputs per line
  size_t linecount {};                        // Count of output lines
  for (double radius {0.2}; radius <= 3.0; radius += 0.2)
  {
    std::cout << std::fixed << std::setprecision(2)
              << "  radius =" << std::setw(5) << radius
              << "  area =" << std::setw(6) << pi * radius * radius;
    if (perline == ++linecount)
    {
      std::cout << std::endl;
      linecount = 0;
    }
  }
  
  std::cout << std::endl;
}
// When perline outputs have been written...
// ...start a new line...
// ...and reset the line counter