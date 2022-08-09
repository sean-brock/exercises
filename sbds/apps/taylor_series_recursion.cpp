#include <iostream>

double taylor_series(int x, int n) {
  static double factorial = 1;
  static double exponent = 1;
  if (n == 0) {
    return 1;
  } else {
    double sum = taylor_series(x, n - 1);
    exponent *= x;
    factorial *= n;
    return sum + (exponent / factorial);
  }
}

double taylor_series_horner_recursive(int x, int n) {
  static double result = 1;
  if (n == 0) {
    return result;
  } else {
    result = 1 + (x / double(n)) * result;
    return taylor_series_horner_recursive(x, n-1);
  }
}

double taylor_series_horner(int x, int n) {
  double result = 1;
  for (double i = n; i > 0; i--) {
    result = 1 + (x / i) * result;
  }
  return result;
}

int main() {
  std::cout << taylor_series(3, 10) << "\n"
            << taylor_series_horner(3, 10) << "\n"
            << taylor_series_horner_recursive(3, 10) << std::endl;
  return 0;
}