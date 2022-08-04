#include <iostream>

void print_greater_zero(int n) {
  if (n > 0) {
    std::cout << n << std::endl;
    print_greater_zero(n - 1);
  }
}

int main() {
  constexpr int x = 3;
  print_greater_zero(x);

  return 0;
}