#include "racionales.hpp"

int main() {
  Racional r1(4, 2), r2(2, 3);

  std::cout << r1 << std::endl << r2 << std::endl;
  std::cout << r1.suma(r2) << std::endl;
  return 0;
}