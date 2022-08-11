#include "sbds/array.h"
#include <iostream>

int main() {
  Array<int> arr{5, 10};
  arr.display();
  arr.set(2, 5);
  arr.display();
  arr.append(5);
  arr.display();
  int x = arr.remove(2);
  std::cout << "removed index 2: " << x << std::endl;
  arr.display();

  arr.insert(0, 11);
  arr.display();
  arr.remove(0);

  arr.display();

  auto result = arr.linearSearch(5);
  arr.display();
  std::cout << result.found << ", " << result.index << std::endl;
  return 0;
}