#include <iostream>

int fact(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

int main() { std::cout << fact(4) << std::endl; }