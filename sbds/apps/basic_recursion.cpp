#include <iostream>

void tail(int n) {
  if (n > 0) {
    std::cout << n << std::endl;
    tail(n - 1);
  }
}

void head(int n) {
  if (n > 0) {
    head(n - 1);
    std::cout << n << std::endl;
  }
}

int main() {
  constexpr int x = 3;
  std::cout << "Head:" << std::endl;
  head(x);
  std::cout << "Tail:" << std::endl;
  tail(x);

  return 0;
}