#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  return std::find(container.begin(), container.end(), value);
}

#endif  // __EASYFIND_H__
