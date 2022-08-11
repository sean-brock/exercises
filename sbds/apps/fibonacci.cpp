#include <iostream>
#include <memory>

/*
  fib (n) 0 1 1 2 3 5 8 13
  n       0 1 2 3 4 5 6 7

  fib(n) =
    n if n <= 1
    fib(n-2) + fib(n-1)
*/
int fib_recursive(int *cache, int n) {
  if (n <= 1) {
    cache[n] = n;
    return n;
  }
  if (cache[n - 2] < 0)
    cache[n - 2] = fib_recursive(cache, n - 2);
  if (cache[n - 1] < 0)
    cache[n - 1] = fib_recursive(cache, n - 1);

  return cache[n-1] + cache[n-2];
}

int fib(int n) {
  if (n <= 1)
    return n;

  int cache[] = {0, 1};
  int tmp = 0;
  for (int i = 2; i <= n; i++) {
    tmp = cache[0] + cache[1];
    cache[0] = cache[1];
    cache[1] = tmp;
  }
  return cache[1];
}

int main() {
  constexpr int n = 20;

  auto cache = std::make_unique<int[]>(n);
  for (int i = 0; i < n; i++) {
    cache[i] = -1;
  }

  std::cout << fib(n) << "\n" << fib_recursive(cache.get(), n) << std::endl;

  int x = 1;
  std::cin >> x;
  int arr[x];

  std::cout << x <<std::endl;

  return 0;
}