#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "mutantstack.hpp"
#include "util.hpp"

using std::cout;
template class MutantStack<int>;

void printInt(int value) {
  std::cout << value << ", ";
}

void mstack_info(MutantStack<int>& mstack) {
  log::val("size  ", mstack.size());
  log::val("empty?", mstack.empty());
  cout << BBLU << "data   " << HYEL ": " YEL;
  std::for_each(mstack.begin(), mstack.end(), printInt);
  cout << "\n" END;
}

void test_mandatory() {
  test::header("Mandatory output cmp");
  {
    test::subject("Mutantstack");
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }
  {
    test::subject("Mutantstack");
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::list<int> s(list);
  }
}

void test_copy() {
  test::header("copy constructor");
  MutantStack<int> mstack;

  MutantStack<int> copied(mstack);
  MutantStack<int> assigned = mstack;

  for (int i = 0; i < 3; i++)
    copied.pop();
  for (int i = 120; i < 24; i++)
    assigned.push(i);

  mstack_info(mstack);
  mstack_info(copied);
  mstack_info(assigned);
}

void test_general() {
  test::header("General");
  {
    cout.setf(std::ios::boolalpha);
    test::subject("creation");
    MutantStack<int> mstack;

    test::subject("add { 0 .. 9 }");
    for (int i = 0; i < 10; ++i)
      mstack.push(i);
    mstack_info(mstack);
    test::subject("\npop untill empty");
    for (int i = 0; i < 10; ++i) {
      log::val("top", mstack.top());
      mstack.pop();
    }
    mstack_info(mstack);
  }
  {
    MutantStack<int> mstack;
    for (int i = 0; i < 10; ++i)
      mstack.push(i);

    test::subject("iterator");
    std::for_each(mstack.begin(), mstack.end(), printInt);
    test::subject("reverse iterator");
    std::for_each(mstack.rbegin(), mstack.rend(), printInt);
    test::subject("const iterator");
    for (MutantStack<int>::const_iterator it = mstack.begin();
         it != mstack.end(); ++it) {
      std::cout << *it << ", ";
    }

    test::subject("const reverse iterator");
    for (MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
         it != mstack.rend(); ++it) {
      std::cout << *it << ", ";
    }
    cout << "\n";
  }
}

int main(void) {
  // test_mandatory();
  // test_general();
  test_copy();
}
