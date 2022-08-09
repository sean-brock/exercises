#include <iostream>


// This performs tree recursion in a depth-first manner.
void tree(int n) {
  if (n > 0) {
    std::cout << n << std::endl;
    tree(n - 1);
    tree(n - 1);
  }
}

int main() {
  constexpr int x = 4;
  tree(x);

  return 0;
}