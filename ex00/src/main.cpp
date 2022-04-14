#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "easyfind.hpp"
#include "test.hpp"

using std::cout;
using std::string;

void test_vector() {
  test::header("vector");
  std::vector<int> vec(10);
  for (int i = 0; i < 10; ++i)
    vec[i] = i;

  test_easyfind(vec);
}

void test_list() {
  test::header("list");
  std::list<int> lst(10);

  for (int i = 0; i < 10; ++i)
    lst.push_back(i);

  test_easyfind(lst);
}

int main(void) {
  test_vector();
  test_list();
  return 0;
}
