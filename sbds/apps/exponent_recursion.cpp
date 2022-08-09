#include <iostream>

int pow2(int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return 2;
  } else {
    return 2 * pow2(n - 1);
  }
}

int pow(int m, int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return m;
  } else if (n % 2 == 0) {
    return pow(m * m, n / 2);
  } else {
    return m * pow(m * m, (n - 1) / 2);
  }
}

int main() {
  std::cout << pow2(8) << "\n"
            << pow2(2) << "\n"
            << pow(2, 8) << "\n"
            << pow(2, 2) << "\n"
            << pow(2, 7) << std::endl;
  return 0;
}