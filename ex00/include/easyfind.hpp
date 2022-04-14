#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "color.hpp"
using std::cout;

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  return std::find(container.begin(), container.end(), value);
}

template <typename T>
void test_easyfind(T& container) {
  for (int i = -1; i < 12; ++i) {
    typename T::iterator it = easyfind(container, i);
    cout << std::setw(2) << i << ": ";
    if (it == container.end())
      cout << RED "not found\n" END;
    else
      cout << GRN << *it << "\n" END;
  }
}
#endif  // __EASYFIND_H__
