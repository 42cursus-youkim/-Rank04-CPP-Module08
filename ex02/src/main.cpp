#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include "mutantstack.hpp"

using std::cout;

void printInt(int value) {
  std::cout << value << "\n";
}

template class MutantStack<int>;

int main(void) {
  {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    cout << "top : " << mstack.top() << "\n";

    mstack.pop();
    cout << "top : " << mstack.top() << "\n";
    cout << "size : " << mstack.size() << "\n";

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::for_each(mstack.begin(), mstack.end(), printInt);
  }
  return 0;
}

// std::cout << "================ list test ================" << "\n";

// std::list<int> list;

// list.push_back(5);
// list.push_back(17);

// std::cout << "top : " << list.back() << "\n";

// list.pop_back();
// std::cout << "top : " << list.back() << "\n";
// std::cout << "size : " << list.size() << "\n";

// list.push_back(3);
// list.push_back(5);
// list.push_back(737);
// list.push_back(0);

// std::list<int>::iterator l_it = list.begin();

// for (; l_it != list.end(); l_it++) {
//   std::cout << "value : " << *l_it << "\n";
// }

// std::cout << "================ copy constructor test ================"
//           << "\n";
// MutantStack<int> s_copy(mstack);
// MutantStack<int> s_oper = mstack;

// s_copy.pop();
// s_copy.pop();
// s_copy.pop();
// s_copy.push(42);
// s_copy.push(43);
// s_copy.push(44);

// MutantStack<int>::iterator c_iter = s_copy.begin();
// for (; c_iter != s_copy.end(); c_iter++) {
//   std::cout << *c_iter << "\n";
// }

// std::cout << "-------------------------------------------------------"
//           << "\n";

// s_oper.pop();
// s_oper.pop();
// s_oper.pop();
// s_oper.push(52);
// s_oper.push(53);
// s_oper.push(54);

// MutantStack<int>::iterator o_iter = s_oper.begin();
// for (; o_iter != s_oper.end(); o_iter++) {
//   std::cout << *o_iter << "\n";
// }

// std::cout << "================ reverse iterator test================"
//           << "\n";
// MutantStack<int> reverse;
// reverse.push(1);
// reverse.push(2);
// reverse.push(3);
// reverse.push(4);
// reverse.push(5);

// for (MutantStack<int>::reverse_iterator r_iter = reverse.rbegin();
//      r_iter != reverse.rend(); r_iter++) {
//   std::cout << "value : " << *r_iter << "\n";
// }
