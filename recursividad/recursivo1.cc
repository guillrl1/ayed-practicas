#include <iostream>

unsigned int digits(const unsigned int number) {
  return number > 0 ? 1 + digits(number / 10) : 0;
}

unsigned int sum(const unsigned int number) {
  return number > 0 ? (number % 10) + sum(number / 10) : 0;
}
unsigned int binario(const unsigned int number) {
  return number > 0 ? (binario(number / 2)) * 10 + (number % 2) : 0;
}
unsigned int Collatz(const unsigned int number) {
  return number == 1 ? 1 : number > 1 ? 1 + Collatz(number / 2) : 1 + Collatz(3 * number + 1);
}
int main() {
  unsigned int n = 3984;
  unsigned result = Collatz(n);
  std::cout << result << std::endl;
}