#include <iostream>

/*
  fib (n) 0 1 1 2 3 5 8 13
  n       0 1 2 3 4 5 6 7

  fib(n) = 
    n if n <= 1
    fib(n-2) + fib(n-1)
*/
int fib_recursive(int n) { return 0; }

int fib(int n) { 
  if (n <= 1)
    return n;

  int cache[] = {0,1};
  int tmp = 0;
  for (int i = 2; i <= n; i++) {
    tmp = cache[0] + cache[1];
    cache[0] = cache[1];
    cache[1] = tmp;
  }
  return cache[1]; 
}

int main() {
  std::cout << fib(6) << "\n" << fib_recursive(6) << std::endl;
  return 0;
}