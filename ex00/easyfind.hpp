#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw std::out_of_range("easyfind: Value not found");
  return it;
}

#endif  // __EASYFIND_H__