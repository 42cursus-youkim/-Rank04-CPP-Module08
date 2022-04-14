#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "easyfind.hpp"
#include "test.hpp"

using std::string;

int main(void) {
  {
    test::header("vector");
    std::vector<int> v(10);
    for (int i = 0; i < 10; ++i) {
      v[i] = i;
    }
    for (int i = 0; i < 15; ++i) {
      std::vector<int>::iterator it = easyfind(v, i);
      if (it == v.end()) {
        std::cout << "Not found" << std::endl;
      } else {
        std::cout << "Found: " << *it << std::endl;
      }
    }
  }
  {
    test::header("list");
    std::list<int> l;
    for (int i = 0; i < 10; ++i) {
      l.push_back(i);
    }
    for (int i = 0; i < 15; ++i) {
      std::list<int>::iterator it = easyfind(l, i);
      if (it == l.end()) {
        std::cout << "Not found" << std::endl;
      } else {
        std::cout << "Found: " << *it << std::endl;
      }
    }
  }
}
