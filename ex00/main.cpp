#include <array>
#include <iostream>
#include <string>
#include "easyfind.hpp"

int main(void) {
  std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "arr: ";
  for (std::array<int, 10>::iterator it = arr.begin(); it != arr.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << "\n";

  std::cout << "find 4: " << *easyfind(arr, 4) << "\n";
  std::cout << "find 10: " << *easyfind(arr, 10) << "\n";

  std::cout << "find 42: ";
  try {
    std::cout << *easyfind(arr, 42) << "\n";
  } catch (std::exception& e) {
    std::cout << e.what() << "\n";
  }
  return (0);
}
